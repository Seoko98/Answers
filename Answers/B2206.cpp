/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int field[1001][1001];
bool visited[1001][1001];
pair<int, int> dir4[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };
int N, M;

void B2206Input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> field[i][j];
	}
}

bool isValid(pair<int, int> current, pair<int, int> dir4)
{
	if (current.first + dir4.first >= 0 && current.first + dir4.first <= N &&
		current.second + dir4.second >= 0 && current.second + dir4.second <= M)
		return true;
	else
		return false;
}

void bfs(int start_row, int start_col)
{
	queue<pair<int, int>> que;
	vector<pair<int, int>> tmp;
	bool isCrush = false;

	que.push(make_pair(start_row, start_col));
	visited[start_row][start_col] = true;
	field[start_row][start_col]++;

	while (!que.empty())
	{
		pair<int, int> current = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			if (isValid(current, dir4[i]))
			{
				pair<int, int> next = make_pair(current.first + dir4[i].first, current.second + dir4[i].second);

				if (!visited[next.first][next.second])
				{
					tmp.emplace_back(next);
					visited[next.first][next.second] = true;
				}
			}
		}

		if (que.empty())
		{
			bool isAllOne = true; // 상하좌우 모두 1일 때 true
			int size = tmp.size();

			for (int i = 0; i < size; i++)
			{
				if (field[tmp[i].first][tmp[i].second] == 0)
				{
					isAllOne = false;
					field[tmp[i].first][tmp[i].second] = field[current.first][current.second] + 1;
					que.push(tmp[i]);
				}
			}

			if (isAllOne && !isCrush)
			{
				for (int i = 0; i < size; i++)
				{
					field[tmp[i].first][tmp[i].second] = field[current.first][current.second] + 1;
					que.push(tmp[i]);
					isCrush = true;
				}
			}
		}
	}
}

void B2206Solution()
{
	B2206Input();
}

int main()
{
	return 0;
}
*/