#include<iostream>
using namespace std;
void printarray(int a[], int n){
    for (int i = 0; i < n; i++){
        cout<< a[i] << " ";
    }
    cout<<endl;
}

void swap(int& a, int& b){
    int aux = a;
    a = b;
    b = aux;
}

void quicksort(int a[],int sx, int dx){
    int i = sx;
    int j = dx;
    int pivot = a[(sx+dx)/2];
    cout<<"lx: "<< i <<"\trx: "<< j <<"\tp: "<<pivot<< endl;
    printarray(a,10);

    while (i<=j){
        //find the first (i,j) that violates the order compared to the pivot (if they exist)
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j){
            swap(a[i], a[j]);
            i++,j--;
            printarray(a,10);
        }
    }

    cout<<"Sub-array partitioned: ";
    printarray(a,10);

    if (j > sx) quicksort(a,sx,j);    
    if (i < dx) quicksort(a,i,dx);
}

void quicksort (int a[], int n){
    quicksort(a,0,n-1);
}


int main(){

    int a[10] = {12,63,4,11,55,2,0,90,15,100};

    cout<<"Input: ";
    printarray(a,10);
    
    quicksort(a,10);
    
    cout<<"Output: ";
    printarray(a,10);

    return 0;
}
