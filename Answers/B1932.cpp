/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangle[500][500];
int memo[500][500];

void B1932Input(int &N)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}
}

void tree(int N)
{
	memo[1][0] = triangle[1][0] + triangle[0][0];
	memo[1][1] = triangle[1][1] + triangle[0][0];

	for (int i = 2; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				memo[i][j] = triangle[i][j] + memo[i - 1][j];
			}
			else if (j == i)
			{
				memo[i][j] = triangle[i][j] + memo[i - 1][j - 1];
			}
			else
			{
				memo[i][j] = max(triangle[i][j] + memo[i - 1][j - 1], triangle[i][j] + memo[i - 1][j]);
			}
			//µð¹ö±×
			//cout << "memo[" << i << "][" << j << "] = " << memo[i][j] << endl;
		}
	}
}

void B1932Solution()
{
	int N;
	int sum = 0;

	B1932Input(N);

	int answer = 0;

	tree(N);

	for (int i = 0; i < N; i++)
	{
		answer = max(answer, memo[N - 1][i]);
	}
	
	if (N == 1)
		answer = triangle[0][0];

	cout << answer;
}

int main()
{
	B1932Solution();
}
*/