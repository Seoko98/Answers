/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char map[26][26];
bool visited[26][26] = {false, };
pair<int, int> dir4[4] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

void B2667Input(int &N)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
}

/*
int bfs(int start_x, int start_y, int size)
{
	queue<pair<int, int>> que;
	que.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;

	int count = 1;
	while (!que.empty())
	{
		pair<int, int> curr_Pos = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = make_pair(curr_Pos.first + dir4[i].first, curr_Pos.second + dir4[i].second);
			if (next.first >= 0 && next.first < size && next.second >= 0 && next.second < size)
			{
				if (map[next.first][next.second] == '1' && !visited[next.first][next.second])
				{
					que.push(next);
					visited[next.first][next.second] = true;
					count++;
				}
			}
		}
	}
	return count;
}


void B2667Solution()
{
	int N;
	vector<int> answer;

	B2667Input(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '1' && !visited[i][j])
				answer.emplace_back(bfs(i, j, N));
		}
	}

	int size = answer.size();
	cout << size << endl;
	
	sort(answer.begin(), answer.end());

	for (int i = 0; i < size; i++)
		cout << answer[i] << endl;
}


int main()
{
	B2667Solution();
	return 0;
}
*/