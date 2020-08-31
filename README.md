# C-IPFS
IPFS implementation in C, (not just an API client library).

## Quick start for users:
* **ipfs init** to create an ipfs repository on your machine
* **ipfs add MyFile.txt** to add a file to the repository, will return with a hash that can be used to retrieve the file.
* **ipfs cat _hash_** to retrieve a file from the repository

## For techies (ipfs spec docs):
* [getting started](https://github.com/ipfs/specs/blob/master/overviews/implement-ipfs.md)
* [specifications](https://github.com/ipfs/specs)
* [getting started](https://github.com/ipfs/community/issues/177)
* [libp2p](https://github.com/libp2p/specs)

## Prerequisites - to compile the C version you will need:
* liblmdb
* [c-libp2p](https://github.com/mateuszviste/c-libp2p)

## How to compile the C version:

### First fetch and compile the IPFS companion library (libp2p):
```
svn co https://github.com/mateuszviste/c-libp2p
cd c-libp2p/trunk
make
```
### Now fetch and compile IPFS itself (and link the libp2p lib)
```
svn co https://github.com/mateuszviste/c-ipfs
cd c-ipfs/trunk
ln -s ../../c-libp2p/trunk c-libp2p
make
```
