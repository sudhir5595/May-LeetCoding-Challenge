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
    
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        ListNode* temp1 = new ListNode(head->val);
        ListNode* temp3 = temp1;
        head = head->next;
        ListNode* temp2 = new ListNode(head->val);
        ListNode* temp4 = temp2;
        int i = 3;
        while(head->next != NULL){
            head = head->next;
            if(i%2 == 1){
                temp1->next = new ListNode(head->val);
                temp1 = temp1->next;
            }
            else{
                temp2->next = new ListNode(head->val);
                temp2 = temp2->next;
            }
            i++;
        }
        temp1->next = temp4;
        return temp3;
    }
};
