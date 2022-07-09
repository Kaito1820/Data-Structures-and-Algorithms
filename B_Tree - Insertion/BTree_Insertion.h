#pragma once
#include <iostream>
using namespace std;

class BTreeNode{
private:
	int *keys; // An array of keys
	int t;	 // Minimum degree (defines the range for number of keys)
	BTreeNode **C; // An array of child pointers
	int n;	 // Current number of keys
	bool leaf; // Is true when node is leaf. Otherwise false
public:
	BTreeNode(int _t, bool _leaf); 

	// A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
 
    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);
	
	void traverse();

	BTreeNode *search(int k);

    friend class BTree;
};


class BTree{
private:
	BTreeNode *root; // Pointer to root node
	int t; // Minimum degree
public:
	BTree(int _t){ 
        root = NULL; 
        t = _t; 
    }

	// The main function that inserts a new key in this B-Tree
    void insert(int k);

	void traverse(){ 
        if (root != NULL) root->traverse(); 
    }

	BTreeNode* search(int k){ 
        return (root == NULL)? NULL : root->search(k); 
    }
};