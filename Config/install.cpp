#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
bool IsProcessRunAsAdmin()
{
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup;
    BOOL b = AllocateAndInitializeSid(
        &NtAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &AdministratorsGroup);
    if(b)
    {
        CheckTokenMembership(NULL, AdministratorsGroup, &b);
        FreeSid(AdministratorsGroup);
    }
    return b == TRUE;
}

void FirstZipUsing() {
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