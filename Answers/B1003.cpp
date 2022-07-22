#include <iostream>
#include <vector>

using namespace std;

pair<int, int> fibo(int N)
{
	pair<int, int> zero = make_pair(1, 0);
	pair<int, int> one = make_pair(0, 1);
	vector<pair<int, int>> tmp;

	tmp.emplace_back(zero);
	tmp.emplace_back(one);

	if (N > 1)
	{
		for (int i = 0; i < N - 1; i++)
		{
			tmp.emplace_back(make_pair(tmp[i].first + tmp[i + 1].first, tmp[i].second + tmp[i + 1].second));
		}
	}
	else if (N == 1)
	{
		return one;
	}
	else
	{
		return zero;
	}

	int size = tmp.size();

	return tmp[size - 1];
}

void B1003Solution()
{
	int T, N;
	vector<pair<int, int>> answers;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		
		answers.emplace_back(fibo(N));
	}

	for (int j = 0; j < T; j++)
	{
		cout << answers[j].first << ' ' << answers[j].second << endl;
	}
}

/*
int main()
{
	B1003Solution();
}
*/