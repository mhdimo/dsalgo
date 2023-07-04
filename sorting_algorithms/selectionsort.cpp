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
void selectionsort(T a[], T b){
    for(int i = 0; i < b-1; i++){
        T _min = i;
        for (int k = i+1; k < b; k++){
            if(a[k] < a[_min]){
                _min = k;

            }
        }
        if(_min != i){
            Swap(a[i],a[_min]);
        }
    }
}

int main(){

    int a[10] = {6,5,3,2,1,4,34,5345,1234,453};

    cout<<"Initial output: ";
    printarr(a,10);

    selectionsort(a,10);

    cout<<"Array sorted: ";
    printarr(a,10);

}

/*
    Complexity:
    
    Best Time: O( n^2)
    Worst Time: O(n^2)
    Average Time: O(n^2)
*/