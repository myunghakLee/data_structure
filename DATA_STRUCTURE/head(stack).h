#ifndef __HEAD_H__
#define __HEAD_H__

class node {
private:
	node * next_node;
	int data;
	node(int num) { data = num; next_node = 0; }
	friend class stack;
};

class stack{
private:
	node *head_node;
public:
	void stack_init();
	void push(int data);
	int peek();
	bool is_it_empty() {
		if (head_node == NULL) {
			return true; 
		} else {
			return false; 
		} 
	}
	int pop();
	void search(int num);
};

class calculator {
private:
	stack dish;
	float formular[100];
	float postfix[100];
	int length;				//식의 길이 123+1 은 길이 3으로 측정
public:
	calculator() {
		for (int i = 0; i < 100; i++) {
			formular[i] = 0;
			postfix[i] = 0;
			dish.stack_init();
		}
	}
	void get_formular();
	void change_postfix();
	int get_op_prec(int num);
	void calc();
	float calc_sub(float a, float b, char c);
};

#endif