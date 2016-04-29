#include "LinkedList(head).h"

using namespace std;

void main() {
	linked_list L;

	L.Sinsert(1);
	L.Sinsert(3);
	L.Sinsert(5);
	L.Sinsert(4);
	L.Sinsert(2);
	L.Sinsert(6);
	
	L.Sremove(1);
	L.Sremove(2);
	L.Sremove(3);
	L.Sremove(4);
	L.Sremove(6);

	L.Sremove(5);


	cout << L.Nview_tail() << endl;
	cout << L.Nview_tail() << endl;
	cout << L.Nview_tail() << endl;
	cout << L.Nview_tail() << endl;
	cout << L.Nview_tail() << endl;
	cout << L.Nview_tail() << endl;
	cout << L.Nview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Pview_tail() << endl;
	cout << L.Nview_tail() << endl;

}