#include <bits/stdc++.h>
using namespace std;
class Bitset {
public:
    Bitset(int size) {
        this->store = vector<bool>(size, false);
        this->size = size;
        this->one_number = 0;
        this->flip_flag = false; // first set the flag to be true
    }
    /*
    * table 
    * | flag | 0 | 0 | 1 | 1 |   
    * | ori  | 0 | 1 | 0 | 1 | 
    * | ans  | 1 | 1 | 0 | 0 | 
    * | unfix| 0 | 0 | 1 | 1 |
    */
    void fix(int idx) {
        // change the store[idx] to be true
        if(store[idx] ^ flip_flag == false) {
            store[idx] = !flip_flag;
            one_number++;
        }
    }
    
    void unfix(int idx) {
        if(store[idx] ^ flip_flag == true) {
            store[idx] = flip_flag;
            one_number--;
        }
    }
    
    void flip() {
        flip_flag = !flip_flag;
        one_number = size - one_number;
    }
    
    bool all() {
        return size == one_number;
    }
    
    bool one() {
        return one_number > 0;
    }
    
    int count() {
        return one_number;
    }
    
    string toString() {
        string temp = "";
        for(int i = 0; i < size; i++) {
            if(!store[i] ^ flip_flag) {
                temp += "0";
            } else {
                temp += "1";
            }
        }
        return temp;
    }
private:
    int size;
    vector<bool> store;
    int one_number;
    bool flip_flag;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */