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
	node *temp;					//함수에서 특정값을 찾을때 사용
public:
	linked_list(){
		node *tail = NULL;
	}
	bool is_it_empty();
	void insert(int num);
	void Sinsert(int num);		//정렬해서 집어넣기
	int Nview_tail();			//현재 tail값을 return하고 tail을 한칸 뒤로 옮긴다
	int Pview_tail();			//현재 tail값을 return하고 tail을 한칸 앞으로 옮긴다
	void remove();				//맨 뒤에거(tail) 삭제
	void Sremove(int num);		//지정된 숫자 삭제	
	int search(int num);
};

#endif