#ifndef HUFFMAN_CODE_H_INCLUDED
#define HUFFMAN_CODE_H_INCLUDED
#endif // HUFFMAN_CODE_H_INCLUDED
#include<map>
#include<string>
#include<vector>
#include<utility>
#include "tree.hh"

using namespace std;
typedef pair<string,int> sym_freq;
struct Node{
    sym_freq data;
    Node *left_child;
    Node *right_child;
};
typedef struct Node Pairs;
typedef vector<Pairs*> map_symbols;


class HuffmanCode {
private :
    //stores name of symbols and their frequencies
    map_symbols symbols;
    Pairs* mergeTwoSymbols(Pairs*,Pairs*);
    vector<pair<string,string>> binary_codes;
    void generateTree();
public :
    HuffmanCode(vector<string>,vector<int>);
    void generateBinaryCodes();
    void print_progress();
    void postOrderTree(Pairs *root);
    void print_node(Pairs*);
    void insertCodes(Pairs*,string);
};
