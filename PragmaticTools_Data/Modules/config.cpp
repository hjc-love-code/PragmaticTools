#include<bits/stdc++.h>
#include<windows.h>
#include"import.h"
using namespace std;

void FirstZipUsing() { // install the 7z to system32
    string namepath = "Config\\zip_installed.txt";
    ifstream f(namepath);
    if( f.good() ) {
        cout << "7Z installed." << endl;
    }
    else {
        system("copy PragmaticTools_Data\\Zip\\7z.dll C:\\Windows\\System32");
        system("copy PragmaticTools_Data\\Zip\\7z.exe C:\\Windows\\System32");
        ofstream out(namepath);
        out << "Have installed 7Z! -- create by pragmaticTools setup.";
        out.close();
        cout << "7Z installed." << endl;
    }
}