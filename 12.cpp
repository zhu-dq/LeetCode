/*
	���⣺
		
		����һ��intֵ��1-3999��֮��
		����ת������������
		ע����������ֻ��7��,   I		V		X		L		C		 D		M
							1		5		10		50		100		500		1000
						����Ҽ�
		
	˼·��

		Ͷ��ȡ�ɣ��оٳ�����������		
*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {

		unordered_map<int, string> thousands = {{0,""}, { 1, "M" }, { 2, "MM" }, { 3, "MMM" }};

		unordered_map<int, string> hundreds = {{0,""},{ 1, "C" }, { 2, "CC" }, { 3, "CCC" }, { 4, "CD" }, { 5, "D" },{ 6, "DC" }, { 7, "DCC" }, { 8, "DCCC" }, { 9, "CM" }};

		unordered_map<int, string> tens = {{0,""},{ 1, "X" }, { 2, "XX" }, { 3, "XXX" }, { 4, "XL" }, { 5, "L" },{ 6, "LX" }, { 7, "LXX" }, { 8, "LXXX" }, { 9, "XC" }};

		unordered_map<int, string> bits = {{0,""},{ 1, "I" }, { 2, "II" }, { 3, "III" }, { 4, "IV" }, { 5, "V" },{ 6, "VI" }, { 7, "VII" }, { 8, "VIII" }, { 9, "IX" }};

		int div = num / 1000;
		int remainder = num % 1000;
		string result = thousands[div];
		
		if (remainder == 0)
			return result;

		div = remainder / 100;
		remainder = remainder % 100;
		result += hundreds[div];

		if (remainder == 0)
			return result;

		div = remainder / 10;
		remainder = remainder % 10;
		result += tens[div];
		result += bits[remainder];

		return result;

	}
};