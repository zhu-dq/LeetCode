/*
	题意：
			不利用额外空间，一个intger 是不是回文

	思路：
			1. 负数肯定不是回文
			2. 翻转int 
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
