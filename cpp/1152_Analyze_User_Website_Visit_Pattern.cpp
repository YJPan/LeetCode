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
    static bool comp(pair<int, string>& a, pair<int, string>& b) {
        return a.first < b.first;
    }

    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string, vector<pair<int, string>>> record;
        map<string, int> counter;
        int ret_max = 0;
        string w[3];

        for (int i = 0; i < username.size(); i++) {
            if (record.count(username[i]) == 0) {
                record[username[i]] = {make_pair(timestamp[i], website[i])};
            } else {
                record[username[i]].push_back(make_pair(timestamp[i], website[i]));
            }
        }

        for (auto &r : record) {
            sort(r.second.begin(), r.second.end(), comp);
        }

        for (auto r : record) {
            if (r.second.size() >= 3) {
                set<string> already;
                for (int i = 0; i < r.second.size() - 2; i++) {
                    for (int j = i + 1; j < r.second.size() - 1; j++) {
                        for (int k = j + 1; k < r.second.size(); k++) {
                            string order = r.second[i].second + " " + r.second[j].second + " " + r.second[k].second;
                            if (already.count(order) != 0)
                                continue;
                            already.insert(order);

                            if (counter.count(order) == 0) {
                                counter[order] = 1;
                            } else {
                                counter[order]++;
                            }

                            if (counter[order] > ret_max) {
                                ret_max = counter[order];
                                w[0] = r.second[i].second;
                                w[1] = r.second[j].second;
                                w[2] = r.second[k].second;
                            } else if (counter[order] == ret_max) {
                                if ((r.second[i].second < w[0]) ||
                                    (r.second[i].second == w[0] && r.second[j].second < w[1]) ||
                                    (r.second[i].second == w[0] && r.second[j].second == w[1] && r.second[k].second < w[2])) {
                                    w[0] = r.second[i].second;
                                    w[1] = r.second[j].second;
                                    w[2] = r.second[k].second;
                                }
                            }
                        }
                    }
                }
            }
        }

        return {w[0], w[1], w[2]};
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> timestamp;
    vector<string> username, website, ret;

    // Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
    // Output: ["home","about","career"]
    username = {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"};
    timestamp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    website = {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"};
    ret = solution.mostVisitedPattern(username, timestamp, website);
    for (auto r : ret) {
        cout << r << endl;
    }

    return 0;
}
