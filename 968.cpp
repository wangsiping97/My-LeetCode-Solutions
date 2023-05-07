// You are given the root of a binary tree. We install cameras on the tree nodes
// where each camera at a node can monitor its parent, itself, and its immediate
// children. Return the minimum number of cameras needed to monitor all nodes of
// the tree.

#include <vector>
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
  vector<int> dp(TreeNode *node) {  // (cam_on_parent, parent_covered) = [(true,
                                    // true), (false, true), (false, false)]
    vector<int> result;
    result.reserve(3);
    // if is leaf
    if (!node->left && !node->right) {
      return {0, 1, 1};
    }
    if (!node->left) {
      auto right_res = dp(node->right);
      int cam_on_me = 1 + right_res[0];
      // if cam_on_parent
      int cam_not_on_me = right_res[1];
      result[0] = (cam_on_me < cam_not_on_me) ? cam_on_me : cam_not_on_me;
      // if cam not on parent and parent covered
      cam_not_on_me = right_res[2];
      result[1] = (cam_on_me < cam_not_on_me) ? cam_on_me : cam_not_on_me;
      // if cam not on parent and parent not covered
      result[2] = cam_on_me;
      return result;
    }
    if (!node->right) {
      auto left_res = dp(node->left);
      int cam_on_me = 1 + left_res[0];
      // if cam_on_parent
      int cam_not_on_me = left_res[1];
      result[0] = (cam_on_me < cam_not_on_me) ? cam_on_me : cam_not_on_me;
      // if cam not on parent and parent covered
      cam_not_on_me = left_res[2];
      result[1] = (cam_on_me < cam_not_on_me) ? cam_on_me : cam_not_on_me;
      // if cam not on parent and parent not covered
      result[2] = cam_on_me;
      return result;
    }
    auto left_res = dp(node->left);
    auto right_res = dp(node->right);
    int cam_on_me = 1 + left_res[0] + right_res[0];
    // if cam_on_parent
    int cam_not_on_me = left_res[1] + right_res[1];
    result[0] = (cam_on_me < cam_not_on_me) ? cam_on_me : cam_not_on_me;
    // if cam not on parent and parent covered
    int cam_on_left = left_res[2] + right_res[1];
    int cam_on_right = left_res[1] + right_res[2];
    cam_not_on_me = (cam_on_left < cam_on_right) ? cam_on_left : cam_on_right;
    result[1] = (cam_on_me < cam_not_on_me) ? cam_on_me : cam_not_on_me;
    // if cam not on parent and parent not covered
    result[2] = cam_on_me;
    return result;
  }
  int minCameraCover(TreeNode *root) { return dp(root)[1]; }
};