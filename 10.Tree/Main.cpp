#include "Container/Node.h"
#include "Container/Tree.h"

int main()
{
    //Node<int>* parent = new Node<int>(10);
    //parent->AddChild(20);

    //Node<int>* child = new Node<int>(30);
    ////child->SetParent(parent);

    //parent->RemoveChild(child);

    Tree<int> tree(10);
    tree.AddChild(10, 20);
    tree.AddChild(10, 30);

    // 검색 테스트.
    Node<int>* outNode = nullptr;
    if (tree.Find(20, outNode))
    {
        std::cout << "검색 성공. 노드 데이터: " << outNode->GetData() << "\n";
    }
    else
    {
        std::cout << "검색 실패. 해당 값을 가진 노드를 찾을 수 없음.\n";
    }

    return 0;
}