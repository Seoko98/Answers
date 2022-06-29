#include "stds.h"

// N1 = people_Num, N2 = party_Num, N3 = known_Num
void input_nums(int& N1, int& N2, int& N3, vector<int>& knowns, vector<vector<int>>& party_Info)
{
	cin >> N1 >> N2 >> N3;

	// 진실을 아는 사람이 있다면
	if (N3 > 0)
	{
		// 아는 사람 수 만큼 knowns에 추가.
		for (int i = 0; i < N3; i++)
		{
			int tmp = 0;
			cin >> tmp;
			knowns.emplace_back(tmp);
		}
	}

	vector<int> p_Number; // 사람 번호

	for (int j = 0; j < N2; j++)
	{
		int p = 0; // 사람 수
		cin >> p;

		for (int k = 0; k < p; k++)
		{
			int n = 0; // 번호
			cin >> n;

			p_Number.emplace_back(n);
		}

		party_Info.emplace_back(p_Number);
		p_Number.clear();
	}
}

int lier()
{
	int people_Num, party_Num, known_Num, count = 0; // 사람 수, 파티 수, 진실을 아는 사람 수, 말할 수 있는 파티 수
	vector<int> knowns;					  // 진실을 아는 사람들의 번호
	vector<vector<int>> party_Info;				  // 각 파티의 정보

	input_nums(people_Num, party_Num, known_Num, knowns, party_Info);

	bool check[51] = { false, };		// 진실을 아는 사람의 번호 확인용

	// 진실을 아는 사람이 있다면
	if (known_Num > 0)
	{
		// 그 번호의 사람이 진실을 아는 것으로 한다.
		for (int i = 0; i < known_Num; i++)
		{
			check[knowns[i]] = true;
		}
	}

	// 진실을 아는 사람이 늘어나는 전처리 과정
	for (int i = 0; i < party_Num; i++)
	{
		int len = party_Info[i].size();
		// 진실을 아는 사람이 늘었을 경우 처음부터 다시 탐색하기 위한 flag
		bool flag = false;

		for (int j = 0; j < len; j++)
		{
			// 현재 번호의 사람이 진실을 안다면
			if (check[party_Info[i][j]] == true)
			{
				// 이 파티의 모든 사람이 진실을 알게 된다.
				for (int k = 0; k < len; k++)
				{
					// 진실을 아는 사람이 늘었다면
					if (check[party_Info[i][k]] == false)
						flag = true;

					check[party_Info[i][k]] = true;
				}
			}
		}

		if (flag)
			i = -1;
	}

	// 말할 수 있는 파티 수 구하기 (전처리 과정과 거의 비슷하다)
	for (int i = 0; i < party_Num; i++)
	{
		int len = party_Info[i].size();
		count++;

		for (int j = 0; j < len; j++)
		{
			if (check[party_Info[i][j]] == true)
			{
				count--;
				break;
			}
		}
	}
	return count;
}