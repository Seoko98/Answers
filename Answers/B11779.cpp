/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[1001];
vector<int> path[1001];
int dist[1001];

void B11779Input(int &n, int &start, int &end)
{
	int m;
	cin >> n >> m;

	int v1, v2, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> cost;
		edge[v1].emplace_back(make_pair(cost, v2));
	}

	cin >> start >> end;
}

void diikstra(int start)
{
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	path[start].emplace_back(start);
	pq.push(make_pair(dist[start], start));

	while (!pq.empty())
	{
		int current = pq.top().second;
		int currentDist = -pq.top().first;
		pq.pop();

		if (dist[current] < currentDist)
			continue;

		for (int i = 0; i < edge[current].size(); i++)
		{
			int next = edge[current][i].second;
			int nextDist = edge[current][i].first + currentDist;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				path[next].clear();
				for (int i = 0; i < path[current].size(); i++)
					path[next].emplace_back(path[current][i]);
				path[next].emplace_back(next);
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

void B11779Solution()
{
	int n = 0, start = 0, end = 0;
	const int INF = 1e9;

	B11779Input(n, start, end);
	for (int i = 0; i < 1001; i++)
		dist[i] = INF;

	diikstra(start);

	cout << dist[end] << endl;
	cout << path[end].size() << endl;
	for (int i = 0; i < path[end].size(); i++)
		cout << path[end][i] << ' ';
}

int main()
{
	B11779Solution();
	return 0;
}
*/