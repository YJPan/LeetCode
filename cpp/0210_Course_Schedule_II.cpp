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

using namespace std;

class Solution {
public:
    bool haveCycle(vector<vector<int>>& graph, vector<int>& visit, int course, vector<int>& ans) {
        if (visit[course] == 1) return true;
        if (visit[course] == 2) return false;

        visit[course] = 1;

        for (auto pre : graph[course]) {
            if (haveCycle(graph, visit, pre, ans))
                return true;
        }

        ans.push_back(course);
        visit[course] = 2;

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> visit(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());

        for (auto p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        for (auto p : prerequisites) {
            if (haveCycle(graph, visit, p[0], ans)) {
                return {};
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> prerequisites;
    vector<int> ans;

    // Input: numCourses = 2, prerequisites = [[1,0]]
    // Output: [0,1]
    prerequisites = {{1, 0}};
    ans = solution.findOrder(2, prerequisites);
    for (auto course : ans) {
        cout << course << " ";
    }
    cout << endl;

    // Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    // Output: [0,2,1,3]
    prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    ans = solution.findOrder(4, prerequisites);
    for (auto course : ans) {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}
