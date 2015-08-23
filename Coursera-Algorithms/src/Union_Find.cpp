#include "Union_Find.h"
#include <iostream>

/** \brief Initialize the Data Structure with number of nodes.
 *
 * \param size (int) : No of groups to start with.
 *
 */
Union_Find::Union_Find(int size) {
    for(int i=0; i<size; i++) {
        grp g=grp();
        g.parent=i;
        g.size=1;
        this->vertices.push_back(g);
    }
}

/** \brief Find operation returns group to which given point belongs.
 *
 * \param i (int) : Vertex for which parent(group) is needed.
 * \return (int) : Leader vertex (Group)
 *
 */

int Union_Find::find(int i) {
    return this->vertices[i].parent;
}

/** \brief Union operations perform union of two vertices. If two vertices are different group
 *         This function combines them in a single group.
 *
 * \param i (int) : First vertex to be combined.
 * \param j (int) : Second vertex to be combined.
 *
 */
void Union_Find::unionVertices(int i,int j) {
    cout<<"Union "<<endl;
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
    cout<<"Updating parents ..."<<endl;
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

/** \brief For the formatted output of the all the vertices in Union-Find Data Structure.
 *
 */

ostream& operator<<(ostream& strm, const grp& g) {
    strm << "{" << g.parent<<"|"<<g.size<<"}";
    return strm;
}

void Union_Find::printAll() {
    vector<grp>::iterator start=this->vertices.begin();
    vector<grp>::iterator finish=this->vertices.end();
    cout<<"Union Find :"<<endl;
    while(start != finish){
        cout<<(*start)<<endl;
        start++;
    }
}
