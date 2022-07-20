#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void B1263input(vector<pair<int, int>> &schedule)
{
	int N, T, S;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> T >> S;
		
		schedule.emplace_back(make_pair(T, S));
	}
}

// 제한 시간(S) 오름차순 정렬
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int B1263solution(vector<pair<int, int>> schedule)
{
	sort(schedule.begin(), schedule.end(), compare);

	// first = 소요 시간(T), second = 제한 시간(S)
	int start_Time = schedule[0].second - schedule[0].first; // 첫 스케쥴을 최대한 늦게 시작한다.
	int current_Time = start_Time;
	int size = schedule.size();

	// 스케쥴 진행
	for (int i = 0; i < size; i++)
	{
		// 0시에 시작해도 스케줄을 끝내지 못한다면 -1 출력.
		if (start_Time < 0)
		{
			start_Time = -1;
			break;
		}

		current_Time += schedule[i].first;

		// 정해진 시간 내에 해결하지 못했다면
		if (current_Time > schedule[i].second)
		{
			// 첫 스케쥴 시작 시간을 한 시간 앞당겨 다시 시작한다.
			start_Time--;
			current_Time = start_Time;
			i = -1;
			continue;
		}
	}

	return start_Time;
}

/*
int main()
{
	vector<pair<int, int>> schedule;

	B1263input(schedule);
	
	cout << B1263solution(schedule);
}
*/