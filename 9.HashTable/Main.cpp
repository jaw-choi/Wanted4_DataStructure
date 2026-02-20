#include "Container/HashTable.h"
#include <iostream>		// std::cout.



int main()
{
    HashTable table;

    table.Add("name", "Jae");
    table.Add("age", "29");
    table.Add("age", "27");
    table.Add("job", "programmer");
    table.Add("hobby", "game");
    table.Add("hobby", "movie");
    table.Print();

    Pair<std::string, std::string> outEntry;
    if (table.Find("name", outEntry))
    {
        std::cout << "검색 성공. Key: " << outEntry.key << " | Value: " << outEntry.value << "\n";
    }
    else
    {
        std::cout << "검색 실패. 해당 키를 찾을 수 없음.\n";
    }


    //if (table.Delete("age"))
    //{
    //    std::cout << "삭제 성공. Key: age\n";
    //}
    //else
    //{
    //    std::cout << "삭제 실패. 해당 키를 찾을 수 없음.\n";
    //}


    table.Print();
    return 0;
}