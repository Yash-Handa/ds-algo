/*
? There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting
? i and F[i] is finish time of meeting i.
? What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting
? can be held in the meeting room at a particular time?
? Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::pair;

bool my_comp(const pair<int, int> &e1, const pair<int, int> &e2)
{
    return (e1.second < e2.second);
}

vector<pair<int, int>> meeting_select(vector<int> &s, vector<int> &e)
{
    // data  pre-processing
    vector<pair<int, int>> v, ans;
    const int sz = s.size();
    for (int i = 0; i < sz; i++)
        v.push_back({s[i], e[i]});

    std::sort(v.begin(), v.end(), my_comp);
    ans.push_back(v[0]);
    int overlap = v[0].second;

    for (int i = 1; i < sz; i++)
        if (v[i].first > overlap)
        {
            ans.push_back(v[i]);
            overlap = v[i].second;
        }

    return ans;
}

int main()
{
    vector<int> s = {1, 3, 0, 5, 8, 5}, e = {2, 4, 6, 7, 9, 9};
    // vector<int> s = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924},
    //             e = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};

    vector<pair<int, int>> ans = meeting_select(s, e);
    std::cout << "The maximum meetings possible are: " << ans.size() << '\n';
    for (auto &ele : ans)
        std::cout << ele.first << " -> " << ele.second << '\n';
}