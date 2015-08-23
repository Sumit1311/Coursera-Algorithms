#include "Union_Find.h"
#include <iostream>

Union_Find::Union_Find(int size) {
    for(int i=0; i<size; i++) {
        grp g=grp();
        g.parent=i;
        g.size=1;
        this->vertices.push_back(g);
    }
}

int Union_Find::find(int i) {
    return this->vertices[i].parent;
}

void Union_Find::unionVertices(int i,int j) {
    cout<<"Union ";
    int combinedParent,updateParent,currentSize,updatedCount=0;
    if(this->vertices[i].size >= this->vertices[j].size) {
        updateParent=this->vertices[j].parent;
        combinedParent=this->vertices[i].parent;
    } else {
        updateParent=this->vertices[i].parent;
        combinedParent=this->vertices[j].parent;
    }
    currentSize=this->vertices[combinedParent].size;
    vector<grp>::iterator start=this->vertices.begin();
    vector<grp>::iterator finish=this->vertices.end();
    cout<<"Updating parents ...";
    while(start != finish) {
        if((*start).parent == updateParent) {
            (*start).parent=combinedParent;
            updatedCount++;
        }
        start++;
    }
    start=this->vertices.begin();
    while(start != finish) {
        if((*start).parent == combinedParent) {
            (*start).size=currentSize+updatedCount;
        }
        start++;
    }
    return;
}


ostream& operator<<(ostream& strm, const grp& g) {
    strm << "{" << g.parent<<"|"<<g.size<<"}";
    return strm;
}

void Union_Find::printAll() {
    vector<grp>::iterator start=this->vertices.begin();
    vector<grp>::iterator finish=this->vertices.end();
    while(start != finish){
        cout<<(*start)<<endl;
        start++;
    }
}
