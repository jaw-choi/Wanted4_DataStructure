#include "List.h"
#include <iostream>
#include <vector>

int main()
{
    List<int> list;

    for (int i = 0; i < 10; ++i)
    {
        list.Add(i * 10);
    }
    std::vector<int> a;
    a.push_back(10);
    return 0;
}