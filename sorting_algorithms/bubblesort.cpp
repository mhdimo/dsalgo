#include<iostream>

using namespace std;

template<typename T>
void printarr(T a[], T b){
    for (int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
void Swap(T& a, T& b){
    T aux = a;
    a = b;
    b = aux;
}

template<typename T>
void bubblesort(T a[], T b){
    T temp;
    for (int j = 0; j < b-1; j++){
        for (int i = 0; i < b-1; i++){
            if (a[i] > a[i+1]){
                Swap(a[i], a[i+1]);    
            }   
        }
    }
    cout << "Sorted array: ";
    printarr(a, 10);
}


int main(){
    int a[10] = {3424,12334,1230,495,349,48534,54758,3284,293,192};
    cout<<"Initial output: ";
    printarr(a,10);
    bubblesort<int>(a,10);
}


    /*
        Complexity:
        Best Time: O(n)
        Worst Time: O(n^2)
        Average Time: O(n^2)
    
    */