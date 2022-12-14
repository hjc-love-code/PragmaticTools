#include<iostream>
#include"PragmaticTools_Data\Modules\import.h"
#include<string>
using namespace std;
//startup
void FirstZipUsing();
//deafultPath
string cdPath = "C:\\Users\\hjc-love-code";
int main() {
    // if the app is run in admin
    // install zip / check zip
    FirstZipUsing();
    // main process
    cout << "PragmaticTools 1.0.0 for Windows started......" << endl;
    cout << "You can enter \"help\" for helps" << endl << endl;
    while (true) {
        cout << cdPath << ">";
        string input;
        getline(cin, input);
        // check features
        if(input[0] == 'c' && input[1] == 'd') { // cd command(can't work by code "system")
            input = input.erase(0,3); 
            input = correctSpell(input, "path");
            string ret = isFolder(input);
            if (ret == "ok") {
                cdPath = input;
            }
            continue;
        }
        else if(input == "help" || input == "HELP") { // cmd helps and Pragmatictools helps
            helps();
            continue;
        }
        else if (input == "moveapps" || input == "moveApps") { // moveapps
            // getpath
            string Vfrom, Vto, isSafe;
            cout << "folder location you want to change: ";
            cin >> Vfrom;
            cout << "folder that you want to move to: ";
            cin >> Vto;
            cout << "safe mode?(takes up a small amount of disk space(Y/N): ";
            cin >> isSafe;
            // calculate
            Vfrom = correctSpell(joinPath(Vfrom, cdPath), "system");
            Vto = correctSpell(joinPath(Vto, cdPath), "system");
            if (isSafe == "y" || isSafe == "Y") {
                writeJournal(Vfrom);
            }
            string ret = MoveFolder(Vfrom, Vto);
            continue;
        }
        else if(input == "hideFolder" || input == "hidefolder") {
            string Vfrom;
            cout << "folder location you want to hide: ";
            cin >> Vfrom;
            hideFolder(Vfrom, cdPath, "hide");
            cout << "finish!";
            continue;
        }
        else if(input == "showFolder" || input == "showfolder") {
            string Vfrom;
            cout << "folder location you want to show: ";
            cin >> Vfrom;
            hideFolder(Vfrom, cdPath, "show");
            cout << "finish!";
            continue;
        }
        else { // maybe the enter is an cmd command
            const char * c_input = input.c_str();
            system(c_input);
            continue;
        }
        cout << endl << endl;
    }
}




