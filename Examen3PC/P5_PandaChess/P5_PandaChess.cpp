#include <bits/stdc++.h>
using namespace std;

#define ll long long


map<ll, unordered_set<ll>> IC_wins;
map<ll, int> dist;
vector<ll> ts;

void TopSort(ll x) {
    dist[x] = 1;
    for (auto v : IC_wins[x]) {
        if (dist[v] == 0) TopSort(v);
    }
    ts.emplace_back(x);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, m, d;
    cin>>n>>m>>d;
    
    unordered_set<ll> IC_numbers;
    
    for (size_t i = 0; i < m; i++) {
        ll a, b;
        cin>>a>>b;        
        IC_wins[a].insert(b);
        IC_numbers.insert(a);
        IC_numbers.insert(b);
    }
    for (auto x : IC_numbers) {
        if (dist[x] == 0) TopSort(x);
    }
    reverse(ts.begin(), ts.end());

    
    for (size_t i = 0; i < n; i++) {
        dist[ts[i]] = i+1;  
    }
    
    vector<int> v;
    vector<int> L(n, 0);  
    for (size_t i = 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);
        if (dist[a] == 0) continue;
        v.push_back(dist[a]);
    }

    int k = 0;  
    for (size_t i = 0; i < (int) v.size(); i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, v[i]) - L.begin();
        L[pos] = v[i];
        if (pos == k) {
            k++;
        }
    }
    cout<<2*(n - k)<<endl;

    return 0;
}