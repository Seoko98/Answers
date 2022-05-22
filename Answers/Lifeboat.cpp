#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    // people을 오름차순 정렬한 sort_People
    vector<int> sort_People = people;
    sort(sort_People.begin(), sort_People.end(), less<int>());

    int len = sort_People.size();
    int back_ptr = len;
    int answer = 0;

    // 2명을 최대한 limit에 가깝게 태운다.
    for (int i = 0; i < len; i++)
    {
        // 제일 가벼운 사람.
        int first = sort_People[i];
        for (int j = back_ptr - 1; j > 0; j--)
        {
            // 제일 무거운 사람.
            int second = sort_People[j];
            // 둘의 무게가 limit과 같거나 작다면
            if (first + second <= limit)
            {
                // 둘을 보트에 태운다(벡터에서 제거)
                sort_People.erase(sort_People.begin() + j);
                sort_People.erase(sort_People.begin() + i);

                // 인덱스 조정 및 answer 증가
                len -= 2;
                back_ptr = j;
                i--;
                answer++;

                break;
            }
        }
    }

    // 2명씩 못타는 사람들을 태운다(나머지를 더함)
    answer += sort_People.size();
    
    return answer;
}

int main()
{
    vector<int> people = { 40, 50, 50, 60, 70, 150, 160, 170, 200 };
    int limit = 200;

    cout << solution(people, limit);
}