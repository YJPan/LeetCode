#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ret;
        int team_num = votes[0].size();
        set<char> teams;
        vector<vector<int>> record(26, vector<int>(team_num, votes.size()));

        for (auto vote : votes) {
            for (int i = 0; i < team_num; i++) {
                teams.insert(vote[i]);
                record[vote[i] - 'A'][i]--;
            }
        }

        vector<vector<int>> str;
        for (auto team : teams) {
            record[team - 'A'].push_back(team - 'A');
            str.push_back(record[team - 'A']);
        }

        sort(str.begin(), str.end());
        for (auto s : str) {
            ret += ('A' + s.back());
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> votes;

    // Input: votes = ["ABC","ACB","ABC","ACB","ACB"]
    // Output: "ACB"
    votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
    cout << solution.rankTeams(votes) << endl;

    // Input: votes = ["WXYZ","XYZW"]
    // Output: "XWYZ"
    votes = {"WXYZ", "XYZW"};
    cout << solution.rankTeams(votes) << endl;

    // Input: votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
    // Output: "ZMNAGUEDSJYLBOPHRQICWFXTVK"
    votes = {"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
    cout << solution.rankTeams(votes) << endl;

    // Input: votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
    // Output: "ABC"
    votes = {"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"};
    cout << solution.rankTeams(votes) << endl;

    // Input: votes = ["M","M","M","M"]
    // Output: "M"
    votes = {"M", "M", "M","M"};
    cout << solution.rankTeams(votes) << endl;

    return 0;
}
