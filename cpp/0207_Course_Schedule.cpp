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
    bool haveLoop(vector<vector<int>>& graph, vector<int>& visit, int course) {
        if (visit[course] == 1) return true;
        if (visit[course] == 2) return false;

        visit[course] = 1;

        for (auto pre_course : graph[course]) {
            if (haveLoop(graph, visit, pre_course))
                return true;
        }

        visit[course] = 2;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visit(numCourses, 0);
        // 0: unknown, 1: visiting, 2; visited

        for (auto p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        for (auto p : prerequisites) {
            if (haveLoop(graph, visit, p[0]))
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> prerequisites;

    // Input: numCourses = 2, prerequisites = [[1,0]]
    // Output: true
    prerequisites = {{1, 0}};
    cout << solution.canFinish(2, prerequisites) << endl;

    // Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    // Output: false
    prerequisites = {{1, 0}, {0, 1}};
    cout << solution.canFinish(2, prerequisites) << endl;

    return 0;
}
