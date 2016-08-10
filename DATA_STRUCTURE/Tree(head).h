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
	int volume;											//tree의 크기 저장
	node * N;											//root에서부터 시작하여 이동하는 노드
	int bin[20];										//complte tree를 만드는중 이진수를 사용해야 되는데 그때 사용할 함수 complte tree함수와 heap둘다 에서 사용해야하기에 class의 맴버변수로 집어넣음
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
	void make_left_sub_tree(node * Pt, int data);		//pt의 왼쪽트리를 생성하고 거기에 data값을 집어넣음
	void make_right_sub_tree(node * Pt, int data);
	void post_order_traverse(node * bt);
	void in_order_traverse(node * bt);
	void pre_order_traverse(node * bt); 
	node *get_root() { return root; }

	int insert_complete_binary_tree(int data);							//tree에 위에서 아래로, 왼쪽에서 오른쪽으로 값을 차곡차곡 쌓음
	void insert_tree_sort(int data);					//tree에 값을 집어넣되 정렬(처음시작한 값 즉 root노드보다 크면 오른쪽 작으면 왼쪽에 저장)해서 집어넣음

	void insert_min_heap(int data);
	void insert_max_heap(int data);
	int delete_max_heap();								//max heap의 root node를 지움
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
	void make_AVL_tree(int data);							//AVL트리를 만들때 사용할것
	void change_left_sub_tree(node *a, node *b);			//a의 left sub tree 를 b로 바꾼다.
	void change_right_sub_tree(node *a, node *b);			//a의 left sub tree 를 b로 바꾼다.
	void rebalancing(node *a);										//tree의 밸런스를 다시맞춤
	node* RRrotate(node * a);										//오른쪽으로만 2개의 노드가 있는상태
	node* LLrotate(node * a);										//왼쪽으로만 2개의 노드가 있는상태
	node* LRrotate(node * a);										//왼쪽으로 하나 그 다음 오른쪽으로 하나가 있는 상태
	node* RLrotate(node * a);										//오른쪽으로 하나 그 다음 왼쪽으로 하나가 있는 상태
	int return_BF(node *a);									//node a d의 bf를 구해서 반환해줌 balance factor(균형인수) 왼쪽 서브트리와 오른쪽 서브트리의 높이차, AVL tree에서 사용


};

#endif