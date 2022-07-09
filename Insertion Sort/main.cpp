#include <iostream>
using namespace std;

void swap(int &a, int &b);
void insertionSort(int a[], int n);

int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionSort(a,n);
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

void insertionSort(int a[], int n){
    
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= -1; j--){
            if((j == -1) || a[i] >= a[j]){
                int temp = a[i];
                for(int k = i; k >= j; k--){
                    a[k] = a[k-1];
                }
                a[j+1] = temp;
            }
        }
    }
}