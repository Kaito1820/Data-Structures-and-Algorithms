#include <iostream>
using namespace std;

void swap(int &a, int &b);
void shakerSort(int a[], int l, int r);

int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    shakerSort(a,0, n-1);
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

void shakerSort(int a[],int l, int r){
    int i, j, k = r;
    while(l < r){
        // day phan tu nho hon
        for(j = r; j > l; j--){
            if(a[j-1] > a[j]) {
                swap(a[j-1], a[j]);
                k = j;
            }
        }
        l = k;

        // day phan tu lon hon
        for(i = l; i < r; i++){
            if(a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                k = i;
            }
        }
        r = k;
    }
}