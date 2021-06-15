#include"trie.h"


/**
* Iterative implementation of insert into trie
*/
void Trie::insert(std::string word){
  NodeTrie *current = &(*m_pRoot);
  for (int i = 0; i < word.length(); i++){
      char ch = word[i];
      NodeTrie *node = current->children[ch];
      // if(!node){
      //     std::cout << "any" << std::endl;
      // }
      // std::cout << node->isEndOfWord() << std::endl;
      if ( !node) {
          node = new NodeTrie();
          current->children[ch] = node;
          if(current==m_pRoot){
              string valueStateTemp = "";
              valueStateTemp.push_back(ch);
              node->setValueState(valueStateTemp);
          }else{
              string valueStateTemp = current->getValueState();
              valueStateTemp.push_back(ch);
              node->setValueState(valueStateTemp);
          }
      }
      current = node;
  }
  //mark the current nodes endOfWord as true
  current->endOfWord = true;
  current->setValueState(word);
}



// A1 -> A2 [label=f];
//	f10[shape=Mrecord, style=filled, fillcolor="#02ff14" , label="{ <data> 52  |  <ew>F   } "];
/*
    DOT  TRIE IN FILE.DOT TO CONVERT IN .PNG
*/
void Trie::printTrie(NodeTrie *&root){
     std::fstream file;
     file.open("AFD.dot", std::ios::out);
     file << "digraph ll {" << std::endl;
     file <<"\tnode [shape=Mrecord];"<<endl;
     //etiquetas de los nodos
     printPreOrden(root,file);
     file<<endl;
     queue< NodeTrie* > *treeQueue = new queue< NodeTrie* >();
     treeQueue->push(root);
     NodeTrie *nodo;
     //RECORRIDO DE TODOS LOS NODOS.
     while( !treeQueue->empty() ){
         nodo = treeQueue->front();treeQueue->pop();
         // if(nodo->children.empty()){
         //     //cout << nodo->isEndOfWord() << endl;
         //     file << "\t" <<"\""<<nodo <<"\"" << " -> " << "\""<< "any"<<"\""  << endl;
         // }
         for(auto it = nodo->children.begin() ; it != nodo->children.end(); it++){
            //cout << it->first << " ";
            treeQueue->push(it->second);
            //file << "\t" <<"\""<<nodo <<"\"" << " -> " << "\""<< it->second<<"\"" <<
                    //" [label=" << it->first << "];" << endl;
            file<<"\t" << nodo->getValueState() <<":ew:c -> " << it->second->getValueState()
                <<" [label=" << it->first << "];"<<endl;
         }
     }
     delete treeQueue;
     file << "}";
     file.close();
}


void Trie::printTrieConsole(){
    printTrie(m_pRoot);
    system("dot -Tpng AFD.dot -o AFD.png");
}

/*
    RECORRE EL TRI EL PREORDEN
*/
void Trie::printPreOrden(NodeTrie *nodeTrie,ostream&file){
    string COLOR="";
    if(nodeTrie ==m_pRoot){COLOR=GREEN;}
    if(nodeTrie->isEndOfWord()){COLOR=VIOLET;}
    //cout << nodeTrie << endl;
    file<<"\t" << nodeTrie->getValueState() << "[style=filled, fillcolor="<<"\""<<COLOR<<"\""
        << ", label="<<"\""<<"{ <data> " <<nodeTrie->getValueState()<<" | <ew> "<< nodeTrie->isEndOfWord() <<" }" <<"\""<<"];"<<endl;
    //PRINT ONLY CHILDREN,ALFABETO
    for(auto it = nodeTrie->children.begin() ; it!= nodeTrie->children.end();it++ ){
        //cout << it->first << " ";
        printPreOrden(it->second,file);
    }
}





/**
* BUBEMZER MINIMIZATION
*/
void Trie::minimizeBubenzer(NodeTrie*root,REGISTER &R,STATEMAP &M){
    for(auto it = root->children.begin(); it!= root->children.end(); it++){
        //cout << it->first << " " << it->second << endl;
        if(!M[it->second]) minimizeBubenzer(it->second,R,M);
        // t_next = M[t_next]
        it->second = M[it->second];
    }
    SignatureState ss(root);
    if(!R[ss]){
        M[root] = R[ss] = root;
    }else{
        M[root] = R[ss];
        cout << "deleting " << root->getValueState() << endl;
    }
}
