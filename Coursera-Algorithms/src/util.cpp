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

/** \brief Prints a 2-d array with r rows and columns.
 *
 * \param arr : a pointer to pointer.
 * \param r : number of rows.
 * \param c : number of columns.
 * \return
 *
 */

void print_2d_array(int **arr,int r,int c) {
    cout<<"Array is : "<<endl;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

/** \brief To read graph data from file in format (source,destination,edgeLength).
 *          First line will be excluded.
 *
 * \param file_name : file to read from
 * \param content : a 2-d array with 3 columns to store graph data read from file.
 * \return void
 *
 */
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
