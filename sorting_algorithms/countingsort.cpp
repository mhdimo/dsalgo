#include<iostream>

using namespace std;

void printarr(int a[],int b){
    for (int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int findmax(int a[], int b){
    int max = a[0];
    for (int i = 0; i < b; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

void countingsort(int a[], int b){
    int max = findmax(a,b);
    int count[max+1] = {0};

    for (int i = 0; i < b; i++) {
        count[a[i]]++;
    }

    int index = 0;

    for (int i = 0; i < max+1; i++) {
        while (count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
}

int main(){
    
    int a[10] = {6,5,3,2,1,4,34,5345,1234,453};

    cout<<"Initial output: ";
    printarr(a,10);

    countingsort(a,10);
    
    cout<<"Sorted output: ";
    printarr(a,10);
    return 0;
}

/*
    complexity:

    best time:O(n+k)
    average time:O(n+k)
    worst time:O(n+k)
*/