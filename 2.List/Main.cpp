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
    
    // Range-based for loop.
    for (const int item : list)
    {
        std::cout << item << std::endl;
    }

    // 초기식 , 조건식, 증감식
    // Iterator 사용한 반복문.
    //for (List<int>::ListIterator it = list.begin(); it != list.end(); ++it)
    //{
    //    std::cout << (*it) << std::endl;
    //}
    return 0;
}