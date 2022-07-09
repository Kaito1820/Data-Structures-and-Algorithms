#include <iostream>
#include <vector>
using namespace std;
#define hashTableSize 27
vector<string> hashTable[hashTableSize];

int hashFunc(string s){
    return (s[0] - 'a');
}

void insert(string s){
    int index = hashFunc(s);
    hashTable[index].push_back(s);
}
bool search(string s){
    int index = hashFunc(s);
    
    for(auto u : hashTable[index])
        if(u == s) return 1;
    
    return 0;
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