/*
	���⣺���ַ������ҳ����ظ��ַ�����Ӵ��ĳ���
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
		˼·������ǰ������ͣͣ�������ߵ��жΣ�ͻȻ�����ظ�ֵ�ˣ�
		��ʱ������������ʲô��
		����������~~~~~~~~~���ɵ����old_max��**********�����µ�һ��·:now_count��!(ͣ:1.����������ĸ���2.���ص�����ȥͳ��)
	*/
	int lengthOfLongestSubstring(string s)
	{
		unsigned int old_max = 0;
		unsigned int now_count = 0;
		unordered_map<char, int> sub_map;

		for (size_t i = 0; i < s.size(); ++i)
		{
			/*
				��������ظ�ֵ
				1.��Ҫ����ͳ�� �������￪ʼ����ͳ���أ�		
				2.sub_map ��Ҫclear��
					����Ҫ��sub_map ������λ�ظ��ַ����ϴ�λ��
			*/
			if (sub_map.count(s[i]))
			{
				old_max = max(old_max,now_count);//���˼·����1
				/*
				//now_count = i-sub_map[s[i]];//����sub_map[s[i]]λ�ÿ�ʼ
				������������˼���Ǵ���ģ�û����һ�������s[i]�ǲ���******�����Ԫ���أ�
				����ǣ������s[i]λ�ÿ�ʼ����������Ҫ���¼���������Ϊi-sub_map[s[i]]
				������ǣ���ʵ�ǲ���Ҫ���¼����ģ�Ӧ��now_count++
				if(��)
					now_count = i-sub_map[s[i]]
				else now_count=now_count+1

				�����ڵ��������޷��ж�s[i]�ǲ���*****����ģ���ô�죿

				��������һ�����ɣ�
				if(��)
					i-sub_map[s[i]]<=now_count+1
				else i-sub_map[s[i]]>=now_count+1

				�� �϶���ȡ��ֵ���н�С���ĸ�  �� ������


				*/
				now_count = min((i - sub_map[s[i]]), now_count + 1);//���˼·����2
			}
			else
			{
				now_count++;
			}
			sub_map[s[i]] = i;//����ж��s[i]ʼ�ձ���Ϊ����  (��Ҳ�Ǹ��ؼ���)
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