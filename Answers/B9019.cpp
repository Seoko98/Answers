#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
/*
// 시간 초과 발생. 최적화 필요

vector<string> answer;
bool visited[10001] = { false, };

void B9019Input(int &A, int &B)
{
	cin >> A >> B;
}

int D(int A)
{
	int tmp = A * 2;

	if (tmp >= 10000)
		tmp = tmp % 10000;

	return tmp;
}

int S(int A)
{
	int tmp = A - 1;

	if (tmp <= 0)
		tmp = 9999;

	return tmp;
}

int L(int A)
{
	int tmp = A;
	int left = A / 1000;
	int remain = A % 1000;

	tmp = remain * 10 + left;

	return tmp;
}

int R(int A)
{
	int tmp = A;
	int right = A % 10;
	int remain = A / 10;
	
	tmp = right * 1000 + remain;
	
	return tmp;
}

void bfs(int A, int B)
{
	queue<int> que;
	map<int, string> str_map;
	que.push(A);
	visited[A] = true;

	while (!que.empty())
	{
		int curr_Register = que.front();
		if (curr_Register == B)
		{
			answer.emplace_back(str_map[curr_Register]);
			return;
		}

		que.pop();

		int next_Register;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
			{
				next_Register = D(curr_Register);
				if (!visited[next_Register])
				{
					str_map[next_Register] = str_map[curr_Register] + 'D';

					if (next_Register == B)
					{
						answer.emplace_back(str_map[curr_Register]);
						return;
					}

					visited[next_Register] = true;
					que.push(next_Register);
				}
				break;
			}
			case 1:
			{
				next_Register = S(curr_Register);
				if (!visited[next_Register])
				{
					str_map[next_Register] = str_map[curr_Register] + 'S';

					if (next_Register == B)
					{
						answer.emplace_back(str_map[curr_Register]);
						return;
					}

					visited[next_Register] = true;
					que.push(next_Register);
				}
				break;
			}
			case 2:
			{
				next_Register = L(curr_Register);
				if (!visited[next_Register])
				{
					str_map[next_Register] = str_map[curr_Register] + 'L';

					if (next_Register == B)
					{
						answer.emplace_back(str_map[curr_Register]);
						return;
					}

					visited[next_Register] = true;
					que.push(next_Register);
				}
				break;
			}
			case 3:
			{
				next_Register = R(curr_Register);
				if (!visited[next_Register])
				{
					str_map[next_Register] = str_map[curr_Register] + 'R';

					if (next_Register == B)
					{
						answer.emplace_back(str_map[curr_Register]);
						return;
					}

					visited[next_Register] = true;
					que.push(next_Register);
				}
				break;
			}
			}
		}
	}
}

void B9019Solution()
{
	int T;
	int A, B;
	cin >> T;

	while (T--)
	{
		B9019Input(A, B);
		bfs(A, B);
		memset(visited, false, sizeof(bool) * 10000);
	}

	for(int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}

int main()
{
	B9019Solution();

	return 0;
}
*/