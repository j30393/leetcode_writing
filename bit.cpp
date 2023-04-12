#include <bits/stdc++.h>
using namespace std;
int lowbit(int x){
    return x&(-x);
};
int main(){
    int x = 20;
    cout << lowbit(x) << endl;
    return 0;
}