#include "Union_Find.h"

void run_union_find(){
    Union_Find uf=Union_Find(5);
    uf.printAll();
    uf.unionVertices(0,4);
    uf.printAll();
    uf.unionVertices(1,3);
    uf.printAll();
    uf.unionVertices(4,1);
    uf.printAll();
}
