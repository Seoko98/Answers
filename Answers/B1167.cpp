/*
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[100001]; // 0 = v1, 1 = v2, 2 = distance
bool visited[100001] = { false, };
int max_distance = 0;
int max_vertex = 1;

void B1167Input()
{
	int N, v1, v2, distance;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> v1;
		while (true)
		{
			cin >> v2;
			if (v2 == -1)
				break;
			cin >> distance;
			tree[v1].emplace_back(make_pair(v2, distance));
		}
	}
}

void dfs(int start_vertex, int curr_distance)
{
	visited[start_vertex] = true;
	int dis = curr_distance;

	int size = tree[start_vertex].size();
	
	for (int i = 0; i < size; i++)
	{
		int next_vertex = tree[start_vertex][i].first;
		int next_dis = dis + tree[start_vertex][i].second;

		if (!visited[next_vertex])
		{
			//cout << "start = " << start_vertex << " next = " << next_vertex << " distance = " << next_dis << endl;
			if (next_dis > max_distance)
			{
				max_distance = next_dis;
				max_vertex = next_vertex;
			}
			dfs(next_vertex, next_dis);
		}
	}
}


void B1167Solution()
{
	B1167Input();
	dfs(1, 0);
	memset(visited, false, sizeof(bool) * 100001);
	dfs(max_vertex, 0);

	cout << max_distance;
}

int main()
{
	B1167Solution();
}
*/