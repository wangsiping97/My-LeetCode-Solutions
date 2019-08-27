// Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
// In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix
// Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

#include <string> 
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> add;
        string temp;
        istringstream iss(path);
        while (getline(iss, temp, '/')) {
            if (temp == "..") {
                if (!add.empty())
                    add.pop();
            }
            else if (temp == "." || temp == "")
                continue;
            else 
                add.push(temp);
        }
        string address;
        while (!add.empty()) {
            address = '/' + add.top() + address;
            add.pop();
        }
        if (address.empty()) address = "/";
        return address;
    }
};