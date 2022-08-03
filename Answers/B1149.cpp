#include <iostream>
#include <vector>

using namespace std;

void B1149Input(int &N, int house[][3])
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

int painting(int N, int house[][3], int firstColor)
{
	int cost = house[0][firstColor];
	int prev_Color = firstColor;

	for (int i = 1; i < N; i++)
	{
		switch (prev_Color)
		{
		case 0:
		{
			if (house[i][1] > house[i][2])
			{
				cost += house[i][2];
				prev_Color = 2;
			}
			else
			{
				cost += house[i][1];
				prev_Color = 1;
			}
			break;
		}
		case 1:
		{
			if (house[i][0] > house[i][2])
			{
				cost += house[i][2];
				prev_Color = 2;
			}
			else
			{
				cost += house[i][0];
				prev_Color = 0;
			}
			break;
		}
		case 2:
		{
			if (house[i][0] > house[i][1])
			{
				cost += house[i][1];
				prev_Color = 1;
			}
			else
			{
				cost += house[i][0];
				prev_Color = 0;
			}
			break;
		}
		}
	}
	cout << cost << endl;
	
	return cost;
}

void B1149Solution()
{
	int N;
	int house[1001][3];
	int minCost;

	B1149Input(N, house);

	// 첫 집을 각 색깔로 칠했을 때의 비용을 비교해 최소 값을 구한다.
	minCost = painting(N, house, 0);
	minCost = min(minCost, painting(N, house, 1));
	minCost = min(minCost, painting(N, house, 2));

	cout << minCost;
}
/*
int main()
{
	B1149Solution();
	return 0;
}
*/