#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>
#include <vector>

using namespace std;
ofstream texto1("trie.dot");
class Node {
	public:
		char ch;
		map<char, Node*> children;
		bool isEndOfword;
//		bool mark;
		int h;
};

class Trie {
  public:
    Trie() { head.ch = -1; };
    ~Trie(){
    	for (int i=0; i<children.size(); ++i) {
    		delete children[i];
    	}
    }

    void construir_trie(string words[], int length){
    	for (int i=0; i<length; ++i) {
    		insertar(words[i]);
    	}
    }
    void insertar(string s)
    {
    	Node *root=&head;
    	for(int i = 0; i < s.size(); i++){
    		char next = s[i];
    		Node* currNode = root->children[next];
    		//if the current node doesn't exist, add it
    		if(!currNode){
    			currNode = new Node();
    			currNode->ch=next;
    			currNode->h=i+1;
    			Label.push_back(currNode);
    			q2.push(currNode);
    			root->children[s[i]] = currNode;
    		}
    		root = currNode;
    		
    	}
    	root->isEndOfword = true;
	}
	
	//Funciona pero no añade el booleano de fin de palabra
//    void insert(string word){
//    	map<char, Node*> *current_tree = &head.children;
//    	map<char, Node*>::iterator it;
//    	
//		for (int i=0; i<word.length(); ++i) {
//			char ch = word[i];
//			
//			if ((it = current_tree->find(ch)) != current_tree->end()) {
//				current_tree = &it->second->children;
//				continue;
//			}
//			
//			
//			if (it == current_tree->end()) {
//				Node* new_node = new Node();
//				new_node->ch = ch;
////				new_node->isEndOfword=true;
//				//      new_node->h++;
//				(*current_tree)[ch] = new_node;
//				
//				// Para continuar insertando palabras
//				current_tree = &new_node->children;
//				
//				// Para hacer limpiar facilmente la memoria
//				children.push_back(new_node);
//			}
//			
//		}
//		for(it=current_tree->begin();it!=current_tree->end();it++)
//		{
//			cout<<it->first<<"---";
//			it->second->isEndOfword=true;
//		}
//	}

    void search(string word, bool &result){
    	map<char, Node*> current_tree = head.children;
    	map<char, Node*>::iterator it;
    	
    	for (int i=0; i<word.length(); ++i) {
    		if ((it = current_tree.find(word[i])) == current_tree.end()) {
    			result = false;
    			return;
    		}
    	current_tree = it->second->children;
    	}
    	result = true;
    	return ;
	}

	//Para comprobar cuales son los nodos finales
	int contador(map<char,Node*> tree){
		int cont=0;
		for (map<char, Node*>::iterator it=tree.begin(); it!=tree.end(); ++it){
			if(it->second->isEndOfword==true)
			{
//				cout<<it->second->ch<<"---"; 
				cont+=1;
			}
			cont+=contador(it->second->children);
		}
		return cont;
	}
	int conta(){
		map<char, Node*> current_tree = head.children;
		int cont=0;
		cont+= contador(current_tree);
		return cont;
	}


    void print_tree(map<char, Node*> tree){
    	if (tree.empty()) {
    		return;
    	}
    	
    	for (map<char, Node*>::iterator it=tree.begin(); it!=tree.end(); ++it) {
    		cout << it->first<< endl;
    		print_tree(it->second->children);
    	}
    }
    void print(){
    	map<char, Node*> current_tree = head.children;
    	print_tree(current_tree);
    }
//    list<map<char,Node*>> 
    void inheight(map<char,Node*> current, int h,list<map<char,Node*>> &aux)
    {
//    	list<map<char,Node*>> aux;
    	map<char,Node*> x;
    	map<char,Node*>::iterator it;
    	for(it=current.begin();it!=current.end();++it)
    	{
    		if(it->second->h==h)
    		{
    			x.insert(make_pair(it->first,it->second));
//    			cout<<it->first<<"----"<<endl;
    			aux.push_back(x);

    			x.erase(it->first);
    			
			}
			inheight(it->second->children,h,aux);
		}
//		return aux;
	}


	void inheight(int h)
	{
		map<char, Node*> current_tree = head.children;
		list<map<char,Node*>> recent;
		
		//Con la funcion inheight obtenemos los nodos que esten en una altura h
		//Los nodos comienzan con altura 1 debido a que la raiz es de altura 0
		inheight(current_tree,h,recent);
		list<string> subcadenas;
		string word;
		
		//Recorro la lista para obtener los sufijos que se generan despues 
		//de haber obtenido todos los nodos de altura h con la funcion hijosNodo
		//ejemplo: Nodo con letra "b" sus hijos serian "ar", "arril", "arz", "az"
		//Ya que son los sufijos que siguen despues de la letra b
		list<map<char,Node*>>::iterator it;
		for(it=recent.begin();it!=recent.end();it++)
    	{
    		map<char,Node*>::iterator it2;
    		for(it2=it->begin();it2!=it->end();it2++)
    		{
    			map<char,Node*> recorrido= it2->second->children;
    			hijosNodo(recorrido,subcadenas,word);
			}
//    		
		}
		showSubchain(subcadenas);
//		showList(recent);
	}
	
	//Funcion para obtener sucesores de una letra dado un antecesor
	void hijosNodo(map<char,Node*> current,list<string> &subcadenas,string word)
	{
//		map<char,Node*>::iterator it= head.children->find(x);
		map<char,Node*>::iterator it2;
//		string word;
		string word1=word; 
		for(it2=current.begin();it2!=current.end();++it2)
		{
			word.push_back(it2->first);
			if(it2->second->isEndOfword==true)
			{
				subcadenas.push_back(word);
			}
			hijosNodo(it2->second->children,subcadenas,word);
			word=word1;
		}
	
	}
	
	//sOLO MUESTRA UNA LISTA
	void showSubchain(list<string> a){
		list<string>::iterator it;
		for(it=a.begin();it!=a.end();++it)
		{
			cout<<*it<<" ";
		}
	}
	//SOLO MUESTRA LA LISTA DE MAPS 
    void showList(list<map<char,Node*>> b)
    {
    	list<map<char,Node*>>::iterator it;
    	for(it=b.begin();it!=b.end();it++)
    	{
    		map<char,Node*>::iterator it2;
    		for(it2=it->begin();it2!=it->end();it2++)
    		{
    			cout<<it2->first;
			}
		}
	}
	
	//AUN FALTA HACER
    void Escribir_dot1(map<char,Node*> current)
    {
    	map<char,Node*>::iterator it1;
    	for(it1 = current.begin();it1!=current.end();++it1){
    		texto1<<"nodo1"<<"->";
			texto1 << it1->first  <<  '\n';
			if(it1->second->isEndOfword==true)
			{
				texto1<<it1->first<<";"<<endl;
			}
			texto1 <<it1->first<<"->";//" [label = "<<'"'<<it1->first <<'"' <<"];" <<endl;
			Escribir_dot2(it1->second->children); 
//			texto1<<";"<< endl;
		}
		
	}
	//AUN FALTA HACER
	void Escribir_dot2(map<char,Node*> current)
    {
    	map<char,Node*>::iterator it1;
    	for(it1 = current.begin();it1!=current.end();++it1){
//			texto1 << it1->first  <<  '\n';
  		    
			texto1 <<it1->first<<";"<<endl;//" [label = "<<'"'<<it1->first <<'"' <<"];" <<endl;
			Escribir_dot1(it1->second->children); 
//			texto1<<";"<< endl;
		}
		
	}
	//AUN FALTA HACER
    void Escribir_dot(){
		texto1<<"digraph g { ratio = fill;	node [style=filled]; \n";
		map<char,Node*> current=head.children;
		
		int contR=1;
		Escribir_dot1(current);
		texto1 << "\n}";
		texto1.close();
		
	}
	
	//AUN FALTA HACER
	void creardot1(){
			Escribir_dot();
	    	string aux="dot -Tpng trie.dot -o trie.png";
	    	const char * hel1 = aux.c_str();
	    	system(hel1);
	  	}
	//AUN FALTA HACER
    void equal()
    {
//    	queue<Node*> q2;
    	queue<Node*> q1;
//    	copia(Label,q2);
    	while(!q2.empty())
    	{
    		q1.push(q2.front());
    		q2.pop();
		}
	}


	void bucketSort(float arr[], int n){
		vector<float> b[n]; 
		for (int i=0; i<n; i++){
			int bi = n*arr[i]; 
			b[bi].push_back(arr[i]); 
    	} 
  
    
    	for (int i=0; i<n; i++) 
       		sort(b[i].begin(), b[i].end()); 
  
   
    	int index = 0; 
    	for (int i = 0; i < n; i++) 
        	for (int j = 0; j < b[i].size(); j++) 
          		arr[index++] = b[i][j]; 
	}	 
  protected:
    Node head;
    vector<Node*> children;
    list<Node*> Label;
    queue<Node*> q2;
};



int main(int argc, char** argv)
{
  string words[] = {"foo", "bar", "baz","barril", "barz","hola","gaa"};
  int n=sizeof( words ) / sizeof( words[0] );
  Trie trie;
  int h;
  cin>>h;
//  cout<<n;

  trie.construir_trie(words, n);
  cout << "Nodos del Trie" << endl;
  trie.print();
  cout<<"nodos terminales: "<<trie.conta()<<endl;
//  cout<<"nodos en altura "<<h<<" son: "<<endl;
  trie.inheight(h);
//  trie.equal();
//  trie.subChains(h);
//  trie.creardot1();

  return 0;
}
