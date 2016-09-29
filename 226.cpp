/*
	�ݹ��㷨���裺
    1���Զ����������������з�ת
    2���Զ����������������з�ת
    3�������������ĸ��ڵ���н��������ÿ���ԭ�������ĸ��ڵ㣬��Ϊԭ�������ĸ��ڵ��ڷ�תǰ��û�иı䣩
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