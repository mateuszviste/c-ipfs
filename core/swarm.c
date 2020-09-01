#include <stdio.h>
#include <stdlib.h>

#include "libp2p/utils/logger.h"
#include "ipfs/core/ipfs_node.h"
#include "ipfs/core/swarm.h"
#include "ipfs/core/http_request.h"

/***
 * Connect to a swarm
 * @param local_node the local node
 * @param address the address of the remote
 * @returns true(1) on success, false(0) otherwise
 */
int ipfs_swarm_connect(struct IpfsNode* local_node, const char* address) {
	char* response = NULL;
	size_t response_size;
	// use the API to connect
	struct HttpRequest* request = ipfs_core_http_request_new();
	if (request == NULL)
		return 0;
	request->command = "swarm";
	request->sub_command = "connect";
	libp2p_utils_vector_add(request->arguments, address);
	int retVal = ipfs_core_http_request_get(local_node, request, &response, &response_size);
	if (response != NULL && response_size > 0) {
		fwrite(response, 1, response_size, stdout);
		free(response);
	}
	ipfs_core_http_request_free(request);
	return retVal;
}

/***
 * Handle command line swarm call
 */
int ipfs_swarm (struct CliArguments* args) {
	int retVal = 0;
	struct IpfsNode* client_node = NULL;

	if (args->argc < (args->verb_index + 2)) {
		libp2p_logger_error("swarm", "Not enough command line arguments. Should be \"swarm connect <peer>\" or \"swarm disconnect\" etc.\n");
		goto exit;
	}

	// make sure API is running
	if (!ipfs_node_offline_new(args->config_dir, &client_node)) {
		libp2p_logger_error("swarm", "Unable to create offline node.\n");
		goto exit;
	}
	if (client_node->mode != MODE_API_AVAILABLE) {
		libp2p_logger_error("swarm", "API must be running.\n");
		goto exit;
	}

	const char* which = args->argv[args->verb_index + 1];
	const char* path = args->argv[args->verb_index + 2];
	// determine what we're doing
	if ((strcmp(which, "connect") == 0) && (args->argc == args->verb_index + 3)) {
		retVal = ipfs_swarm_connect(client_node, path);
	} else if (strcmp(which, "disconnect") == 0) {
		libp2p_logger_error("swarm", "Swarm disconnect not implemented yet.\n");
		retVal = 0;
	} else {
		libp2p_logger_error("swarm", "Nothing useful found on command line. Should be \"swarm connect <peer>\" or \"swarm disconnect\".\n");
		goto exit;
	}

	exit:
	// shut everything down
	ipfs_node_free(client_node);

	return retVal;
}
