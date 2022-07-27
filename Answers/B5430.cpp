#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

void B5430Input(int &size, string &fuc, string &arr)
{
	cin >> fuc >> size >> arr;
}
// 문자열을 ','을 기준으로 분리한다.
void split(string arr, int answer[])
{
	int index = 0;
	string s = arr;
	s.erase(s.end() - 1);
	s.erase(s.begin());
	
	istringstream ss(s);
	string stringBuffer;

	while (getline(ss, stringBuffer, ','))
	{
		answer[index] = stoi(stringBuffer);
		index++;
	}
}
/*
// 1. 문자열을 분리한다.
// 2. 입력받은 함수에 맞는 처리를 한다.
// 2-1) 배열을 뒤집을 때 일일이 뒤집으면 많은 자원이 들어간다.
// 2-2) 따라서 배열이 뒤집어져 있는지 알 수 있는 bool 변수를 설정하도록 한다.
// 2-3) 배열이 뒤집어져 있다면 배열의 맨 뒤를, 그렇지 않다면 배열의 맨 앞을 제거하도록 한다.
// 3. 위 과정이 끝나고 나온 값을 정답 벡터에 저장 후 테스트케이스가 끝나면 한꺼번에 출력한다.
*/
void B5430Solution()
{
	int T;
	cin >> T;

	int tmp[100000];
	vector<string> answers;
	string fuc = "", arr = "", answer = "";
	int size = 0;
	bool isReverse = false;

	for (int i = 0; i < T; i++)
	{	
		memset(tmp, 100000, sizeof(int));
		B5430Input(size, fuc, arr);
		split(arr, tmp);
		
		int beginPtr = 0, endPtr = size - 1; // 함수 D 실행 시 배열의 논리적 위치를 가리키는 포인터.
		int fuc_count = fuc.size();
		// 입력받은 함수 수만큼 반복
		for (int j = 0; j < fuc_count; j++)
		{
			// 배열이 0이 되면 탈출
			if (size < 0)
				break;

			// 함수 R 실행
			if (fuc[j] == 'R')
			{
				// 배열을 뒤집어준다.
				if (isReverse)
					isReverse = false;
				else
					isReverse = true;
			}
			// 함수 D 실행
			else if (fuc[j] == 'D')
			{
				// 배열의 뒤집힘 여부에 따라 맨 앞, 맨 뒤를 제거한다.
				if (isReverse)
				{
					tmp[endPtr] = -1;
					endPtr--;
					size--;
				}
				else
				{
					tmp[beginPtr] = -1;
					beginPtr++;
					size--;
				}
			}
		}

		if (size < 0)
		{
			answer += 'e';
			answer += 'r';
			answer += 'r';
			answer += 'o';
			answer += 'r';
		}
		else if (size == 0)
		{
			answer += '[';
			answer += ']';
		}
		else
		{
			answer += '[';
			
			if (isReverse)
			{
				for (int j = endPtr; j > beginPtr; j--)
				{
					answer += to_string(tmp[j]);
					answer += ',';
				}
				answer += to_string(tmp[beginPtr]);
			}
			else
			{
				for (int j = beginPtr; j < endPtr; j++)
				{
					answer += to_string(tmp[j]);
					answer += ',';
				}
				answer += to_string(tmp[endPtr]);
			}
			answer += ']';
		}
		answers.emplace_back(answer);

		// 초기화
		answer.clear();
		isReverse = false;
	}

	for (int i = 0; i < answers.size() - 1; i++)
	{
		cout << answers[i] << endl;
	}
	cout << answers[answers.size() - 1];
}

int main()
{
	B5430Solution();
	return 0;
}