/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int N, M, H;
int zero_count = 0;
int box[100][100][100];
bool visited[100][100][100] = { false, };

pair<int, int> dir_xy[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };
int dir_z[2] = { -1, 1 };

void B7569Input(int& N, int& M, int& H)
{
	cin >> N >> M >> H;

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> box[i][j][k];
			}
		}
	}
}

void output()
{
	cout << endl;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << box[i][j][k] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}

int bfs(vector<tuple<int, int, int>> tup)
{
	queue<pair<int, int>> que_xy;
	queue<int> que_z;
	vector<pair<int, int>> tmp_xy;
	vector<int> tmp_z;
	
	int count = 0;

	int size = tup.size();
	for (int i = 0; i < size; i++)
	{
		que_xy.push(make_pair(get<0>(tup[i]), get<1>(tup[i])));
		que_z.push(get<2>(tup[i]));
	}

	while (!que_xy.empty() && !que_z.empty())
	{
		pair<int, int> curr_Pos_xy = make_pair(que_xy.front().first, que_xy.front().second);
		int curr_Pos_z = que_z.front();
		que_xy.pop();
		que_z.pop();

		for (int i = 0; i < 6; i++)
		{
			pair<int, int> next_Pos_xy;
			int next_Pos_z;
			// xy ¹æÇâ Å½»ö
			if (i < 4)
			{
				next_Pos_xy = make_pair(curr_Pos_xy.first + dir_xy[i].first,
					curr_Pos_xy.second + dir_xy[i].second);
				next_Pos_z = curr_Pos_z;

				if (next_Pos_xy.first >= 0 && next_Pos_xy.first < M &&
					next_Pos_xy.second >= 0 && next_Pos_xy.second < N &&
					box[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z] == 0 &&
					!visited[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z])
				{
					box[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z] = 
						box[curr_Pos_xy.first][curr_Pos_xy.second][curr_Pos_z] + 1;

					count = max(box[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z], count);
					que_xy.push(make_pair(next_Pos_xy.first, next_Pos_xy.second));
					que_z.push(next_Pos_z);

					visited[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z] = true;
					zero_count--;
				}
			}
			// z ¹æÇâ Å½»ö
			else
			{
				next_Pos_xy = make_pair(curr_Pos_xy.first, curr_Pos_xy.second);
				next_Pos_z = curr_Pos_z + dir_z[i - 4];

				if (next_Pos_z >= 0 && next_Pos_z < H &&
					box[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z] == 0 &&
					!visited[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z])
				{
					box[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z] = 
						box[curr_Pos_xy.first][curr_Pos_xy.second][curr_Pos_z] + 1;
					count = max(box[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z], count);

					que_xy.push(make_pair(next_Pos_xy.first, next_Pos_xy.second));
					que_z.push(next_Pos_z);

					visited[next_Pos_xy.first][next_Pos_xy.second][next_Pos_z] = true;
					zero_count--;
				}
			}
		}
	}

	return count - 1;
}

int getZero()
{
	int count = 0;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (box[i][j][k] == 0)
					count++;
			}
		}
	}

	return count;
}

void B7569Solution()
{
	vector<tuple<int, int, int>> tup;
	int count = 0;
	B7569Input(N, M, H);

	zero_count = getZero();

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (box[i][j][k] == 1 && !visited[i][j][k])
				{
					tup.emplace_back(make_tuple(i, j, k));
					visited[i][j][k] = true;
				}
			}
		}
	}

	if(zero_count > 0)
		count = bfs(tup);

	if (zero_count > 0)
		count = -1;
	
	cout << count;
}

int main()
{
	B7569Solution();
	return 0;
}
*/