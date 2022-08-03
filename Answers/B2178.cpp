/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[101][101];
int visited[101][101] = {0, };

void B2178Input(int &N, int &M)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
}
// 현재 위치에서 상하좌우를 검색해 1이고 방문하지 않았다면 탐색
vector<pair<int, int>> find_next(pair<int, int> current, int width, int height)
{
	vector<pair<int, int>> tmp;

	if (current.first - 1 >= 0 && !visited[current.first - 1][current.second] && map[current.first - 1][current.second] == '1')
	{
		tmp.emplace_back(make_pair(current.first - 1, current.second));
		visited[current.first - 1][current.second] = visited[current.first][current.second] + 1;
	}
	if (current.first + 1 < width && !visited[current.first + 1][current.second] && map[current.first + 1][current.second] == '1')
	{
		tmp.emplace_back(make_pair(current.first + 1, current.second));
		visited[current.first + 1][current.second] = visited[current.first][current.second] + 1;
	}
	if (current.second - 1 >= 0 && !visited[current.first][current.second - 1] && map[current.first][current.second - 1] == '1')
	{
		tmp.emplace_back(make_pair(current.first, current.second - 1));
		visited[current.first][current.second - 1] = visited[current.first][current.second] + 1;
	}
	if (current.second + 1 < height && !visited[current.first][current.second + 1] && map[current.first][current.second + 1] == '1')
	{
		tmp.emplace_back(make_pair(current.first, current.second + 1));
		visited[current.first][current.second + 1] = visited[current.first][current.second] + 1;
	}

	return tmp;
}

int bfs(int destination_X, int destination_Y)
{
	queue<pair<int, int>> que;
	vector<pair<int, int>> next_Pos;

	que.push(make_pair(0, 0));
	visited[0][0] = 1;

	while (!que.empty())
	{
		pair<int, int> current_Pos = que.front();
		que.pop();
		next_Pos = find_next(current_Pos, destination_X, destination_Y);

		for (int i = 0; i < next_Pos.size(); i++)
		{
			que.push(next_Pos[i]);	
		}
		next_Pos.clear();
	}

	return visited[destination_X - 1][destination_Y - 1];
}

void B2178Solution()
{
	int N, M;
	B2178Input(N, M);

	int answer = bfs(N, M);

	cout << answer;
}


int main()
{
	B2178Solution();
	return 0;
}
*/