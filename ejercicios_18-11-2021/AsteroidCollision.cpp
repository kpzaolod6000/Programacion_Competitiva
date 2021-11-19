#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
	
    stack<int> survive;
    //larger_asteroids.push_back(asteroids[0]);

    for(size_t i=0 ; i<asteroids.size() ; i++){
        int asteroid = asteroids[i];
        
        if (survive.empty()) {survive.push(asteroid); continue;};
    
        bool isDestroy = false;
        while (!survive.empty() && survive.top() > 0 && asteroid < 0)
        {
            if (survive.top() < abs(asteroid))
            {
                survive.pop();
            }else if (survive.top() == abs(asteroid))
            {
                survive.pop();
                isDestroy = true;
                break;
            }else
            {
                isDestroy = true;
                break;
            }
            
        }
        
        if(isDestroy) continue;
        survive.push(asteroid);
    }

    vector<int> larger_asteroids(survive.size());
    for (int j = survive.size()-1; j >= 0; j--)
    {
        larger_asteroids[j] = survive.top();
        survive.pop();
    }
        
    return larger_asteroids;
        

    //     if(ast > 0){
    //         if( asteroids[i]>0 ){
    //             larger_asteroids.push_back(asteroids[i]);
    //         }else{
    //             int elem = larger_asteroids.size() - 1;
    //             bool survive = false;
    //             while(elem >= 0){                
    //                 ast = larger_asteroids[elem];
    //                 if(ast == abs(asteroids[i])){
    //                     larger_asteroids.erase (larger_asteroids.begin()+elem);
    //                     survive = false;
    //                     break;
    //                     //larger_asteroids.push(asteroids[i]);
    //                 }else if(ast < abs(asteroids[i])){
    //                     larger_asteroids.erase (larger_asteroids.begin()+elem);
    //                     survive = true;
    //                 }else{
    //                     survive = false;
    //                     break;
    //                 }
    //                 elem--;
    //             }
    //             if(survive) larger_asteroids.push_back(asteroids[i]);
    //             //ver que asteroide es mayot
    //         }
    //     }else{// aca entran porque <- y -> como <- <-
    //         larger_asteroids.push_back(asteroids[i]);
    //     }
    // }
    // return larger_asteroids;
}



int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> asteroids(n);

    for (size_t i = 0; i < n; i++) cin>>asteroids[i];

    vector<int> ast = asteroidCollision(asteroids);
    for (size_t i = 0; i < ast.size(); i++) cout << ast[i]<<" ";
    cout<<"\n";
    return 0;
    
}


