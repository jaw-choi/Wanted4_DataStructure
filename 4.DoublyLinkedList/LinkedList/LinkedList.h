#pragma once

#include "Node.h"
#include <iostream>

// 단일 연결 리스트 클래스.

template<typename T>
class LinkedList
{
    // 타입 알리아싱 지정.
    using NodeType = Node<T>*;
public:
    LinkedList() : first(new Node<T>()), last(new Node<T>()), count(0)
    {
        first->next = last;
        last->prev = first;
    }
    ~LinkedList()
    {
        if (_heapchk() != _HEAPOK)
        {
            __debugbreak();
        }
        // 메모리 정리.
        //Clear();

        //delete first;
        //first = nullptr;

        //delete last;
        //last = nullptr;
    }
    // 출력 함수.
    void Print()
    {
        NodeType current = first->next;

        std::cout << "List Item Count: " << count << '\n';

        while (current != last)
        {
            std::cout << "Item: " << current->data << '\n';

            current = current->next;
        }
    }

    // 검색 함수.
    Node<T>* Find(const T& data)
    {
        Node<T>* current = first->next;
        while (current && current != last)
        {
            if (current->data == data)
            {
                return current;
            }
            current = current->next;
        }

        std::cout << "Can't find the data.\n";
        return nullptr;
    }

    // 역방향 검색 함수.
    Node<T>* FindReverse(const T& data)
    {
        Node<T>* current = last->prev;
        while (current && current != first)
        {
            if (current->data == data)
            {
                return current;
            }
            current = current->prev;
        }

        std::cout << "Can't find the data.\n";
        return nullptr;
    }



    void Clear()
    {
        // 데이터를 갖는 첫 항목부터 삭제.
        NodeType current = first->next;

        // 마지막 노드 도달 전 까지 반복.
        while (current && current != last)
        {
            // 다음 노드 임시 저장.
            NodeType next = current->next;

            // 현재 노드 삭제.
            delete current;
            // 다음 노드로 이동.
            current = next;
        }

        // 값 정리
        count = 0;
        // 초기 상태로 리셋.
        first->next = last;
        last->prev = first;
    }

    // 첫 위치에 노드 추가 함수.
    void InsertFirst(const T& data)
    {
        // 새 노드 생성.
        NodeType newNode = new Node<T>();
        newNode->data = data;

        // 포인터 정리.
        // 새 노드의 다음 노드를 first->next(기존의 첫 노드)로 지정.
        // 이전 first->next를 새 노드로 설정.
        NodeType next = first->next;
        newNode->next = first->next;
        next->prev = newNode;

        first->next = newNode;
        newNode->prev = first;

        // 노드 증가 처리.
        ++count;
    }

    // 첫 위치에 노드 추가 함수.
    void InsertLast(const T& data)
    {
        // 새 노드 생성.
        NodeType newNode = new Node<T>();
        newNode->data = data;

        // 포인터 정리.
        // 새 노드의 이전 노드를 last->prev(기존의 마지막 노드)로 지정.
        // 이전 last -> prev를 새 노드로 설정.
        NodeType prev = last->prev;
        newNode->prev = last->prev;
        prev->next = newNode;

        newNode->next = last;
        last->prev = newNode;

        // 노드 증가 처리.
        ++count;
    }

    void Delete(const T& data)
    {
        // 리스트가 비어 있는지 확인
        if(count ==0)
        {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }

        NodeType deleteNode = Find(data);

        // 삭제할 노드가 없는 경우.
        if (!deleteNode)
        {
            std::cout << "Data not found. Cannot delete.\n";
            return;
        }

        // 포인터 정리.
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;

        // 노드 삭제.
        delete deleteNode;
        deleteNode = nullptr;

        //항목 감소
        --count;
    }

private:
    NodeType first = nullptr;
    NodeType last = nullptr;

    // 연결 리스트에 저장된 항목의 수.
    int count = 0;
};