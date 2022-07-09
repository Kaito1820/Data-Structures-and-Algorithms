#include <iostream>
using namespace std;
#define hashTableSize 27
string hashTable[hashTableSize];

int hashFunc(string s){
    return (s[0] - 'a');
}

void insert(string s){
    int index = hashFunc(s);
    int k = 1;
    while(hashTable[index] != ""){
        index = (index+ k*k) % hashTableSize;
        k++;
    }
    hashTable[index] = s;
}
int search(string s){
    int index = hashFunc(s);
    int k = 1;
    while(hashTable[index] != "" && hashTable[index] != s){
        index = (index + k*k) % hashTableSize;
        k++;
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