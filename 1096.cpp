// Under a grammar given below, strings can represent a set of lowercase words.  Let's use R(expr) to denote the set of words the expression represents.

// Grammar can best be understood through simple examples:
// Single letters represent a singleton set containing that word.
// R("a") = {"a"}
// R("w") = {"w"}
// When we take a comma delimited list of 2 or more expressions, we take the union of possibilities.
// R("{a,b,c}") = {"a","b","c"}
// R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
// When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
// R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
// R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}

// Formally, the 3 rules for our grammar:
// For every lowercase letter x, we have R(x) = {x}
// For expressions e_1, e_2, ... , e_k with k >= 2, we have R({e_1,e_2,...}) = R(e_1) ∪ R(e_2) ∪ ...
// For expressions e_1 and e_2, we have R(e_1 + e_2) = {a + b for (a, b) in R(e_1) × R(e_2)}, where + denotes concatenation, and × denotes the cartesian product.
// Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.

#include <string> 
#include <vector> 
#include <stack> 
#include <set> 
#include <iostream> 
using namespace std; 

class Solution {
public:
    vector<string> compute(vector<string>& x, vector<string>& y) {
        set<string> set;
        for (int i = 0; i < x.size(); ++i) 
            for (int j = 0; j < y.size(); ++j) 
                set.insert(x[i] + y[j]);
        vector<string> res;
        res.assign(set.begin(), set.end());
        return res;
    }
    vector<string> braceExpansionII(string expression) {
        cout << expression << endl;
        vector<string> ans;
        int l = expression.length(); 
        stack< vector<string> > st;
        vector<string> v;
        for (int i = 0; i < l; ++i) {
            if (expression[i] >= 'a' && expression[i] <= 'z') {
                string str = "";
                str = str + expression[i];
                v.push_back(str);
                if (i > 0 && expression[i - 1] != ',') {
                    v = compute(st.top(), v);
                    st.pop();
                }
                st.push(v);
                v.clear();
            }
            else if (expression[i] == '{') {
                int count = 0, j = i;
                for (; j < l; ++j) {
                    if (expression[j] == '{') count++;
                    if (expression[j] == '}') count--;
                    if (count == 0) break;
                }
                v = braceExpansionII(expression.substr(i + 1, j - i - 1));
                if (i > 0 && expression[i - 1] != ',' && expression[i - 1] != '{') {
                    v = compute(st.top(), v);
                    st.pop();
                }
                st.push(v);
                v.clear();
                i = j;
            }
        }
        set<string> set;
        while (!st.empty()) {
            for (int i = 0; i < st.top().size(); ++i) 
                set.insert(st.top()[i]);
            st.pop();
        }
        ans.assign(set.begin(), set.end());
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.braceExpansionII("{{a,z},a{b,c},{ab,z}}");
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
}