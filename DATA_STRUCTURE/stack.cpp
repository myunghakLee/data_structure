#include<iostream>
#include "Stack(head).h"
void main()
{
	
	calculator C;
	std::cout << "수식을 입력하시오\n";
	C.get_formular();

	C.calc();

}