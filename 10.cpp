/*
	��Ŀ��
			������ʽƥ��

			'.' ƥ���κε����ַ���
			'*' ƥ��������һ�θ�ǰ���Ԫ�ء�(0�������ͬ�ַ�x,��Ӧ"x*")

			ƥ��Ӧ�������������ַ��������Ǿֲ��ģ���

	˼·��
			����S
			���õݹ飬���õķ��������ö�̬�滮�����˼ҵ�  555~~���������ǵݹ�ʵ�֡�
			
			���� '*'	�������������

				1. �� * �й�ϵ
				2. �� * û��ϵ

				����û��ϵ�ַ����֣�
									1. ��ǰ��ʹƥ��Ҳ����û��ϵ
									2. ��ǰ��ƥ�� �϶�û��ϵ

			Ҳ����������⣺

				��ǰƥ�䣺 
						
						���ܴ��ں�*�޹ص����Ŷ

			PS:
				�´ο����ö�̬�滮 ��һ��

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
			while (*s != '\0' && (*p == *s || *p == '.'))//��*�й�ϵ
			{
				if (isMatch(s, p + 2))//	ƥ���еĺ�*û��ϵ
					return true;
				s++;
			}
			return isMatch(s, p + 2);//  ��ƥ�� ��Ȼû��ϵ
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