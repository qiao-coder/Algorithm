﻿#include <string>

using namespace std;
/*
* 罗马数字转整数:https://leetcode.cn/problems/roman-to-integer/
*
* 字符          数值
*	I             1
*	V             5
*	X             10
*	L             50
*	C             100
*	D             500
*	M             1000
*
*	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。	---------IV 5   IX 9
*	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 ------XL 40  XC 90
*	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。---CD 400 CM 900
*
* 有一个规律没有注意到：
*	IV = V - I
*	IX = X - I
*	XL = L - X
*	XC = C - X
*	CD = D - C
*	CM = M - 100
*/
class Solution {
public:
	int romanToInt(string s) {
		int ans = 0;
		int i = 0;
		//MCMXCIV 1994
		//CMXCIX  999
		//LLL	  30
		while (i < s.size()) {
			
		}
	}
};

int main() {

}