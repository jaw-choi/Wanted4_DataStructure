#pragma once

#include <iostream>

template<typename T, int Size = 10>
class Deque
{
public:
    Deque()
	: front(0), rear(0)
    {
	size = Size + 1;
    }

    bool IsEmpty() const
    {
	return front == rear;
    }

    bool IsFull() const
    {
	return (front % size) == ((rear + 1) % size);
    }

    void AddRear(T value)
    {
	if (IsFull() == true)
	{
	    std::cout << "큐가 가득찼습니다.\n";
	    __debugbreak();
	    return;
	}

	rear = (rear + 1) % size;
	data[rear] = value;
    }

    T DeleteFront()
    {
	if (IsEmpty() == true)
	{
	    std::cout << "큐가 비었습니다.\n";
	    __debugbreak();
	    return 0;
	}

	front = (front + 1) % size;
	return data[front];
    }

    T Front()
    {
	if (IsEmpty() == true)
	{
	    std::cout << "큐가 비었습니다.\n";
	    __debugbreak();
	    return 0;
	}
	else
	{
	    return data[(front + 1) % size];
	}
    }

    void AddFront(const T& value)
    {
	if (IsFull() == true)
	{
	    std::cout << "Error, 덱이 포화 상태입니다." << "\n";
	}
	else
	{
	    data[front] = value;
	    front = (front - 1 + size) % size;
	}
    }

    T DeleteRear()
    {
	if (IsEmpty() == true)
	{
	    std::cout << "Error, 덱이 공백 상태입니다." << "\n";
	    __debugbreak();
	    return 0;
	}
	else
	{
	    T value = data[rear];
	    rear = (rear - 1 + size) % size;
	    return value;
	}
    }

    T GetRear()
    {
	if (IsEmpty() == true)
	{
	    std::cout << "Error, 덱이 공백 상태입니다." << "\n";
	    __debugbreak();
	    return 0;
	}
	else
	{
	    return data[rear];
	}
    }

    void Display()
    {
	std::cout << "덱의 내용 : ";
	int max = (front < rear) ? rear : rear + size;
	for (int ix = front + 1; ix <= max; ++ix)
	{
	    std::cout << " " << data[ix % size];
	}

	std::cout << "\n";
    }

private:
    int front = 0;
    int rear = 0;
    int size = 0;
    T data[Size + 1] = {};
};