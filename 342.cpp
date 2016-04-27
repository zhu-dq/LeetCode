/*
 * 题目：判断一个32位整数是不是4的n次方
 * 要求：
 *      1.不能用循环
 *      2.不能用递归
 * 思路：
 *      这是一个规律题：
 *      4   二进制： 100            4-1  ：011
 *      16  二进制： 10000          16-1  ：01111
 *      64  二进制： 1000000        64-1  ：0111111
 *     特点：
 *          1. 大于0
 *          2. 1的个数是1
 *          3. num-1 的1 的个数是2的倍数
 */
#include <iostream>
#include <bitset>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0)
            return false;
        bitset<32> bit_num(num);
        if(bit_num.count()!=1)
            return false;
        bitset<32> bit_num1(num-1);
        if(bit_num1.count()%2==0)
            return true;
        return false;
    }
};