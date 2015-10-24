 Problem Statement
     	

A rotation of a string S is the operation of moving its first character to the end. For example, if we rotate the string "abcde" we get the string "bcdea".

A cyclic shift of a string S is any string that can be obtained from S by a sequence of zero or more rotations. For example, the strings "abcde", "cdeab", and "eabcd" are some of the cyclic shifts of the string "abcde".

Given two equally long strings, the smaller one is the one with a smaller character at the first index where they differ. For example, "cable" < "cards" because 'b' < 'r'.

You are given a string s of lowercase letters and an int k. You are allowed to change at most k letters of s into some other lowercase letters.

Your goal is to create a string that will have the smallest possible cyclic shift. Compute and return that cyclic shift.
Definition
     	
Class: 	Cyclemin
Method: 	bestmod
Parameters: 	string, int
Returns: 	string
Method signature: 	string bestmod(string s, int k)
(be sure your method is public)
Limits
     	
Time limit (s): 	2.000
Memory limit (MB): 	256
Stack limit (MB): 	256
Constraints
- 	s will contain between 1 and 50 characters, inclusive.
- 	Each character in s will be between 'a' and 'z', inclusive.
- 	k will be between 0 and the length of s, inclusive.
Examples
0) 	
     	

"aba"

1

Returns: "aaa"

We are allowed to change at most 1 character. Clearly, the optimal change is to change the 'b' into an 'a'.
1) 	
     	

"aba"

0

Returns: "aab"

We are not allowed to change anything. In this case, the answer is the smallest cyclic shift of the given string s.
2) 	
     	

"bbb"

2

Returns: "aab"


3) 	
     	

"sgsgaw"

1

Returns: "aasgsg"

The optimal solution is to change the 'w' into an 'a', and then to take the cyclic shift that starts with the last two letters of s.
4) 	
     	

"abacaba"

1

Returns: "aaaabac"


5) 	
     	

"isgbiao"

2

Returns: "aaaisgb"


This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved. 



/* Solution */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Cyclemin {
public:
	string bestmod(string s, int k) {
		int n = s.size();
		string best = s;
		for (int iter = 1; iter <= n; iter++) {
			string sCopy = s;
			int uk = 0;
			for (int j = 0; j < n; j++) {
				if (uk < k && s[j] != 'a') {
					uk++;
					sCopy[j] = 'a';
				}
			}
			best = min(best, sCopy);
			s = s.substr(1) + s.substr(0, 1);
		}
		return best;
	}
};



