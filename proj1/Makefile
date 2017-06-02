upgma : main.o dynmatrix.o
	g++ -Wall -g main.o dynmatrix.o -o upgma

main.o : main.cc dynmatrix.h
	g++ -Wall -g -c main.cc

dynmatrix.o : dynmatrix.h dynmatrix.cc
	g++ -Wall -g -c dynmatrix.cc

clean :
	rm -f dynmatrix.o main.o upgma
