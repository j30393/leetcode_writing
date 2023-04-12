/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> L1_vec;
        vector<int> L2_vec;
        while(l1 != nullptr){
            L1_vec.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            L2_vec.push_back(l2->val);
            l2 = l2->next;
        }
        int L1_size = L1_vec.size();
        int L2_size = L2_vec.size();
        vector<int> ans_vec(L1_size > L2_size ? L1_size : L2_size);
        bool carry_flag = false;
        for(int i = 0 ; i < ans_vec.size() ; i ++){
            if(i < L1_size && i < L2_size){
                ans_vec[i] = L1_vec[i] + L2_vec[i];
            }
            else if(i < L1_size){
                ans_vec[i] = L1_vec[i];
            }
            else{
                ans_vec[i] = L2_vec[i];
            }
            if(carry_flag) ans_vec[i] ++;
            
            if(ans_vec[i] < 10)
                carry_flag = false;
            else{
                ans_vec[i] -= 10;
                carry_flag = true;
            }
        }
        if(carry_flag){
            ans_vec.push_back(1);
        }
        int ans_size = ans_vec.size();
        ListNode* root = new ListNode(ans_vec[0]);
        ListNode* original_root = root;
        for(int i = 1 ; i < ans_size ; i ++){
            ListNode* temp = new ListNode(ans_vec[i]);
            root->next = temp;
            root = temp;
        }
        return original_root;
    }
};