#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

string dircpp() {
    system("ls *.cpp > ls.txt");
    fstream f("ls.txt", ios::in);
    string res, fn;
    res = "";
    while(!f.eof()) {
        string tmp = fn;
        f >> fn;
        if (fn == tmp) {
            break; // костыль для отмены последнего повторного чтения из файла
        }
        res += " " + fn;
    }
    
    f.close();
    system("rm -rf ls.txt");
    
    return res;
}

int main(int argc, char **argv) {
    bool FRun = false, FClean = false;
    for(int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-r") == 0) FRun = true;
        if (strcmp(argv[i], "-cl") == 0) FClean = true;
    }
    
    string ls = dircpp();
    
    fstream f("Makefile", ios::out);
    f << "all:\n\tg++ --std=c++11 " + ls + " -o lab\n\n";
    f << "clean:\n\trm -rf lab\n";
    f.close();
    
    if (FRun) {
        system("make");
        cout << "=====lab begin=====" << endl;
        system("./lab");
        cout << endl << "=====lab end=====" << endl;
    }
    
    if (FClean) {
        system("make clean");
        system("rm Makefile");
    }
    
    return 0;
}
