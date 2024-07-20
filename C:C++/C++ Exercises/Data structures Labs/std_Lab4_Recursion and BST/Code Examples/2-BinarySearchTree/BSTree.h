#pragma once

#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

class BSTree
{
private:
	Node* root;

	// Utility Functions - Recursive Functions --------------------------

	// Given functions
	static void rec_insertBST(Node *& subRoot, int key);
	static void rec_inorder_traverse(Node* subRoot);
	static void rec_preorder_traverse(Node* subRoot);
	static void rec_postorder_traverse(Node* subRoot);	
	static void rec_destroy_tree(Node *& subRoot);

	//Functions to be implemented by student
	static Node*  rec_find_max(Node* subRoot);
	static Node*  rec_find_min(Node* subRoot);
	static int rec_max_depth(Node* subRoot);

	static int rec_count_greater(Node* subRoot, int value);

	void rec_printBT(const std::string& prefix, Node* node, bool isLeft);

public:
	void printBT();

	// [Note]: in the above utility functions:
	// we made them static --
	// because they don't need an object of BSTree to be executed
	// in otherwords, they don't can't with the non-static data members of BSTree (the "root" data member)
	// this is a way that will prevent you from: 
	// using "root" instead of the passed "subRoot" by mistake  -> syntax error

public:
	BSTree(void);
	~BSTree(void);

	// Public Functions --------------------------

	// Given functions
	void insertBST(int key); // not const
	void inorder_traverse() const;
	void preorder_traverse() const;
	void postorder_traverse() const;	
	void destroy_tree(); // not const

	// Functions to be implemented by student
	Node*  find_max() const; // return a pointer to the node that hold the maximum value in binary search tree.
	Node*  find_min() const; // return a pointer to the node that hold the minimum value in binary search tree.
	int max_depth() const;

	int count_greater(int value);

	// [Note]: in the above public functions:
	// const functions are const because there is no probibility to change 
	// the root (data member) either directly (root = something) 
	// or by indirectly by passing it (by reference) to another function (utility fn here)
};

