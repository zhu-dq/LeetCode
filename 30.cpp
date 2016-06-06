/*
	题目：30. Substring with Concatenation of All Words
	You are given a string, s, and a list of words, words, that are all of the same length. 
	Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once 
	and without any intervening characters.

	For example, given:
	s: "barfoothefoobarman"
	words: ["foo", "bar"]

	You should return the indices: [0,9].
	(order does not matter).
	题意：1.找出s中所有包含所有word中所有单词的子串。
		  2.word中的单词长度相同。
		  3.返回子串的首位置
	解析：
		1. 利用 hash  存储单词  这样find比较省时
		2. 利用迭代器操作原串，比substr省时
		3. 注意单词有重复的情况：计数

	
*/

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) 
	{
		vector<int> v;
		if (s.empty() || words.empty())
			return v;

		int wordsize = words[0].size();
		int len = wordsize*words.size();

		if (s.size() < len)
			return v;

		unordered_map<string, int> hashmap;
		for (auto & item : words)
			++hashmap[item];
		auto i = s.begin();
		while (i <= prev(end(s),len))
		{
			unordered_map<string, int> temp_hash_map(hashmap);
			auto j = i;
			while (j!=next(i,len))
			{
				auto pos = temp_hash_map.find(string(j,j+wordsize));
				if (pos == temp_hash_map.end())
					break;
				if (--pos->second == 0)
					temp_hash_map.erase(pos);
				j += wordsize;
			}
			if (temp_hash_map.size() == 0)
				v.push_back( distance(s.begin(),i));
			++i;
		}
		return v;
	}
};

int main()
{
	Solution sl;
	string str("wordgoodgoodgoodbestword");
	vector<string> v = {"word","good","best","good"};
	vector<int> vvv = sl.findSubstring(str,v);
	for (auto & elem : vvv)
	{
		cout << elem << endl;
	}
	system("pause");
	return 0;
}