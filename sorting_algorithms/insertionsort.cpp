#include<iostream>

using namespace std;

void printarray(int a[], int b){
    for(int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertionsort(){

}

int main(){

    int a[10] = {1,3,5,4,6,8,9,10,2,7};
    cout<<"Initial output: ";
    printarray(a,10);

    insertionsort();
    
    cout<<"Sorted output: ";
    printarray(a,10);

    return 0;
}