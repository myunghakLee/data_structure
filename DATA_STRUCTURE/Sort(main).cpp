#include<iostream>
#include"Tree(head).h"

#define space <<" ";

void swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

void selection_sort(int arr[], int n){
	int max_idx;
	int temp;
	for (int i = 0; i < n-1; i++) {
		max_idx = i;						//가장큰 값의 배열의 idx값
		for (int j = i + 1; j < n; j++) {
			if (arr[max_idx] < arr[j]) {
				max_idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = temp;
	}

}

void insert_sort(int arr[], int n) {
	int temp;
	int j;
	for (int i = 0; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0; j--){		//이 경우 반복문 밖에서도 j값을 사용해야 하므로 int j라고 쓰지 않음
			if (temp > arr[j]) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = temp;

		
	}
}

void heap_sort(int arr[], int n) {
	tree T(arr[0]);
	for (int i = 1; i < n; i++) {
		T.insert_min_heap(arr[i]);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = T.delete_min_heap();
	}

}

void merge_to_area(int arr[], int left, int mid, int right) {

	int Lidx = left;
	int Ridx = mid + 1;

	int *arr2 = new int[right + 1];

	int Sidx = left;		//시작할 함수

	while (Lidx <= mid && Ridx <= right) {
		if (arr[Lidx] <= arr[Ridx]) {
			arr2[Sidx] = arr[Lidx];
			Lidx++;
		}
		else {
			arr2[Sidx] = arr[Ridx];
			Ridx++;
		}
		Sidx++;
	}

	if (Lidx <= mid) {
		for (int i = Lidx; i <= mid; i++) {
			arr2[Sidx] = arr[i];
			Sidx++;
		}
	}
	else {
		for (int i = Ridx; i <= right; i++) {
			arr2[Ridx] = arr[i];
			Ridx++;
		}
	}
	for (int i = left; i <= right; i++){
		arr[i] = arr2[i];
	}
	delete(arr2);
}

void merge_sort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);

		merge_to_area(arr, left, mid, right);
	
	}

}

int partition(int arr[], int left, int right) {
	int low = left + 1;
	int high = right;
	int pivot = arr[left];

	while (low <= high) {
		while (pivot >= arr[low] && low <= right) {
			low++;
		}
		while (pivot <= arr[high] && high >= left + 1) {
			high--;
		}
		if (low <= high) {
			swap(arr, low, high);
		}
	}
	swap(arr, left, high);
	return high;
}

void quick_sort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot+1, right);

	}
}
void main() {

	//int arr[] = { 10,5,4,8,7,9,0,-1,6,2,3,1 };
	int arr[] = { 5,9,6,7,3,2,8,1,4 };
	//int arr[] = { 3,3,3 };
	//bubble_sort(arr, sizeof(arr)/sizeof(int));
	//selection_sort(arr, sizeof(arr)/sizeof(int));
	//insert_sort(arr, sizeof(arr) / sizeof(int));
	// heap_sort(arr, sizeof(arr) / sizeof(int));
	
	//merge_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	quick_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		std::cout << arr[i]space;
	}
}