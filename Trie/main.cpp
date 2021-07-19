#include"trie.h"
//#include"support.h"
using MAP = map<NodeTrie*,int>;

int main(){;

    Trie *trie = new Trie();

    // trie->insert("car");trie->insert("cart");trie->insert("cat");trie->insert("clay");
    // trie->insert("pat");trie->insert("pay");trie->insert("play");
    // trie->insert("rat");trie->insert("ray");
    // trie->insert("sat");trie->insert("say");trie->insert("stay");


    /*
        INSERT MANUAL OR LOAD FILE
    */
    trie->loadFile("words.txt");
    // trie->loadFile("integrantes.txt");
    // trie->insert("pa");trie->insert("py");
    // trie->insert("ca");trie->insert("cy");
    // trie->insert("py");trie->insert("pa");

    //print png trie
    trie->printTrieConsole();

    //CALL FUNCTION countNodes
    // before minimize
    cout << "# NODOS INICIALES: "<<trie->getHeight() << endl;

    //CONTABILIZANDO LOS NODOS ACEPTADOS ANTES DE MINIMIZAR
    cout <<"# DE NODOS ACEPTADOS ANTES DE MINIMIZAR: " <<trie->countNodosAceptados() << endl;


    // fstream file;
    // file.open("test.txt",ios::app);
    // trie->printPreOrden(trie->m_pRoot,file);


    //MINIIZAR EL TRIE CON EL ALGORITMO DE BUBENZER
    cout << "MINIMIZANDO.." << endl;
    REGISTER R;
    STATEMAP M;
    trie->minimizeBubenzer(trie->m_pRoot,R,M);

    // UNA VEZ LLAMADA A BUBENZER EL NUMERO DE NODOS REDUCIRA
    trie->printTrieConsole("AFDminimozado.png");
    cout << "# NODOS FINALES: "<<trie->getHeight() << endl;


    //CONTABILIZANDO LOS NODOS ACEPTADOS DESPUES DE MINIMIZAR
    cout <<"# DE NODOS ACEPTADOS ANTES DE MINIMIZAR: " <<trie->countNodosAceptados() << endl;

    //trie->verifyFile("words_copy.txt");

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


    /*
    *   DESPUES DE MINIMIZAR EL TRIE, LEEREMOS EL MISMO ARCHIVO PARA VER SI
    +   LA ESTRUCTURA TRIE FUE DISTORSIONADA
    */
    trie->verifyFile("words.txt");
    //trie->verifyFile("words_copy.txt");




    /*
    *   count nodos aceptados
    */
    // cout << trie->countNodosAceptados() << endl;



    delete trie;
    return 0;
}
