#include<bits/stdc++.h>
#include"PragmaticTools_Data\Modules\import.h"
#include<sys/stat.h>
using namespace std;
string nowPath = "C:\\Users\\Juncheng Hu.JONATHAN";
int main() {
    bool IsProcessRunAsAdmin();
    bool isAdmin = IsProcessRunAsAdmin();
    void FirstZipUsing();
    if (isAdmin != true) {
        cout << "Please run app as admin!";
        cin.get();
        return 0;
    }
    FirstZipUsing();
    cout << "PragmaticTools 1.0.0 for Windows started......" << endl;
    cout << "You can enter \"help\" for helps" << endl << endl;
    while (true) {
        cout << nowPath << "> ";
        string input;
        std::getline(cin, input);
        // check features
        if (input == "moveapps") {
            // Input
            string Vfrom, Vto, isSafe;
            cout << "folder location you want to change: ";
            cin >> Vfrom;
            cout << "folder that you want to move to: ";
            cin >> Vto;
            cout << "safe mode?(takes up a small amount of disk space(Y/N): ";
            cin >> isSafe;
            // Calculate
            Vfrom = correctSpell(Vfrom);
            Vto = correctSpell(Vto);
            if (isSafe == "y" || isSafe == "Y") {
                writeJournal(Vfrom);
            }
            string ret = MoveFolder(Vfrom, Vto);
        }
        else if(input == "help") {
            helps();
        }
        else if(input[0] == 'c' && input[1] == 'd') {
            input = input.erase(0,3); 
            input = correctSpell(input);
            nowPath = input;
        }
        else {
            const char * c_input = input.c_str();
            system(c_input);
        }
        cout << endl;
    }
}




