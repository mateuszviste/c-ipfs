
DEBUG = true
export DEBUG

all:
	cd blocks; make all;
	cd cid; make all;
	cd cmd; make all;
	cd commands; make all;
	cd core; make all;
	cd exchange; make all;
	cd importer; make all;
	cd journal; make all;
	cd merkledag; make all;
	cd multibase; make all;
	cd pin; make all;
	cd repo; make all;
	cd flatfs; make all;
	cd datastore; make all;
	cd thirdparty; make all;
	cd unixfs; make all;
	cd routing; make all;
	cd dnslink; make all;
	cd namesys; make all;
	cd path; make all;
	cd util; make all;
	cd main; make all;
	cd test; make all;

clean:
	cd blocks; make clean;
	cd cid; make clean;
	cd cmd; make clean;
	cd commands; make clean;
	cd core; make clean;
	cd exchange; make clean;
	cd importer; make clean;
	cd journal; make clean;
	cd merkledag; make clean;
	cd multibase; make clean;
	cd pin; make clean;
	cd repo; make clean;
	cd flatfs; make clean;
	cd datastore; make clean;
	cd thirdparty; make clean;
	cd unixfs; make clean;
	cd main; make clean;
	cd routing; make clean;
	cd dnslink; make clean;
	cd namesys; make clean;
	cd path; make clean;
	cd util; make clean;
	cd test; make clean;

rebuild: clean all
