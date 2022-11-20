#include <iostream>
#include"import.h"
#include <sys/types.h>
#include <sys/stat.h>


string correctSpell(string location, string type) { // correct the path spell to the way that cmd can recognise
    for (int i = 0; i < location.size(); i++) {
        if (location[i] == '/') {
            location[i] = '\\';
        }
    }
    // cdPath don't need to del the last "\", it will be strange if we do that
    if (type == "system") {
        if (location[location.size() - 1] == '\\') {
        location[location.size() - 1] = '\0';
        }
    }
    
    return location;
}


string joinPath(string path, string nowPath) {// to rerecognise the path is the full name path or relative path
    if (path[1] == ':') {
        return path;
    }
    else {
        // join the cdPath
        if (nowPath[nowPath.length() - 1] != '\\') {
            nowPath = nowPath + "\\";
        }
        string ret_newPath = nowPath + path;
        return ret_newPath;
    }
} 

string isFolder(string path) {// a func  to check if the path is point to a folder
    struct stat info;
    // check the folder
    if (stat(path.c_str(), &info) != 0) {
        cout << "No such directory named \"" << path.c_str() << "\"" << endl;
        return "Error";
    } 
    else if (info.st_mode & S_IFDIR) {
        return "ok";
    }
    else {
        cout << "Not a directory named \"" << path.c_str() << "\"";
        return "Error";
    }       
    
}