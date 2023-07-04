#include<iostream>

using namespace std;

template<typename T>
void printarray(T a[],T b){
    for (int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
void merge(T left[],T right[], T a[],T b,T middle){
    T leftsize = middle;
    T rightsize = b-middle;

    T i = 0;
    T l = 0;
    T r = 0;

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

    template <typename T>
    void mergesort(T a[],T b){
        if (b <= 1) return;

        T middle = b/2;
        T leftarray[middle];
        T rightarray[b-middle];

        T i = 0; //leftarr
        T j = 0; //rightarr

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