#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char P[2000001];
char S[1000001];

void B5525Input(char P[], char S[], int &pLen, int& sLen)
{
	cin >> pLen >> sLen;

	pLen = pLen * 2 + 1;

	P[0] = 'I';
	for (int i = 1; i < pLen; i++)
	{
		if (i % 2 == 1)
			P[i] = 'O';
		else
			P[i] = 'I';
	}

	for (int i = 0; i < sLen; i++)
	{
		cin >> S[i];
	}
}

void B5525Solution()
{
	int pLen = 0, sLen = 0, count = 0;

	B5525Input(P, S, pLen, sLen);

	if (pLen > sLen)
	{
		cout << count;
		return;
	}

	// S의 처음을 가리킨다.
	char* ptr = S;
	for (int i = 0; i < sLen; i++)
	{
		// P랑 같은 문자열이 있는 곳을 가리킨다.
		ptr = strstr(ptr, P);
		
		// P와 같은 곳이 있다면
		if (ptr != NULL)
		{
			// 그 다음을 가리킨다.
			ptr++;
			count++;
		}
		else
		{
			break;
		}
	}

	cout << count;
}

/*
int main()
{
	B5525Solution();
	return 0;
}
*/