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
    int partition(vector<pair<int, string>>& record, int start, int end) {
        pair<int, string> pivot_val = record[start];
        int i = start, j = end;

        while (i < j) {
            while (i < j && (record[j].first > pivot_val.first || (record[j].first == pivot_val.first && record[j].second <= pivot_val.second)))
                j--;
            while (i < j && (record[i].first < pivot_val.first || (record[i].first == pivot_val.first && record[i].second >= pivot_val.second)))
                i++;

            if (i < j) {
                pair<int, string> tmp = record[j];
                record[j] = record[i];
                record[i] = tmp;
            }
        }

        record[start] = record[i];
        record[i] = pivot_val;

        return i;
    }

    void qsort(vector<pair<int, string>>& record, int start, int end, int k) {
        if (start < end) {
            int pivot = partition(record, start, end);

            if (pivot <= k) {
                qsort(record, pivot + 1, end, k);
            } else {
                qsort(record, start, pivot - 1, k);
                qsort(record, pivot + 1, end, k);
            }
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> c;
        vector<pair<int, string>> record;
        vector<string> ret;

        for (auto w : words) {
            if (c.count(w) == 0)
                c[w] = 1;
            else
                c[w]++;
        }
        for (auto r : c) {
            record.push_back(make_pair(r.second, r.first));
        }

        qsort(record, 0, record.size() - 1, record.size() - k);

        for (int i = 0; i < k; i++) {
            ret.push_back(record.back().second);
            record.pop_back();
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> words, ret;

    // Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    // Output: ["i", "love"]
    words = {"i", "love", "leetcode", "i", "love", "coding"};
    ret = solution.topKFrequent(words, 2);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    // Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
    // Output: ["the", "is", "sunny", "day"]
    words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    ret = solution.topKFrequent(words, 4);
    for (auto r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
