#include<bits/stdc++.h>
#include"PowerTools_Data\Modules\import.h"
using namespace std;
string input;
int main() {
    cout << "PowerTools 1.0.0 for Windows started......" << endl;
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
            string Vfrom, Vto;
            cout << "folder location or apps name: ";
            cin >> Vfrom;
            cout << "folder that you want to move: ";
            cin >> Vto;
            string ret = getLocation(Vfrom);
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