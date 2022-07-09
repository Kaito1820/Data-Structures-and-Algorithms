#include <iostream>
using namespace std;

void swap(int &a, int &b);
void selectionSort(int a[], int n);

int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    selectionSort(a,n);
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

void selectionSort(int a[], int n){
    for(int i = 0 ; i < n-1; i++){
        int m = i;
        for(int j = i; j < n; j++){
            if(a[j] <= a[m]) m = j;
        }
        swap(a[i], a[m]);
    }
}