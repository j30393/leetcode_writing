#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map_1;
        int cnt = 0;
        vector<int> solution(nums2.size(),-1);
        for(auto it : nums2){
            map_1.insert(std::make_pair(it,cnt++));
        }
        cnt = 0;
        stack<int> stk;
        for(int i = 0 ; i < nums2.size() ; i++){
            while( !stk.empty() && stk.top() < nums2[i]){
                solution[map_1[stk.top()]] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        vector<int> return_vec;
        for(auto it : nums1){
            return_vec.push_back(solution[map_1[it]]);
        }
        return return_vec;
    }
};

int main(){
    vector<int> nums1;
    vector<int> nums2;
    int n,m;
    cin >> n >> m;
    while(n--){
        int input;
        cin >> input;
        nums1.push_back(input);
    }
    while(m--){
        int input;
        cin >> input;
        nums2.push_back(input);
    }
    Solution sol;
    vector<int> ans = sol.nextGreaterElement(nums1,nums2);
    for(auto it: ans) cout << it << " ";
}