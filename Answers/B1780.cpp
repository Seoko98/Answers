#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// bfs로 풀면 무려 O(n^3) ~ O(n^4)이나 걸린다. 따라서 분할 정복해야함. 
// 2차원 배열 전체를 탐색 후 9조각으로 나눠 각 조각을 탐색하는 것을 반복한다(재귀).
// 재귀 함수 사용시 벡터를 사용하면 시간이 굉장히 오래 걸리므로 배열을 사용하도록 한다.

int Minus = 0, Zero = 0, One = 0;
int map[2188][2188];

void B1780Input(int &N)
{
	cin >> N;

	int num;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			map[i][j] = num;
		}
	}
}

void B1780Solution(int N, int x, int y)
{
	bool all_Minus = true, all_Zero = true, all_One = true;

	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (map[i][j] == -1)
			{
				all_Zero = false;
				all_One = false;
			}
			else if (map[i][j] == 0)
			{
				all_Minus = false;
				all_One = false;
			}
			else
			{
				all_Minus = false;
				all_Zero = false;
			}
		}
	}

	if (all_Minus)
	{
		Minus++;
		return;
	}
	if (all_Zero)
	{
		Zero++;
		return;
	}
	if (all_One)
	{
		One++;
		return;
	}

	B1780Solution(N / 3, x, y);
	B1780Solution(N / 3, x + N / 3, y);
	B1780Solution(N / 3, x + N * 2 / 3, y);
	B1780Solution(N / 3, x, y + N / 3);
	B1780Solution(N / 3, x, y + N * 2 / 3);
	B1780Solution(N / 3, x + N / 3, y + N / 3);
	B1780Solution(N / 3, x + N * 2 / 3, y + N / 3);
	B1780Solution(N / 3, x + N / 3, y + N * 2 / 3);
	B1780Solution(N / 3, x + N * 2 / 3, y + N * 2 / 3);
}

/*
int main()
{
	int N, sum = 0;

	B1780Input(N);
	B1780Solution(N, 0, 0);

	cout << Minus << endl;
	cout << Zero << endl;
	cout << One;

	return 0;
}
*/