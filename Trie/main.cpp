#include"trie.h"
//#include"support.h"

int main(){;

    Trie *trie = new Trie();

    // trie->insert("car");trie->insert("cart");trie->insert("cat");trie->insert("clay");
    // trie->insert("pat");trie->insert("pay");trie->insert("play");
    // trie->insert("rat");trie->insert("ray");
    // trie->insert("sat");trie->insert("say");trie->insert("stay");

    //trie->loadFile("words.txt");

    trie->insert("pa");trie->insert("py");
    trie->insert("pa");

    // trie->insert("ca");trie->insert("cy");
    //trie->insert("cat");trie->insert("pa");

    trie->printTrieConsole();

    // fstream file;
    // file.open("test.txt",ios::app);
    // trie->printPreOrden(trie->m_pRoot,file);

    REGISTER R;
    STATEMAP M;

    trie->minimizeBubenzer(trie->m_pRoot,R,M);
    trie->printTrieConsole("AFDminimozado.png");

    /*
    cout << "Print Map: " << endl;
    for(auto it = M.begin() ;it != M.end() ; it++){
        cout << it->first->getValueState() << "=>" << it->second->getValueState() << endl;
    }
    cout << "\nPrint Register: " << endl;
    for(auto it = R.begin() ;it != R.end() ; it++){
        cout << it->first << "=>" << it->second->getValueState() << endl;
    }
    cout << "MEGE BRANCHS" << endl;
    */


    delete trie;
    return 0;
}
