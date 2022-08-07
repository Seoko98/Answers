/*
#include <iostream>
#include <vector>
#include <tuple>

const int INF = 1e9;

using namespace std;

vector<tuple<int, int, int>> field;
vector<string> answer;
int dist[501];
int N, M, W;

void B1865Input()
{
	cin >> N >> M >> W;

	int v1, v2, cost;
	// 도로 입력 (방향이 없다)
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> cost;
		field.emplace_back(make_tuple(v1, v2, cost));
		field.emplace_back(make_tuple(v2, v1, cost));
	}
	// 웜홀 입력 (방향이 있다)
	for (int i = 0; i < W; i++)
	{
		cin >> v1 >> v2 >> cost;
		field.emplace_back(make_tuple(v1, v2, -cost));
	}
}

void bellman_ford(int start)
{
	dist[start] = 0;
	int size = field.size();

	// 정점의 개수 - 1(N - 1) 만큼 반복 -> 음의 사이클 방지 목적
	for (int i = 1; i <= N - 1; i++)
	{
		// 간선의 개수(M) 만큼 반복
		for (int j = 0; j < size; j++)
		{
			int curr_start = get<0>(field[j]);
			int curr_end = get<1>(field[j]);
			int curr_dist = get<2>(field[j]);
			
			// 현 정점까지의 거리(비용)가 무한대이면 패스. 한번이라도 계산된 정점이면 무한대가 아닐것이다.
			// -> 바로 아래 구문을 빼면 정답처리가 된다. 왜인지 모르겠다.
			if (dist[curr_start] == INF)
				continue;
			// 다음 정점까지의 최소 거리를 찾았다면 갱신해준다.
			if (dist[curr_end] > dist[curr_start] + curr_dist)
				dist[curr_end] = dist[curr_start] + curr_dist;
		}
	}

	// 음의 사이클이 존재하는지 확인한다. -> N - 1만큼 반복한 이후로 더 반복하면 음의 사이클 발생
	// -> 존재한다면 무조건 시간이 줄어든 채로 도착할 수 있기 때문이다.
	for (int i = 0; i < size; i++)
	{
		int curr_start = get<0>(field[i]);
		int curr_end = get<1>(field[i]);
		int curr_dist = get<2>(field[i]);

		if (dist[curr_start] == INF)
			continue;
	
		// 최소 거리가 갱신됐다면
		if (dist[curr_end] > dist[curr_start] + curr_dist)
		{
			// 음의 사이클이 존재하는 것이다.
			answer.emplace_back("YES");
			return;
		}
	}
	
	answer.emplace_back("NO");
	return;
}

void B1865Solution()
{
	int T;
	cin >> T;
	while (T--)
	{
		// 거리 정보 초기화
		for (int i = 0; i < 501; i++)
		{
			dist[i] = INF;
		}

		// 간선 정보를 입력해준다.
		B1865Input();
		bellman_ford(get<0>(field[0]));

		// 초기화
		field.clear();
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
	
	return;
}

int main()
{
	B1865Solution();
	return 0;
}
*/