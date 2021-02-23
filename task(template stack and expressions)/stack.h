#ifndef STACK_H
#define STACK_H

const int MAX_SIZE = 1E6;

template<class T>
class Stack {
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	int size;

public:
	Stack();
	~Stack();
	void push(const T& x);				// добавление эл-та на верхушку стека
	T pop();						// извлечение верхнего эл-та со стека
	T* top();						// получения указателя на вершину стека

	bool stackEmpty();				// проверка пуст ли стек
	int stackSize();				// получение 
};

template<class T>
Stack<T>::Stack() :head(nullptr){}

template<class T>
Stack<T>::~Stack(){
	while(head){
		Node* pv = head;
		head = head->next;
		delete pv;
	}

}

template<class T>
void Stack<T>::push(const T& x)
{
	Node* pv = new Node;
	pv->data = x;
	pv->next = head;
	head = pv;
	size++;
}

template<class T>
T Stack<T>::pop()
{
	if (stackEmpty()) throw - 1;
	T temp = head->data;
	Node* pv = head;
	head = head->next;
	delete pv;
	size--;
	return temp;
}
template<class T>
bool Stack<T>::stackEmpty()
{
	return head ? false : true;
}

template<class T>
T* Stack<T>::top()
{
	if (stackEmpty()) throw - 1;
	T* temp = &head->data;
	return temp;
}

template<class T>
int Stack<T>::stackSize() {
	return size;
}

#endif // !STACK_H