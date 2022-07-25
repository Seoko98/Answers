#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
// 1. 큐에 현재 위치를 넣고
// 2. 현 위치에서 -1, +1, x2 하는 경우를 그 위치에 방문하지 않은 경우 모두 큐에 넣는다.
// 3. 탐색 중에 목적지와 같아지면 목적지까지 간 횟수를 리턴
*/

void B1697Input(int &curr_Pos, int &destination)
{
	cin >> curr_Pos >> destination;
}

int bfs(int curr_Pos, int destination, int visited[])
{
	queue<int> que;
	que.push(curr_Pos);

	while (!que.empty())
	{
		if (curr_Pos == destination)
		{
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			int x = que.front();
			que.pop();

			if (x > 0)
			{
				if (visited[x - 1] == 0)
				{
					que.push(x - 1);
					visited[x - 1] = visited[x] + 1;
				}
			}
			if (x + 1 <= 100000)
			{
				if (visited[x + 1] == 0)
				{
					que.push(x + 1);
					visited[x + 1] = visited[x] + 1;
				}
			}
			if (x * 2 <= 100000 && x != 0)
			{
				if (visited[x * 2] == 0)
				{
					que.push(x * 2);
					visited[x * 2] = visited[x] + 1;
				}
				
			}
		}
	}

	return visited[destination];
}

/*
int main()
{
	int curr_Pos, destination;
	int visited[100001] = { 0, };

	B1697Input(curr_Pos, destination);
	
	int answer = bfs(curr_Pos, destination, visited);

	cout << answer;
	return 0;
}
*/