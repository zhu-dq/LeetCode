
/*
	题目：36. Valid Sudoku
	数独：每行、每列、粗方格内的数字都不重复。
	思路：遍历一遍行，遍历一遍列，遍历一遍粗线格
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<char,int> un_map;
		for (int i = 0; i < 9; ++i)
		{
			//行
			un_map.clear();
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
					continue;
				if (un_map.count(board[i][j]))
					return false;
				un_map[board[i][j]] = 0;
			}
			//列
			un_map.clear();
			for (int j = 0; j < 9; ++j)
			{
				if (board[j][i] == '.')
					continue;
				if (un_map.count(board[j][i]))
					return false;
				un_map[board[j][i]] = 0;
			}
		}
		//粗线框格
		for (int r = 0; r < 3; ++r)
		{
			for (int c = 0; c < 3; ++c)
			{
				un_map.clear();
				for (int i = 3 * r; i < 3 * r + 3; ++i)
				{
					for (int j = c * 3; j < 3 * c + 3; ++j)
					{
						if (board[i][j] == '.')
							continue;
						if (un_map.count(board[i][j]))
							return false;
						un_map[board[i][j]] = 0;
					}
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<char>> board(9,vector<char>(9));
	ifstream fin("test.txt");
	if (fin)
	{
		string word;
		int cnt = 0;
		while (getline(fin, word) && cnt<9)
		{
			stringstream s_word(word);
			s_word >> board[cnt][0]>>board[cnt][1]>>board[cnt][2]>>board[cnt][3]>>board[cnt][4]
				>>board[cnt][5]>>board[cnt][6]>>board[cnt][7]>>board[cnt][8];
			cnt++;
		}
		Solution sl;
		bool result = sl.isValidSudoku(board);
		system("pause");
	}
	return 0;
}