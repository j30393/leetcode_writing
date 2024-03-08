#include <bits/stdc++.h>
using namespace std;
bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second; // Sort by second value first
    } else {
        return a.first < b.first; // If second values are equal, sort by first value
    }
}

int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n , limit;
        cin >> n >> limit;
        vector<pair<int,int>> v;
        vector<int> transition;
        int current;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        sort(v.begin(), v.end(), customComparator);
        current = v[0].second;
        int cnt = 0;
        transition.push_back(cnt);
        for(auto it : v){
            if(it.second != current){
                transition.push_back(cnt);
                current = it.second;
            }
            cnt++;
            //cout << it.first << " " << it.second << endl;
        }
        int ans = 0;
        for(auto start_position : transition){
            priority_queue<int> pq;
            int ans_this_time = 0;
            int heap_value = 0;
            int current_position = start_position;
            int start_value = v[start_position].second;
            int record = 0;
            int limit_this_time = limit;
            for(int i = current_position; i < n; i++){
                if(v[i].second != start_value){
                    // limit the limit
                    limit_this_time -= (v[i].second - start_value);
                    if(limit_this_time <= 0){
                        break;
                    }
                    start_value = v[i].second;
                    while(heap_value > limit_this_time){
                        if(!pq.empty()){
                            heap_value -= pq.top();
                            pq.pop();
                            ans_this_time--;
                        }
                        else{
                            break;
                        }
                    }
                }
                if(heap_value + v[i].first <= limit_this_time){
                    ans_this_time++;
                    record = max(record , ans_this_time);
                    pq.push(v[i].first);
                    heap_value += v[i].first;
                }
                else{
                    if(pq.empty()){
                        break;
                    }
                    else{
                        if(v[i].first < pq.top()){
                            heap_value -= pq.top();
                            pq.pop();
                            pq.push(v[i].first);
                            heap_value += v[i].first;
                            record = max(record , ans_this_time);
                        }
                    }
                    
                }
            }
            //cout << "嘿嘿" << ": record" << record <<endl;
            ans = max(ans, record);
        }
        cout << ans << endl;
    }
    return 0;
}