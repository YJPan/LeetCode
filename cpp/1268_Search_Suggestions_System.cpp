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
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        int lb = 0, ub = products.size() - 1;
        int pos = 0;

        sort(products.begin(), products.end());

        for (int i = 0; i < searchWord.length(); i++) {
            while (lb <= ub && products[lb][i] != searchWord[i])
                lb++;
            while (lb <= ub && products[ub][i] != searchWord[i])
                ub--;

            vector<string> tmp;
            if (lb <= ub) {
                int size = min(3, ub - lb + 1);

                for (int j = 0; j < size; j++)
                    tmp.push_back(products[lb + j]);
            }

            ret.push_back(tmp);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> products;
    string searchWord;
    vector<vector<string>> ret;

    // Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
    // Output: [
    //     ["mobile","moneypot","monitor"],
    //     ["mobile","moneypot","monitor"],
    //     ["mouse","mousepad"],
    //     ["mouse","mousepad"],
    //     ["mouse","mousepad"]
    // ]
    products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    searchWord = "mouse";
    ret = solution.suggestedProducts(products, searchWord);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: products = ["havana"], searchWord = "havana"
    // Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
    products = {"havana"};
    searchWord = "havana";
    ret = solution.suggestedProducts(products, searchWord);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
    // Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
    products = {"bags", "baggage", "banner", "box", "cloths"};
    searchWord = "bags";
    ret = solution.suggestedProducts(products, searchWord);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Input: products = ["havana"], searchWord = "tatiana"
    // Output: [[],[],[],[],[],[],[]]
    products = {"havana"};
    searchWord = "tatiana";
    ret = solution.suggestedProducts(products, searchWord);
    for (auto vv : ret) {
        for (auto v : vv) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
