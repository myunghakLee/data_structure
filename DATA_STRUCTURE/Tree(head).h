#ifndef __TREE_H__
#define __TREE_H__

#include<iostream>

class node {
private:
	int data;

public:
	friend class tree;
	friend class AVL_tree;
	node * Lnode;
	node * Rnode;

};


class tree {
private:
	node * root;
	int volume;											//tree�� ũ�� ����
	node * N;											//root�������� �����Ͽ� �̵��ϴ� ���
	int bin[20];										//complte tree�� ������� �������� ����ؾ� �Ǵµ� �׶� ����� �Լ� complte tree�Լ��� heap�Ѵ� ���� ����ؾ��ϱ⿡ class�� �ɹ������� �������
public:
	tree(int num) {
		root = new node;
		root->data = num;
		root->Rnode = NULL;
		root->Lnode = NULL;
		volume = 1;
	}
	tree() {}
	void make_node(node * N, int data);
	void make_left_sub_tree(node * Pt, int data);		//pt�� ����Ʈ���� �����ϰ� �ű⿡ data���� �������
	void make_right_sub_tree(node * Pt, int data);
	void post_order_traverse(node * bt);
	void in_order_traverse(node * bt);
	void pre_order_traverse(node * bt); 
	node *get_root() { return root; }

	int insert_complete_binary_tree(int data);							//tree�� ������ �Ʒ���, ���ʿ��� ���������� ���� �������� ����
	void insert_tree_sort(int data);					//tree�� ���� ����ֵ� ����(ó�������� �� �� root��庸�� ũ�� ������ ������ ���ʿ� ����)�ؼ� �������

	void insert_min_heap(int data);
	void insert_max_heap(int data);
	int delete_max_heap();								//max heap�� root node�� ����
	int delete_min_heap();
	void change_node(node*a, node*b);
	friend class AVL_tree;
};

class AVL_tree : public tree {
public:
	AVL_tree(int num) {
		root = new node;
		root->data = num;
		root->Rnode = NULL;
		root->Lnode = NULL;
		volume = 1;
	}
	void make_AVL_tree(int data);							//AVLƮ���� ���鶧 ����Ұ�
	void change_left_sub_tree(node *a, node *b);			//a�� left sub tree �� b�� �ٲ۴�.
	void change_right_sub_tree(node *a, node *b);			//a�� left sub tree �� b�� �ٲ۴�.
	void rebalancing(node *a);										//tree�� �뷱���� �ٽø���
	node* RRrotate(node * a);										//���������θ� 2���� ��尡 �ִ»���
	node* LLrotate(node * a);										//�������θ� 2���� ��尡 �ִ»���
	node* LRrotate(node * a);										//�������� �ϳ� �� ���� ���������� �ϳ��� �ִ� ����
	node* RLrotate(node * a);										//���������� �ϳ� �� ���� �������� �ϳ��� �ִ� ����
	int return_BF(node *a);									//node a d�� bf�� ���ؼ� ��ȯ���� balance factor(�����μ�) ���� ����Ʈ���� ������ ����Ʈ���� ������, AVL tree���� ���


};

#endif