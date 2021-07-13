#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
fstream archivo;
void read_file(){
    archivo.open("borrar.txt",ios::in);
    if (archivo.is_open()) {
        string a;
        while ( !archivo.eof() )
        {
            a = archivo.get();
            cout<<a<<endl;
        }
        archivo.close();
    }
    else
    {
        cout<<"Archivo no encontrado";
    }
}
int main(){
    read_file();
    return 0;
}