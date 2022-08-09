/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int house[1001][3];
int memo[1001][3];

void B1149Input(int &N)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> house[i][j];
		}
	}
}

void painting(int N)
{
	memo[0][0] = house[0][0];
	memo[0][1] = house[0][1];
	memo[0][2] = house[0][2];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int cost = house[i][j];

			switch (j)
			{
			case 0:
				memo[i][j] = min(cost + memo[i - 1][1], cost + memo[i - 1][2]);
				break;
			case 1:
				memo[i][j] = min(cost + memo[i - 1][0], cost + memo[i - 1][2]);
				break;
			case 2:
				memo[i][j] = min(cost + memo[i - 1][0], cost + memo[i - 1][1]);
				break;
			}
			//cout << "i = " << i << " j = " << j << " memo[i][j] = " << memo[i][j] << endl;
		}
	}
}

void B1149Solution()
{
	int N;
	int minCost;

	B1149Input(N);
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 3; j++)
			memo[i][j] = 1000001;
	}
	
	painting(N);
	minCost = min(memo[N - 1][0], memo[N - 1][1]);
	minCost = min(minCost, memo[N - 1][2]);

	cout << minCost;
}

int main()
{
	B1149Solution();
	return 0;
}
*/