#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
    
};

class Tree{
public:
    Node *insert(Node *root, int data){
        if(root == NULL){
            return new Node(data);
        }
        else{
            Node *cur;
            if(data <= root->data){
                cur = insert(root->left, data);
                root->left = cur;
            }
            else{
                cur = insert(root->right, data);
                root->right =cur;
            }
        }
        return root;
    }

    void preOrder(Node *root) {
        if(root == NULL) return;
        cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrder(Node *root) {
        if(root == NULL) return;
        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }
    void postOrder(Node *root) {
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ' ';
    }
};

int main(){
    Tree myTree;
    Node* root = NULL;
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    int t;
    int data;

    cin >> t;

    while(t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }
    cout << "PreOrder:  ";
	myTree.preOrder(root);
    cout << '\n';
    cout << "InOrder:   ";
	myTree.inOrder(root);
    cout << '\n';
    cout << "PostOrder: ";
	myTree.postOrder(root);
    
    return 0;
}