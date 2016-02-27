/*
	题意：从字符串中找出无重复字符的最长子串的长度
*/
#include <iostream>
//#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	/*
		思路：假设前面走走停停，现在走到中段，突然遇到重复值了，
		这时候已有条件是什么？
		。。。。。~~~~~~~~~（旧的最大：old_max）**********（最新的一段路:now_count）!(停:1.现在最大是哪个？2.返回到哪里去统计)
	*/
	int lengthOfLongestSubstring(string s)
	{
		unsigned int old_max = 0;
		unsigned int now_count = 0;
		unordered_map<char, int> sub_map;

		for (size_t i = 0; i < s.size(); ++i)
		{
			/*
				如果存在重复值
				1.需要重新统计 但从哪里开始重新统计呢？		
				2.sub_map 需要clear吗？
					不需要，sub_map 用来定位重复字符的上次位置
			*/
			if (sub_map.count(s[i]))
			{
				old_max = max(old_max,now_count);//解决思路问题1
				/*
				//now_count = i-sub_map[s[i]];//从是sub_map[s[i]]位置开始
				后来发现这种思想是错误的，没分清一种情况：s[i]是不是******里面的元素呢？
				如果是，则从是s[i]位置开始，真正的需要重新计数，长度为i-sub_map[s[i]]
				如果不是，其实是不需要重新计数的，应该now_count++
				if(是)
					now_count = i-sub_map[s[i]]
				else now_count=now_count+1

				但现在的问题是无法判断s[i]是不是*****里面的，怎么办？

				发现这样一个规律：
				if(是)
					i-sub_map[s[i]]<=now_count+1
				else i-sub_map[s[i]]>=now_count+1

				即 肯定是取两值当中较小的哪个  即 问题解决


				*/
				now_count = min((i - sub_map[s[i]]), now_count + 1);//解决思路问题2
			}
			else
			{
				now_count++;
			}
			sub_map[s[i]] = i;//如果有多个s[i]始终保持为最右  (这也是个关键点)
		}
		return max(old_max,now_count);
	}
};

int main()
{
	Solution s;
	int length = s.lengthOfLongestSubstring("aa");
	cout << length << endl;
	system("pause");
	return 0;
}