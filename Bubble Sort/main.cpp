#include <iostream>
using namespace std;

void swap(int &a, int &b);
void bubbleSort(int a[], int n);

int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bubbleSort(a,n);
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

void bubbleSort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(a[j-1] > a[j]) swap(a[j-1], a[j]);
        }
    }
}