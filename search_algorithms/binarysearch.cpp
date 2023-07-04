#include <cstdlib>
#include<iostream>

using namespace std;

template<typename T>
void printarray(T arr[],T b){
    for(int i = 0; i < b; i++){
        cout<<arr[i]<<" ";
    }
    return;
}

template<typename T>
bool binarysearch(T arr[], T lowest, T highest, T key){
    T central;
    T centralvalue;
    while (lowest <= highest){
        central = (lowest + highest) / 2;
        centralvalue = arr[central];

        if (key == centralvalue){
            return true;
        }

        else if (key < centralvalue){
            highest = central - 1;
        }
        else{
            lowest = central + 1;
        }
    }

    return false;
}


int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Array = [ ";
    printarray(arr,10);
    cout << "]" << endl;
    int key = 0;
    cout<<"Insert the number you want to search for: ";
    cin>>key;

    bool x = binarysearch(arr, 0, 10, key);
    if(x == true){
        cout<<"the number has been found: "<<key<<endl; 
        exit(EXIT_SUCCESS);
    }else{
        cerr<<" Number not found";
        exit(EXIT_FAILURE);
    }
}