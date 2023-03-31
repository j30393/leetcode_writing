#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int cur_val , vector<int> cur , vector<int>&sorted_candidates , vector<vector<int>>& ans , int cursor){
        for(int i = cursor ; i < sorted_candidates.size() ; i++){
            if(cur_val - sorted_candidates[i] < 0) break;
            else{
                if(cur_val - sorted_candidates[i] == 0){
                    cur.push_back(sorted_candidates[i]);
                    ans.push_back(cur);
                    return;
                }
                else{
                    vector<int> new_cur = cur;
                    new_cur.push_back(sorted_candidates[i]);
                    solve(cur_val - sorted_candidates[i] , new_cur , sorted_candidates , ans , i );
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<int> sorted_cand = candidates;
        sort(sorted_cand.begin(),sorted_cand.end());
        vector<vector<int>> ans;
        vector<int> empty;
        solve(target , empty , sorted_cand , ans , 0);
        return ans;
    }
};