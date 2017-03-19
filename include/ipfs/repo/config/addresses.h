#ifndef addresses_h
#define addresses_h

#include "libp2p/utils/linked_list.h"
#include "swarm.h"

struct Addresses {
	struct Libp2pLinkedList* swarm_head;
	char* api;
	char* gateway;
};

/**
 * initialize the Addresses struct with data. Must add the SwarmAddresses later
 * @param addresses the struct
 * @param api the API address (like "/ip4/127.0.0.1/tcp/5001")
 * @param gateway the gateway address (like "ip4/127.0.0.1/tcp/8080")
 * @returns true(1) on success, otherwise false(0)
 */
int repo_config_addresses_new(struct Addresses** addresses, char* api, char* gateway);

/**
 * clear any memory allocated by a address_new call
 * @param addresses the struct
 * @returns true(1)
 */
int repo_config_addresses_free(struct Addresses* addresses);

#endif /* addresses_h */
