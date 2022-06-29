#include "stds.h"

int dfs(int start, vector<pair<int, vector<pair<int, int>>>> vertex_Info)
{
	bool visit[100001] = {false, };
	vector<int> last_V;
	stack<int> s;
	int current_D = 0, max_D = 0; // 현재 거리, 최대 거리

	int current = 0;

	for (int i = 1; i < vertex_Info.size() + 1; i++)
	{
		if (vertex_Info[i].first == start)
		{
			current = i;
			break;
		}
	}
	
	s.push(current);
	visit[current] = true;
	while (!s.empty())
	{
		bool flag = true;
		current = s.top();
		s.pop();
		// 정점의 논리적 위치를 물리적 위치로 치환
		for (int i = 1; i < vertex_Info.size() + 1; i++)
		{
			if (vertex_Info[i].first == current)
			{
				current = i;
				break;
			}
		}
		
		int len = vertex_Info[current].second.size();
		
		for (int i = 0; i < len; i++)
		{
			if (!visit[vertex_Info[current].second[i].first])
			{
				s.push(vertex_Info[current].second[i].first);
				visit[vertex_Info[current].second[i].first] = true;
				current_D += vertex_Info[current].second[i].second;
				flag = false;
			}

			if (!flag)
				break;
		}		

		if (flag)
		{
			if (current_D > max_D)
				max_D = current_D;

			current_D = 0;

			for (int i = 1; i < vertex_Info.size() + 1; i++)
				visit[i] = false;

			for (int i = 0; i < last_V.size(); i++)
				visit[last_V[i]] = true;

			s.push(start);
			visit[start] = true;
			break;
		}
	}	

	return max_D;
}

void input(int &vertex_Count, vector<pair<int, vector<pair<int, int>>>> &vertex_Info)
{
	cin >> vertex_Count;

	vector<pair<int, int>> tmp;
	tmp.emplace_back(make_pair(0, 0));
	vertex_Info.emplace_back(make_pair(0, tmp));

	tmp.clear();

	int v1, v2, d; // 각각 정점, 거리
	for (int i = 0; i < vertex_Count; i++)
	{
		cin >> v1;
		while (true)
		{
			cin >> v2;
			// v2 입력 단계에 -1 입력 시 종료
			if (v2 == -1)
				break;

			cin >> d;

			tmp.emplace_back(make_pair(v2, d));
		}

		vertex_Info.emplace_back(make_pair(v1, tmp));
		tmp.clear();
	}
}

int tree_Radius()
{
	int vertex_Count;
	vector<pair<int, vector<pair<int, int>>>> vertex_Info;

	input(vertex_Count, vertex_Info);

	return dfs(1, vertex_Info);
}

int main()
{
	cout << tree_Radius();
}