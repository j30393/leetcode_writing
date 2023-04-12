#include <bits/stdc++.h>
using namespace std;
#define custom_word pair<string,int>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        queue<custom_word> q;
        q.push(make_pair(beginWord,0));
        while(!q.empty()){
            custom_word front = q.front();
            q.pop();
            if(front.first == endWord) return front.second;
            else{
                for(int i = 0; i < front.first.size(); i++){
                    string temp = front.first;
                    for(char c = 'a'; c <= 'z'; c++){
                        temp[i] = c;
                        if(dict.find(temp) != dict.end()){
                            q.push(make_pair(temp,front.second+1));
                            dict.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};