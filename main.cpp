#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    map<string,string> a = {{"key1","value"}, {"key2","value2"}};
    a.insert({{"a","b"},{"f","g"}});
    a["c"]="d";
    a["42343"]="43242";

    for(auto k : a) {
        cout << k.first << ":" << k.second << endl;
    }

    return 0;
}
