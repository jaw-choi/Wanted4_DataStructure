#include <iostream>
#include "Container/Deque.h"

int main()
{
    Deque<int, 10> deque;

    for (int ix = 1; ix < 10; ++ix)
    {
	if (ix % 2 != 0)
	{
	    deque.AddFront(ix);
	}
	else
	{
	    deque.AddRear(ix);
	}
    }

    deque.Display();
    deque.DeleteFront();
    deque.DeleteRear();
    deque.DeleteFront();
    deque.Display();

    std::cin.get();
}