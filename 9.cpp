/*
	���⣺
			�����ö���ռ䣬һ��intger �ǲ��ǻ���

	˼·��
			1. �����϶����ǻ���
			2. ��תint 
*/

#include <iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		long long int result = 0;
		int x_copy = x;
			while (x>0)
			{
				result = result * 10 + x % 10;
				x = x / 10;
			}
			if (result == x_copy)
				return true;
			return false;
	}
};
