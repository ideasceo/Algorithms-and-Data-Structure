/*

Implement two stacks sharing the same array. Stacks must include the following fuctions:
adding, and removing elements, listing elements, checking is stack full or empty. Find the
maximum and minimum elements of the stack and swap them (do not brake LIFO principle).

*/

#include<iostream> 
using namespace std;

//implementation of Class stack
class Stack
{
	//declaring class variables
	const int STACK_SIZE = 100;
	int top;
	int a[100];    //Maximum size of Stack 
public:
	//declaring class functions
	Stack();
	bool adding(int x);
	int removing();
	bool isEmpty();
	bool isFull();
	void listing_element();
	void minMaxElements();
};
//implementation of default constructor of class 'Stack'
Stack::Stack()
{
	top = -1;
}
//implementation of 'adding method' of class 'Stack'
bool Stack::adding(int x)
{
	if (isFull())
	{
		cout << "OH dear!!!! No element can be inserted because the stack is full now." << endl;
		return false;
	}
	else
	{
		top = top + 1;
		a[top] = x;
		return true;
	}
}
//implementation of 'removing method' of class 'Stack'
int Stack::removing()
{
	if (isEmpty())
	{
		cout << "Oh dear!!! No element is present in stack." << endl;
		return 0;
	}
	else
	{
		int value = a[top];
		top = top - 1;
		return value;
	}
}
//implementation of 'isEmpty' method of class 'Stack'
bool Stack::isEmpty()
{
	if (top < 0)
	{
		return true;
	}
	else
		return false;
}
//implementation of 'isFull' method of class 'Stack'
bool Stack::isFull()
{
	if (top >= STACK_SIZE - 1)
	{
		return true;
	}
	else
		return false;
}
//implementation of 'listingElement' method of class 'Stack'
void Stack::listing_element()
{
	for (int i = 0; i <= top; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

//implementation of 'minMaxElements' method of class 'Stack'
void Stack::minMaxElements()
{
	int maxValue = a[0];
	int minValue = a[0];
	int minIndex = 0;
	int maxIndex = 0;
	for (int i = 0; i <= top; i++)
	{
		if (a[i]<minValue)
		{
			minValue = a[i];
			minIndex = i;
		}
		if (a[i]>maxValue)
		{
			maxValue = a[i];
			maxIndex = i;
		}
	}
	int temp;
	a[minIndex] = maxValue; //min value has max value swaped
	a[maxIndex] = minValue; //max has min value
}

// Driver program to test above functions 
int main()
{
	const int ELEMENTS = 10;
	class Stack s, s1;

	//initializing two arrays
	int first[ELEMENTS] = { 44, 65, 22, 24, 22, 56, 78, 99, 32, 48 };
	int second[ELEMENTS] = { 144, 45, 12, 84, 62, 61, 78, 39, 33, 46 };
	for (int i = 0; i<ELEMENTS; i++)
	{
		s.adding(first[i]);
		s1.adding(second[i]);
	}
	//calling functions of stack

	cout << "**************************************\n";
	cout << "Stack 1:" << endl;
	s.listing_element();
	cout << "\nStack 2:" << endl;
	s1.listing_element();
	s1.minMaxElements();
	cout << "Stack 1 after swapping min and max value:" << endl;
	s.listing_element();
	cout << "Stack 2 after swapping min and max value:" << endl;
	s1.listing_element();
	cout << s.removing() << " Popped from stack 1\n";
	cout << "Stack 1 new elements:" << endl;
	s.listing_element();
	cout << s1.removing() << " Popped from stack 1\n";
	cout << "Stack 2 new elements:" << endl;
	s1.listing_element();
	cout << "**************************************\n";

	cout << endl << endl;
	system("pause");
	return 0;
}
