#pragma once

template <class T>
class Stack
{
	T* mem;
	int top;
	int size;

	void init(const Stack<T> &rhs);
	void resize();
	void resize(int s);

public:
	Stack();
	explicit Stack(int s);
	Stack(const Stack &rhs);
	~Stack();

	void reserve(int s);

	Stack& operator=(const Stack<T> &rhs);

	void Push(const T &rhs);
	T Pop();

	void* operator new[](size_t s) = delete;
	void operator delete[](void *p) = delete;

	bool IsEmpty() const;
	bool IsFull() const;
};

template <class T>
void Stack<T>::init(const Stack<T> &rhs)
{
	size = rhs.size;
	top = rhs.top;
	mem = new T[size];
	for (int i = 0; i <= top; ++i) mem[i] = rhs.mem[i];
}

template <class T>
void Stack<T>::resize()
{
	size *= 2;
	T* tempMem = new T[size];
	for (int i = 0; i <= top; ++i) tempMem[i] = mem[i];
	std::swap(mem, tempMem);
	delete[]tempMem;
}

template <class T>
void Stack<T>::resize(int s)
{
	size = s;
	T* tempMem = new T[size];
	for (int i = 0; i <= top; ++i) tempMem[i] = mem[i];
	std::swap(mem, tempMem);
	delete[]tempMem;
}

template <class T> 
Stack<T>::Stack()
{
	size = 10;
	top = -1;
	mem = new T[size];
}

template <class T>
Stack<T>::Stack(int s)
{
	if (s <= 0)throw "Bad arg";
	size = s;
	top = -1;
	mem = new T[size];
}

template <class T> 
Stack<T>::Stack(const Stack<T> &rhs)
{
	init(rhs);
}

template <class T>
Stack<T>::~Stack()
{
	delete[]mem;
	mem = nullptr;
}

template <class T>
void Stack<T>::reserve(int s)
{
	if (s < 0) throw "Bad arg";
	if (s <= size) return;
	resize(s);
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs)
{
	if (this == &rhs) return *this;
	delete[]mem;
	init(rhs);
	return *this;
}

template <class T>
void Stack<T>::Push(const T &rhs)
{
	if (IsFull()) resize();
	++top;
	mem[top] = rhs;
}

template <class T>
T Stack<T>::Pop()
{
	if (IsEmpty()) throw "Bad mem";
	--top;
	return mem[top + 1];
}

template <class T>
bool Stack<T>::IsEmpty() const
{
	return top == -1;
}

template <class T>
bool Stack<T>::IsFull() const
{
	return top == size;
}