/*
	The purpose of this program is to create a library of a Binary Search Tree, and implements the methods:
  Insert constant(string name, string value)
  Get value(string name)
  Num constants()
  ~BST()
  BST(const BST &rhs)
  BST& operator=(const BST &rhs)

 Date of last modification: 29/04/23
 Program written by Sam McDonald
*/

#include <string>
#include "BST.h"
using namespace std;

string to_string_helper(Node *root); //Prototype of a helper function,
									 //You can add additional helper functions
									//to this code file

BST::BST()
{
    this->root = nullptr;
}


void constructor_helper(Node *oldRoot, Node *&newRoot)
{
  if (oldRoot != nullptr)
  {
    //creates new node
    newRoot = new Node;
    newRoot->left = nullptr;
    newRoot->right = nullptr;
    newRoot->name = oldRoot->name;
    newRoot->value = oldRoot->value;

    //recursively construct left and right
    constructor_helper(oldRoot->left, newRoot->left);
    constructor_helper(oldRoot->right, newRoot->right);
  }
}

BST::BST(const BST &other)
{
   //TODO: Implement the copy constructor
   constructor_helper(other.root, root);
}


void destructer_helper(Node *root)
{
  if(root == nullptr)
  {
    return;
  }
    //recursively destruct left and right
    destructer_helper(root->left);
    destructer_helper(root->right);

    delete (root);
}


BST::~BST()
{
    //TODO: Implement the destructor
    destructer_helper(root);
}


//A helper function to allow recursive calls
//You can add helper functions like this for the other methods,
//to recursively move through the tree
string to_string_helper(Node *root)
{
    if(root == nullptr)
    {
        return "";
    }
    else
    {
        return to_string_helper(root->left) +
            root->name + "=" + root->value + " " +
            to_string_helper(root->right);
    }
}

string BST::to_string() const
{
    string ret = to_string_helper(this->root);
    if(ret.length() > 1)
    {
         ret.pop_back(); //remove final space
    }

    return ret;
}


void insert_helper(Node **tree, string name, string value) {

  if (*tree == nullptr) {
    // Create new node
    *tree = new Node;
    // Set new value
    (*tree)->value = value;
    (*tree)->name = name;
    // Set branches to nullptr
    (*tree)->left = nullptr;
    (*tree)->right = nullptr;
  }
  else
  {
      //recursively insert
      if (name < (*tree)->name)
      {
        insert_helper(&(*tree)->left,name, value);
      }

      if (name > (*tree)->name)
      {
        insert_helper(&(*tree)->right, name, value);
      }
  }
}

void BST::insert_constant(string name, string value)
{
  insert_helper(&root, name, value);
   //TODO: Implement the insert_constant method
}


string get_value_helper(Node *tree, string name)
{

  if(tree == nullptr)
  {
    return "";
  }

   // Check if current node matches name
   if (name == tree->name)
   {
     return tree->value;
   }
   // Recursively search for data value
    if  (name < tree->name)
    {
     return(get_value_helper(tree->left,name));
    }
    if (name > tree->name)
    {
      return(get_value_helper(tree->right,name));
    }
    return "";

}

string BST::get_value(string name) const
 {
    return get_value_helper(root, name);
 }


int num_constants_helper(Node *tree)
{

  if(tree == nullptr)
  {
    return 0;
  }
  else
  {
    //recursively count the number if constants
    return num_constants_helper(tree->left) + num_constants_helper(tree->right) +1;
  }

}


int BST::num_constants() const
{
    return num_constants_helper(root); //TODO: Change this to implement the num_constants() method
}


BST& BST::operator=(const BST &rhs)
{
  //deletes existing nodes
  destructer_helper(root);

  //creates deep copy
  constructor_helper(rhs.root, root);

	return *this; //TODO: Add code here to implement the = operator
}
