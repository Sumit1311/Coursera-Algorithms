#include "JobSchedulingTest.h"
#include "job_scheduling.h"

int JobSchedulingTest::run_test() {
    read_data_from_file();
    return schedule_jobs(jobs,no_of_jobs);
}
JobSchedulingTest::JobSchedulingTest(char* filename) {
    file_stream.open(filename);
    no_of_jobs=read_length();
    jobs=new int*[no_of_jobs];
    for(int i=0;i<no_of_jobs;i++){
        jobs[i]=new int[4];
    }
}

void JobSchedulingTest::read_data_from_file() {
    int a,b,count=0;
    while(file_stream>>a>>b){
        jobs[count][0]=a;
        jobs[count][1]=b;
        count++;
    }
}

JobSchedulingTest::~JobSchedulingTest() {
    for(int i=0;i<no_of_jobs;i++){
        delete jobs[i];
    }
    delete[] jobs;
}

int JobSchedulingTest::read_length() {
    int a;
    file_stream>>a;
    return a;
}
