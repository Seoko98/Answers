/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[1001];
int dist[1001];
int INF = 1e9;

void B1916Input(int &start, int &end)
{
	int N, M;
	cin >> N >> M;

	int v1, v2, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> cost;
		edge[v1].emplace_back(cost, v2);
	}

	cin >> start >> end;
}
// 다익스트라 알고리즘
void diikstra(int start)
{
	priority_queue<pair<int, int>> pq;
	// 시작 지점은 비용이 0이다.
	dist[start] = 0;
	pq.push(make_pair(0, start)); // first = cost(dist), second = next vertex

	while (!pq.empty())
	{
		// 현재 경로를 받는다.
		int current = pq.top().second;
		int current_dist = -pq.top().first;
		pq.pop();
		
		// 만약 경로가 최소 경로가 아니라면
		if (current_dist > dist[current])
			continue;

		// 다음 경로를 탐색한다.
		int size = edge[current].size();
		for (int i = 0; i < size; i++)
		{
			// 다음 경로를 받는다.
			int next = edge[current][i].second;
			int next_dist = current_dist + edge[current][i].first;

			// 다음 경로까지 비용이 최소라면
			if (dist[next] > next_dist)
			{
				// 갱신하고 우선순위 큐에 넣는다.
				dist[next] = next_dist;
				pq.push(make_pair(-next_dist, next));
			}
		}
	}
}

void B1916Solution()
{
	int start, end;
	B1916Input(start, end);

	// 최소 경로 배열 초기화
	for (int i = 0; i < 1001; i++)
		dist[i] = INF;

	// 시작점을 매개 변수로 넣어 각 위치까지의 최소 경로를 찾는다.
	diikstra(start);

	// 도착점까지의 최소 경로를 출력
	cout << dist[end];
}

int main()
{
	B1916Solution();
	return 0;
}
*/