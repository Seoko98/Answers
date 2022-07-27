#include <iostream>

using namespace std;

char map[129][129];

/*
// 분할정복으로 2차원 배열을 4등분 하면서 모두 0 혹은 1로 구성되어있는지 확인
*/

int zero = 0, one = 0;

void B2630Input(int& N)
{
	cin >> N;

	char tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
}

void divide(int N, int x, int y)
{
	bool all_Zero = true, all_One = true;

	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (map[i][j] == '0')
				all_One = false;

			else if (map[i][j] == '1')
				all_Zero = false;
		}
	}

	if (all_Zero)
	{
		zero++;
		return;
	}
	else if (all_One)
	{
		one++;
		return;
	}

	divide(N / 2, x, y);
	divide(N / 2, x, y + N / 2);
	divide(N / 2, x + N / 2, y);
	divide(N / 2, x + N / 2, y + N / 2);
}

void B2630Solution()
{
	int N;
	B2630Input(N);

	divide(N, 0, 0);

	cout << zero << endl << one;
}

/*
int main()
{
	B2630Solution();
	return 0;
}
*/