#include <iostream>
#include <vector>
#include <queue>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void input(priority_queue<int, vector<int>, greater<int>> &pr, vector<int> &answer)
{
	int tmp = 0;

	//scanf("%d", &tmp);
	
	if (tmp == 0)
	{
		if (pr.size() == 0)
		{
			answer.emplace_back(0);
			return;
		}
		
		answer.emplace_back(pr.top());
		pr.pop();
		return;
	}

	pr.push(tmp);
}

void B1927Solution()
{
	int N;
	priority_queue<int, vector<int>, greater<int>> pr_Que;
	vector<int> answer;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		input(pr_Que, answer);
	}

	int size = answer.size();
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", answer[i]);
	}
}

/*
int main()
{
	B1927Solution();
}
*/