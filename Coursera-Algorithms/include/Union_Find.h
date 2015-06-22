#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <vector>
#include <string>
using namespace std;

struct group {
    int parent,size;
};

typedef struct group grp;

class Union_Find {
public:
    Union_Find(int);
    int find(int);
    void unionVertices(int,int);
    void printAll();
protected:
private:
    vector<grp> vertices;
};

#endif // UNION_FIND_H
