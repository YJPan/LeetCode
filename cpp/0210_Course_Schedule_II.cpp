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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        vector<int> ret;

        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int course = q.front(); q.pop();
                ret.push_back(course);
                for (auto c : graph[course]) {
                    indegree[c]--;
                    if (indegree[c] == 0)
                        q.push(c);
                }
            }
        }

        return (ret.size() == numCourses) ? ret : vector<int>();
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

    // Input: numCourses = 1, prerequisites = []
    // Output: [0]
    prerequisites = {};
    ans = solution.findOrder(1, prerequisites);
    for (auto course : ans) {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}
