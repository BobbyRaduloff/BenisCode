all:
	g++ main.cpp -o beniscode

install:
	cp beniscode /usr/local/bin/beniscode

delete:
	rm /usr/local/bin/beniscode