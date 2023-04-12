#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<vector<int>> ans;
    void gen_ans(int cur , int max , vector<int> temp , vector<bool> visited , vector<int>& nums){
        if(cur==max){
            ans.insert(temp);
            return;
        }
        else{
            for(int i = 0 ; i < max ; i++){
                if(!visited[i]){
                    visited[i] = true;
                    temp.push_back(nums[i]);
                    gen_ans(cur+1 , max , temp , visited , nums);
                    temp.erase(temp.end()-1);
                    visited[i] = false;
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size() , false);
        gen_ans(0 , nums.size() , vector<int>() , visited , nums);
        vector<vector<int>> ret;
        for(auto i : ans){
            ret.push_back(i);
        }
        return ret;
    }
};