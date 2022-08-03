/*
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M; // N = 행 M = 열
int field[501][501];
bool visited[501][501] = { false, };
int init[1][1] = { {1} };
pair<int, int> dir4[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) }; // 상하좌우
vector<int> answer;

void B14500Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> field[i][j];
		}
	}
}

// 현재 위치에서 다음 위치로 이동하려 할 때, 유효한 범위인지 알려준다.
bool isInvalidRange(pair<int, int> curr_Pos, pair<int, int> dir)
{
	if (curr_Pos.first + dir.first >= 0 && curr_Pos.first + dir.first < N &&
		curr_Pos.second + dir.second >= 0 && curr_Pos.second + dir.second < M)
	{
		return false;
	}
	else
		return true;
}

int bfs(int start_row, int start_col)
{
	queue<pair<int, int>> que;
	vector<pair<int, int>> tmp; // visited 배열 초기화를 위한 벡터
	int sum;

	que.push(make_pair(start_row, start_col));
	tmp.emplace_back(make_pair(start_row, start_col));
	visited[start_row][start_col] = true;
	sum = field[start_row][start_col];

	for (int i = 0; i < 3; i++)
	{
		pair<int, int> curr_Pos = que.front();
		que.pop();

		pair<int, int> next_Pos;
		pair<int, int> next_Max; // 제일 값이 큰 위치를 갖는 변수
		// ㅗ모양 처리 (노가다로 처리했다)
		// 이 과정에서 완전한 모양이 나오진 않지만 정답으로 최대값을 찾기 때문에 문제는 없다.
		if (i == 0)
		{
			// ㅗ, ㅜ, ㅏ, ㅓ 4가지 모양.
			pair<int, int> up, down, left, right;
			up = make_pair(curr_Pos.first + dir4[0].first, curr_Pos.second + dir4[0].second);
			down = make_pair(curr_Pos.first + dir4[1].first, curr_Pos.second + dir4[1].second);
			left = make_pair(curr_Pos.first + dir4[2].first, curr_Pos.second + dir4[2].second);
			right = make_pair(curr_Pos.first + dir4[3].first, curr_Pos.second + dir4[3].second);

			int sum_tmp = sum;
			// 상 좌 하
			if (!isInvalidRange(curr_Pos, dir4[0]))
					sum_tmp += field[up.first][up.second];
			if (!isInvalidRange(curr_Pos, dir4[2]))
					sum_tmp += field[left.first][left.second];
			if (!isInvalidRange(curr_Pos, dir4[1]))
					sum_tmp += field[down.first][down.second];

			if(sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;

			// 상 우 하
			if (!isInvalidRange(curr_Pos, dir4[0]))
					sum_tmp += field[up.first][up.second];
			if (!isInvalidRange(curr_Pos, dir4[3]))
					sum_tmp += field[right.first][right.second];
			if (!isInvalidRange(curr_Pos, dir4[1]))
					sum_tmp += field[down.first][down.second];

			if (sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;

			// 좌 하 우
			if (!isInvalidRange(curr_Pos, dir4[2]))
					sum_tmp += field[left.first][left.second];
			if (!isInvalidRange(curr_Pos, dir4[1]))
					sum_tmp += field[down.first][down.second];
			if (!isInvalidRange(curr_Pos, dir4[3]))
					sum_tmp += field[right.first][right.second];

			if (sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;

			// 좌 상 우
			if (!isInvalidRange(curr_Pos, dir4[2]))
					sum_tmp += field[left.first][left.second];
			if (!isInvalidRange(curr_Pos, dir4[0]))
					sum_tmp += field[up.first][up.second];
			if (!isInvalidRange(curr_Pos, dir4[3]))
					sum_tmp += field[right.first][right.second];

			if(sum_tmp <= 4000)
				answer.emplace_back(sum_tmp);
			sum_tmp = sum;
		}

		int curr_max = 0;
		for (int j = 0; j < 4; j++)
		{
			if (!isInvalidRange(curr_Pos, dir4[j]))
			{
				next_Pos = make_pair(curr_Pos.first + dir4[j].first, curr_Pos.second + dir4[j].second);
				// 방문하지 않았고 현재 제일 큰 값보다 크다면
				if (!visited[next_Pos.first][next_Pos.second] &&
					field[next_Pos.first][next_Pos.second] >= curr_max)
				{
					curr_max = field[next_Pos.first][next_Pos.second];
					next_Max = next_Pos;
				}
			}
		}

		// 상하좌우 4방향을 모두 탐색 후 가장 큰 값을 가진 방향으로 이동
		//cout << "next_Max[" << i << "] = " << next_Max.first << ' ' << next_Max.second << endl;
		que.push(next_Max);
		tmp.emplace_back(next_Max);
		visited[next_Max.first][next_Max.second] = true;
		sum += field[next_Max.first][next_Max.second];
	}

	// 이번 탐색에 방문한 위치들을 초기화한다.
	for (int i = 0; i < 4; i++)
	{
		visited[tmp[i].first][tmp[i].second] = false;
	}
	tmp.clear();

	return sum;
}

void dfs(int start_row, int start_col)
{

}

void B14500Solution()
{
	B14500Input();
	int max_value = 0;
	int tmp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cout << i << ' ' << j << endl;
			tmp = bfs(i, j);
			if (tmp > max_value)
				max_value = tmp;
		}
	}

	max_value = max(max_value, *max_element(answer.begin(), answer.end()));

	cout << max_value;
}

int main()
{
	B14500Solution();
	return 0;
}
*/