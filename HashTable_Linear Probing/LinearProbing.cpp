#include <iostream>
using namespace std;
#define hashTableSize 27
string hashTable[hashTableSize];

int hashFunc(string s){
    return (s[0] - 'a');
}

void insert(string s){
    int index = hashFunc(s);
    while(hashTable[index] != ""){
        index = (index+1) % hashTableSize;
    }
    hashTable[index] = s;
}

int search(string s){
    int index = hashFunc(s);
    while(hashTable[index] != "" && hashTable[index] != s){
        index = (index+1) % hashTableSize;
    }
    if(hashTable[index] == s) return index;
    else return -1;
}

int main(){
    insert("strawberry");
    insert("banana");
    insert("mango");
    insert("watermelon");
    insert("apple");
    insert("grapes");
    insert("kiwi");
    insert("coconut");
    insert("cantaloupe");
    insert("melon");
    insert("cherry");

    cout << "kiwi: " << search("kiwi") << endl;
    cout << "mango: " << search("mango") << endl;
    cout << "melon: " << search("melon") << endl;
    cout << "chery: " << search("chery") << endl;
    cout << "cherry: " << search("cherry") << endl;
    cout << "coconut: " << search("coconut") << endl;
    cout << "cantaloupe: " << search("cantaloupe") << endl;

    return 0;
}