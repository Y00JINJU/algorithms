#include <iostream>

using namespace std;

int number = 15;

typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
}node;

void preorder(treePointer ptr){
    if (ptr){
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void inorder(treePointer ptr){
    if (ptr){
        preorder(ptr->leftChild);
        cout << ptr->data << ' ';
        preorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr){
    if (ptr){
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main(void){
    node nodes[16];

    for (int i = 0; i <= number; ++i){
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    for (int i = 1; i <= number; ++i){
        if (i % 2 == 0)
            nodes[i/2].leftChild = &nodes[i]; // 짝수면 왼쪽 자식 
        else 
            nodes[i/2].rightChild = &nodes[i]; // 홀수면 오른쪽 자식
    }

    cout << "<<<< preorder >>>>" << endl;
    preorder(&nodes[1]);
    cout << "\n\n";
    cout << "<<<< inorder >>>>" << endl;
    inorder(&nodes[1]);
    cout << "\n\n";
    cout << "<<<< postorder >>>>" << endl;
    postorder(&nodes[1]);
    cout << "\n\n";

    return 0;
}