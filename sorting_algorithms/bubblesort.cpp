#include<iostream>

using namespace std;

void printarr(int a[], int b){
    for (int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void swap(int& a, int& b){
    int aux = a;
    a = b;
    b = aux;
}

void bubblesort(int a[], int b){
    int temp;

    for (int j = 0; j < b-1; j++){
        for (int i = 0; i < b-1; i++){
            if (a[i] > a[i+1]){
                swap(a[i],a[i+1]);    
            }   
        }
    }
    

    cout<<"Sorted array: ";
    printarr(a,10);
}


int main(){

    int a[10] = {3424,12334,1230,495,349,48534,54758,3284,293,192};
    cout<<"Initial output: ";
    printarr(a,10);
    bubblesort(a,10);

}


/*
    Complexity:
    Best Time: O(n)
    Worst Time: O(n^2)
    Average Time: O(n^2)
 
*/