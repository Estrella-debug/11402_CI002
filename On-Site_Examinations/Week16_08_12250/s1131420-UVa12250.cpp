#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    string line;
    int n;
    map <string, string> language = {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"},
    };
    while (cin >> line && (line != "#")){
        n ++;
        language.find(line) != language.end() ? cout << "Case " << n << ": " << language[line] << "\n" : cout << "Case " << n << ": " << "UNKNOWN" << "\n";
    }
    return 0;
}
