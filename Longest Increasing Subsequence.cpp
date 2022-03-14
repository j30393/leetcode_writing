#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> store(nums.size(),0x3f3f3f3f); // the first is the "x"th and the second is the value
        int cnt = 0;
        int cursor = 0;
        for(auto it : nums){
            if(store[cnt] < it){
                store[cnt] = it;
                cnt++;
            }
        }
        return 0;
    }
};
int main(){
    Solution sol;
    int num;
    vector<int> nums;
    cin >> num;
    while(num--){
        int input;
        cin >> input;
        nums.push_back(input);
    }
    cout << sol.lengthOfLIS(nums) << endl;
}