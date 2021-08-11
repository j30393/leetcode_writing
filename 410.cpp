#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check( const vector<int>& nums , int current , int limit){
        int temp = 0,cnt = 0;
        for(int num:nums){
            if( num > current ) return 0;
            if(temp + num > current){
                temp = num;
                cnt += 1;
            }
            else{
                temp += num;
            }
        }
        if(temp != 0) cnt++;
        //cout << limit << " " << cnt << endl;
        if (limit  >= cnt ) return 1;
        return 0;
    }
    int splitArray(vector<int>& nums, int m) {
        int max_num = 10000050;
        int min_num = 0;
        while(max_num > min_num){
            int between = (max_num + min_num) / 2;
            if(check(nums,between,m)){
                max_num = between ;
            }
            else{
                min_num = between + 1;
            }
            //cout << max_num << " " <<min_num << endl;
        }
        return max_num;
    }
};
int main(){
    int k,m;
    cin >> k;
    Solution ans;
    vector<int> inp;
    for(int i=0;i<k;i++){
        int in;
        cin >> in;
        inp.push_back(in);
    }
    cin >> m;
    cout << ans.splitArray(inp, m) << endl;
}