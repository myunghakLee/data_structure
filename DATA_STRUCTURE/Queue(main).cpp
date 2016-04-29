#include"Queue(head).h"

void main() {
	queue Q;

	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);


	std::cout << Q.qpeek() << "\n";
	std::cout << Q.dequeue() << "\n";
	std::cout << Q.qpeek() << "\n";
	std::cout << Q.dequeue() << "\n";
	std::cout << Q.qpeek() << "\n";
	std::cout << Q.dequeue() << "\n";
	std::cout << Q.qpeek() << "\n";
	std::cout << Q.dequeue() << "\n";
	std::cout << Q.qpeek() << "\n";
	std::cout << Q.dequeue() << "\n";

}