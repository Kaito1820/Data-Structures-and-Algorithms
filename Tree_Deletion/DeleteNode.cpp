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
        if(root == NULL) 
            return new Node(data);
        else if(data <= root->data) 
            root->left = insert(root->left, data);
        else 
            root->right = insert(root->right,data);
        return root;
    }

    Node* FindMin(Node* root){
        if(!root->left) return root;
        return FindMin(root->left);
    }
    
    Node* deleteNode(Node* root, int key){
        if(root == NULL) return root;
        else if(key < root->data) deleteNode(root->left, key);
        else if(key > root->data) deleteNode(root->right, key);
        else{
            if(!root->left && !root->right){
                delete root;
                root = NULL;
            }
            else if(root->left && !root->right){
                root->data = root->left->data;
                delete root->left;
                root->left = NULL;
            }
            else if(!root->left && root->right){
                root->data = root->right->data;
                delete root->right;
                root->right = NULL;
            }
            else{
                Node* temp = FindMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    void inOrder(Node* root){
        if(root == NULL) return;
        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }

    void preOrder(Node* root){
        if(root == NULL) return;
        cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }

};

int main(){
    Tree t;
    Node* root = NULL;
    int n, data, deleteKey;
    
    cout << "Enter n: ";
    cin >> n;
    
    cout << "Enter elements of Tree: ";
    while(n--){
        cin >> data;
        root = t.insert(root, data);
    }

    cout << "Initial Tree: ";
    t.preOrder(root);

    cout << "\nEnter the element that you want to delete: ";
    cin >> deleteKey;
    t.deleteNode(root, deleteKey);

    cout << "Tree after deletion: ";
    t.preOrder(root);

    return 0;

}