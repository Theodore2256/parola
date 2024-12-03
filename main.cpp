#include <iostream>
#include <ctype.h>
#include <set>
#include <vector>

using namespace std;

string toLower(const string &s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {

    string litere;
    cin>>litere;
//  vector<string>factor;
    set<string>cuvinte;
    set<string>cuvinte2;
    string buffer;
//    while (cin>>buffer)
//    {
//        factor.emplace_back(buffer);
//    }
    while (cin>>buffer)
    {
         buffer=toLower(buffer);
        cuvinte.insert(buffer);
    }

    for(auto it:cuvinte)
    {
        int k=0;
        for(auto it3:litere)
        {
//            if(std::count(it.begin(), it.end(),it3))
            if(it.find(it3)==2)

                k++;
        }
        if(k==litere.size())
            cuvinte2.insert(it);

    }

    for(auto it:cuvinte2)
        cout<<(it)<<" ";

    return 0;
}