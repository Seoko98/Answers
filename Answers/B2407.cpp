/*
#include <iostream>
#include <vector>

using namespace std;

void B2407Input(int &n, int &m)
{
	cin >> n >> m;
}

void B2407Solution()
{
	int n, m;
	B2407Input(n, m);

	if (m > (n / 2 + n % 2))
		m = n - m;

	vector<int> numerators;
	vector<int> denominators;

	int numerator;
	int denominator;
	long long answer = 1;

	for (int i = 1; i <= m; i++)
	{
		numerator = n - (i - 1);
		denominator = i;

		numerators.emplace_back(numerator);
		denominators.emplace_back(denominator);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (numerators[j] % denominators[i] == 0)
			{
				numerators[j] = numerators[j] / denominators[i];
				break;
			}
		}
	}

	int size = numerators.size();
	for (int i = 0; i < size; i++)
	{
		answer = answer * numerators[i];
	}

	if (m == 0)
		answer = 1;

	cout << answer;
}

int main()
{
	B2407Solution();
}
*/