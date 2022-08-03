/*
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long N; int r, c;
pair<int, int> dir4[4] = {make_pair(0, 0), make_pair(1, 0), make_pair(0, 1), make_pair(1, 1)};

void searching(long long N, int Row, int Col, long long start)
{
	for (int i = 0; i < 4; i++)
	{
		if (Row + dir4[i].first == r && Col + dir4[i].second == c)
		{
			cout << start + i;
			return;
		}
	}

	if (N > 2)
	{
		searching(N / 2, Row, Col, start);
		searching(N / 2, Row + N / 2, Col, start + (N * N) / 2);
		searching(N / 2, Row, Col + N / 2, start + (N * N) / 4);
		searching(N / 2, Row + N / 2, Col + N / 2, start + (N * N) / 2 + (N * N) / 4);
	}
}

void B1074Solution()
{
	cin >> N >> r >> c;

	searching(pow(2, N), 0, 0, 0);
}

int main()
{
	B1074Solution();
}
*/