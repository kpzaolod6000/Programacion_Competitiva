
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    long long autobtsDead,minAutobtsDead; // autobots dead
    long long cntPlanets,maxCntPlanets;// planet destruction
    long long P,M,value;
    vector<long long> arr;
    int ind;
    cin>>T;
    while (T--)
    {
        cin>>P>>M;
        for(size_t i=0; i< P; i++)
        {
            cin>>value;
            arr.push_back(value);
        }
        // for (size_t i = 0; i < P; i++)
        // {
        //     cout<<arr[i];
        // }
        
        minAutobtsDead = LLONG_MIN;
        autobtsDead = 0;

        maxCntPlanets = 0;
        cntPlanets=0;
        
        ind = 0;
        for(int i=0; i< P; i++)
        {
            autobtsDead += arr[i];
            cntPlanets++;
            if((maxCntPlanets < cntPlanets && autobtsDead <=M) || (maxCntPlanets == cntPlanets && minAutobtsDead > autobtsDead))
            {
                maxCntPlanets = cntPlanets;
                minAutobtsDead = autobtsDead;
            }
            while(autobtsDead>M)
            {
                autobtsDead -= arr[ind];
                cntPlanets--;
                ind++;
            }
            if ((maxCntPlanets < cntPlanets && autobtsDead <=M) || (maxCntPlanets == cntPlanets && minAutobtsDead > autobtsDead))
            {
                maxCntPlanets = cntPlanets;
                minAutobtsDead = autobtsDead;
            }
        }


        cout<<minAutobtsDead<<" "<<maxCntPlanets<<"\n";
        arr.clear();
    }
    return 0;
}

