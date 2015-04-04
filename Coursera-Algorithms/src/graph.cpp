#include "graph.h"
#include <cstddef>
#include <iostream>

using namespace std;
/** \brief Default constructor for initializing node class
 *
 *
 */

node::node() {
    value=-1;
}

/** \brief Single valued constructor with value being value for node
 *
 * \param x (int) : Value for the given node
 *
 */


node::node(int x) {
    value=x;
}

/** \brief Default constructor for the [adj_node] class
 *  [adj_node]: @ref adjacent_node "adjacent_node"
 *
 */


adjacent_node::adjacent_node() {
    edge_value=0;
    next=NULL;
}
/** \brief Constructor for initializing the graph
 *
 * \param number (int) : no of vertices in the graph
 *
 */

Graph::Graph(int number) {
    heads=new adjacent_node[number];
    value=number;
    cout<<"Graph created .... With "<<value<<" nodes"<<endl;
}

/** \brief Method to add a node in the graph.
 *
 *   > Until the node added to graph no edge can exist with the node in the graph
 * \param v (int) : Index of node to be added in the graph
 * \return void
 *
 */


void Graph::add_node(int v) {
    cout<<"Adding node : "<<v<<endl;
    heads[v].n=node(v);
    heads[v].edge_value=0;
    heads[v].next=NULL;
}

/** \brief Add edge to the graph
 *
 * \param source_node (int) :
 * \param
 * \return
 *
 */

int Graph::add(int source_node,int dest_node) {
    node x(source_node),y(dest_node);
    cout<<"Adding edge : "<<x.value<<" to "<<y.value<<endl;
    adjacent_node *temp=new adjacent_node();
    temp->n=y;
    temp->edge_value=0;
    temp->next=NULL;
    adjacent_node *source=heads[x.value].next;
    if(source == NULL) {
        heads[x.value].next=temp;
        return 1;
    }

    while(source -> next!=NULL) {
        //cout<<"Searching end of list"<<endl;
        source=source->next;
    }

    source->next=temp;
    cout<<"Added edge : "<<x.value<<" to "<<y.value<<endl;
    return 1;
}

int Graph::add_edge(int source,int dest) {
    add(source,dest);
    add(dest,source);
    return 1;
}

void Graph::print_graph() {
    for(int i=0; i<value; i++) {
        if(heads[i].n.value==-1) {
            continue;
        }
        cout<<"Adjancency List for node "<<heads[i].n.value<<endl;
        adjacent_node *source=heads[i].next;
        if(source == NULL) {
            continue;
        }
        //cout<<"source not null"<<endl;
        while(source != NULL) {
            cout<<source->n.value<<" "<<source->edge_value<<endl;
            source=source->next;
        }
    }
}

int Graph::remove(int source,int dest) {
    adjacent_node *source_node=&heads[source];
    cout<<"Searching for node : "<<dest<<endl;
    while(source_node!=NULL) {
        if(source_node->next == NULL) {
            source_node=NULL;
        } else if(source_node->next->n.value == dest) {
            break;
        } else {
            source_node=source_node->next;
        }

    }

    if(source_node == NULL) {
        cout<<"No such edge exist";
    } else {
        cout<<"Found required node : "<<source_node->next->n.value<<endl;
        delete source_node->next;
        source_node->next=source_node->next->next;
    }
}

int Graph::remove_edge(int source,int dest) {
    remove(source,dest);
    remove(dest,source);
}

void Graph::set_edge_value(int source,int destination,int v) {
    set_edge(source,destination,v);
    set_edge(destination,source,v);
}

void Graph::set_edge(int s,int d,int v) {
    adjacent_node *source_node=&heads[s];
    while(source_node !=NULL && source_node->n.value != d) {
        source_node=source_node->next;
    }
    if(source_node == NULL) {
        cout<<"No such edge exists......";
    } else {
        source_node->edge_value=v;
    }
}

int Graph::get_edge_value(int source,int dest) {
    adjacent_node *source_node=&heads[source];
    while(source_node !=NULL && source_node->n.value != dest) {
        source_node=source_node->next;
    }
    if(source_node == NULL) {
        cout<<"No such edge exists......";
    } else {
        return source_node->edge_value;
    }
}

int Graph::get_node_value(int n) {
    return heads[n].n.value;
}

void Graph::set_node_value(int n,int v) {
    heads[n].n.value=v;
}

bool Graph::isAdjacent(int v1,int v2) {
    adjacent_node *source=&heads[v1];
    while(source !=NULL && source->n.value != v2) {
        source=source->next;
    }
    if(source != NULL) {
        return 1;
    }
    return 0;
}

int* Graph::neighbors(int v1,int n) {
    int temp[n],count=0;
    adjacent_node *start=heads[v1].next;
    while(start != NULL) {
        temp[count++]=start->n.value;
        start=start->next;
    }
    return temp;

}
