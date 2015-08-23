#include <iostream>
#include <fstream>
#include <cstdlib>
#include "utils.h"
#include <typeinfo>

using namespace std;

/** \brief Compare 2 rows in 2-d array.
 *
 * \param a (void *)
 * \param b (void *)
 * \return (int)
 *
 */

int compare(const void *a,const void *b) {
    int **aint=(int **)a;
    int **bint=(int **)b;
    if(aint[0][2] > bint[0][2])
        return -1;
    if(aint[0][2] == bint[0][2]) {
        if(aint[0][0] > bint[0][0])
            return -1;
        if(aint[0][0] == bint[0][0])
            return 0;
        if(aint[0][0] < bint[0][0])
            return 1;
    }
    if(aint[0][2] < bint[0][2])
        return 1;
}

/** \brief Sorts the two 2-d array which contains all the greedy value generated for
 *  \brief given jobs.
 *
 * \param arr (int **)
 * \param n (int)
 * \return
 *
 */
void sort_by_greedy_criteria(int **arr,int n) {
    //cout<<"M : "<<n;
    qsort(arr,n,sizeof(arr[0]),compare);
}

/** \brief Start the greedy algorithm for job scheduling.
 *         Greedy Criterian : (w1-c1)
 *
 * \param jobs (int **) : 2D array of jobs with every row in format (weith, completion time,blank,blank).
 * \param no_of_jobs (int) : No of jobs in scheduling.
 * \return (int) : Sum of completion time of all jobs.(With optimal schedule)
 */
int schedule_jobs(int **jobs,int no_of_jobs) {
    for(int i=0; i<no_of_jobs; i++) {
        jobs[i][2]=jobs[i][0]-jobs[i][1];
    }
    //int sum=0;
    print_2d_array(jobs,no_of_jobs,4);
    sort_by_greedy_criteria(jobs,no_of_jobs);
    //print_2d_array(jobs,no_of_jobs,4);
    unsigned long long int completion_time=0,sum=0,temp;
    for(int i=0; i<no_of_jobs; i++) {
        temp=completion_time+jobs[i][1];
        completion_time=temp;
        jobs[i][3]=completion_time;
        temp=jobs[i][0]*completion_time;
        sum+=temp;
    }
    print_2d_array(jobs,no_of_jobs,4);
    return sum;
}
