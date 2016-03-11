/*
���⣺

		����һ����������
		ת����һ��intֵ��1-3999��֮��

		ע����������ֻ��7��,   I		V		X		L		C		 D		M
								1		5		10		50		100		500		1000
		����Ҽ�

˼·��

			unordered_map<int, string> thousands = { { 0, "" }, { 1, "M" }, { 2, "MM" }, { 3, "MMM" } };

		unordered_map<int, string> hundreds = { { 0, "" }, { 1, "C" }, { 2, "CC" }, { 3, "CCC" }, { 4, "CD" }, { 5, "D" }, { 6, "DC" }, { 7, "DCC" }, { 8, "DCCC" }, { 9, "CM" } };

		unordered_map<int, string> tens = { { 0, "" }, { 1, "X" }, { 2, "XX" }, { 3, "XXX" }, { 4, "XL" }, { 5, "L" }, { 6, "LX" }, { 7, "LXX" }, { 8, "LXXX" }, { 9, "XC" } };

		unordered_map<int, string> bits = { { 0, "" }, { 1, "I" }, { 2, "II" }, { 3, "III" }, { 4, "IV" }, { 5, "V" }, { 6, "VI" }, { 7, "VII" }, { 8, "VIII" }, { 9, "IX" } };

		unordered_map<string, int> roman_num = {
		{ "I", 1 }, { "V", 5 }, { "X", 10 }, { "L", 50 }, { "C", 100 }, { "D", 500 }, {"M",1000}
		};

		�ؼ���λ��������ֵ��һλ

		1.�����һλ�͵�ǰλ��ȣ��� ��+���ϲ���һ�� sig_sum  ��������һ���ַ���ȵ������
		2.
			�жϵ�ǰ����ַ�����һ���ַ��ĵĹ�ϵ 
												�����ǰ����ַ�����һ���ַ�С����sum+=��-sig_sum��  ���� ȷ��һλ ������һ���ַ��ȵ�ǰ��������
												�����ǰ����ַ�����һ���ַ�����sum+=sig_num		 ���� ȷ��һλ	������һ���ַ��ȵ�ǰС�������





		

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