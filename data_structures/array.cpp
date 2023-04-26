#include<iostream>

using namespace std;

void printarray(int a[],int b){

    for (int i = 0; i < b; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main(){
    //an array is just a set of data of the same type.
    //we allocate an array in this way
    //          type nameofvariable[size_of_array];
    //       ex:int array[10]
    //you can allocate a array even using a variable
    //       int x = 10;
    //       ex:int array[x];
    /* example start*/

    int x = 10;

    int array[x] = { 13,23,54,23,54,121,546,34,123,1312};

    int arraytwo[10] = { 13142,395358,9384,9423,1873,3843,98328,2813,18889,10293};

    cout<<"data of array[x] = ";
    printarray(array,x);

    cout<<"data of arraytwo[10] = ";
    printarray(arraytwo, 10);


    //declaration of a 2d array
    /* type namevariable[rows][coulumns]*/
    // you can do the same thing as listed above
    //for using input/output of 2d arrays you will need 2 for() loops
    int matrix[x][x];
    int matrixtwo[10][10];

    //declaration of a 3d array
    /* type namevariable[rows][columns][depth]*/
    int matrixthree[x][x][x];
    int matrixfour[10][10][10];


    //how many slots would we have in a 2Darray/3Darray?
    //simple. do rows*columns or rows*columns*depth if 3d array
}