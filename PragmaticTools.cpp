#include<bits/stdc++.h>
#include"PragmaticTools_Data\Modules\import.h"
#include<sys/stat.h>
using namespace std;
string input;
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
    cout << "You can enter \"help\" for helps" << endl;
    while (true) {
        cout << ">>> ";
        cin >> input;
        // change char into small letter
        for (int i = 0; i < input.size(); i++) {
            if (input[i] >= 65 && input[i] <= 90) {
                input[i] = input[i] + 32;
            }
        }
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
        else {
            cout << "No such command name \"" << input << "\"";
        }
        cout << endl << endl;
    }
}




