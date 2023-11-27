#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> missingwords(const string s, const string t){
    istringstream set_s(s), set_t(t);
    string word_s, word_t;
    vector<string> missing;

    set_t >> word_t;
    while (set_s>>word_s){
        if (word_s==word_t){
            if(!(set_t>> word_t)){
                break;
            }
        }
        else {
            missing.push_back(word_s);
        }
    }
   while (set_s>>word_s){
    missing.push_back(word_s);
   }
   return missing;
}

int main(){
    string s;
    string t;
    cout<< "Please enter first word phrase: "<<endl;
    getline(cin,s);
    cout<< "Please enter second word phrase: "<<endl;
    getline(cin,t);
    vector<string> result= missingwords(s,t);

    for(string word : result){
        cout<< word << " ";
        cout<<endl;
    }
    return 0;
}

