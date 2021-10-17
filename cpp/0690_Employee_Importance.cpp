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
    int dfs(vector<Employee*>& employees, map<int, int>& id_to_idx, int id) {
        if (id_to_idx[id] == -1) return 0;

        int idx = id_to_idx[id];
        id_to_idx[id] = -1;
        int ret = employees[idx]->importance;
        for (auto sub : employees[idx]->subordinates)
            ret += dfs(employees, id_to_idx, sub);

        return ret;
    }

    int getImportance(vector<Employee*> employees, int id) {
        map<int, int> id_to_idx;
        for (int i = 0; i < employees.size(); i++)
            id_to_idx[employees[i]->id] = i;

        return dfs(employees, id_to_idx, id);
    }
};

/*
// BFS
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ret = 0;
        queue<int> q;
        map<int, int> id_to_idx;
        for (int i = 0; i < employees.size(); i++)
             id_to_idx[employees[i]->id] = i;
        q.push(id);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int ID = q.front(); q.pop();
                int idx = id_to_idx[ID];
                id_to_idx[ID] = -1;
                Employee* e = employees[idx];
                ret += e->importance;

                for (auto sub : e->subordinates) {
                    if (id_to_idx[sub] != -1) {
                        q.push(sub);
                    }
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
