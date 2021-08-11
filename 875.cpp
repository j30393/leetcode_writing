#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_num = 1,max_num = 0x3f3f3f3f;
        while(min_num < max_num ){
            int bet,num = 0;
            bet = (min_num + max_num)/2;
            for(int k:piles){
                num += (k-1)/bet;
                num += 1;
            }
            if(num > h){
                min_num = bet+1;
            }
            else{
                max_num = bet;
            }
        }
        return max_num;
    }
};
int main(){
    int m,h;
    Solution ans;
    cin >> m;
    vector<int> pile;
    for(int i=0;i<m;i++){
        int num;
        cin >> num;
        pile.push_back(num);
    }
    cin >> h;
    cout << ans.minEatingSpeed(pile,h) << endl;
}