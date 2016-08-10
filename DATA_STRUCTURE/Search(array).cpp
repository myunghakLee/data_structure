#include<iostream>

int binary_search(int target, int first, int last, int arr[]) {
	int mid = (first + last) / 2;

	if (arr[mid] == target) {
		std::cout << arr[mid] << " is exist.\n";
		return mid;
	}
	else if (first > last) {
		std::cout << target << " is not exist.\n";
		return -1;
	}
	else if (arr[mid] < target) {
		binary_search(target, mid + 1, last, arr);
	}
	else {
		binary_search(target, first, mid - 1, arr);
	}

}

int interpolation_search(int target, int first, int last, int arr[]) {
	int mid = (target-arr[first])/(arr[last]-arr[first])*(last-first)+first;

	if (arr[mid] == target) {
		std::cout << arr[mid] << " is exist.\n";
		return mid;
	}
	else if (arr[first]>target || arr[last]<target) {
		std::cout << target << " is not exist.\n";
		return -1;
	}
	else if (arr[mid] < target) {
		binary_search(target, mid + 1, last, arr);
	}
	else {
		binary_search(target, first, mid - 1, arr);
	}

}


void main() {
	int arr[] = { 1,4,5,6,7,8,9,11,13,15,16,17,19,21,24,26,28,30 };
	int arr_size = sizeof(arr) / sizeof(int) - 1;
	binary_search(28, 0, arr_size, arr);
	binary_search(29, 0, arr_size, arr);
}
