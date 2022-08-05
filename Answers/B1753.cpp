/*
#include <iostream>
#include <vector>
#include <queue>

int INF = 1e9;

using namespace std;

vector<pair<int, int>> field[20001];
int dist[20001];

void B1753Input(int &V, int &K)
{
	int E;
	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		field[u].emplace_back(make_pair(w, v));
	}
}

void diikstra(int start)
{
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int curr_dist = -pq.top().first;

		pq.pop();

		if (dist[curr] < curr_dist)
			continue;

		int size = field[curr].size();
		for (int i = 0; i < size; i++)
		{
			int next = field[curr][i].second;
			int next_dist = curr_dist + field[curr][i].first;

			if (next_dist < dist[next])
			{
				dist[next] = next_dist;
				pq.push(make_pair(-next_dist, next));
			}
		}
	}
}

void B1753Solution()
{
	int V, K;
	for (int i = 0; i < 20001; i++)
		dist[i] = INF;

	B1753Input(V, K);

	diikstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] >= INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	B1753Solution();
	return 0;
}
*/