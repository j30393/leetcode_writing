#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char digit: num) {
            while (k && !ans.empty() && digit < ans.back()) {
                ans.pop_back();
                k--;
            }
            if (!ans.empty() || digit != '0') ans.push_back(digit);
        }
        while (!ans.empty() && k--) ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};
int main(){
    string input;
    int k;
    cin >> input >> k;
    Solution sol;
    string ans = sol.removeKdigits(input,k);
    cout << ans;
}