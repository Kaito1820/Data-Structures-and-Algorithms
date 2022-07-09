#include <iostream>
using namespace std;

void swap(int &a, int &b);
void interchangeSort(int a[], int n);

int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    interchangeSort(a,n);
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void interchangeSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]) swap(a[i], a[j]);
        }
    }
}