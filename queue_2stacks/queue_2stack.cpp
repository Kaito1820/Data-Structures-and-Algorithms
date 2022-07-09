#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class MyQueue {
private:
    stack<int> que1;
    stack<int> que2;
public:
    
    MyQueue() {
        
    }   
    
    void push(int x) {
        que1.push(x);
    }
    
    void pop() {
        while(!que1.empty()){
            que2.push(que1.top());
            que1.pop();
        }
        
        que2.pop();
        
        while(!que2.empty()){
            que1.push(que2.top());
            que2.pop();
        }
    }
    
    int peek() {
        while(!que1.empty()){
            que2.push(que1.top());
            que1.pop();
        }
        
        int temp = que2.top();
        
        while(!que2.empty()){
            que1.push(que2.top());
            que2.pop();
        }
        
        return temp;
    }
    
    bool empty() {
        return que1.empty();
    }
};

int main() {
    int n;
    MyQueue queRes;
    cin >> n;
    vector<int> vt;
    vector<int> x;
    for(int i = 0; i < n; i++){
        int q;
        int temp = -1;
        cin >> q;
        if(q == 1) cin >> temp;
        vt.push_back(q);
        x.push_back(temp);
    }
    
    for(int i = 0; i < n; i++){
        if(vt[i] == 1){
            queRes.push(x[i]);
        }else if(vt[i] == 2){
            queRes.pop();
        }else if(vt[i] == 3){
            cout << queRes.peek() << '\n';
        }
    } 
    
    return 0;
}
