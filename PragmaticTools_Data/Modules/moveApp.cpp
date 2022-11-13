#include <iostream>
#include <ctime>
#include"import.h"
#include <sys/types.h>
#include <sys/stat.h>

string MoveFolder(string choiceLocation, string moveLocation) { // function to move folder to another place
    string file_name = choiceLocation;
    struct stat info;
    string move_file_name = moveLocation;
    struct stat info2;
    // check the folder
    if (stat(file_name.c_str(), &info) != 0) {
        cout << "No such directory named \"" << file_name.c_str() << "\"" << endl;
        return "Error";
    }        
    else if (info.st_mode & S_IFDIR)
        if (stat(move_file_name.c_str(), &info2) != 0) {
            cout << "No such directory named \"" << move_file_name.c_str() << "\"";
            return "Error";
        }        
        else if (info2.st_mode & S_IFDIR) {    
            // move and create link    
            string str_moveCommand = "move " + choiceLocation + " " + moveLocation;
            string str_shortcutCommand = "mklink /j " + choiceLocation + " " + moveLocation;
            const char * moveCommand = str_moveCommand.c_str();
            const char * shortcutCommand = str_shortcutCommand.c_str();
            cout << "moving......" << endl;
            system(moveCommand);
            system(shortcutCommand);
            string detail = "move " + choiceLocation + " to " + moveLocation + "by PragmaticTools.moveApps";
            return detail;
        }        
        else {
            cout << "Not a directory named \"" << move_file_name.c_str() << "\"";
            return "Error";
        }  
    else {
        cout << "Not a directory named \"" << file_name.c_str() << "\"";
        return "Error";
    }  

}



void writeJournal(string choiceLocation) {
    // if choice the safe mod, it will create 7z backup
    string path = "PragmaticTools_Data/Journal/" + to_string(time(0)) + "-" + to_string(rand());
    string saveModePath = "7z a " + path + ".7z " + choiceLocation;
    cout << saveModePath;
    const char * saveModePath_c = saveModePath.c_str();
    system(saveModePath_c);
}





