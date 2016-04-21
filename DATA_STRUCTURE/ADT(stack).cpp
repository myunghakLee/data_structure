#include<iostream>
#include "head(stack).h"


void stack::stack_init() {
	head_node = NULL;

}

void stack::push(int data) {
	node *new_node = new node(data);
	new_node->next_node = head_node;
	head_node = new_node;
}

int stack::pop() {
	if (head_node != NULL) {
		int num = head_node->data;
		//node *D_node = head_node;			//나중에 메모리 반환을 위해
		head_node = head_node->next_node;
		//free(D_node);
		return num;
	}
	else {
		std::cout << "stack is empty";
		return -100;
	}
}

int stack::peek() {

	if (!is_it_empty()) {
		return head_node->data;
	}
	else {
		return -100;
	}
}

void stack::search(int num) {
	node *search_node = head_node;
	while (search_node != NULL) {
		if (search_node->data == num) {
			std::cout << num << " is exist\n";
			return;
		}
		else {
			search_node = search_node->next_node;
		}
	}
	std::cout << num << " is not exist\n";

}

void calculator::get_formular() {
	char get[100];
	std::cin >> get;
	int j = 0;
	float decimal_part = 0;
	bool is_exist_decimal = false;
	for (int i = 0; i < 100; i++) {
		if (get[i] != '\0') {
			if (get[i] == '.') {
				decimal_part = 0;
				is_exist_decimal = true;
				j--;
			}
			else if (is_exist_decimal) {
				decimal_part += get[i] - '0';
				decimal_part /= 10;
				j--;
				if (get[i + 1] <= '0') {  formular[j] += decimal_part; is_exist_decimal = false; }
			}
			else if (get[i] != '0' || formular[j] != 0 || get[i+1] =='.') {		//식에 0이 있을경우 그것을 무시 그러나 10에서의 0은 무시하면 안됨
				formular[j] += get[i] - '0';
				if (get[i + 1] - '0' >= 0 && get[i] - '0' >= 0) { formular[j] *= 10; j--; }
			}
			else { continue; }
		}
		else {
			length = j;
			break;
		}
		j++;
		length = j;
	}
}

int calculator::get_op_prec(int num)
{
	switch (num) {
	case'+' - '0':
		return 2;
	case'-' - '0':
		return 2;
	case'*' - '0':
		return 3;
	case'/' - '0':
		return 3;
	case'(' - '0':
		return 1;
	case -100:
		return -100;
	}
}

void calculator::change_postfix() {
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (formular[j] > 0) {
			postfix[i] = formular[j];
			j++;
		}
		else if (formular[j] == '(' - '0') {
			dish.push(formular[j]);
			j++;
			i--;
		}
		else {
			if (formular[j] == ')' - '0') {
				j++;
				length -= 2;
				while (dish.peek() != '(' - '0') {
					postfix[i] = dish.pop();
					i++;
				}
				i--;
				dish.pop();
			}
			else if (get_op_prec(dish.peek()) >= get_op_prec(formular[j]) || formular[j] == 0) {	//날리는경우
				postfix[i] = dish.pop();
			}
			else {
				dish.push(formular[j]);
				j++;
				i--;
			}
		}
	}
	for (int i = 0; i < length; i++) {
		if (postfix[i] == '*' - '0' || postfix[i] == '/' - '0' || postfix[i] == '+' - '0' || postfix[i] == '-' - '0') {
			int a = postfix[i];
			printf("%c ", a + '0');
		}
		else {
			printf("%f ", postfix[i]);
		}
	}
}

void calculator::calc() {
	change_postfix();
	for (int i = 0; i < length; i++) {
		if (postfix[i] < 0) {		//수식인경우
			if (i >= 2) {
				int j = i - 1;
				int k = i - 2;
				while (postfix[j] == 0 && j >= 0) { j--; }
				while (postfix[k] == 0 && k >= 0) { k--; }
				postfix[i] = calc_sub(postfix[k], postfix[j], postfix[i]);
				postfix[k] = 0;
				postfix[j] = 0;
			}
			else {
				int j = i - 1;
				postfix[j];
				while (postfix[j] == 0 && j >= 0) { j--; }

				postfix[i] = calc_sub(0, postfix[j], postfix[i]);
				postfix[j] = 0;
			}
		}
	}
	std::cout << " = " << postfix[length - 1];

}

float calculator::calc_sub(float a, float b, char c) {
	switch (c) {
	case'+' - '0':
		return a + b;
	case'-' - '0':
		return a - b;
	case'*' - '0':
		return a * b;
	case'/' - '0':
		return a / b;
	}
}
