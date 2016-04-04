/*
 * 题目：蛇形矩阵
 * 例如：输入n = 3
 *      输出：
 *      [
            [ 1, 2, 3 ],
            [ 8, 9, 4 ],
            [ 7, 6, 5 ]
        ]
     思路：
      1.从左往右
      2.从上往下
      3.从右往左
      4.从下往上

      不过要注意一些细节：
      上面四种状态换方向的时候，临界条件的变化
      1.i，j下标的变化
      2.临界值的变化
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
     vector<vector<int>> matrix;
        if(n<=0)
            return matrix;
        //init
        vector<int> v_(n,-1);
        for(size_t i=0;i<n;++i)
            matrix.push_back(v_);
        int num = 1,lhs=0,rhs = n-1,lowhs=0,highhs=n-1,max=n*n;
        int i=0,j=0;
        while (num<=max)
        {
            //从左往右
            while(num<=max && j<=rhs)matrix[i][j++]=num++;
            if(num<=max)
            {
                j--;
                i++;
                lowhs++;
            }
            //从上往下
            while(num<=max && i<=highhs)matrix[i++][j]=num++;
            if(num<=max)
            {
                i--;
                j--;
                rhs--;
            }
            //从右向左
            while(num<=max && j>=lhs)matrix[i][j--]=num++;
            if(num<=max)
            {
                j++;
                i--;
                lhs++;
            }
            //从下往上
            while(num<=max && i>=lowhs)matrix[i--][j]=num++;
            if(num<=max)
            {
                i++;
                j++;
                highhs--;
            }
        }
        return matrix;
    }
};
int main() {
    int n = 0;
    cout<<"please input n :" <<endl;
    cin>>n;

    Solution sl;
    vector<vector<int>> v =  sl.generateMatrix(n);

    for(auto & vi : v)
    {
        cout<<endl;
        for(auto & e: vi)
            cout<<e<<"\t";
        cout<<endl;
    }
    getchar();
    return 0;
}