#include "LinkedList/LinkedList.h"
#include <iostream>

int main()
{
    LinkedList<int> list;
    for (int i = 0; i < 10; i++)
    {
        list.InsertLast(i * 10);
    }
    std::cout << "노드 추가 후 출력\n";
    list.Print();
    
    list.Delete(30);
    list.Delete(50);
    list.Delete(80);

    list.Delete(95);

    std::cout << "노드 삭제 후 출력\n";
    list.Print();

    return 0;
}