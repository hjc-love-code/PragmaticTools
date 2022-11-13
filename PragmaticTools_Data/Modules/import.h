// import headfile
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;
string MoveFolder(string choiceLocation, string moveLocation);
void writeJournal(string detail);
string correctSpell(string location, string type);
string joinPath(string path, string nowPath);
string isFolder(string path);
void helps();