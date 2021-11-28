#include <bits/stdc++.h>
using namespace std;


#define MAX 500001


int LSOne(int idx){
    return idx & (-idx);
}

int sum_Index(vector<int>& Deletion_items,int idx){
    int sum_ = 0;
    while(idx > 0){
        sum_ += Deletion_items[idx];
        idx -= LSOne(idx);
        //cout<<LSOne(idx)<<"b\n";
    }
    return sum_;
}

void update(vector<int>& Deletion_items,int idx, int v){
    while(idx < MAX){
        Deletion_items[idx] += v;
        idx += LSOne(idx);  
        //cout<<LSOne(idx)<<"b\n";
    }
}
int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> Deletion_items(MAX);

    int idx;
    for(int i = 1; i <= n; i++){
        cin>>idx;
        printf("%d%s", (idx - sum_Index(Deletion_items,idx)), (i == n ? "\n" : " "));
        update(Deletion_items,idx, 1);
    }
    return 0;
    
}