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
    ListNode* reverselist(ListNode* head)
    {
        ListNode *temp = NULL;
        ListNode *nextp = NULL;
        while(head!=NULL)
        {
            nextp = head->next;
            head->next = temp;
            temp = head;
            head = nextp;
        }
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow -> next;
            fast = fast->next->next;
        }
        slow->next = reverselist(slow->next);
        slow = slow->next;

        ListNode *temp  =head;
        while(slow != NULL)
        {
            if(slow->val != temp->val)
                return false;
            slow = slow->next;
            temp = temp->next;
        }
        return true;
    }
};
