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
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        vector<int> freqs(26, 0);
        for (auto task : tasks) {
            freqs[task - 'A']++;
        }

        sort(freqs.begin(), freqs.end());

        int most_freq = freqs.back(); freqs.pop_back();
        int idle = (most_freq - 1) * n;

        while (!freqs.empty() && idle > 0) {
            idle -= min(most_freq - 1, freqs.back());
            freqs.pop_back();
        }
        idle = max(0, idle);

        return tasks.size() + idle;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<char> tasks;

    // Input: tasks = ["A","A","A","B","B","B"], n = 2
    // Output: 8
    tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << solution.leastInterval(tasks, 2) << endl;

    // Input: tasks = ["A","A","A","B","B","B"], n = 0
    // Output: 6
    tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << solution.leastInterval(tasks, 0) << endl;

    // Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
    // Output: 16
    tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << solution.leastInterval(tasks, 2) << endl;

    return 0;
}
