#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Tree{
public:
    Node* insert(Node* root, int data){
        if(root == NULL) return new Node(data);
        if(data <= root->data) 
            root->left = insert(root->left,data);
        else root->right = insert(root->right, data);
        return root;
    }
    Node* searchTree(Node* root, int x){
        if (root == NULL) return NULL;
        else{
            if(root->data == x) return root;
            else if(root->data > x) return searchTree(root->left, x);
            else return searchTree(root->right, x); 
        }
        return NULL;
    }
    void inOrder(Node* root, int level = 0){
        if(root == NULL) return;
        inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right); 
    }
};

int main(){
    Tree t;
    Node* root = NULL;
    int n, data;
    cin >> n;
    while(n--){
        cin >> data;
        root = t.insert(root,data);
    }
    // Node* temp = NULL;
    // int x;
    // cin >> x; 
    // temp = t.searchTree(root, x);
    // cout << temp->data << endl;
    t.inOrder(root);
    return 0;
}