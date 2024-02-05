
BST:
	clang++ -std=c++11 -c BST.cpp BSTtest.cpp
	clang -c -o BST.obj BST.cpp
	ar rcs BST.lib BST.obj

BSTtest:
		clang++ BSTtest.cpp BST.lib -o BSTtest

PartB:
		clang++ -std=c++11 -c replace.cpp -o replace.o
		clang++ replace.cpp BST.lib -o replace

clean:
		rm -rf BST.obj BST.lib BST.o
		rm -rf BSTtest BSTtest.o
		rm -rf replace replace.o
