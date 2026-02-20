#include "HashTable.h"
#include <string>
#include <iostream>

// 해시 함수(Hash Function). hash는 숫자임.
// 키를 어떠한 과정을 통해서 숫자로 변환 해주는 함수.
// 여기 붙이는 static은 전역이 아니라 이 파일에서만 사용할 수 있는 함수라는 의미.(private)
static int GenerateHash(const std::string& keyString)
{
    // 출력할 해시 변수 선언.
    int hash = 0;

    // 문자열을 문자 배열로 활용해 해시 생성.
    const int length = static_cast<int>(keyString.length());

    for (int i = 0; i < length; ++i)
    {
        // 해시 생성 로직
        // hash += keyString[i] * (i + 1);

        // Java방식, Hornor's Method: hash = hash * 31 + keyString[i];
        hash = hash * 31 + keyString[i];    //
    }

    // 배열의 인덱스로 사용할것임.
    // 오버플로우 방지 위해 절댓값으로 반환
    return std::abs(hash);
}


HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
    // 해시 값을 생성한 후에 배열의 인덱스로 활용.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 저장할 동적 배열(2차 자료구조) 선택.
    std::vector<Entry>& position = table[bucketIndex];

    // 중복된 키가 있는지 확인 후 없으면 추가.
    const int length = static_cast<int>(position.size());

    // 순차 탐색(처음부터 일일이 하나씩 검색하는 방법).
    for (int i = 0; i < length; ++i)
    {
        // 중복된 키값 확인.
        if (position[i].key == key)
        {
            // 중복된 키 허용 안 함.
            return false;
        }
    }

    // 중복된 키가 없다면 자료 추가.
    position.push_back(Entry(key, value));
    return true;

}

bool HashTable::Delete(const std::string& key)
{
    // 해시 값을 생성한 후에 배열의 인덱스로 활용.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 저장할 동적 배열(2차 자료구조) 선택.
    std::vector<Entry>& position = table[bucketIndex];

    // 중복된 키가 있는지 확인 후 있으면 삭제.
    const int length = static_cast<int>(position.size());

    // 순차 탐색(처음부터 일일이 하나씩 검색하는 방법).
    for (int i = 0; i < length; ++i)
    {
        // 중복된 키값 확인.
        if (position[i].key == key)
        {
            // 중복된 키 값 확인.
            position.erase(position.begin() + i);

            // swap pop 방식.
                // position[i] = position.back();
                // position.pop_back();

            return true;
        }
    }
    // 원하는 키를 갖는 데이터를 찾지 못함 - 삭제 실패.
    return false;
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{
    // 해시 값을 생성한 후에 배열의 인덱스로 활용.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 저장할 동적 배열(2차 자료구조) 선택.
    std::vector<Entry>& position = table[bucketIndex];

    // 예외 처리 - 2차 자료구조에 저장된 데이터가 없는 경우.
    if (position.empty())
    {
        return false;
    }

    // 중복된 키가 있는지 확인.
    const int length = static_cast<int>(position.size());

    // 순차 탐색(처음부터 일일이 하나씩 검색하는 방법).
    for (int i = 0; i < length; ++i)
    {
        // 중복된 키값 확인.
        if (position[i].key == key)
        {
            // 출력용 변수에 값 할당.
            outEntry = position[i];
            return true;
        }
    }

    return false;
}

void HashTable::Print()
{
    // 모든 자료를 출력.
    for (auto& container : table)
    {
        if (container.empty())
        {
            continue;
        }

        for (auto& item : container)
        {
            std::cout << "Key: " << item.key << " | Value: " << item.value << "\n";
        }
    }
}

bool HashTable::IsEmpty() const
{
    // 배열 - 2차 자료구조 전체를 순회하면서 하나라도 데이터가 있으면 false 반환.
    int sum = 0;
    for (const auto& container : table)
    {
        // 2차 자료구조의 저장된 데이터 개수 합산.
        sum += static_cast<int>(container.size());
    }
    return sum == 0;
}
