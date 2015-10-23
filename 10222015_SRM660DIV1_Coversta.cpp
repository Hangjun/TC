Problem Statement
There is a rectangular field divided into a grid of n rows by m columns of unit square cells. Each cell (i, j) has some strategic value which is an integer between 0 and 9, inclusive. You are given these values as a a where each a[i][j] is a digit between '0' and '9', inclusive.

It is possible to build stations in some cells. A station built in a cell covers some set of cells. You are given the offsets of those cells as s x and y. More precisely, for each valid k, a station in the cell (i, j) covers the cell (i + x[k], j + y[k]) if a cell with those coordinates exists. Note that it may be the case that a station in (i, j) does not cover the cell (i, j).

Your task is to place two stations into two distinct cells. The total strategic value of the two stations is the sum of strategic values of all cells that are covered by at least one of the stations. Return the largest possible total strategic value of the two stations.

Definition
Class: Coversta
Method: place
Parameters: vector <string>, vector <int>, vector <int>
Returns: int
Method signature: int place(vector <string> a, vector <int> x, vector <int> y)
(be sure your method is public)
Limits
Time limit (s): 2.000
Memory limit (MB): 256
Notes
- The two stations must be built in two distinct cells of the given rectangular array. It is not allowed to build the stations at coordinates that are outside the given array.
Constraints
- n will be between 2 and 100, inclusive.
- m will be between 2 and 100, inclusive.
- a will contain exactly n elements.
- Each element of a will contain exactly m characters.
- Each character in a will be a digit ('0'-'9').
- x will contain between 1 and 10 elements, inclusive.
- x and y will contain the same number of elements.
- Each element in x will be between -(n-1) and (n-1), inclusive.
- Each element in y will be between -(m-1) and (m-1), inclusive.
- The pairs (x[k], y[k]) will be distinct.
Examples
0)
{"11", "11"}
{0,0}
{0,1}
Returns: 4
A station at (i, j) covers the cells (i, j) and (i, j+1). The optimal solution is to place the two stations at (0, 0) and (1, 0).
1)
{"11", "11"}
{0,1}
{0,1}
Returns: 3
Here a station at (i, j) also covers (i+1, j+1). One optimal solution is to place the two stations at (0, 0) and (0, 1). The first station also covers the cell (1, 1).
2)
{"15", "61"}
{0}
{0}
Returns: 11
In this test case each station only covers its own cell. The optimal solution is to build the two stations in the two most important locations.
3)
{"151", "655", "661"}
{0,0,-1}
{0,1,0}
Returns: 33
4)
{"303", "333", "000"}
{-1,-1}
{-1,1}
Returns: 12
Note that in this test case the offset (0, 0) is not among the offsets (x[k], y[k]).
5)
{"0000000", "1010101"}
{-1,-1}
{-1,1}
Returns: 0
The stations must be built on some cells of the given field. They cannot be built outside the field.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.



/* Solution: O(hw(hw + n^2) Time, O(hw) Space */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Coversta {
public:
    int place(vector<string> a, vector<int> x, vector<int> y) {
    	if (a.empty() || a[0].empty() || x.empty())  return 0;
    	int h = a.size();
    	int w = a[0].size();
    	int n = x.size();
    	vector<vector<int>> sum1(h, vector<int>(w));
    	for (int i = 0; i < h; i++) {
        	for (int j = 0; j < w; j++) {
            	for (int k = 0; k < n; k++) {
                	int nx = i+x[k];
                	int ny = j+y[k];
                	if (inBound(a, nx, ny))
                    	sum1[i][j] += (a[nx][ny] - '0');
            	}
        	}
    	}
    	int maxSum = 0;
    	for (int i = 0; i < h; i++) {
        	for (int j = 0; j < w; j++) {
            	vector<vector<int>> sum2 = sum1;
            	for (int k1 = 0; k1 < n; k1++) {
                	int nx = i+x[k1];
                	int ny = j+y[k1];
                	if(!inBound(a, nx, ny))  continue;
                	// find coordinates of station2 such that it covers (nx, ny)
                	for (int k2 = 0; k2 < n; k2++) {
                    	int nnx = nx-x[k2];
                    	int nny = ny-y[k2];
                    	if(inBound(a, nnx, nny))
                        	sum2[nnx][nny] -= (a[nx][ny] - '0');
                	}
            	}
            	for (int a = 0; a < h; a++) {
                	for (int b = 0; b < w; b++) {
                    	maxSum = max(maxSum, sum1[i][j] + sum2[a][b]);
                	}
            	}
        	}
    	}
    	return maxSum;
	}

private:
    bool inBound(vector<string> a, int z, int w) {
    	int n = a.size();
    	int m = a[0].size();
    	return (z >= 0 && z < n && w >= 0 && w < m);
	}
};
