#include "Tree(head).h"

void main() {
	tree T(1);

	//T.make_left_sub_tree(T.get_root(),2);
	//T.make_left_sub_tree(T.get_root()->Lnode,4);
	//T.make_right_sub_tree(T.get_root()->Lnode,5);
	//T.make_right_sub_tree(T.get_root()->Lnode->Lnode, 8);
	//T.make_left_sub_tree(T.get_root()->Lnode->Lnode->Rnode, 9);
	//T.make_right_sub_tree(T.get_root()->Lnode->Lnode->Rnode, 10);
	//T.make_right_sub_tree(T.get_root(), 3);
	//T.make_left_sub_tree(T.get_root()->Rnode, 6);
	//T.make_right_sub_tree(T.get_root()->Rnode->Lnode, 7);

	T.insert_max_heap(2);
	T.insert_max_heap(0);
	T.insert_max_heap(4);
	T.insert_max_heap(5);
	T.insert_max_heap(6);
	T.insert_max_heap(7);

	T.delete_max_heap();

	T.post_order_traverse(T.get_root());
	std::cout << std::endl;
	T.in_order_traverse(T.get_root());
	std::cout << std::endl;
	T.pre_order_traverse(T.get_root());
	std::cout << std::endl;
}