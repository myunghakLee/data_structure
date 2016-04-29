#include"Queue(head).h"

bool queue::is_it_empty() {
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void queue::enqueue(int a) {
	node *new_node = new node(a);
	if (is_it_empty()) {
		front = new_node;
		rear = new_node;
	}
	else{
		rear->next_node = new_node;
		rear = new_node;
		rear->next_node = NULL;
	}
}

int queue::dequeue() {
	if (is_it_empty()) {
		std::cout << "queue is empty\n";
		return -1;
	}
	else {
		int data = front->num;
		front = front->next_node;
		return data;
	}
}

int queue::qpeek() {
	if (is_it_empty()) {
		std::cout << "queue is empty\n";
		return -1;
	}
	else {
		return front->num;
	}
}