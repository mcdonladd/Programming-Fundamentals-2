/*
	The purpose of this file is to provide a blueprint of the BST class.
  It defines the public and private members of the class and how objects if the class can be manipulated.

 Program written by Sam McDonald
*/

#pragma once
#include <string>
struct Node
{
    Node *left;
    Node *right;
    std::string name;
    std::string value;
};

class BST
{
public:
    BST();
    BST(BST const &other); //Assignment operator, e.g. tree1 = tree2. Deletes the nodes in tree1, freeing memory, and then makes deep copies of all of the nodes in tree2.
    ~BST(); //Destructor for the BST class. This should free all heap-allocated memory
    BST& operator=(const BST &rhs); //Creates a binary search tree by copying all of the constant-value pairs from an existing binary search tree
    void insert_constant(std::string name, std::string value); //inserts constant name and value
    std::string to_string() const;
    std::string get_value(std::string name) const; //returns the value that corrosponds to name
    int num_constants() const; //Returns the number of constant-value pairs that have been inserted into the tree

private:
    Node *root;
};
