#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,0x3f3f3f));
        for(auto it: edges){
            matrix[it[0]][it[1]] = matrix[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++){
            matrix[i][i] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(matrix[i][k]+matrix[k][j] < 0x3f3f3f) matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int least = 101,ans;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] <= distanceThreshold && i!=j) cnt++;
            }
            cout << cnt;
            if(cnt <= least){
                ans = i;
                least = cnt;
            } 
        }
        return ans;
    }
};
int main(){
    int n,times,dis;
    Solution ans;
    cin >> n >> times;
    vector<vector<int>> edges;
    for(int i=0;i<times;i++){
        vector<int> a;
        for(int j=0;j<3;j++){
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        edges.push_back(a);
    }
    cin >> dis;
    cout << ans.findTheCity(n,edges,dis);
}