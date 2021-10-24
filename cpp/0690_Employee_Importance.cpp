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

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// DFS
class Solution {
public:
    int dfs(vector<Employee*> employees, int id, map<int, int>& id_to_idx) {
        int idx = id_to_idx[id];
        Employee *e = employees[idx];
        int ret = e->importance;
        for (auto sub : e->subordinates)
            ret += dfs(employees, sub, id_to_idx);

        return ert;
    }

    int getImportance(vector<Employee*> employees, int id) {
        map<int, int> id_to_idx;
        for (int i = 0; i < employees.size(); i++)
             id_to_idx[employees[i]->id] = i;

        return dfs(employees, id, id_to_idx);
    }
};


/*
// BFS
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ret = 0;
        map<int, int> id_to_idx;
        for (int i = 0; i < employees.size(); i++)
             id_to_idx[employees[i]->id] = i;

        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int ID = q.front(); q.pop();
                int idx = id_to_idx[ID];
                Employee *e = employees[idx];

                ret += e->importance;
                for (auto sub : e->subordinates) {
                    q.push(sub);
                }
            }
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    // Solution solution;

    return 0;
}
