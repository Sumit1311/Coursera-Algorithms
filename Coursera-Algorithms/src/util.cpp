#include "utils.h"
#include <iostream>

using namespace std;

void print_array(int arr[],int n){
    cout<<"Array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
