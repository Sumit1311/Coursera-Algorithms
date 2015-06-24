#include<iostream>
#include<huffman_code.h>
#include<algorithm>

/** \brief Overloaded operator <<. The function prints the Pairs type in proper format.
 *
 * \param strm (ostream &) : Output stream to which redirect data.
 * \param kvPair (Pairs&) : A key value pair which is a object of Pairs type.
 * \return strm (ostream &).
 */
ostream& operator<<(ostream& strm, const Pairs& kvPair) {
    strm << kvPair.data.first << "{" << kvPair.data.second<<"|"<<kvPair.left_child<<"|"<<kvPair.right_child<<"}";
    return strm;
}

/** \brief This method generates a Pair type for given symbol and frequency.
 *
 * \param sym (string) : Symbols value.
 * \param freq (int) : Frequency of the symbol.
 * \return (Pair*)
 *
 */
Pairs* getNewPair(string sym,int freq){
    Pairs *p=new Pairs();
    p->data.first=sym;
    p->data.second=freq;
    p->left_child=NULL;
    p->right_child=NULL;
    return p;
}

/** \brief Prints the given pair
 *
 * \param p (Pairs *)
 *
 */
void HuffmanCode::print_node(Pairs *p) {
    cout<<*p<<endl;
}

/** \brief postOrder traversal of the tree generated.
 *
 * \param root (Pair *) : Reference of root of tree to be traversed.
 *
 */
void HuffmanCode::postOrderTree(Pairs *root){
    if(root == NULL){
        return;
    }
    //cout<<"Print Root :"<<root<<endl;
    //print_node(*root);
    this->postOrderTree(root->left_child);
    cout<<*root<<","<<endl;
    this->postOrderTree(root->right_child);
}

/** \brief This method inserts the binary codes in the vector. For each symbol.
 *         This is a recursive method which generates the code for each symbol one by one.
 *
 * \param p (Pairs *) : Reference to the root of Huffman Tree.
 * \param str (string) : Previously generated string of binary codes.
 */
void HuffmanCode::insertCodes(Pairs *p,string str){
    if(p==NULL){
        return;
    }
    if(p->left_child != NULL){
        insertCodes(p->left_child,str+"0");
    }
    if(p->right_child !=NULL){
        insertCodes(p->right_child,str+"1");
    }
    if(p->left_child ==NULL && p->right_child==NULL){
        this->binary_codes.push_back(pair<string,string>(p->data.first,str));
        return;
    }
}
/** \brief Function for comparison of pairs to sort by highest value first
 *
 * \param first_item (Pairs *) : First item to be compared
 * \param second_item (Pairs *) : Second item to be compared
 * \return (bool)
 *
 */
bool nodeComparison(const Pairs* first_item, const Pairs* second_item)  {
    //cout<<"Symbols : "<<first_item.data.first<<","<<second_item.data.first<<endl;
    if(first_item->data.second < second_item->data.second){
        //cout<<"return "<<first_item.data.first<<endl;
        return false;
    }
    //cout<<"return "<<second_item.data.first<<endl;
    return true;
}

/** \brief Function for generating the Huffman tree. It uses Heap to store the freq as key and sym as values.
 *         It generates the tree by popping up the values from heap.
 */
void HuffmanCode::generateTree() {
    if(this->symbols.size() == 1){
        return;
    }else{
        Pairs *p1=this->symbols.front();
        pop_heap(this->symbols.begin(),this->symbols.end(),nodeComparison);
        this->symbols.pop_back();
        Pairs *p2=this->symbols.front();
        pop_heap(this->symbols.begin(),this->symbols.end(),nodeComparison);
        this->symbols.pop_back();
        //cout<<"After Pop Heap :"<<endl;
        //print_progress();
        Pairs *merged=mergeTwoSymbols(p1,p2);
        cout<<"After Merge : "<<endl;
        postOrderTree(merged);
        cout<<endl;
        this->symbols.push_back(merged);
        push_heap(this->symbols.begin(),this->symbols.end(),nodeComparison);
        cout<<"After Push Heap :"<<endl;
        print_progress();
        return generateTree();
    }
}

/** \brief Merge two symbols to form an internal node in Huffman Tree.
 *
 * \param first (Pairs *)
 * \param second (Pairs *)
 * \return (Pairs *)
 */
Pairs* HuffmanCode::mergeTwoSymbols(Pairs *first,Pairs *second) {
    Pairs *p=new Pairs();
    p->data.first="$";
    //cout<<"Freq : "<<first.data.second<<","<<second.data.second<<endl;
    p->data.second=first->data.second+second->data.second;
    //cout<<"Combined :"<<p.data.second;
    p->left_child=first;
    p->right_child=second;
    return p;
}

/** \brief Print all the symbols in map_symbols. To give view of generated tree.
 *
 */
void HuffmanCode::print_progress() {
    map_symbols::iterator it=this->symbols.begin();
    while(it!=this->symbols.end()) {
            print_node(*it);
            it++;
    }
}



/** \brief Constructor which initializes the map with given symbols and frequencies.
 *
 * \param vector of symbols.
 * \param vector of frequencies
 *
 */
HuffmanCode::HuffmanCode(vector<string> symbols, vector<int> freq) {
    this->symbols=map_symbols();
    this->binary_codes=vector<pair<string,string>>();
    unsigned int i,j;
    for(i=0,j=0; i<symbols.size() && j<freq.size(); i++,j++) {
        this->symbols.push_back(getNewPair(symbols[i],freq[j]));
        //this->symbols.push_back(make_pair(symbols[i],freq[i]));
    }
    //if freq not given assume as 0

    while(i != symbols.size()) {
        this->symbols.push_back(getNewPair(symbols[i],0));
        i++;
    }
    print_progress();
    return;
}

/** \brief Used to generate huffman codes of given symbols.
 */

void HuffmanCode::generateBinaryCodes() {
    make_heap(this->symbols.begin(),this->symbols.end(),nodeComparison);
    cout<<"After Make Heap :"<<endl;
    print_progress();
    generateTree();
    cout<<"Final tree : "<<endl;
    string str;
    postOrderTree(this->symbols.front());
    insertCodes(this->symbols.front(),"");
    vector<pair<string,string>>::iterator start=this->binary_codes.begin();
    vector<pair<string,string>>::iterator finish=this->binary_codes.end();
    while(start!=finish){
        cout<<"Symbol : "<<start->first<<", Code : "<<start->second<<endl;
        start++;
    }
    cout<<endl;
}


