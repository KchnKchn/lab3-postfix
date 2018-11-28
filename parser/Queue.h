#pragma once

template <class T>
class Queue
{
	T *pmem;
	size_t first;
	size_t last;
	size_t size;
	
	void init(const Queue<T> &rhs);
	void resize();
public:
	Queue();
	explicit Queue(size_t s);
	Queue(const Queue &rhs);
	~Queue();

	void* operator new[](size_t s) = delete;
	void operator delete[](void *p) = delete;

	Queue &operator=(const Queue<T> &rhs);

	void Push(const T &rhs);
	T Pop();

	bool IsEmpty() const;
	bool IsFull() const;
};

template <class T>
void Queue<T>::init(const Queue<T> &rhs)
{
	size = rhs.size;
	first = rhs.first;
	last = rhs.last;
	pmem = new T[size];
	for (size_t i = first; i != (last + 1) % size; i = (i + 1) % size)
		pmem[i] = rhs.pmem[i];
}

template <class T>
void Queue<T>::resize()
{
	size_t new_size = size * 2;
	T* tempMem = new T[new_size];
	int j = 0;
	for (size_t i = first; i != (last + 1) % size; i = (i + 1) % size)
	{
		tempMem[j] = pmem[i];
		j++;
	}
	std::swap(pmem, tempMem);
	size = new_size;
	last = j - 1;
	first = 0;
	delete[]tempMem;
}

template <class T>
Queue<T>::Queue()
{
	size = 10;
	first = 0;
	last = size - 1;
	pmem = new T[size];
}

template <class T>
Queue<T>::Queue(size_t s)
{
	if (s <= 0)throw "Bad arg";
	size = s;
	first = 0;
	last = size -1;
	pmem = new T[size];
}

template <class T>
Queue<T>::Queue(const Queue &rhs)
{
	init(rhs);
}

template <class T>
Queue<T>::~Queue()
{
	delete[]pmem;
	pmem = nullptr;
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rhs)
{
	if (this == &rhs) return *this;
	delete[]pmem;
	init(rhs);
	return *this;
}

template <class T>
void Queue<T>::Push(const T &rhs)
{
	if (IsFull()) resize();
	last = (last + 1) % size;
	pmem[last] = rhs;
}

template <class T>
T Queue<T>::Pop()
{
	if (IsEmpty())throw "Bag mem";
	first = (first + 1) % size;
	return pmem[(first - 1) % size];
}

template <class T>
bool Queue<T>::IsEmpty() const
{
	return first == ((last + 1) % size);
}

template <class T>
bool Queue<T>::IsFull() const
{
	return first == ((last + 2) % size);
}