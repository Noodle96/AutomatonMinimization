#include <bits/stdc++.h>
#include "estudiante.hpp"

int main() {
  std::vector<Estudiante> estudiantes;
  std::ifstream iFile{"datos.txt", std::ios::in};
  if (!iFile)
  {
      std::cout << "error" << std::endl;
      return 0;
  }
  std::string name;
  float talla;
  while (iFile >> name >> talla){
    Estudiante obj(name, talla);
    estudiantes.push_back(obj);
  }
  iFile.close();
    
  std::sort(estudiantes.begin(), estudiantes.end());
  std::ofstream MyFile("resultado.txt", std::ios::out);
  MyFile << "talla más alta: " << estudiantes[0].g_nam() << "  tall:" << estudiantes[0].g_tall() << std::endl;
  for (auto e : estudiantes)
    MyFile << e.g_nam() << "  " << e.g_tall() << std::endl;
  MyFile.close();
    
  return 0;
}