/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void B1629Input(long long &A, long long &B, long long &C)
{
	cin >> A >> B >> C;
}

void B1629Solution()
{
	vector<long long> tmp;
	long long A, B, C;
	int cycle = 1;
	int cycle_start = 0;
	bool isCycle = false;

	B1629Input(A, B, C);
	for (int i = 1; i <= B; i++)
	{
		long long num = pow(A, i);

		if (num < C)
			cycle_start++;

		num = num % C;
		tmp.emplace_back(num);

		if (i > cycle_start + 1 && tmp[cycle_start] == num)
		{
			cycle = i - 1;
			isCycle = true;
			break;
		}
	}

	int p = (B - cycle_start) % cycle;
	if (cycle == 1)
		p = 1;

	if(isCycle)
		cout << tmp[abs(p + cycle_start)];
	else
	{
		long long num = pow(A, B);
		cout << num % C;
	}
}

int main()
{
	B1629Solution();
	return 0;
}
*/