#ifndef __LINKED_LIST_HEAD__
# define __LINKED_LIST_HEAD__

#include<iostream>

class node {
private:
	node *next_node;
	node *prev_node;
	int data;
public:
	friend class linked_list;
};

class linked_list {
private:
	node *tail;
	node *temp;					//�Լ����� Ư������ ã���� ���
public:
	linked_list(){
		node *tail = NULL;
	}
	bool is_it_empty();
	void insert(int num);
	void Sinsert(int num);		//�����ؼ� ����ֱ�
	int Nview_tail();			//���� tail���� return�ϰ� tail�� ��ĭ �ڷ� �ű��
	int Pview_tail();			//���� tail���� return�ϰ� tail�� ��ĭ ������ �ű��
	void remove();				//�� �ڿ���(tail) ����
	void Sremove(int num);		//������ ���� ����	
	int search(int num);
};

#endif