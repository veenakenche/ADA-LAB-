/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp=head;
    struct ListNode* prevs=NULL;
    while(temp!=NULL)
    {
        if(temp->val==val)
        {
            if(temp == head)
            {
                head=head->next;
            }
            else
            {
                prevs->next=temp->next;
            }
            temp=temp->next;
        }
        else
        {
            prevs=temp;
            temp=temp->next;
        }
    }
    return head;
}
