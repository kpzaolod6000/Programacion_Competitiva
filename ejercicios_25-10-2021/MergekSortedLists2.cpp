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

    if(lists.size() == 0) return nullptr;
    
    for(auto i : lists){
        ListNode* iter = i;
        if(iter==nullptr) continue;
        while (iter != nullptr)
        {
            ordered.push(iter->val);
            iter = iter->next;
        }
    }
    if(ordered.size() == 0) return nullptr;

    ListNode* list_ = new ListNode();
    list_->val = ordered.top();
    ordered.pop();

    ListNode* aux = list_;
    while (!ordered.empty())
    {
        ListNode* nxt = new ListNode();
        nxt->val = ordered.top();
        aux->next = nxt;
        aux = aux->next;
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
        ListNode *init= new ListNode();
        cin>>num;
        init->val = num;

        ListNode* aux = init;
        
        for (size_t j = 0; j < m-1; j++)
        {
            cin>>num;
            ListNode *newNode = new ListNode();
            newNode->val = num;
            aux->next = newNode;
            aux = aux->next;
        }
        list_.push_back(init);
    }
    // for(auto i : list_){
    //     ListNode* iter = i;
    //     while (iter != nullptr)
    //     {
    //         cout<<iter->val<<" ";
    //         iter = iter->next;
    //     }
    //     cout<<"\n";
    // }
    ListNode* odr = mergeKLists(list_);

    while (odr)
    {
        cout<<odr->val<<" ";
        odr = odr->next;
    }
    

    return 0;
    
}

