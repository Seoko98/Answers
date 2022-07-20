#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void B1946Input(vector<pair<int, int>> &workers)
{
	int N;

	cin >> N;

	int document_Grade, interview_Grade;
	for (int i = 0; i < N; i++)
	{
		cin >> document_Grade >> interview_Grade;
		workers.emplace_back(make_pair(document_Grade, interview_Grade));
	}
}
// 서류 성적을 기준으로 오름차순 정렬
bool compareDocument(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}
// 면접 성적을 기준으로 오름차순 정렬
bool compareInterview(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

void B1946Solution()
{
	vector<pair<int, int>> workers;
	vector<int> answers;
	int T, hireCount, size, maxInterview;
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		hireCount = 1; // 서류 성적 1등은 무조건 채용되므로 1부터 시작.

		B1946Input(workers);

		// 서류 성적을 기준으로 오름차순 정렬
		sort(workers.begin(), workers.end(), compareDocument);

		maxInterview = workers[0].second;
		size = workers.size();

		for (int j = 1; j < size; j++)
		{
			// 타 지원자의 최고 면접 성적보다 낮다면 탈락
			if (workers[j].second > maxInterview) 
			{}
			// 타 지원자의 최고 면접 성적보다 좋다면 채용
			else
			{
				maxInterview = workers[j].second;
				hireCount++;
			}
		}
	

		// 테스트 케이스 종료 시 초기화
		workers.clear();

		answers.emplace_back(hireCount);
	}

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << endl;
	}
}
/*
int main()
{
	B1946Solution();
}
*/