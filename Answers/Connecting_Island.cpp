#include "stds.h"

////////////
// GLOBAL //
////////////
int INF = 100000000;

int dijkstra(int start, vector <pair<int, int>> lines[], int cost[])
{
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;	// heap structure
	pq.push(make_pair(start, 0));

	// Use a queue because it is processed in close order
	while (!pq.empty())
	{
		int current = pq.top().first;
		// Make a short one negative so that it comes first.
		int distance = -pq.top().second;
		pq.pop();

		// Skip when distance is not shortest
		if (cost[current] < distance)
			continue;

		for (int i = 0; i < lines[current].size(); i++)
		{
			// Close node of current node
			int next = lines[current][i].first;
			// Cost that pass current node to close node
			int nextDistance = distance + lines[current][i].second;

			// If cheaper than existing cost, change it
			if (nextDistance < cost[next])
			{
				cost[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}

	int len_costs = lines->size();
	int shortest_distance = 0;

	for (int i = 0; i < 4; i++)
	{
		cout << cost[i] << ' ';
		shortest_distance += cost[i];
	}

	return shortest_distance;
}

int solution(int n, vector<vector<int>> costs)
{
	vector<pair<int, int>> lines[5501];
	int cost[5501];

	int len_costs = costs.size();

	// Generally, cost is infinity when it is not connected
	for (int i = 0; i < len_costs; i++)
	{
		cost[i] = INF;
	}

	for (int i = 0; i < len_costs; i++)
	{
		int start = costs[i][0];
		int end = costs[i][1];
		int distance = costs[i][2];

		lines[start].emplace_back(make_pair(end, distance));
	}

	int answer = dijkstra(costs[0][0], lines, cost);
	
	return answer;
} 

int main()
{
	// 1, 2번째 : 첫 번째 번호와 두 번째 번호를 이음. 3번째 : 이을 때의 비용
	vector<vector<int>> islands = { {0, 1, 5}, {0, 2, 2}, {1, 2, 9}, {1, 3, 1}, {2, 3, 8} };
	int n = 4;
	
	cout << solution(n, islands);
}