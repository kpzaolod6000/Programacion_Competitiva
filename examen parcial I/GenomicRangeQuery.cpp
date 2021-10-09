
#include <bits/stdc++.h>
//algoritmo kadane
using namespace std;

// vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q){// CAGCCTA 
//     vector<int> minImpactFacts;
//     vector<char> adn = {'A','C','G','T'};

//     int pos1,pos2;
//     int in_;
//     int min_;
//     char prev;
//     for (size_t i = 0; i < P.size(); i++)
//     {
//         pos1 = P[i];//2
//         pos2 = Q[i];//4
//         min_ = 999999;
        
//         vector<char>::iterator itr = find(adn.begin(), adn.end(), S[pos1]);
//         in_ = distance(adn.begin(), itr);
//         prev = S[pos1];
        
//         in_ = in_+1;
//         if (in_ < min_) min_ = in_;

//         for (size_t j = pos1+1; j <= pos2; j++)
//         {
//             if (prev!=S[j])
//             {
//                 vector<char>::iterator itr = find(adn.begin(), adn.end(), S[j]);
//                 in_ = distance(adn.begin(), itr);
//                 in_ = in_+1;
//                 if (in_ < min_) min_ = in_;
//             }
            
//             prev = S[j];
//         }
//         minImpactFacts.push_back(min_);
//     }
//     return minImpactFacts;
// }


vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q){// CAGCCTA  (N * M)
    vector<int> minImpactFacts;
    vector<char> adn_factor;
    int min_;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == 'A') adn_factor.push_back(1);
        else if (S[i] == 'C') adn_factor.push_back(2);
        else if (S[i] == 'G') adn_factor.push_back(3);
        else if (S[i] == 'T') adn_factor.push_back(4);
    }
    for (size_t i = 0; i < P.size(); i++)
    {
        int in_ = P[i];
        int en_ = Q[i];
        min_ = *min_element(adn_factor.begin()+in_,adn_factor.begin()+en_+1); 
        minImpactFacts.push_back(min_);
    }

    return minImpactFacts;

}

// vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q){
//     unordered_map<char,int> ADN;
//     ADN= {{'A',1},{'C',2},{'G',3},{'T',4}};
//     vector<int> minImpactFacts;
//     string::iterator it;

//     for (size_t i = 0; i < P.size(); i++)
//     {

//         for ( auto it = ADN.cbegin(); it != ADN.cend(); ++it ){
            
//             cout<<P[i]<<" "<<Q[i]<<"\n";
//             string str2 = S.substr(P[i],Q[i]-P[i]);
//             cout<<str2<<"\n";
//             size_t found = str2.find(it->first);
//             if (found!=string::npos){
//                 minImpactFacts.push_back (ADN[it->first]);
//                 break;
//             }
//         }        
//     }
//     return minImpactFacts;
// }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,value;
    vector<int> P;
    vector<int> Q;
  

    string S;
    getline(cin, S);

    cin>>m;
    for (size_t i = 0; i < m; i++)
    {          
        cin>>value;
        P.push_back(value);
    }
 
    for (size_t i = 0; i < m; i++)
    {          
        cin>>value;
        Q.push_back(value);
    }
    vector<int> minImpactFacts = GenomicRangeQuery(S,P,Q);

    for (auto x : minImpactFacts) cout<<x<<" ";
    cout<<"\n";
    

    return 0;
}