#include "utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void print_array(int arr[],int n){
    cout<<"Array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void print_2d_array(int **arr,int r,int c){
    cout<<"Array is : "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
