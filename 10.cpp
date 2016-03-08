/*
	题目：
			正则表达式匹配

			'.' 匹配任何单个字符。
			'*' 匹配零个或多一次个前面的元素。(0到多个相同字符x,对应"x*")

			匹配应覆盖整个输入字符串（不是局部的）。

	思路：
			遍历S
			利用递归，更好的方法是利用动态规划（别人家的  555~~），下面是递归实现。
			
			关于 '*'	有两种种情况：

				1. 和 * 有关系
				2. 和 * 没关系

				其中没关系又分两种：
									1. 当前即使匹配也可能没关系
									2. 当前不匹配 肯定没关系

			也可以这样理解：

				当前匹配： 
						
						可能存在和*无关的情况哦

			PS:
				下次可以用动态规划 做一下

 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isCompare(const char * s, const char * p)
	{
		if (*p == '\0') return *s == '\0';

		if (p[1] == '*')
		{
			while (*s != '\0' && (*p == *s || *p == '.'))//和*有关系
			{
				if (isMatch(s, p + 2))//	匹配中的和*没关系
					return true;
				s++;
			}
			return isMatch(s, p + 2);//  不匹配 当然没关系
		}
		else{
			if (*p == *s || *p == '.' && *s != '\0') return isMatch(s + 1, p + 1);
			return false;
		}
	}
	bool isMatch(string s, string p)
	{
		return isCompare(s.c_str(), p.c_str());
	}
};
int main()
{
	Solution sl;

	string s1("aaaaabbccnihao");//
	string s2("a*b*c*nihao");
	
		
		
	bool flag = sl.isMatch(s1,s2);

	system("pause");
	return 0;
}