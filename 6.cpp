/*
	��Ŀ��

		�ַ�����PAYPALISHIRING����д�ھ����ͼ�����������и��������������������ʾһ���̶�����������ģʽ���õĿɶ��ԣ�
		p     A     H     N
		A  P  L  S  I  I  G
		Y	  I	    R
		����������ַ��������״������N������չʾ����������Ҫ�󷵻ذ��ж����Ľ����

	˼·��

		�� x = 0 ʱ��x++
		�� x = numRows - 1ʱ��x--

	Ч�ʣ�

		Ч���е�Ӧ�ÿ������±���㴦���Ż���Ŀǰû��

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