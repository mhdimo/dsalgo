#include<iostream>

using namespace std;

template<typename T>
void printarr(T a[],T b){
    for (int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
T findmax(T a[], T b){
    T max = a[0];
    for (int i = 0; i < b; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

    template<typename T>
    void countingsort(T a[], T b){
        T max = findmax(a,b);
        T* count = new T[max+1]{0};

        for (int i = 0; i < b; i++) {
            count[a[i]]++;
        }

        T index = 0;

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