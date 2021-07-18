#ifndef TRIE_H
#define TRIE_H

#include"nodeTrie.h"
#include"bubenzerTopic.h"

#define VIOLET "#ff31ff"
#define GREEN "#02ff14"

using REGISTER = map<SignatureState,NodeTrie*>;
using STATEMAP = map<NodeTrie*,NodeTrie*>;

class Trie{
public:
    NodeTrie *m_pRoot;
    int m_height;
public:
    Trie(){
        m_pRoot = new NodeTrie();
        m_height =1;
    }
    ~Trie(){delete m_pRoot;}

    int getHeight(){return m_height;}

    /**
    * Iterative implementation of insert into trie
    */
    void insert(std::string word);
    bool find(std::string word);
    void countNumnerosNodos(){;}


    void printTrie(NodeTrie *&root);
    void printTrieConsole(string str ="AFD.png");
    void printPreOrden(NodeTrie *root, ostream&);

    void loadFile(string namefile);

    /**
    * Minimization Bubenzer
    */
    void minimizeBubenzer(NodeTrie*,REGISTER&,STATEMAP&);

    /*
    *   functions count
    */
    int countNodes(NodeTrie*);
};


#endif // TRIE_H
