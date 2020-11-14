// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

#include <vector> 
#include <string> 
using namespace std; 

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int bucket[128];
        vector<string> ans;
        string temp;
        memset(bucket, 0, 128 * sizeof(int));
        for (char c : s) {
            bucket[c]++;
        }
        int count = 0;
        string original = "";
        string mid = "";
        for (int i = 0; i < 128; ++i) {
            int val = bucket[i];
            if (val % 2 == 1) {
                mid.push_back((char)i);
                count++;
            } 
            val /= 2;
            for (int j = 0; j < val; ++j) original.push_back((char)i);
            if (count >= 2) return ans;
        }
        if (original.length() == 0) {
            ans.push_back(mid);
            return ans;
        }
        bool visited[original.length()];
        memset(visited, 0, original.length() * sizeof(bool));
        for (int i = 0; i < original.length(); ++i) {
            if (i > 0 && original[i] == original[i - 1]) continue;
            temp += original[i];
            visited[i] = true;
            dfs(ans, temp, original, visited, mid);
            temp.pop_back();
            visited[i] = false;
        }
        return ans;
    }
    void dfs(vector<string>& ans, string temp, string original, bool* visited, string mid) {
        if (temp.length() == original.length()) {
            ans.push_back(create_ans(temp, mid));
            return;
        }
        for (int i = 0; i < original.length(); ++i) {
            if (visited[i] == true) continue;
            if (i > 0 && original[i] == original[i - 1] && visited[i - 1] == false) continue;
            temp += original[i];
            visited[i] = true;
            dfs(ans, temp, original, visited, mid);
            temp.pop_back();
            visited[i] = false;
        }
    }
    string create_ans(string temp, string mid) {
        string left = temp;
        reverse(temp.begin(), temp.end());
        left += mid;
        left += temp;
        return left;
    }
};