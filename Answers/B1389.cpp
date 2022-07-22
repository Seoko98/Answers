#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

/*
// 기존 bfs는 큐에 바로 넣어서 돌려주는 반면
// 이 알고리즘은 탐색할 다음 트리를 벡터에 다 받은 후
// 큐가 완전히 비어지면 벡터 내 트리를 큐에 넣어준다.
*/

vector<int> tree[101];

void B1389Input(int &N, int &M)
{
	cin >> N >> M;

	int tmp1, tmp2;

	for (int i = 0; i < M; i++)
	{
		cin >> tmp1 >> tmp2;

		tree[tmp1].emplace_back(tmp2);
		tree[tmp2].emplace_back(tmp1);
	}
}

int bfs(int start, bool visited[])
{
	vector<int> tmp;
	queue<int> que;
	int stage = 1;
	int Kevin_Count = 0;

	que.push(start);
	visited[start] = true;

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		int currentSize = tree[current].size();
		for (int i = 0; i < currentSize; i++)
		{
			int next = tree[current][i];
			// 방문하지 않았다면
			if (!visited[next])
			{
				// 벡터에 다음 트리의 정보를 넣고 케빈 베이컨 수를 단계만큼 증가시킨다.
				tmp.emplace_back(next);
				visited[next] = true;
				Kevin_Count += stage;
			}
		}
		// 큐가 비었다면
		if (que.empty())
		{
			int size = tmp.size();
			// 벡터 내 다음 트리 정보를 큐에 전달한다.
			for (int i = 0; i < size; i++)
				que.push(tmp[i]);
			
			stage++;
			tmp.clear();
		}
	}

	return Kevin_Count;
}

void B1389Solution()
{
	int N, M;
	vector<int> answers;
	bool visited[101] = { false, };

	B1389Input(N, M);

	for (int i = 1; i <= N; i++)
	{
		answers.emplace_back(bfs(i, visited));
		memset(visited, false, sizeof(bool) * 101);
	}

	int min = min_element(answers.begin(), answers.end()) - answers.begin();

	cout <<  min + 1;
}
/*
int main()
{
	B1389Solution();
	return 0;
}
*/