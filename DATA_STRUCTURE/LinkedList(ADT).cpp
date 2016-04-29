#include "LinkedList(head).h"

bool linked_list::is_it_empty() {
	if (tail == NULL) { return true; }
	else { return false; }
}

void linked_list::insert(int num) {
	node * new_node = new node;
	new_node->data = num;
	if (is_it_empty()) {
		tail = new_node;
		tail->next_node = tail;
		tail->prev_node = tail;
	}
	else {
		new_node->next_node = tail->next_node;
		tail->next_node->prev_node = new_node;
		tail->next_node = new_node;
		new_node->prev_node = tail;
		tail = new_node;
	}
}

void linked_list::Sinsert(int num) {
	node *new_node = new node;
	new_node->data = num;

	if (is_it_empty()) {
		tail = new_node;
		tail->next_node = tail;
		tail->prev_node = tail;
	}
	else {
		temp = tail->next_node;
		
		while (temp != tail || tail->data > new_node->data) {		//이 부분과 이 부분의 밑에 부분을 바꾸면 오름차순 내림차순이 바뀜
			if (temp->data > new_node->data) {
				new_node->next_node = temp;
				new_node->prev_node = temp->prev_node;
				temp->prev_node->next_node = new_node;
				temp->prev_node = new_node;
				return;
			}
			temp = temp->next_node;
		}
		new_node->next_node = temp->next_node;
		new_node->prev_node = temp;
		temp->next_node->prev_node = new_node;
		temp->next_node= new_node;
		tail = new_node;

	}
}

int linked_list::Nview_tail() {
	if (!is_it_empty()) {
		int num = tail->data;
		tail = tail->next_node;
		return num;
	}
	else {
		std::cout << "Linked List is empty";
		return -1;
	}
}

int linked_list::Pview_tail() {
	if (!is_it_empty()) {
		int num = tail->data;
		tail = tail->prev_node;
		return num;
	}
	else {
		std::cout << "Linked List is empty";
		return -1;
	}
}

int linked_list::search(int num) {
	if (!is_it_empty()) {
		temp = tail;
		do {
			if (temp->data == num) {
				std::cout << num << " is exist\n";
				return num;
			}
			temp = temp->next_node;
		} while (temp != tail);
		std::cout << num << " is not exist\n";
	}
	else {
		std::cout << "Linked List is empty";
	}
	return NULL;

}

void linked_list::remove() {
	if (is_it_empty()) { std::cout << "Linked List is empty\n"; return; }
	if (tail == tail->prev_node) { tail = NULL; return; }


	tail->next_node->prev_node = tail->prev_node;
	tail->prev_node->next_node = tail->next_node;
	
	tail = tail->prev_node;

}

void linked_list::Sremove(int num) {
	if (is_it_empty()) { std::cout << "Linked List is empty"; return; }
	temp = tail;
	if (tail->data == num) {
		std::cout << temp->data << " is exist\n";
		std::cout << temp->data << " is delete\n";
		remove();
		return;
	}
	if (search(num) !=NULL) {
		std::cout << temp->data << " is delete\n";
		temp->prev_node->next_node = temp->next_node;
		temp->next_node->prev_node = temp->prev_node;
		free(temp);
	}
	temp = tail;
}
