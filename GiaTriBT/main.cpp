#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack<int> nums;
    stack<char> op;
    string bt;
    cin >> bt;
    if(bt[bt.length()] == ' ') bt[bt.length()] = '\0';
    if(bt.length() == 1){
        cout << bt[0];
        return 0;
    }
    nums.push(bt[0] - '0');

    for(int i = 1; i < bt.length(); i+=2){
        if(bt[i] == '+' || bt[i] == '-') 
            op.push(bt[i]);
    }
    // cout << op.top() << '\n';
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
        // cout << temp << '\n';
        // cout << nums.top() << '\n';
        nums.push(temp);
    }

    if(nums.size() == 1){
        cout << nums.top();
        return 0;
    }

    

    int temp1 = rvsNums.top();
    int temp2 = 0;
    rvsNums.pop();
    while(!rvsOP.empty()){
        if(rvsOP.top() == '+'){
            temp1 += rvsNums.top();
        }
        else if(rvsOP.top() == '-'){
            temp1 = rvsNums.top() - temp1;
        }
        rvsNums.pop();
        if(!rvsNums.empty()) temp2 = rvsNums.top();
        rvsNums.push(temp1);
        temp1 = temp2;
        rvsOP.pop();
    }

    cout << rvsNums.top();
    return 0;
}