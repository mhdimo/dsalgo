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

void selectionsort(int a[], int b){
    
    for(int i = 0; i < b-1; i++){
        int _min = i;
        for (int k = i+1; k < b; k++){
            if(a[k] < a[_min]){
                _min = k;

            }
        }
        if(_min != i){
            swap(a[i],a[_min]);
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