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

class Logger {
public:
    map<string, int> record;

    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (record.count(message) == 0 || timestamp - record[message] >= 10) {
            record[message] = timestamp;
            return true;
        }

        return false;
    }
};

#if 0
class Logger {
public:
    set<string> forbid;
    queue<pair<int, string>> record;

    /** Initialize your data structure here. */
    Logger() {
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!record.empty()) {
            pair<int, string> p = record.front();
            if (timestamp - p.first < 10)
                break;

            forbid.erase(p.second);
            record.pop();
        }

        if (forbid.count(message) != 0)
            return false;

        forbid.insert(message);
        record.push(make_pair(timestamp, message));
        return true;
    }
};
#endif

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main(int argc, char *argv[]) {
    Logger l;
    // Input
    // ["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
    // [[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
    // Output
    // [null, true, true, false, false, false, true]

    cout << l.shouldPrintMessage(1, "foo") << endl;
    cout << l.shouldPrintMessage(2, "bar") << endl;
    cout << l.shouldPrintMessage(3, "foo") << endl;
    cout << l.shouldPrintMessage(8, "bar") << endl;
    cout << l.shouldPrintMessage(10, "foo") << endl;
    cout << l.shouldPrintMessage(11, "foo") << endl;

    return 0;
}
