/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 내부 공기와 접촉은 카운트하지 않는 걸 고려하지 않았다. 다시 해야됨

int N, M; // N = col, M = row
int field[101][101];
bool visited[101][101] = { false, };
pair<int, int> dir4[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) }; // 상하좌우

void B2638Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> field[i][j];
		}
	}
}

// 유효 범위인지 판단한다.
bool isValid(pair<int, int> coord)
{
	if (coord.first >= 0 && coord.first < M &&
		coord.second >= 0 && coord.second < N)
		return true;

	return false;
}


void bfs(int start_row, int start_col)
{
	queue<pair<int, int>> que;
	vector<pair<int, int>> melting;
	vector<pair<int, int>> freezed;
	que.push(make_pair(start_row, start_col));
	visited[start_row][start_col] = true;

	while (!que.empty())
	{
		pair<int, int> current = que.front();
		int melt_count = 0;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = make_pair(current.first + dir4[i].first, current.second + dir4[i].second);
			// 다음 좌표가 유효 범위이고
			if (isValid(next))
			{
				// 값이 0이면
				if (field[next.first][next.second] == 0)
					melt_count++;
				// 값이 1이면
				else
				{
					if (!visited[next.first][next.second])
					{
						que.push(next);
						visited[next.first][next.second] = true;
					}
				}
			}
		}

		// 치즈가 녹는지 안녹는지 처리
		if (melt_count > 1)
			melting.emplace_back(current);
		else
			freezed.emplace_back(current);

		// 치즈 전체를 다 탐색했다면 (큐가 빈다면)
		// 치즈가 녹고 다음에 녹는 치즈를 찾는다.
		if (que.empty())
		{
			int melt_size = melting.size();
			int freezed_size = freezed.size();
		}
	}
}

void B2638Solution()
{
	B2638Input();
}

int main()
{
	B2638Solution();
}
*/