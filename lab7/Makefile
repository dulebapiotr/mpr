compile:
	gcc -Wall static_generator.c -o static_generator -fopenmp
	gcc -Wall dynamic_generator.c -o dynamic_generator -fopenmp
	chmod +x static_generator
	chmod +x dynamic_generator

static:
	./static_generator 1000 10
	./static_generator 10000 10
	./static_generator 100000 10


dynamic:
	./dynamic_generator 1000 10
	./dynamic_generator 10000 10
	./dynamic_generator 100000 10