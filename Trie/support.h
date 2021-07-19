#ifndef SUPPORT_H
#define SUPPORT_H

void loadFile(string nameFile){
    string line;
    fstream file;
    file.open(nameFile);
    while ( getline (file,line) )
    {
      cout << line << endl;
    }
    file.close();
}

#endif // SUPPORT_H
