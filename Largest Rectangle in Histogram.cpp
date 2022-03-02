#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk; // first store the index and the second store the value 
        int ans = 0;
        int length = heights.size();
        stk.push({0,0});
        for(int i = 0 ; i < length ; i++ ){
            int temp_high;
            int idx = i;
            while(!stk.empty() && stk.top().second > heights[i]){
                idx = stk.top().first;
                temp_high = stk.top().second;
                stk.pop();
                ans = max(ans,temp_high*( i - idx));
            }
            stk.push(std::make_pair(idx,heights[i]));
        }
        while(!stk.empty()){
            ans = max(ans,(length - stk.top().first)*stk.top().second);
            stk.pop();
        }
        return ans;
    }
};
int main(){
    int num,in;
    vector<int> input; 
    cin >> num;
    while(num--){
        cin >> in;
        input.push_back(in);
    }
    Solution sol;
    int ans = sol.largestRectangleArea(input);
    cout << ans;
}