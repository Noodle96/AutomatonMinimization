#include<iostream>
#include<list>
#include"trie.h"

int main(){

    // NodeTrie nodetrie1;
    // std::cout << nodetrie1.isEndOfWord() << std::endl;

    // std::string main ="main";
    // for(auto e = 0 ; e<main.size(); e++){
    //     char caracter = main[e];
    //     std::cout << caracter << ",";
    //     // std::cout << main[e] <<" ," ;
    // }std::cout << "\n";

    std::map<char,int> first;
    std::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;
    if(!first['d']){
        //std::cout << "Dont exist the caracter d\n";
    }


    //testing map[(),(),()] = node
    map< list< pair<int,int> >, string  > mapLS_S;
    map<int ,int> map_ints;
    map_ints[10] = 1000;

    list< pair<int,int> > lista0;
    lista0.push_back(make_pair(10,100));

    mapLS_S[lista0]= "10-100";

    //testing temp list
    // list< pair<int,int> > lista1; lista1.push_back(make_pair(10,100));
    // if(mapLS_S[lista0]) cout << "existe\n";
    // if(map_ints[10])cout << "existe map de 1\n";

    cout <<"hola"<<endl;
    int *tre = new int(900);
    list<pair<int,int*>> a;a.push_back(make_pair(1,tre));a.push_back(make_pair(3,nullptr));
    list<pair<int,int*>> b;b.push_back(make_pair(1,nullptr)); b.push_back(make_pair(3,nullptr));
    if(a<b)cout << "a es menor que b\n";
    else if(a>b) cout << "a es mayor que b\n";
    else if(a == b) cout << "a es igual que b\n";

    return 0;
}
