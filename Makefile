all:
	gcc -o mymatrix bstree.c matrix.c main.c datatype.c
clean:
	rm -rg mymatrix.exe