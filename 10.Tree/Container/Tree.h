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
        // 자손 노드 모두 제거하는 함수 구현 후 호출.
        DestroyRecursive(root);

    }
public:
    // 여기에 작성되는 함수를 객체지향 이론에서 "메시지"라고 지칭.
    // 메시지 = 공개(public) 메소드. - 인터페이스.
    // 객체 지향 -> 객체가 메시지를 주고 받는 형태로 동작하는 프로그래밍 패러다임.
    // 손님과 은행직원 사이 의 관계로 비유할 수 있음. - 손님은 은행직원에게 메시지를 보냄(예: 돈을 인출하고 싶어요).
    // 
    // 굳이 은행직원이 손님에게 구체적인 처리 과정을 설명할 필요는 없음. - 캡슐화(Encapsulation) 개념과도 관련이 있음.
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

    bool Remove(const T& data)
    {
        //  재귀 함수 구현 후 호출.
        return RemoveRecursive(data, root);
    }

    // 전위 순회(Pre-order Traversal) 함수.
    void PreorderTraversal(int depth = 0)
    {
        // 
        PreorderTraversalRecursive(root, depth);
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

    // 삭제 재귀 함수.
    // data: 삭제할 노드의 값.
    // node: 현재 검색할 노드. RemoveImpl.
    bool RemoveRecursive(const T& data, Node<T>* node)
    {
        // 삭제 실패(탈출 조건): 검색할 노드가 없는 경우.
        if (!node)
        {
            return false;
        }
        // 삭제할 노드 검색.
        Node<T>* outNode = nullptr;
        bool result = FindRecursive(data, node, outNode);

        //검색에 성공했으면 삭제 처리.
        if (result)
        {
            // 부모 노드의 자손 목록에서 현재 노드 제거.
            Node<T>* parent = outNode->GetParent();
            if (parent)
            {
                auto it = std::find(parent->GetChildren().begin(), parent->GetChildren().end(), outNode);
                // 목록에서 노드 제거.
                parent->GetChildren().erase(it);
            }

            // 노드가 자손이 있다면 자손 노드 제거.
            std::vector<Node<T>*>& children = outNode->GetChildren();
            while (children.size() > 0)
            {
                outNode->RemoveChild(children[0]);
            }

            // 노드 제거 및 정리.
            SafeDelete(outNode);
            return true;
        }
        return false;
    }

    // 전위 순회 재귀 함수.
    void PreorderTraversalRecursive(Node<T>* node, int depth = 0)
    {
        // 탈출 조건: 노드가 없는 경우.
        if (!node)
        {
            return;
        }

        // 계층을 보여주기 위한 깊이 출력.
        for (int i = 0; i < depth; ++i)
        {
            std::cout << "  ";
        }
        // 전위 순회는 부모 노드를 먼저 처리(방문).
        std::cout << node->GetData() << "\n";
        
        // 자손 노드로 내려가면서 재귀적으로 추가 처리 진행.
        std::vector<Node<T>*>& children = node->GetChildren();
        const int length = static_cast<int>(children.size());

        if (length == 0)
        {
            return;
        }

        for (int i = 0; i < length; ++i)
        {
            PreorderTraversalRecursive(children[i], depth + 1);
        }
    }

    void DestroyRecursive(Node<T>*& node)
    {
        // 탈출 조건: 노드가 없는 경우.
        if (!node)
        {
            return;
        }
        // 자손 노드로 내려가면서 재귀적으로 추가 처리 진행.
        

        // 부모 목록 정리
        Node<T>* parent = node->GetParent();
        if (parent)
        {
            auto it = std::find(parent->GetChildren().begin(), parent->GetChildren().end(), node);
                // 목록에서 노드 제거.
            if (it != parent->GetChildren().end())
                parent->GetChildren().erase(it);
        }

        std::vector<Node<T>*>& children = node->GetChildren();

        while (children.size() > 0)
        {
            DestroyRecursive(children[0]);
        }
        // 노드 제거 및 정리.
        SafeDelete(node);
    }
private:
        // 트리의 루트 노드.
    Node<T>* root = nullptr;
};