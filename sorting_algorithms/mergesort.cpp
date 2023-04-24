#include<iostream>

using namespace std;

void printarray(int a[],int b){
    for (int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void merge(int left[],int right[], int a[],int b,int middle){
    int leftsize = middle;
    int rightsize = b-middle;

    int i = 0;
    int l = 0;
    int r = 0;

    //check the condition of merge;
    while (l < leftsize && r < rightsize){
        if (left[l] < right[r]){
            a[i] = left[l];
            i++;
            l++;
        } else {
            a[i] = right[r];
            i++;
            r++;
        } 
    }
    while (l < leftsize){
        a[i] = left[l];
        i++;
        l++;
    }
    while (r < rightsize){
        a[i] = right[r];
        i++;
        r++;
    }
    
}

void mergesort(int a[],int b){
    if (b <= 1) return;

    int middle = b/2;
    int leftarray[middle];
    int rightarray[b-middle];
    
    int i = 0; //leftarr
    int j = 0; //rightarr

    for (int i = 0; i < b; i++){
        if (i<middle){
            leftarray[i] = a[i];
        } else {
            rightarray[j] = a[i];
            j++;
        }
    }
    mergesort(leftarray,middle);
    mergesort(rightarray,b-middle);

    merge(leftarray,rightarray,a,b,middle);
}

int main(){
    int a[8] = {3,7,8,5,4,2,6,1};

    cout<<"Initial output: ";
    printarray(a,8);
    
    mergesort(a,8);

    cout<<endl;
    cout<<"Sorted output: ";
    printarray(a,8);
    return 0;
}



/*
    Complexity:
    
    Best Time: O(n * logn)
    Worst Time: O(n * logn)
    Average Time: O(n^2)
*/