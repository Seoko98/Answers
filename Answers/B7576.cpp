/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; // N = 열, M = 행
int box[1000][1000];
bool visited[1000][1000] = { false, };
pair<int, int> dir4[4] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)}; // 상하좌우
int zero_count = 0;	// 박스 내 0의 개수

void B7576Input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> box[i][j];
		}
	}
}

int bfs(vector<pair<int, int>> start)
{
	int answer = 0;
	queue<pair<int, int>> que;

	int size = start.size();
	for (int i = 0; i < size; i++)
	{
		que.push(make_pair(start[i].first, start[i].second));
		visited[start[i].first][start[i].second] = true;
	}

	while (!que.empty())
	{
		pair<int, int> curr_Pos = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next_Pos = make_pair(curr_Pos.first + dir4[i].first, curr_Pos.second + dir4[i].second);

			// 유효 범위 이내이며 방문하지 않았고 토마토가 들어있다면
			if (next_Pos.first >= 0 && next_Pos.first < M &&
				next_Pos.second >= 0 && next_Pos.second < N &&
				!visited[next_Pos.first][next_Pos.second] &&
				box[next_Pos.first][next_Pos.second] == 0)
			{
				que.push(next_Pos);
				visited[next_Pos.first][next_Pos.second] = true;
				box[next_Pos.first][next_Pos.second] = box[curr_Pos.first][curr_Pos.second] + 1;
				zero_count--;

				if (box[next_Pos.first][next_Pos.second] > answer)
					answer = box[next_Pos.first][next_Pos.second];
			}
		}
	}

	return answer - 1;
}

void B7576Solution()
{
	vector<pair<int, int>> start;
	int count = 0;
	B7576Input();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (box[i][j] == 0)
				zero_count++;
			else if (box[i][j] == 1)
				start.emplace_back(make_pair(i, j));
		}
	}

	if (zero_count > 0)
		count = bfs(start);
	
	if (zero_count > 0)
		count = -1;

	cout << count;
}

int main()
{
	B7576Solution();
	return 0;
}
*/