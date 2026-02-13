#include <iostream>
#include "LinkedList/LinkedList.h"
int main()
{
    LinkedList<int> list;
    list.Insert(20);
    list.Insert(30);
    list.Insert(10);

    std::cout << "노드 추가 후 출력\n";
    list.Print();
    
    list.Delete(30);
    list.Delete(10);

    std::cout << "노드 삭제 후 출력\n";
    list.Print();

    return 0;
}