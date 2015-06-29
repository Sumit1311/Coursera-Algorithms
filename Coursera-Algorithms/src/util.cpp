#include "utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void print_array(int arr[],int n) {
    cout<<"Array is : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void print_2d_array(int **arr,int r,int c) {
    cout<<"Array is : "<<endl;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void read_data_from_file(char * file_name, int content[][3]) {
    fstream file(file_name);
    int a,b,c;
    file>>a>>b;
    int count=0;
    while(file>>a>>b>>c) {
        content[count][0]=a;
        content[count][1]=b;
        content[count][2]=c;
        count++;
    }

}

int getMaxOfTwo(int a,int b) {
    return a>b ? a:b;
}
