#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit)
{
    
    vector<int> sort_People = people;
    sort(sort_People.begin(), sort_People.end(), less<int>());

    int len = sort_People.size();

    int answer = 0;

    if (sort_People[len - 1] > limit / 2)
    {
        for (int j = len - 1; j > 0; j--)
        {
            int first = sort_People[0];
            int second = sort_People[j];

            if (first + sort_People[1] > limit)
                break;

            if (first + second <= limit)
            {
                sort_People.erase(sort_People.begin() + j);
                sort_People.erase(sort_People.begin());

                j--;

                answer++;
            }
        }

        answer += sort_People.size();
    }
    else
        answer += (len / 2 + len % 2);
    
    return answer;
}