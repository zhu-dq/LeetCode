/*
	递归算法步骤：
    1、对二叉树的左子树进行翻转
    2、对二叉树的右子树进行翻转
    3、将左右子树的根节点进行交换（不用考虑原二叉树的根节点，因为原二叉树的根节点在翻转前后没有改变）
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return NULL;
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		swap(root->left, root->right);
		return root;
	}
};