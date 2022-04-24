#include <vector>
#include <iostream>

using namespace std;

/**
 * �����е������·��: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * ����˼·��
 * 1.�����֪������һ��matrix[i][j]�㣬�����ĸ���������ƶ���matrix�����Ѿ���һ������ͼ������Ҫ�ٹ���ͼ
 * 2.ÿ����϶���Ҫ������Ϊ��㣬��һ��
 *	1.��ʱ�����dp�����Լ�¼���߹��Ľڵ㡣���Լ�֦��
 *  2.��̬������ dp[x][y] = max(dp[x][y],dp[nx][ny] + 1)
 * 3.ÿ���㣬������һ�����ߵ�ǰ����
 *	1.matrix[x][y] <= matrix[nx][ny]
 */
class Solution {
private:
	int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& move) {
		//if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) return 0;
		//��֦
		if (dp[x][y] != -1) return dp[x][y];
		//Ĭ����1
		int maxPath = 1;
		for (int i = 0; i < move.size(); i++) {
			int nx = x + move[i][0];
			int ny = y + move[i][1];
			if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()) continue;
			if (matrix[x][y] <= matrix[nx][ny]) continue;
			maxPath = max(maxPath, dfs(nx, ny, matrix, dp, move) + 1);
		}
		dp[x][y] = maxPath;
		return maxPath;
	}

public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
		vector<vector<int>> move{ {0,1},{1,0},{0,-1},{-1,0} };
		int maxPath = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				int dist = dfs(i, j, matrix, dp, move);
				maxPath = max(maxPath, dist);
				//dp[i][j] = dist;
			}
		}
		return maxPath;
	}
};

int main() {
	vector <vector<int>> matrix{ {9,9,4 }, { 6,6,8 }, { 2,1,1 } };
	Solution su;
	int ret = su.longestIncreasingPath(matrix);
	cout << ret << endl;

	vector<vector<int>> matrix2{ {3,4,5 }, { 3,2,6 }, { 2,2,1 } };
	int ret2 = su.longestIncreasingPath(matrix2);
	cout << ret2 << endl;
}