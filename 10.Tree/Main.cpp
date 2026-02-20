#include "Container/Node.h"
#include "Container/Tree.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //Node<int>* parent = new Node<int>(10);
    //parent->AddChild(20);

    //Node<int>* child = new Node<int>(30);
    ////child->SetParent(parent);

    //parent->RemoveChild(child);

    Tree<int> tree(10);
    //if (tree.Remove(10))
        //int a = 1;
    //tree.AddChild(10, 20);
    //tree.AddChild(20, 30);
    //tree.AddChild(30, 31);
    //tree.AddChild(30, 32);
    //tree.AddChild(33, 33);
    ////tree.AddChild(20, 33);

    //// 검색 테스트.
    //Node<int>* outNode = nullptr;
    //if (tree.Find(20, outNode))
    //{
    //    std::cout << "검색 성공. 노드 데이터: " << outNode->GetData() << "\n";
    //}
    //else
    //{
    //    std::cout << "검색 실패. 해당 값을 가진 노드를 찾을 수 없음.\n";
    //}
    //

    //tree.PreorderTraversal();
    ////if (tree.Remove(20))
    ////{
    ////    int a = 1;
    ////}

    //tree.PreorderTraversal();
    //_CrtDumpMemoryLeaks();

}