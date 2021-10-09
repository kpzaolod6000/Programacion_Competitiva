
#include <bits/stdc++.h>

using namespace std;


bool myfunction (int i,int j) { return (i>j); }


vector<int> megatronAtack(vector<int> &nums,int M){

    multimap<int,int> output;
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
        //guardar la maxima numero de planetas destruidos y minimo numero de autobots muertos menores a M
        // output[cntPlanets] = autobtsDead;
        output.insert ( pair<int,int>(cntPlanets,autobtsDead) );
        M_fake = M;
        cntPlanets=0;
        autobtsDead = 0;
    }

    // for (auto it = output.cbegin(); it != output.cend(); ++it)
    //     cout << " [" << it->first << ':' << it->second << ']';
    // cout << '\n';

    return {output.rbegin()->second,output.rbegin()->first};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T,P,M,value;
    cin>>T;
    
    vector<int> PLANETS;
    while (T--)
    {
        cin>>P>>M;
        for (size_t i = 0; i < P; i++)
        {
            cin>>value;
            PLANETS.push_back(value);
        }
    
        for (auto x:megatronAtack(PLANETS,M))
        {
            cout<<x<<" ";
        }
        
        cout<<"\n";
        PLANETS.clear();
    
    }
    
    return 0;
}