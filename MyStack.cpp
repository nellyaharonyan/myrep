#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Stack
{
	T* p;
	int capacity;
	int size;
public:
	Stack() : capacity(0), size(0), p(NULL) {};
	bool Empty();
	T& Top();
	void Pop();
	int Size();
	void Push(T);

};

int main()
{
	Stack<int> s;
	try
	{
		s.Top() = 8;
	}
	catch (exception&ex)
	{
		cout << ex.what() << endl;
	}
	s.Push(5);
	s.Push(6);
	s.Push(0);
	s.Push(10);
	cout << "TOP: " << s.Top() << endl;
	cout << "SIZE: " << s.Size() << endl;
	s.Pop();
	cout << "TOP: " << s.Top() << endl;
	cout << "SIZE: " << s.Size() << endl;
	return 0;
}

/*****************************
Adds new element to the stack.
*****************************/
template <typename T>
void Stack<T>::Push(T a)
{
	if (size == capacity)
	{
		if (capacity == 0)
		{
			p = new T[1];
			size++;
			capacity++;
		}
		else
		{
			capacity = 2 * capacity;
			T* tmp = new T[capacity];
			
			for (int i = 0; i<size; i++)
			{
				tmp[i] = p[i];
			}
			delete []p;
			p = tmp;
			size++;
		}
	}
	else
		size++;
	p[size - 1] = a;

}


/*****************************
Pop out the top element 
of the stack.
*****************************/
template <typename T>
void Stack<T>::Pop()
{
	if (size != 0)
	{
		size--;
	}
}

/*****************************
Returns the top element 
of the stack.
*****************************/
template <typename T>
T& Stack<T>::Top()
{
	if (size != 0)
		return p[size - 1];
	throw exception("stack is empty");
}

/*****************************
Returns the size of the stack.
*****************************/
template <typename T>
int Stack<T>::Size()
{
	return size;
}


/*****************************
Returns true if stack is empty.
*****************************/
template <typename T>
bool Stack<T>::Empty()
{
	if (size == 0)
		return true;
	return false;
}
