#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

void InsertNode(ListNode *head, int data){
    ListNode *tail=head;
    if (tail->next==nullptr){
        ListNode *new_node= new ListNode(data);
        tail->next=new_node;
    }
    else
        InsertNode(tail->next,data);
}

void PrintList(ListNode *head){
    vector<int> res;
    ListNode *tail=head;
    while (tail!=nullptr){
        res.push_back(tail->val);
        tail=tail->next;
    }
    for (int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *pre=nullptr;
        while (fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;
        ListNode *head1=sortList(head);
        ListNode *head2=sortList(slow);
        return mergeList(head1,head2);
    }
    ListNode *mergeList(ListNode *head1, ListNode *head2){
        ListNode *dummy=new ListNode(0), *tail=dummy;
        while (head1 && head2){
            if (head1->val < head2->val){
                tail->next=head1;
                tail=tail->next;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                tail=tail->next;
                head2=head2->next;
            }
        }
        tail->next=(head1!=nullptr)? head1 :head2;
        return dummy->next;
    }
};

int main(){
    ListNode *head=new ListNode(4);
    InsertNode(head,2);
    InsertNode(head,1);
    InsertNode(head,3);
    cout<<"Original List: ";
    PrintList(head); //Original List: 4 2 1 3

    Solution res;
    ListNode *ans=res.sortList(head);
    cout<<"After Sorted : ";
    PrintList(ans); //After Sorted : 1 2 3 4

    return 0;
}

