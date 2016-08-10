#include<iostream>
#include "Tree(head).h"

void main() {
	AVL_tree AT(10);

	AT.make_AVL_tree(9);
	AT.make_AVL_tree(8);
	AT.make_AVL_tree(7);
	AT.make_AVL_tree(6);
	AT.make_AVL_tree(5);
	AT.post_order_traverse(AT.get_root());

}