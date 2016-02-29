/*
	题目：

		字符串“PAYPALISHIRING”是写在锯齿形图案在这样的行给定数量：（你可能想显示一个固定的字体这种模式更好的可读性）
		p     A     H     N
		A  P  L  S  I  I  G
		Y	  I	    R
		即：输入的字符串按锯齿状（反向N）排列展示出来，现在要求返回按行读出的结果。

	思路：

		当 x = 0 时，x++
		当 x = numRows - 1时，x--

	效率：

		效率有点差，应该可以在下标计算处做优化，目前没做

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		unordered_map<int, string> matrix_map;
		int x = 0;
		bool change = false;
		for (auto & elem : s)
		{
			matrix_map[x].push_back(elem);

			if ((x == 0) || (x == numRows - 1))
				change = !change;

			if (change)
				x++;
			else
				x--;
		}

		string result;

		for (int i = 0; i < matrix_map.size(); i++)
		{
			result += matrix_map[i];
		}
		return result;
	}
};
int main()
{
	Solution sl;
	string result = sl.convert("ABC",1);

	cout << result << endl;

	system("pause");
	return 0;
}