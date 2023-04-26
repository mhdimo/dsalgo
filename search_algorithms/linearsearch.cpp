#include <iostream>
using namespace std;

void printarray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    
}

bool linearsearch(int array[], int n, int key)
{
    for (int i = 0; i < n; i++){
        if (array[i] == key){
            return true;
        }
    }

    return false;
}

int main(){
    int arr[10] = {10, 7, 5, 8, 2, 6, 4, 3, 1, 9};

    cout << "Array = [ ";
    
    printarray(arr,10);
    
    cout << "]"<< endl;
    
    int key;
    
    cout<<"Insert the key you want to find on the array: ";
    
    cin>>key;

    bool x = linearsearch(arr, 10, key);

    if (x){
        cout << "Found "<<key<<" in the array"<<endl;
    }

}