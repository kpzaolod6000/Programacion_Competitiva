#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
     
 };


ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<int,vector<int>, greater<int>> ordered; 

    
    for(auto i : lists){
        ListNode* iter = i;
        while (iter != nullptr)
        {
            ordered.push(iter->val);
            iter = iter->next;
        }
    }
    
    ListNode* list_ = new ListNode(ordered.top());
    ordered.pop();

    ListNode* aux = list_;
    while (!ordered.empty())
    {
        ListNode* nxt = new ListNode();
        nxt->val = ordered.top();
        aux->next = nxt;
        ordered.pop();

    }
    return list_;
}


int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;
    cin>>n;

    vector<ListNode*> list_;
    
    for (size_t i = 0; i < n; i++)
    {
        cin>>m;
        ListNode *init = new ListNode();
        ListNode* aux = init;
        for (size_t j = 0; j < m; j++)
        {
            ListNode *newNode = new ListNode();
            cin>>num;
            newNode->val = num;
            aux = newNode;
            aux = aux->next;
        }
        list_.push_back(init);
    }
    
    ListNode* odr = mergeKLists(list_);

    while (odr != nullptr)
    {
        cout<<odr->val<<" ";
        odr = odr->next;
    }
    

    return 0;
    
}

