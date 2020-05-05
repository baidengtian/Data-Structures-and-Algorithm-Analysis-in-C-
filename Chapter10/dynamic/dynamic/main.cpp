/*
 * @Author: lsyy
 * @Date: 2020-03-12 20:38:10
 * @LastEditTime: 2020-03-12 21:08:48
 * @LastEditors: Please set LastEditors
 * @Description: ��̬�滮����
 * @FilePath: \dynamic programmig\Src\main.cpp
 */


#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#include <cmath>
// ����Ǯ����
// �ݹ�
int exchange1(int amount, std::vector<int> coins)
{

	if (amount == 0)       // Ǯ�պô���
		return 0;

	if (amount < 0)        // û�����������
		return -1;

	int result = INT_MAX;

	for (auto x : coins)
	{
		int SubMin = exchange1(amount - x, coins);
		if (SubMin == -1)
			continue;
		result = std::min(SubMin + 1, result);
	}

	if (result == INT_MAX)
		return -1;

	return result;
}
// �޼� ����� result_table
int exchange2(int amount, std::vector<int> coins)
{
	static std::map<int, int> result_table;
	if ( result_table.find(amount) != result_table.end() )
		return result_table[amount];


	if (amount == 0)       // Ǯ�պô���
		return 0;

	if (amount < 0)        // û�����������
		return -1;

	int result = INT_MAX;

	for (auto x : coins)
	{
		int SubMin = exchange2(amount - x, coins);
		if (SubMin == -1)
			continue;
		result = std::min(SubMin + 1, result);
	}

	if (result == INT_MAX)
		return -1;

	result_table[amount] = result;

	return result;
}
// �Ե����� ʵ�ֶ�̬�滮
int exchange3(int amount, std::vector<int> coins)
{
	int* dp = new int[amount + 1];
	for (int i = 0; i < amount + 1; ++i)
	{
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for (int i = 0; i < amount + 1; ++i)
	{
		for (int j = 0; j < coins.size(); ++j)
		{
			if (i >= coins[j])
				dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);
		}
	}

	if (dp[amount] == INT_MAX)
		return -1;
	return dp[amount];


}

// �������������

int maxSubArrary(std::vector<int> array)
{
	std::vector<int> dp(array.size(), 0);
	int result = 0;
	dp[0] = array[0];
	result = dp[0];
	for (int i = 1; i < array.size(); ++i)
	{
		dp[i] = std::max(dp[i - 1], 0) + array[i];
		result = std::max(dp[i], result);
	}
	return result;
}

// ����һ���������ж����ֲ�ͬ�ķ�ʽ�����(0,0) ���յ� (m-1,n-1)��
// ����ÿ���ƶ�ֻ�����һ������£�����ж�������ͬ��·��
int uniquePaths( int n, int m )
{
	int** dp = new int*[n];
	for (int i = 0; i < n; ++i)
		dp[i] = new int[m];

	for (int i = 0; i < m; ++i)
		dp[0][i] = 1;
	for (int i = 0; i < n; ++i)
		dp[i][0] = 1;

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[n - 1][m - 1];
}
// ����һ���������ж����ֲ�ͬ�ķ�ʽ����� ( 0, 0 ) ���յ� ( m - 1, n - 1 )��
// ����ÿ���ƶ�ֻ�����һ������£����ڿ������������ϰ��
// ��ά���� pos �� pos[i][j] = 1 �����λ�ô����ϰ�������ж�������ͬ��·��
int uniquePathsWithObstacles( int n, int m, int** pos )
{
	int** dp = new int* [n];
	for (int i = 0; i < n; ++i)
		dp[i] = new int[m];

	for (int i = 0; i < m; ++i)
		dp[0][i] = 1;
	for (int i = 0; i < n; ++i)
		dp[i][0] = 1;

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			if (pos[i][j])
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[n - 1][m - 1];
}
// ����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻ�
// �����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
int ShortestPath(int n, int m, int** pos)
{
	int** dp = new int* [n];
	for (int i = 0; i < n; ++i)
		dp[i] = new int[m];

	dp[0][0] = pos[0][0];
	for (int i = 1; i < m; ++i)							// ������һ����
		dp[0][i] = pos[0][i] + dp[0][i-1];
	for (int i = 1; i < n; ++i)							// ������һ����
		dp[i][0] = pos[i][0] + dp[i-1][0];

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + pos[i][j];
	return dp[n - 1][m - 1];
}
// ��һ���� 0 �� 1 ��ɵĶ�ά�����ڣ��ҵ�ֻ���� 1 ����������Σ������������
int SquareArea(int n, int m, int pos[][5])
{
	int** dp = new int* [n];

	for (int i = 0; i < n; ++i)
		dp[i] = new int[m];

	pos[0][0] ? dp[0][0] = 1 : dp[0][0] = 0;

	int result = dp[0][0];

	for (int i = 1; i < m; ++i)							// ������һ����
		dp[0][i] = pos[0][i];
	for (int i = 1; i < n; ++i)							// ������һ����
		dp[i][0] = pos[0][i];

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
		{
			pos[i][j] ? 
			dp[i][j] = ( std::min(std::min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1 )
			: dp[i][j] = 0;
			result = std::max(result, dp[i][j]);
		}
			

	return result * result;
}
//int main()
//{
//	int amount = 12;
//	std::vector<int> coins;
//	coins.push_back(1);
//	coins.push_back(2);
//	coins.push_back(5);
//	std::cout << exchange3(amount, coins) << std::endl;
//
//	int array[] = { -2,1,-3,4,-1,2,1,-5,4 };
//	std::vector<int> sub(array, array + sizeof(array) / sizeof(int));
//	int num = maxSubArrary(sub);
//
//	int paths = uniquePaths(7, 3);
//
//
//	int pos[3][3] = { {0,0,0},
//					  {0,1,0},
//					  {0,0,0} };
//	int* p[3];
//	p[0] = &pos[0][0];
//	p[1] = pos[1];
//	p[2] = pos[2];
//	int path = uniquePathsWithObstacles(3, 3, p);
//
//	int PathWeight[3][3] = { {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
//	int* pPathWeight[3];
//	pPathWeight[0] = &PathWeight[0][0];
//	pPathWeight[1] = PathWeight[1];
//	pPathWeight[2] = PathWeight[2];
//
//	int min = ShortestPath(3, 3, pPathWeight);
//
//
//	int map_1[4][5] = { {1,0,1,0,0}, 
//						{1,0,1,1,1}, 
//						{1,1,1,1,1}, 
//						{1,0,0,1,0} };
//
//	int area = SquareArea(4, 5, map_1);
//	return 0;
//}
// ����һ��������������飬�ҵ����������������ĳ��ȡ�
int LongestIncreaseArray(int num,int* sub)
{
	int result = 1;
	int* dp = new int[num];
	for (int i = 0; i < num; ++i)
		dp[i] = 0;
	dp[0] = 1;
	for (int i = 1; i < num; ++i)
	{
		if (sub[i] > sub[i - 1])
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 1;
		result = std::max(result, dp[i]);
	}
	return result;
}
// ����һ��������������飬�ҵ���������������еĳ��ȡ�
int LongestIncreaseSub(int num, int* sub)
{
	int result = 1;
	int* dp = new int[num];
	for (int i = 0; i < num; ++i)
		dp[i] = 1;
	for (int i = 1; i < num; ++i)
	{
		for (int j = i - 1; j > 0; --j)
		{
			if (sub[i] > sub[j])
			{
				dp[i] = std::max( dp[i], dp[j] + 1 );
			}				
		}
		
		result = std::max(result, dp[i]);
	}
	return result;
}
int PaintHouseCosts( int n, int m, int costs[][4] )
{
	int result = INT_MAX;
	int** dp = new int* [n];
	for (int i = 0; i < n; ++i)
		dp[i] = new int[m];

	for (int i = 0; i < m; ++i)						// �� 0 ������
		dp[0][i] = costs[0][i];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m ; ++j)
		{
			int minCost = INT_MAX;
			for (int k = 0; k < m; ++k)
			{
				if (k == j)	continue;
				minCost = std::min(minCost, dp[i - 1][k]);
			}
			dp[i][j] = minCost + costs[i][j];
		}
	}

	for (int i = 0; i < m; ++i)
		result = std::min(result, dp[n - 1][i]);

	return result;

}
int BreakUpMax1(int n, int* sub)
{
	int* dp = new int[n];
	for (int i = 0; i < n; ++i)
		dp[i] = 0;
	dp[0] = sub[0];
	dp[1] = sub[1];
	for (int i = 2; i < n; ++i)
	{
		dp[i] = std::max(dp[i - 2] + sub[i], dp[i - 1]);
	}
	return dp[n-1];
}
int BreakUpMax2(int n, int* sub)
{ 
	int* dp1 = new int[n];
	for (int i = 0; i < n; ++i)
		dp1[i] = 0;
	dp1[0] = sub[0];
	dp1[1] = sub[1];
	int* dp2 = new int[n];
	for (int i = 0; i < n; ++i)
		dp2[i] = 0;
	dp2[0] = sub[0];
	dp2[1] = sub[1];
	for (int i = 2; i < n - 1; ++i)				// [0,n-2]
	{
		dp1[i] = std::max(dp1[i - 2] + sub[i], dp1[i - 1]);
	}
	for (int i = 3; i < n; ++i)					// [1,n-1]
	{
		dp2[i] = std::max(dp2[i - 2] + sub[i], dp2[i - 1]);
	}
	return std::max(dp1[n - 2], dp2[n - 1]);
}
 
int BreakUpMax(int n, int* sub)
{
	int result = 0;
	int* dp = new int[n];
	for (int i = 0; i < n; ++i)
		dp[i] = 0;
	dp[0] = sub[0];
	for (int i = 1; i < n; ++i)
	{
		int max = 0;
		for (int j = 0; j < i - 1; ++j)
			max = std::max(max, dp[j]);
		dp[i] = max + sub[i];
		result = std::max(result, dp[i]);
	}
	return result;
}
int main()
{
	int array[] = { 10,9,2,5,3,7,101,18 };
	int val = LongestIncreaseArray(sizeof(array) / sizeof(int), array);
	val = LongestIncreaseSub(sizeof(array) / sizeof(int), array);
	int color[][4] = {	{17,2,17,9}, 
						{16,16,5,1}, 
						{14,3,19,8},
						{1, 4,20,15} };
	int costs = PaintHouseCosts(4, 4, color);

	int money[] = { 2,7,9,3,1 };
	
	int moneymax = BreakUpMax(5, money);

	int money2[] = { 2,3,2 };
	int moneymax2 = BreakUpMax2(3, money2);
	return 0;
}