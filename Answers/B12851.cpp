#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[100001] = { 0, };
int endVisitCount = 0;

void B12851Input(int &start, int &end)
{
	cin >> start >> end;
}

int bfs(int start, int end)
{
	queue<pair<int, int>> que; // first : current position, second : time
	int min = 100001;

	que.push(make_pair(start, 0));

	while (!que.empty())
	{
		int currentPos = que.front().first;
		int currentTime = que.front().second;
		que.pop();

		visited[currentPos] = 1;

		if (currentTime > min)
			break;

		if (currentPos == end)
		{
			min = currentTime;
			endVisitCount++;
			continue;
		}

		// X + 1
		if (currentPos + 1 < 100001 && visited[currentPos + 1] == 0)
		{
			que.push(make_pair(currentPos + 1, currentTime + 1));
		}
		// X - 1
		if (currentPos - 1 >= 0 && visited[currentPos - 1] == 0)
		{
			que.push(make_pair(currentPos - 1, currentTime + 1));
		}
		// 2 * X
		if (2 * currentPos < 100001 && visited[2 * currentPos] == 0)
		{
			que.push(make_pair(2 * currentPos, currentTime + 1));
		}
	}

	return min;
}

void B12851Solution()
{
	int start, end;
	B12851Input(start, end);

	for (int i = 0; i < 100001; i++)
	{
		visited[i] = 0;
	}

	int minimum = bfs(start, end);

	cout << minimum << endl;
	cout << endVisitCount;
}

int main()
{
	B12851Solution();
	return 0;
}
