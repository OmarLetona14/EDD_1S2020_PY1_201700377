#include "CreateFile.h"
#include <iostream>
#include <fstream>
using namespace std;
CreateFile::CreateFile(){}
void CreateFile::create(std::string dot_file, std::string png_file)
{
    std::string comando = "dot -Tpng " + dot_file + " -o "+ png_file;
    system(comando.c_str());
    system(png_file.c_str());
}
