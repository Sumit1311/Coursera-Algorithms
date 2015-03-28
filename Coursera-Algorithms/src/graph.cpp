#include "graph.h"
#include <cstddef>
#include <iostream>
using namespace std;

void Graph::create_graph(int number){

    heads=new head_adjacency_list[number];
    value=number;
    cout<<"Graph created ...."<<value<<endl;
}
int Graph::add(node x,node y){
    cout<<"Adding edge"<<x.value<<" to "<<y.value<<endl;
    struct adjacent_node *source=heads[x.value].head;
    if(heads[x.value].head ==NULL){
        cout<<"adding first vertex "<<endl;
        struct adjacent_node *temp=new adjacent_node();
        temp->n=x;
        temp->edge_value=0;
        temp->next=NULL;
        heads[x.value].head=temp;
    }
    while(heads[x.value].head->next!=NULL){
        cout<<"Searching end of list"<<endl;
        heads[x.value].head=heads[x.value].head->next;
    }
    struct adjacent_node *temp=new adjacent_node();
    temp->n=y;
    temp->edge_value=0;
    temp->next=NULL;
    heads[x.value].head->next=temp;
    cout<<"Added edge"<<x.value<<" to "<<y.value<<endl;
    return 1;
}

void Graph::print_graph(){
    for(int i=0;i<value;i++){
        cout<<"Adjancency List for node "<<i<<endl;
        struct adjacent_node *source=heads[i].head;
        if(source == NULL){
            continue;
        }
        cout<<"source not null"<<endl;
        while(source != NULL){
            cout<<source->n.value;
            source=source->next;
        }
    }
}
