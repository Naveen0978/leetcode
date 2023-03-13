/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* temp = head;
        while(temp != NULL)
        {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        Node* iter = head;
        while(iter != NULL)
        {
            if(iter->random != NULL)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        
        Node* ans = new Node(0);
        iter = head;
        temp = ans;
        Node* fast = NULL;
        while(iter != NULL)
        {
            fast = iter->next->next;
            temp->next = iter->next;
            iter->next = fast;
            temp = temp->next;
            iter = fast;
        }

        return ans->next;
        
    }
};
