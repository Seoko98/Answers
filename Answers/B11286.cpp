/*
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void B11286Input(int& N, vector<int>& func)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		func.emplace_back(tmp);
	}
}

void B11286Solution()
{
	int N;
	vector<int> func;
	vector<int> answer;
	priority_queue<int, vector<int>, less<int>> minus_pq;
	priority_queue<int, vector<int>, greater<int>> pq;

	B11286Input(N, func);

	for (int i = 0; i < N; i++)
	{
		// 입력 받은 수가 0보다 클 때 (양수)
		if (func[i] > 0)
		{
			pq.push(func[i]);
		}
		// 입력 받은 수가 0일때
		else if (func[i] == 0)
		{
			// 음수 우선순위 큐와 양수 우선순위 큐가 비어있을 경우의 처리
			if (minus_pq.empty() && pq.empty())
			{
				answer.emplace_back(0);
				continue;
			}
			else if (minus_pq.empty())
			{
				answer.emplace_back(pq.top());
				pq.pop();
				continue;
			}
			else if (pq.empty())
			{
				answer.emplace_back(minus_pq.top());
				minus_pq.pop();
				continue;
			}

			// 큐 모두 비어있지 않다면
			if (abs(minus_pq.top()) <= pq.top())
			{
				answer.emplace_back(minus_pq.top());
				minus_pq.pop();
			}
			else
			{
				answer.emplace_back(pq.top());
				pq.pop();
			}
		}
		// 입력 받은 수가 0보다 작을 때 (음수)
		else
		{
			minus_pq.push(func[i]);
		}
	}

	int size = answer.size();
	for (int i = 0; i < size; i++)
	{
		cout << answer[i] << endl;
	}
}

int main()
{
	B11286Solution();
	return 0;
}
*/