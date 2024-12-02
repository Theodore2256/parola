#include <iostream>
#include <string.h>
#include <ctype.h>
#include <set>
#include <vector>

using namespace std;


int main() {

  string litere;
  cin>>litere;
//  vector<string>factor;
    set<string>cuvinte;
    string buffer;
//    while (cin>>buffer)
//    {
//        factor.emplace_back(buffer);
//    }
    while (cin>>buffer)
    {
        cuvinte.insert(buffer);
    }

    for(auto it:cuvinte)
    {
       int k=0;
            for(auto it3:litere)
            {
                if(std::count(it.begin(), it.end(),it3))

                    k++;
            }
            if(k==litere.size())
                cout<<tolower(it)<<" ";

    }

//    for (int i = 0; i < factor.size(); ++i)
//    {
//        for (auto it2:factor[i])
//        {
//            for (auto it: litere) {
//                if (it ==it2 || it2== toupper(it2))
//                    cuvinte.insert(factor[i]);
//            }
//        }
//    }

//    for(auto it:cuvinte)
//        cout<<(it)<<" ";

    return 0;
}
