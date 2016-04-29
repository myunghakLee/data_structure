#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<iostream>

class node {
private:
	int num;
	node *next_node;
public:
	node(int a) {
		num = a;
	}
	friend class queue;
};


class queue {
private:
	node *front;
	node *rear;
public:
	queue(){
		front = NULL;
		rear = NULL;
	}
	bool is_it_empty();
	void enqueue(int a);
	int dequeue();
	int qpeek();
};

#endif