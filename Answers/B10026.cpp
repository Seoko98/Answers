/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;
char screen[101][101];
bool visited[101][101] = { false, };
pair<int, int> dir4[4] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)}; // 좌우상하

void B10026Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> screen[i][j];
		}
	}
}

// 현재 위치에서 다음 위치로 이동하려 할 때, 유효한 범위인지 알려준다.
bool isInvalidRange(pair<int, int> curr_Pos, pair<int, int> dir)
{
	if (curr_Pos.first + dir.first >= 0 && curr_Pos.first + dir.first < N &&
		curr_Pos.second + dir.second >= 0 && curr_Pos.second + dir.second < N)
	{
		return true;
	}
	else
		return false;
}
// 적록색맹이 없는 사람이 볼 때 구분하는 색의 수
void normal_bfs(int start_x, int start_y)
{
	queue<pair<int, int>> que;
	char color = screen[start_x][start_y];
	que.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;

	while (!que.empty())
	{
		pair<int, int> curr_Pos = que.front();
		que.pop();

		pair<int, int> next_Pos;
		for (int i = 0; i < 4; i++)
		{
			// 유효한 범위라면
			if (isInvalidRange(curr_Pos, dir4[i]))
			{
				next_Pos = make_pair(curr_Pos.first + dir4[i].first, curr_Pos.second + dir4[i].second);
				// 상하좌우의 색이 같은 색이고 방문하지 않았다면
				if (screen[next_Pos.first][next_Pos.second] == color &&
					!visited[next_Pos.first][next_Pos.second])
				{
					que.push(next_Pos);
					visited[next_Pos.first][next_Pos.second] = true;
				}
			}
		}
	}
}
// 적록색맹이 있는 사람이 볼 때 구분하는 색의 수
void RGBlindness_bfs(int start_x, int start_y)
{
	queue<pair<int, int>> que;
	char color = screen[start_x][start_y];
	bool isSpecificColor = false; // 처음 R이나 G를 탐색할 때 true.
	if (color == 'R' || color == 'G')
		isSpecificColor = true;

	que.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;

	while (!que.empty())
	{
		pair<int, int> curr_Pos = que.front();
		que.pop();

		pair<int, int> next_Pos;
		for (int i = 0; i < 4; i++)
		{
			// 유효한 범위라면
			if (isInvalidRange(curr_Pos, dir4[i]))
			{
				next_Pos = make_pair(curr_Pos.first + dir4[i].first, curr_Pos.second + dir4[i].second);
				// 상하좌우의 색이 같은 색이고 방문하지 않았다면
				if (screen[next_Pos.first][next_Pos.second] == color &&
					!visited[next_Pos.first][next_Pos.second])
				{
					que.push(next_Pos);
					visited[next_Pos.first][next_Pos.second] = true;
				}
				// 색맹에 영향을 주는 색이라면
				else if (isSpecificColor)
				{
					if(screen[next_Pos.first][next_Pos.second] != 'B' &&
						!visited[next_Pos.first][next_Pos.second])
					{
						que.push(next_Pos);
						visited[next_Pos.first][next_Pos.second] = true;
					}
				}
			}
		}
	}
}

void B10026Solution()
{
	B10026Input();
	int normal_count = 0, rgblindness_count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				normal_bfs(i, j);
				normal_count++;
			}
		}
	}

	memset(visited, false, sizeof(bool) * 10000);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				RGBlindness_bfs(i, j);
				rgblindness_count++;
			}
		}
	}

	cout << normal_count << ' ' << rgblindness_count;
}

int main()
{
	B10026Solution();
	return 0;
}
*/