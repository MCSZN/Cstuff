all:
	gcc src/linked.c -o bin/linked
	gcc src/neural.c -o bin/neural
	./bin/linked