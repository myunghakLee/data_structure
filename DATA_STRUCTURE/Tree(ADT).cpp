#include"Tree(head).h"


void tree::make_node(node* N, int data) {
	N->data = data;
	N->Rnode = NULL;
	N->Lnode = NULL;
}

void tree::make_left_sub_tree(node * Pt, int data) {
	if (Pt == NULL) {
		std::cout << "Parent node is empty";
		return;
	}
	volume++;
	Pt->Lnode = new node;
	make_node(Pt->Lnode, data);
}

void tree::make_right_sub_tree(node * Pt, int data) {
	if (Pt == NULL) {
		std::cout << "Parent node is empty";
		return;
	}
	volume++;
	Pt->Rnode = new node;
	make_node(Pt->Rnode, data);
}

void tree::post_order_traverse(node * bt) {
	if (bt == NULL) { return; }
	post_order_traverse(bt->Lnode);
	post_order_traverse(bt->Rnode);
	std::cout << bt->data << " ";
}

void tree::in_order_traverse(node * bt) {
	if (bt == NULL) { return; }
	in_order_traverse(bt->Lnode);
	std::cout << bt->data << " ";
	in_order_traverse(bt->Rnode);
}

void tree::pre_order_traverse(node * bt) {
	if (bt == NULL) { return; }
	std::cout << bt->data << " ";
	pre_order_traverse(bt->Lnode);
	pre_order_traverse(bt->Rnode);
}

void tree::insert_tree_sort(int data) {
	volume++;
	node * temp = root;
	while (temp != NULL) {
		if (temp->data < data) {
			if (temp->Rnode == NULL) { make_right_sub_tree(temp, data); break; }
			temp = temp->Rnode;
		}
		else {
			if (temp->Lnode == NULL) { make_left_sub_tree(temp, data); break; }
			temp = temp->Lnode;
		}
	}
}

int tree::insert_complete_binary_tree(int data) {
	//volume++;
	int v = volume + 1;					//complte binary tree의 저장 순서(왼쪽 오른쪽의 배열)가 이진수와 비슷하다는 것을 이용하기 위해 tree의 크기를 가져옴
	N = root;

	for (int i = 0; i < 20; i++) { bin[i] = NULL; }
	int num = 0;
	while (v > 0) {
		if (v % 2 == 0) {
			bin[num] = 0;
		}
		else {
			bin[num] = 1;
		}
		v /= 2;
		num++;
	}
	num -= 2;
	int return_num = num;
	while (num > 0) {
		if (bin[num] == 0) {
			N = N->Lnode;
		}
		else {
			N = N->Rnode;
		}
		num--;
	}
	if (bin[0] == 0) {
		make_left_sub_tree(N, data);
	}
	else if (bin[0] == 1) {
		make_right_sub_tree(N, data);
	}

	return return_num;
}

void tree::insert_max_heap(int data) {
	int num = insert_complete_binary_tree(data);

	int num2 = 0;
	int num3 = num;
	while (num2 != num3) {
		N = root;
		num = num3;
		while (num > num2) {
			if (bin[num] == 0) {
				N = N->Lnode;
			}
			else {
				N = N->Rnode;
			}
			num--;
		}
		num2++;
		if (bin[num] == 0) {
			if (N->data <= N->Lnode->data) {
				int a = N->data;
				N->data = N->Lnode->data;
				N->Lnode->data = a;
			}
			else { return; }
		}
		else if (bin[num] == 1) {
			if (N->data <= N->Rnode->data) {
				int a = N->data;
				N->data = N->Rnode->data;
				N->Rnode->data = a;
			}
			else { return; }

		}
	}

	//root node와 그 자식node들은 따로처리
	if (root->Rnode != NULL) {
		if (root->data <= root->Rnode->data) {
			change_node(root, root->Rnode);
		}
		else if (root->data <= root->Lnode->data) {
			change_node(root, root->Lnode);
		}
	}
	else if (root->Lnode != NULL) {
		if (root->data <= root->Lnode->data) {
			change_node(root, root->Lnode);
		}
	}


}

void tree::insert_min_heap(int data) {
	int num = insert_complete_binary_tree(data);

	int num2 = 0;
	int num3 = num;
	while (num2 != num3) {
		N = root;
		num = num3;
		while (num > num2) {
			if (bin[num] == 0) {
				N = N->Lnode;
			}
			else {
				N = N->Rnode;
			}
			num--;
		}
		num2++;
		if (bin[num] == 0) {
			if (N->data >= N->Lnode->data) {
				int a = N->data;
				N->data = N->Lnode->data;
				N->Lnode->data = a;
			}
			else { return; }
		}
		else if (bin[num] == 1) {
			if (N->data >= N->Rnode->data) {
				int a = N->data;
				N->data = N->Rnode->data;
				N->Rnode->data = a;
			}
			else { return; }

		}
	}

	//root node와 그 자식node들은 따로처리
	if (root->Rnode != NULL) {
		if (root->data >= root->Rnode->data) {
			change_node(root, root->Rnode);
		}
		else if (root->data >= root->Lnode->data) {
			change_node(root, root->Lnode);
		}
	}
	else if (root->Lnode != NULL) {
		if (root->data >= root->Lnode->data) {
			change_node(root, root->Rnode);
		}
	}


}

int tree::delete_max_heap() {
	if (root->Lnode == NULL && root->Rnode == NULL) {
		if (root == NULL) {
			std::cout << "heap is empty\n";
			return -1;
		}

		return root->data;
	}


	int return_num = root->data;

	if (root->Lnode == NULL && root->Rnode == NULL) {
		if (root == NULL) {
			std::cout << "heap is empty\n";
			return -1;
		}

		return root->data;
	}



	int v = volume;					//complte binary tree의 저장 순서(왼쪽 오른쪽의 배열)가 이진수와 비슷하다는 것을 이용하기 위해 tree의 크기를 가져옴
	N = root;

	for (int i = 0; i < 20; i++) { bin[i] = NULL; }
	int num = 0;
	/////////////////////////////////////// volume을 2진법으로 변환/////////////////////////////////////////////
	while (v > 0) {
		if (v % 2 == 0) {
			bin[num] = 0;
		}
		else {
			bin[num] = 1;
		}
		v /= 2;
		num++;
	}
	///////////////////////////////////////////////////////////2진법을 이용해 N을 옮김///////////////////////////////////////
	num -= 2;
	while (num > 0) {
		if (bin[num] == 0) {
			N = N->Lnode;
		}
		else {
			N = N->Rnode;
		}
		num--;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	if (bin[0] == 0 && N->Lnode !=NULL) {
		root->data = N->Lnode->data;
		N->Lnode = NULL;
	}
	else if (bin[0] == 1 && N->Rnode!=NULL) {
		root->data = N->Rnode->data;
		N->Rnode = NULL;
	}

	volume--;

	N = root;

	while (N->Lnode != NULL || N->Rnode != NULL) {
		if (N->Rnode != NULL) {
			if (N->Lnode->data < N->Rnode->data) {
				if (N->data > N->Rnode->data) { break; }
				change_node(N, N->Rnode);
				N = N->Rnode;
			}
			else {
				if (N->data > N->Lnode->data) { break; }
				change_node(N, N->Lnode);
				N = N->Lnode;
			}
		}
		else {
			if (N->data > N->Lnode->data) { break; }
			change_node(N, N->Lnode);
			N = N->Lnode;
		}

	}
	return return_num;
}

int tree::delete_min_heap() {
	if (root->Lnode == NULL && root->Rnode == NULL) {
		if (root == NULL) {
			std::cout << "heap is empty\n";
			return -1;
		}

		return root->data;
	}

	int return_num = root->data;


	int v = volume;					//complte binary tree의 저장 순서(왼쪽 오른쪽의 배열)가 이진수와 비슷하다는 것을 이용하기 위해 tree의 크기를 가져옴
	N = root;

	for (int i = 0; i < 20; i++) { bin[i] = NULL; }
	int num = 0;
	/////////////////////////////////////// volume을 2진법으로 변환/////////////////////////////////////////////
	while (v > 0) {
		if (v % 2 == 0) {
			bin[num] = 0;
		}
		else {
			bin[num] = 1;
		}
		v /= 2;
		num++;
	}
	///////////////////////////////////////////////////////////2진법을 이용해 N을 옮김///////////////////////////////////////
	num -= 2;
	while (num > 0) {
		if (bin[num] == 0) {
			N = N->Lnode;
		}
		else {
			N = N->Rnode;
		}
		num--;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	if (bin[0] == 0 && N->Lnode != NULL) {								//맨 끝에있는 노드를 root노드에 덮어 씌우는 과정
		root->data = N->Lnode->data;
		N->Lnode = NULL;
	}
	else if (bin[0] == 1 && N->Rnode != NULL) {
		root->data = N->Rnode->data;
		N->Rnode = NULL;
	}
	volume--;

	N = root;
	while (N->Lnode != NULL || N->Rnode != NULL) {
		if (N->Rnode != NULL && N->Lnode != NULL) {
			if (N->Lnode->data > N->Rnode->data) {
				if (N->data < N->Rnode->data) { break; }
				change_node(N, N->Rnode);
				N = N->Rnode;
			}
			else {
				if (N->data < N->Lnode->data) { break; }
				change_node(N, N->Lnode);
				N = N->Lnode;
			}
		}
		else if (N->Rnode != NULL) {
			if (N->data < N->Rnode->data) { break; }
			change_node(N, N->Rnode);
			N = N->Rnode;
		}
		else {
			if (N->data < N->Lnode->data) { break; }
			change_node(N, N->Lnode);
			N = N->Lnode;
		}

	}


	return return_num;
}

void tree::change_node(node*a, node*b) {
	int num = a->data;
	a->data = b->data;
	b->data = num;
}