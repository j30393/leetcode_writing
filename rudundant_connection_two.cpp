#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
    }
};
int main(){
    Solution solution;
    int n;
    cin >> n;
    vector<vector<int>> edges(n,vector<int>());
    vector<int> ans;
    for(int i = 0 ; i < n ; i ++){
        int fir , sec;
        cin >> fir >> sec;
        edges[i].push_back(fir);
        edges[i].push_back(sec);
    }
    ans = solution.findRedundantDirectedConnection(edges);
}