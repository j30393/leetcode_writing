#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(const pair<int,int> a,const pair<int,int> b ){
        if(a.first != b.first) return a.first < b.first;
        else{
            return a.second > b.second;
        }
        return true;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>> comp;
        vector<int> sequence_a(5010,0x3f3f3f3f);
        int temp = 1;
        int siz = envelopes.size();
        for(int i=0;i<siz;i++){
            comp.push_back(pair<int,int>(envelopes[i][0],envelopes[i][1]));
        }
        sort(comp.begin(),comp.end(),cmp);
        for(int i=0;i<siz;i++){
            for(int j=0;j<temp;j++){
                if(j == temp-1 && sequence_a[j] > comp[i].second){
                    sequence_a[j] = comp[i].second;
                    temp += 1;
                    break;
                }
                else if(sequence_a[j] >= comp[i].second){
                    sequence_a[j] = comp[i].second;
                    break;
                }
            }
        }
        return temp-1;
    }
};
int main(){
    Solution ans;
    int k;
    cin >> k;
    vector<vector<int>> input(k,vector<int>(2,0));
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            cin >> input[i][j];
        }
    }
    cout << ans.maxEnvelopes(input) << endl;
}