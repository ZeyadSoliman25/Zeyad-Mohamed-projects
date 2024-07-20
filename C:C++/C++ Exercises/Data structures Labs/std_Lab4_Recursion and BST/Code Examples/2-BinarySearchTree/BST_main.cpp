
#include "BSTree.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	BSTree bst;
	int max_depth;

	//build tree       8 
	//               /   \ 
	//              3     13
	//             / \   / 
	//            1   4 9

	//==============================================================
	//							InsertBST function
	//==============================================================
	cout << "building the tree with sequence 8 13 3 9 1 4" << endl << endl;
	bst.insertBST(8);
	bst.insertBST(13);
	bst.insertBST(3);
	bst.insertBST(9);
	bst.insertBST(1);
	bst.insertBST(4);
	bst.printBT();
	//==============================================================
	//							Traversal
	//==============================================================
	// traverse the tree with different orders
	cout << "The tree pre-order traversal" << endl;
	bst.preorder_traverse();
	cout << endl;

	cout << "The tree in-order traversal" << endl;
	bst.inorder_traverse();
	cout << endl;

	cout << "The tree post-order traversal" << endl;
	bst.postorder_traverse();
	cout << endl;

	max_depth = bst.max_depth();
	cout << "The tree max depth is " << max_depth << endl;

	cout << "The tree min node is " << bst.find_min()->getdata() << endl;

	cout << "The count of nodes that has values greater than 4 is " << bst.count_greater(4) << endl;
	//==============================================================
	//							Destroy
	//==============================================================
	cout << "Destroying tree " << endl;
	bst.destroy_tree();
	string s;
	getline(cin, s); //just to pause console (output) screen
	return 0;
}
