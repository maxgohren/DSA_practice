.SILENT:

arrays:
	cp arrays.cpp buildArrays/
	cd buildArrays/ && \
	g++ -o runArrays arrays.cpp && \
	./runArrays

missingEl: 
	rm -rf buildMissingElement/*
	cp missingElement.cpp buildMissingElement/
	cd buildMissingElement/ && \
	g++ -o runMissingElement missingElement.cpp && \
	./runMissingElement

pair: 
	rm -rf buildPairSum/*
	cp pairsum.cpp buildPairSum/
	cd buildPairSum/ && \
	g++ -o runPairSum pairsum.cpp && \
	./runPairSum

debugmissingEl:
	rm -rf buildMissingElement/*
	cp missingElement.cpp buildMissingElement/
	cd buildMissingElement/ && \
	g++ -g -o runMissingElement missingElement.cpp && \
	./runMissingElement

