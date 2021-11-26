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
    string visit(map<char, set<char>> &graph) {
        map<char, int> indegree;
        queue<char> q;
        string ret;

        for (auto v : graph) {
            char src = v.first;
            for (auto neighbor : graph[src])
                indegree[neighbor]++;
        }

        for (auto v : graph) {
            char src = v.first;
            if (indegree[src] == 0)
                q.push(src);
        }

        while (!q.empty()) {
            char c = q.front(); q.pop();
            ret += c;

            for (auto neighbor : graph[c]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return ret.size() < graph.size() ? "" : ret;
    }

    string alienOrder(vector<string>& words) {
        map<char, set<char>> graph;

        for (auto &w : words)
            for (char &c : w)
                if (graph.count(c) == 0)
                    graph[c] = set<char>();

        for (int i = 0; i < words.size() - 1; i++) {
            int common_len = min(words[i].length(), words[i + 1].length());

            if (words[i + 1].length() < words[i].length() && words[i].substr(0, common_len) == words[i + 1])
                return "";

            for (int j = 0; j < common_len; j++) {
                char src = words[i][j], dst = words[i + 1][j];

                if (src != dst) {
                    graph[src].insert(dst);
                    break;
                }
            }
        }

        return visit(graph);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};

    solution.alienOrder(words);

    return 0;
}
