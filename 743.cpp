#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> G;
        G.reserve(n);
        for(auto& edge: times)
            G[edge[0] - 1].emplace_back(pair<int,int>(edge[1]-1,edge[2]));
        k--;
        vector<int> d(n,0x3f3f3f3f);
        d[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(pair<int,int>(0,k));
        int delaytime = -1;
        while(!pq.empty()){
            int dist = pq.top().first;
            int w = pq.top().second;
            pq.pop();
            if(d[w] < dist){
                continue;
            }
            delaytime = max(delaytime, d[w]);
            --w;
            for (auto& edge: G[w]) {
                int v = edge.first;
                if (d[v] > d[w] + edge.second) {
                    d[v] = d[w] + edge.second;
                    pq.push({d[v], v});
                }
            }
        }
        return (!n) ? delaytime : -1;
    }
};
int main(){
    int n;
    vector<vector<int>> input;
    Solution ans;
    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> inp;
        for(int j=0;j<3;j++){
            int num;
            cin >> num ;
            inp.push_back(num);
        }
        input.push_back(inp);
    }
    int many,where;
    cin >> many >> where;
    cout << ans.networkDelayTime(input,many,where) << endl;
}