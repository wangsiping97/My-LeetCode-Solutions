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
// 3.1 find peak in bitonic array
int findPeak(vector<int>& nums) {
    int left = 0, right = nums.size() - 1; 
    while (left < right - 1) { // attention
        int mid = left + (right - left) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;
        else if (nums[mid - 1] < nums[mid]) {
            left = mid;
        }
        else right = mid; 
    }
    return nums[left] > nums[right] ? left : right;
}

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

// 6. tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 6.1 return the depth of a tree
int max_depth(TreeNode* root) {
    if (root == NULL) return 0; 
    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);
    return max(left_depth, right_depth) + 1;
}

// 6.2 in-order traversal
// (1) recursive
// (2) iterative -- stack
// (3) iterative -- morris

// 6.3 pre-order traversal

// 6.4 post-order traversal