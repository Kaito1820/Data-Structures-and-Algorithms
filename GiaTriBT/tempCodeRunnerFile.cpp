#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack<int> nums;
    stack<char> exp;
    string bt;
    cin >> bt;
    nums.push(bt[0] - '0');

    for(int i = 1; i < bt.length(); i+=2){
        if(bt[i] == '+' || bt[i] == '-') 
            exp.push(bt[i]);
    }
    // cout << exp.top() << '\n';
    for(int i = 2; i < bt.length(); i+=2){
        int temp = bt[i] - '0';
        // cout << temp << '\n';
        if(bt[i-1] == '*'){
            temp *= nums.top();
            nums.pop();
            // cout << nums.top();
        }
        else if(bt[i-1] == '/'){
            temp = nums.top() / temp;
            nums.pop();
        }
        nums.push(temp);
    }
    
    stack<int> rvsNums;
    stack<char> rvsEXP;
    while(!nums.empty()){
        rvsNums.push(nums.top());
        nums.pop();
        // cout << rvsNums.top() << '\n';
    }
    while(!exp.empty()){
        rvsEXP.push(exp.top());
        exp.pop();
        // cout << rvsEXP.top() << '\n';
    }

    int temp1 = rvsNums.top();
    int temp2 = 0;
    rvsNums.pop();
    while(!rvsEXP.empty()){
        if(rvsEXP.top() == '+'){
            temp1 += rvsNums.top();
        }
        else if(rvsEXP.top() == '-'){
            temp1 = rvsNums.top() - temp1;
        }
        rvsNums.pop();
        if(!rvsNums.empty()) temp2 = rvsNums.top();
        rvsNums.push(temp1);
        temp1 = temp2;
        rvsEXP.pop();
    }

    cout << rvsNums.top();
    return 0;
}