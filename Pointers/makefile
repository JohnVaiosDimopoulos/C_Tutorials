
all: setup ex1 ex2 ex3 ex4

ex1:
	gcc -c src/examples/example1_simple.c -o objects/example1_simple.o
	gcc -o target/example1_simple  objects/example1_simple.o

ex2:
	gcc -c src/examples/example2_swap.c -o objects/example2_swap.o
	gcc -o target/example2_swap objects/example2_swap.o

ex3:
	gcc -c src/examples/example3_dynamic_allocation.c -o objects/example3_dynamic_allocation.o
	gcc -o target/example3_dynamic_allocation objects/example3_dynamic_allocation.o
ex4:
	gcc -c src/examples/example4_dymanic_allocation2.c -o objects/example4_dymanic_allocation2.o
	gcc -o target/example4_dymanic_allocation2 objects/example4_dymanic_allocation2.o

setup:
	mkdir -p target objects
