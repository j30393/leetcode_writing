#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& ans , int cur,int size , vector<bool> visited , vector<int>& nums){
        if(cur == size){
            vector<int> tmp;
            for(int i = 0 ; i < size ; i++){
                if(visited[i]) tmp.push_back(nums[i]);
            }
            ans.push_back(tmp);
            return;
        }
        visited[cur] = false;
        dfs(ans,cur+1,size,visited , nums);
        visited[cur] = true;
        dfs(ans,cur+1,size,visited, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(),false);
        dfs(ans , 0,nums.size(),visited , nums);
        return ans;
    }
};