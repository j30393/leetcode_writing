#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod_num = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        long long int ans = 0;
        stack<pair<int,int>> monotone_stack; // first store the number while the second one store the value
        long long int temp_sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int cnt = 1;
            while(!monotone_stack.empty() && monotone_stack.top().second > arr[i]){
                cnt += monotone_stack.top().first;
                temp_sum -= monotone_stack.top().first * monotone_stack.top().second;
                monotone_stack.pop();
            }
            monotone_stack.push(std::make_pair(cnt,arr[i]));
            temp_sum += cnt*arr[i];
            temp_sum = temp_sum % mod_num;
            ans += temp_sum;
            ans = ans % mod_num;
        }
        return ans;
    }
};
int main(){
    int k,in;
    cin >> k;
    vector<int> input;
    while(k--){
        cin >> in;
        input.push_back(in);
    }
    Solution sol;
    int ans;
    ans = sol.sumSubarrayMins(input);
    cout << ans << endl;
}
