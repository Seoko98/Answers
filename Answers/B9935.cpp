/*
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void B9935Input(string &str1, string &str2)
{
	cin >> str1 >> str2;
}

void explosion(string str, string bomb)
{
	vector<char> answer;
	int len = str.length();
	int bombLen = bomb.length();

	// 문자열 끝까지 반복
	for (int i = 0; i < len; i++)
	{
		answer.emplace_back(str[i]);

		// 문자열이 폭발 문자열 크기보다 커지면
		if (answer.size() >= bombLen)
		{
			bool isExplode = true;
			// 폭발 문자열이 있는지 검사한다.
			for (int j = 0; j < bombLen; j++)
			{
				if (answer[answer.size() - bombLen + j] != bomb[j])
				{
					isExplode = false;
					break;
				}
			}
			// 폭발 문자열이 있다면 폭발
			if (isExplode)
			{
				for (int j = 0; j < bombLen; j++)
					answer.pop_back();
			}
		}
	}

	if (answer.empty())
		cout << "FRULA";
	else
	{
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i];
	}
}

void B9935Solution()
{
	string str, bomb;
	B9935Input(str, bomb);
	explosion(str, bomb);
}

int main()
{
	B9935Solution();
	return 0;
}
*/