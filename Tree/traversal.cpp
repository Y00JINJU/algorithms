#include <iostream>
#define N_MAX 27

using namespace std;

int n;
char c1, c2, c3;

struct node{
    char left;
    char right;
};

struct node tree[N_MAX];

void preorder(char node){
    if(node == '.') return ;
    printf("%c", node);
    preorder(tree[node].left);
    preorder(tree[node].right);
}

void inorder(char node){
    if(node == '.') return ;
    inorder(tree[node].left);
    printf("%c", node);
    inorder(tree[node].right);
}

void postorder(char node){
    if (node == '.') return ;
    postorder(tree[node].left);
    postorder(tree[node].right);
    printf("%c", node);
}

int main(void){

    cin >> n;

    for (int i = 1; i <= n; ++i){
        cin >> c1 >> c2 >> c3;
        tree[c1].left = c2;
        tree[c1].right = c3;
    }

    preorder('F');
    printf("\n");
    inorder('F');
    printf("\n");
    postorder('F');
    printf("\n");
    return 0;
}