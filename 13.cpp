/*
题意：

		给你一个罗马数字
		转换成一个int值（1-3999）之间

		注：罗马数字只有7个,   I		V		X		L		C		 D		M
								1		5		10		50		100		500		1000
		左减右加

思路：

			unordered_map<int, string> thousands = { { 0, "" }, { 1, "M" }, { 2, "MM" }, { 3, "MMM" } };

		unordered_map<int, string> hundreds = { { 0, "" }, { 1, "C" }, { 2, "CC" }, { 3, "CCC" }, { 4, "CD" }, { 5, "D" }, { 6, "DC" }, { 7, "DCC" }, { 8, "DCCC" }, { 9, "CM" } };

		unordered_map<int, string> tens = { { 0, "" }, { 1, "X" }, { 2, "XX" }, { 3, "XXX" }, { 4, "XL" }, { 5, "L" }, { 6, "LX" }, { 7, "LXX" }, { 8, "LXXX" }, { 9, "XC" } };

		unordered_map<int, string> bits = { { 0, "" }, { 1, "I" }, { 2, "II" }, { 3, "III" }, { 4, "IV" }, { 5, "V" }, { 6, "VI" }, { 7, "VII" }, { 8, "VIII" }, { 9, "IX" } };

		unordered_map<string, int> roman_num = {
		{ "I", 1 }, { "V", 5 }, { "X", 10 }, { "L", 50 }, { "C", 100 }, { "D", 500 }, {"M",1000}
		};

		关键定位怎样的数值算一位

		1.如果下一位和当前位相等，用 ‘+’合并到一块 sig_sum  （即和下一个字符相等的情况）
		2.
			判断当前这个字符与下一个字符的的关系 
												如果当前这个字符比下一个字符小，则sum+=（-sig_sum）  至此 确定一位 （即下一个字符比当前大的情况）
												如果当前这个字符比下一个字符大，则sum+=sig_num		 至此 确定一位	（即下一个字符比当前小的情况）





		

*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {

		unordered_map<char, int> roman_num = {
			{ 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
		};

		int sum = 0;

		for (int i = 0; i < s.size();i++)
		{
			char current_char = s[i];
			int current_num = roman_num[current_char];
			int sig_num = current_num;

			while (((i + 1) < s.size()) && (roman_num[s[i+1]] == current_char))
			{
				sig_num += current_num;
				i++;
			}

			if (i == s.size())
				return sum += sig_num;

			if (roman_num[s[i]] < roman_num[s[i+1]])
				sum -= sig_num;
			else
				sum += sig_num;
		}

		return sum;
	}
};

int main()
{
	Solution sl;

	int sum = sl.romanToInt("DCXXI");

	return 0;
}