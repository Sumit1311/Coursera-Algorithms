#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int compare(const void *a,const void *b){
    int *aint=(int *)a;
    int *bint=(int *)b;
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
    qsort(arr,(sizeof(arr)/sizeof(int *)),sizeof(int)*3,compare);
}

int schedule_jobs(int **jobs,int no_of_jobs){
    for(int i=0;i<no_of_jobs;i++){
        jobs[i][2]=jobs[i][0]-jobs[i][1];
    }
    sort_by_greedy_criteria(jobs,no_of_jobs);
    long int completion_time=0;
    for(int i=0;i<no_of_jobs;i++){
        completion_time+=jobs[i][1];
    }
    return completion_time;
}




