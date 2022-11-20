#include<string>
#include "import.h"
using namespace std;
void hideFolder(string location, string nowPath, string mode) {// use cmd attrib to hide folder
    location = correctSpell(location, "system");
    nowPath = correctSpell(nowPath, "user");
    location = joinPath(location, nowPath); // correct path
    string showExplorer = "start " + location;
    const char * c_showExplorer = showExplorer.c_str();
    string ret = isFolder(location);
    if (ret != "Error") {
        if (mode == "hide") {
            location = "attrib +s +a +h +r " + location; // attrib command
            const char * c_location = location.c_str();
            system(c_location);
        }
        else {
            location = "attrib -s -a -h -r " + location; // attrib command
            const char * c_location = location.c_str();
            system(c_location);
            system(c_showExplorer);
        }
    }
}

string lockFolder() {//move file to other location and create exe file to open file

}

string openFolder() {//open the folder lock by pragmaticTools
//
}