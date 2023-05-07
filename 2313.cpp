// You are given the root of a binary tree with the following properties:
// Leaf nodes have either the value 0 or 1, representing false and true
// respectively. Non-leaf nodes have either the value 2, 3, 4, or 5,
// representing the boolean operations OR, AND, XOR, and NOT, respectively. You
// are also given a boolean result, which is the desired result of the
// evaluation of the root node.

// The evaluation of a node is as follows:
// If the node is a leaf node, the evaluation is the value of the node, i.e.
// true or false. Otherwise, evaluate the node's children and apply the boolean
// operation of its value with the children's evaluations. In one operation, you
// can flip a leaf node, which causes a false node to become true, and a true
// node to become false.

// Return the minimum number of operations that need to be performed such that
// the evaluation of root yields result. It can be shown that there is always a
// way to achieve result. A leaf node is a node that has zero children. Note:
// NOT nodes have either a left child or a right child, but other non-leaf nodes
// have both a left child and a right child.

#include <utility>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  pair<int, int> dp(TreeNode *node) {
    // if is leaf
    if (!node->left && !node->right) {
      if (node->val == 1) {
        return pair<int, int>(0, 1);
      }
      return pair<int, int>(1, 0);
    }
    // if NOT
    if (!node->left) {
      auto p = dp(node->right);
      return pair<int, int>(p.second, p.first);
    }
    if (!node->right) {
      auto p = dp(node->left);
      return pair<int, int>(p.second, p.first);
    }
    auto p_left = dp(node->left);
    auto p_right = dp(node->right);
    // if OR
    if (node->val == 2) {
      int a = p_left.first + p_right.second;
      int b = p_left.second + p_right.first;
      int c = p_left.first + p_right.first;
      int min = (a < b) ? a : b;
      min = (min < c) ? min : c;
      return pair<int, int>(min, p_left.second + p_right.second);
    }
    // if AND
    if (node->val == 3) {
      int a = p_left.first + p_right.second;
      int b = p_left.second + p_right.first;
      int c = p_left.second + p_right.second;
      int min = (a < b) ? a : b;
      min = (min < c) ? min : c;
      return pair<int, int>(p_left.first + p_right.first, min);
    }
    // if XOR
    int a = p_left.first + p_right.second;
    int b = p_left.second + p_right.first;
    int c = p_left.first + p_right.first;
    int d = p_left.second + p_right.second;
    return pair<int, int>((a < b) ? a : b, (c < d) ? c : d);
  }
  int minimumFlips(TreeNode *root, bool result) {
    pair<int, int> ans = dp(root);
    if (result) {
      return ans.first;
    }
    return ans.second;
  }
};

// Solution
// ans = f(node, res)
// res         TRUE                FALSE
// AND   f(left,1)+f(right,1)  min{f(left,1)+f(right,0),
//                                 f(left,0)+f(right,1),
//                                 f(left,0)+f(right,0)}
// NOT   f(child,0)               f(child,1)
// OR    min{f(left,1)+f(right,0),   f(left,0)+f(right,0)
//           f(left,0)+f(right,1),
//           f(left,1)+f(right,1)}
// XOR   min{f(left,1)+f(right,0),   min{f(left,1)+f(right,1),
//           f(left,0)+f(right,1)}       f(left,0)+f(right,0)}