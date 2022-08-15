/*
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int common[1002][1002];

void B9251Input(string &s1, string &s2)
{
	cin >> s1 >> s2;
	s1 = '0' + s1;
	s2 = '0' + s2;
}

void LCS(string s1, string s2)
{
	int s1_size = s1.size();
	int s2_size = s2.size();

	common[0][0] = 0;

	for (int i = 1; i < s1_size; i++)
	{
		for (int j = 1; j < s2_size; j++)
		{
			if (s1[i] == s2[j])
				common[i][j] = common[i - 1][j - 1] + 1;
			else
			{
				if (common[i - 1][j] > common[i][j - 1])
					common[i][j] = common[i - 1][j];
				else
					common[i][j] = common[i][j - 1];
			}
		}
	}

	cout << common[s1_size - 1][s2_size - 1];

	return;
}

void B9251Solution()
{
	string s1, s2;
	B9251Input(s1, s2);

	LCS(s1, s2);
}

int main()
{
	B9251Solution();
	return 0;
}
*/