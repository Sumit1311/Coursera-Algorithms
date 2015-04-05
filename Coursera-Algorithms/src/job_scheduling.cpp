#include <iostream>
#include <fstream>
#include <cstdlib>
#include "utils.h"

using namespace std;

int compare(const void *a,const void *b){
    int *aint=(int *)a;
    int *bint=(int *)b;
    cout<<"first : "<<aint[2]<<" second : "<<bint[2]<<endl;
    if(aint[2] > bint[2])
        return -1;
    if(aint[2] == bint[2]){
        if(aint[0] > bint[0])
            return -1;
        if(aint[0] == bint[0])
            return 0;
        if(aint[0] < bint[0])
            return 1;
    }
    if(aint[2] < bint[2])
        return 1;
}

void sort_by_greedy_criteria(int **arr,int n){
    cout<<"M : "<<n;
    qsort(arr,n,sizeof(int *),compare);
}

int schedule_jobs(int **jobs,int no_of_jobs){
    for(int i=0;i<no_of_jobs;i++){
        jobs[i][2]=jobs[i][0]-jobs[i][1];
    }
    print_2d_array(jobs,no_of_jobs,4);
    sort_by_greedy_criteria(jobs,no_of_jobs);
    print_2d_array(jobs,no_of_jobs,4);
    long int completion_time=0,prev_sum=0,sum=0;
    for(int i=0;i<no_of_jobs;i++){
        prev_sum=completion_time;
        completion_time+=prev_sum+jobs[i][1];
        jobs[i][3]=completion_time;
        sum+=(jobs[i][0]*completion_time);
    }
    print_2d_array(jobs,no_of_jobs,4);
    return sum;
}



