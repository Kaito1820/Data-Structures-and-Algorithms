#include <iostream>
#include <cmath>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node *root){
    if(root == NULL) return 0;
    return root->height;
}

Node *rightRotate(Node *root){
    Node *x = root->left;
    root->left = x->right;
    x->right = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *leftRotate(Node *root){
    Node *y = root->right;
    root->right = y->left;
    y->left = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;    
}

Node *Insert(Node* root, int data){
    // 
    if(root == NULL) return new Node(data);
    else if(data < root->data) root->left = Insert(root->left, data);
    else if(data > root->data) root->right = Insert(root->right, data);
    else return root;

    // set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int valBlance = getHeight(root->left) - getHeight(root->right);

    // left left
    if(valBlance > 1 && data < root->left->data){
        return rightRotate(root);
    }

    // right right
    if(valBlance < -1 && data > root->right->data){
        return leftRotate(root);
    }

    // left right
    if(valBlance > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right left
    if(valBlance < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
int main(){
    return 0;
}