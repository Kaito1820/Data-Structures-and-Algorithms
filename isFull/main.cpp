#include <iostream>
using namespace std;

class List{
private:
    Node *head;
    Node *tail;
    int size;
    int maxSize;
public:
    List(int maxSize){
        this->head = nullptr;
        this->tail = nullptr;
        this->maxSize = maxSize;
        this->size = 0;
    }

    bool isFull(){
        return (size == maxSize);
    }
    
};

class Node{
private:
    int data;
    Node *next;
public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

int main(){

}