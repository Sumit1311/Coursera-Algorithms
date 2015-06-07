#include <fstream>

using namespace std;

#ifndef JOBSCHEDULINGTEST_H
#define JOBSCHEDULINGTEST_H


class JobSchedulingTest {
public:
    JobSchedulingTest(char *filename);
    void read_data_from_file();
    int run_test();
    virtual ~JobSchedulingTest();
protected:
private:
    int read_length();
    fstream file_stream;
    int **jobs;
    int no_of_jobs;
};

#endif // JOBSCHEDULINGTEST_H
