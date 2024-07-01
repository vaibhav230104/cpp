#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {

    //creation
    unordered_map<string, int> m;

    //insertion

    //1

    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    //2

    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    //3

    m["mera"] = 1;

    //what will happen

    m["mera"] = 2;

    //Search
    cout << m ["mera"] << endl;
    cout << m.at("babbar") << endl;

   // cout << m.at("unknownkey") <<endl; //error

    cout << m ["unknownkey"] << endl;  //entry bn gyi ans 0
    cout << m.at("unknownkey") << endl;

    //size

    cout<< m.size() << endl;

    //to check count
    cout << m.count("love") << endl;

    //erase
    m.erase("love");
    cout << m.size() << endl;

    // for (auto i:m) { we can use this also
    //     cout << i.first <<" " << i.second << endl;
    // }

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();//if we use order then in order 

    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }


    return 0;

}
