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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp = head;
        int length = 0;
        //count total nodes
        while(temp){
            length++;
            temp = temp -> next;
        }

        int fullNodes = length / k;
        int extraNodes = length % k;

        vector<ListNode*> result(k, NULL);
        ListNode *curr = head;
        ListNode *prev = NULL;

        for(int i = 0; i < k; i++){
            result[i] = curr;
            for(int count = 1; count <= fullNodes + (extraNodes > 0 ? 1 : 0); count++){
                prev = curr;
                curr = curr -> next;
            }

            if(prev != NULL)
                prev -> next = NULL;
                
            extraNodes--;
        }

        return result;
    }
};