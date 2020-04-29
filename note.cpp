#include <string> 
#include <sstream> 
#include <vector> 
using namespace std; 

// split a string
// 1. istringstream
vector<string> splitString(const string str, const char flag) {
    vector<string> vstr;
    vstr.clear();
    istringstream iss(str);
    string temp;
    while (getline(iss, temp, flag)) {
        vstr.push_back(temp);
    }
    return vstr;
}
// 2. two pointers

// 3. binary search

// 4. vector 去重
void f(vector<int>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

// 5. hash: times33
uint32_t time33(string str) {
    unsigned long  hash = 0;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        hash = hash *33 + (unsigned long) str[i];
    }
    return hash;
}
