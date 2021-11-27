 #include <bits/stdc++.h>

using namespace std;
#define ll long long

int elevatorRides(int n, int x,vector<ll>& people) {

    int limit = 1 << n; // deplazar 0000 0001
    vector<pair<ll,ll>> dp_people(limit);
    dp_people[0] ={0,0};

    for (int msk = 1; msk < limit; msk++)
    {
        pair<ll,ll> min_ = {INT_MAX,INT_MAX};

        for (int i = 0; i < n; i++)
        {
            if (((1 << i) & msk) == 0) continue;
            auto current = dp_people[(1 << i) ^ msk];
            
            if(current.second + people[i] <= x) current.second += people[i];
            else
            {
                current.first +=1;
                current.second = people[i];
            }
            min_ = min(min_, current);            
        }
        dp_people[msk] = min_;
    }
    return dp_people[limit-1].first;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x;
    cin>>n>>x;

    vector<ll> people(n);
    for (size_t i = 0; i < n; i++) cin>>people[i];

    cout<<elevatorRides(n,x,people)<<"\n";
    
    return 0;
}
