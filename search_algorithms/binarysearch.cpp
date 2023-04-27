#include<iostream>

using namespace std;

void printarray(int arr[],int b){
    for(int i = 0; i < b; i++){
        cout<<arr[i]<<" ";
    }
}

int binarysearch(int arr[], int lowest, int highest, int key){
    int central;
    int centralvalue;
    while (lowest <= highest){
        central = (lowest + highest) / 2;
        centralvalue = arr[central];

        if (key == centralvalue){
            return central;
        }

        else if (key < centralvalue){
            highest = central - 1;
        }
        else{
            lowest = central + 1;
        }
    }

    return -1;
}


int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Array = [ ";
    printarray(arr,10);
    cout << "]" << endl;
    int key = 0;
    cout<<"Insert the number you want to search for: ";
    cin>>key;

    int x = binarysearch(arr, 0, 10, 3);

    if(x >= 0){
        cout<<"the number has been found: "<<key<<endl; 
    }else{
        cout<<" Number not found";
    }
}