
#include <bits/stdc++.h>

using namespace std;


bool myfunction (int i,int j) { return (i>j); }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T,P,M,value;
    cin>>T;
    
    vector<long long> nums;
    while (T--)
    {
        cin>>P>>M;
        for (size_t i = 0; i < P; i++)
        {
            cin>>value;
            nums.push_back(value);
        }

        multimap<long long,long long> output;
        int n = nums.size();
        int autobtsDead = 0;
        int cntPlanets = 0;
        int ind;
        int M_fake = M;

        sort(nums.begin(), nums.end(), myfunction);

        for (size_t i = 0; i < n; i++)
        {
            ind = i;
            if (M_fake >= nums[ind])
            {    
                M_fake = M_fake - nums[ind]; //AUJTOBOT MUERTOS
                autobtsDead += nums[ind];
                cntPlanets++;//destruccion del planetas
                ind++;
            }else{
                continue;
            }
            // autobtsDead = M
            while (nums[ind] <= M_fake && ind < n)
            {
                M_fake = M_fake - nums[ind]; 
                autobtsDead += nums[ind];
                cntPlanets++;
                ind++;
            }
            // output[cntPlanets] = autobtsDead;
            output.insert ( pair<long long,long long>(cntPlanets,autobtsDead) );
            M_fake = M;
            cntPlanets=0;
            autobtsDead = 0;
        }

        // for (auto it = output.cbegin(); it != output.cend(); ++it)
        //     cout << " [" << it->first << ':' << it->second << ']';
        // cout << '\n';

        cout<< output.rbegin()->second<<" "<<output.rbegin()->first<<'\n';
        // for (auto x:megatronAtack(PLANETS,M))
        // {
        //     cout<<x<<" ";
        // }
        nums.clear();
    
    }
    
    return 0;
}