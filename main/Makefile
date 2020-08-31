CC = gcc
CFLAGS = -O0 -I../include -I../c-libp2p/include -I../c-libp2p/c-multihash/include -I../c-libp2p/c-multiaddr/include -I../c-libp2p/c-protobuf -g3 -Wall -std=gnu99
LFLAGS = -L../c-libp2p -L../c-libp2p/c-multihash -L../c-libp2p/c-multiaddr -l:libp2p.a -lm -llmdb -lmultihash -lmultiaddr -lpthread -lresolv -lcurl
DEPS = cmd/ipfs/test_init.h repo/test_repo_bootstrap_peers.h repo/test_repo_config.h repo/test_repo_identity.h cid/test_cid.h
OBJS = main.o \
	../blocks/block.o ../blocks/blockstore.o \
	../cid/cid.o \
	../cmd/ipfs/init.o \
	../cmd/*.o \
	../commands/argument.o ../commands/command_option.o ../commands/command.o ../commands/cli/parse.o \
	../core/*.o \
	../datastore/ds_helper.o \
	../datastore/key.o \
	../dnslink/*.o \
	../exchange/bitswap/*.o \
	../flatfs/flatfs.o \
	../importer/importer.o ../importer/exporter.o ../importer/resolver.o \
	../journal/*.o \
	../path/path.o \
	../merkledag/merkledag.o ../merkledag/node.o \
	../multibase/multibase.o \
	../namesys/*.o \
	../pin/pin.o \
	../repo/init.o \
	../repo/fsrepo/*.o \
	../repo/config/*.o \
	../routing/*.o \
	../thirdparty/ipfsaddr/ipfs_addr.o \
	../unixfs/unixfs.o \
	../c-libp2p/c-protobuf/protobuf.o ../c-libp2p/c-protobuf/varint.o \
	../util/errs.o \
	../util/time.o \
	../util/thread_pool.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ipfs: $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

all: ipfs

clean:
	rm -f *.o
	rm -f ipfs
