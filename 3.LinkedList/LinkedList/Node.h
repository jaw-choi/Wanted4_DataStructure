#pragma once

// 데이터 필드/링크 필드를 갖는 노드 클래스.
// 연결 리스트에 저장되는 항목.
template<typename T>
class Node
{
    // 연결 리스트 friend 선언.
    template<typename T>
    friend class LinkedList;

    // 노드의 생성은 LinkedList 클래스에서만 가능하도록 private 으로 설정.
private:

    Node();
    Node(T data);
    //    : data(data), next(nullptr)
    //{
    //}


private:
    // 데이터 필드.
    T data;
    // 다음 노드를 가리키는 링크 필드.
    Node* next = nullptr;
};

#include "Node.inl"