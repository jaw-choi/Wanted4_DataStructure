#pragma once
#include "Node.h"
#include <vector>
#include <iostream>

// 트리 자료구조 클래스.
template<typename T>
class Tree
{
public:
    Tree(const T& data)
    {
        // 루트 노드 생성.
        root = new Node<T>(data);
    }

    ~Tree()
    {
        // Todo: 자손 노드 모두 제거하는 함수 구현 후 호출.
        SafeDelete(root);
    }
public:

    // 부모 노드의 값을 사용해 해당 부모에 자식 노드 추가.
    bool AddChild(const T& parentData, const T& childData)
    {
        // 부모 노드 검색.
        // 검색 함수 구현 후 호출.
        Node<T>* outParent = nullptr;
        bool result = Find(parentData, outParent);

        if (result)
        {
            // 부모 노드에 자식 노드 추가.
            outParent->AddChild(childData);
            return true;
        }
        return false;
    }

    bool Find(const T& data, Node<T>*& outNode)
    {
        return FindRecursive(data, root, outNode);
    }
private:
    // data : 검색할 데이터.
    // node : 검색할 노드.
    // outNode : 검색 결과를 반환할 노드 참조 변수.
    // 함수의 반환 값: 검색 성공 여부.
    bool FindRecursive(const T& data, Node<T>* node, Node<T>*& outNode)
    {
        // 검색 실패(탈출 조건): 검색할 노드가 없는 경우.
        if (!node)
        {
            outNode = nullptr;
            return false;
        }

        // 노드가 가진 값이 검색할 값과 일치하는지 확인.
        if (node->GetData() == data)
        {
            outNode = node;
            return true;
        }

        // 자손 노드로 내려가면서 재귀적으로 추가 검색 진행.
        std::vector<Node<T>*>& children = node->GetChildren();
        const int length = static_cast<int>(children.size());
        for (int i = 0; i < length; ++i)
        {
            if (FindRecursive(data, children[i], outNode))
            {
                return true;
            }
        }

        // 검색 실패: 검색할 값을 가진 노드를 찾지 못함.
        outNode = nullptr;
        return false;
    }

private:
        // 트리의 루트 노드.
    Node<T>* root = nullptr;
};