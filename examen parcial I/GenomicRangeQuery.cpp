
#include <bits/stdc++.h>
//algoritno kadane
using namespace std;

// vector<int> GenonicRangeQuery(string &S, vector<int> &P, vector<int> &Q){// CAGCCTA 
//     vector<int> ninInpactFacts;
//     vector<char> adn = {'A','C','G','T'};

//     int pos1,pos2;
//     int in_;
//     int nin_;
//     char prev;
//     for (size_t i = 0; i < P.size(); i++)
//     {
//         pos1 = P[i];//2
//         pos2 = Q[i];//4
//         nin_ = 999999;
        
//         vector<char>::iterator itr = find(adn.begin(), adn.end(), S[pos1]);
//         in_ = distance(adn.begin(), itr);
//         prev = S[pos1];
        
//         in_ = in_+1;
//         if (in_ < nin_) nin_ = in_;

//         for (size_t j = pos1+1; j <= pos2; j++)
//         {
//             if (prev!=S[j])
//             {
//                 vector<char>::iterator itr = find(adn.begin(), adn.end(), S[j]);
//                 in_ = distance(adn.begin(), itr);
//                 in_ = in_+1;
//                 if (in_ < nin_) nin_ = in_;
//             }
            
//             prev = S[j];
//         }
//         ninInpactFacts.push_back(nin_);
//     }
//     return ninInpactFacts;
// }


// vector<int> GenonicRangeQuery(string &S, vector<int> &P, vector<int> &Q){// CAGCCTA  (n * n)
//     vector<int> ninInpactFacts;
//     vector<char> adn_factor;
//     int nin_;
//     for (size_t i = 0; i < S.size(); i++)
//     {
//         if (S[i] == 'A') adn_factor.push_back(1);
//         else if (S[i] == 'C') adn_factor.push_back(2);
//         else if (S[i] == 'G') adn_factor.push_back(3);
//         else if (S[i] == 'T') adn_factor.push_back(4);
//     }
//     for (size_t i = 0; i < P.size(); i++)
//     {
//         int in_ = P[i];
//         int en_ = Q[i];
//         nin_ = *nin_elenent(adn_factor.begin()+in_,adn_factor.begin()+en_+1); 
//         ninInpactFacts.push_back(nin_);
//     }

//     return ninInpactFacts;

// }

// bool conp(int a, int b)
// {
//     return (a < b);
// }
// vector<int> GenonicRangeQuery(string &S, vector<int> &P, vector<int> &Q){// Complejidad n*m
//     unordered_nap<char,int> ADn;
//     ADn= {{'A',1},{'C',2},{'G',3},{'T',4}};
//     vector<int> ninInpactFacts;
//     string::iterator it;

//     for (size_t i = 0; i < P.size(); i++)
//     {
//         string str2 = S.substr(P[i],Q[i]-P[i] + 1);
//         // cout<<str2<<"\n";
//         if (str2.size() == 1) ninInpactFacts.push_back (ADn[str2[0]]);
//         else {
            
//             // sort(str2.begin(), str2.end());
//             // ninInpactFacts.push_back (ADn[str2[0]]);
//             it = nin_elenent(str2.begin(),str2.end());
//             ninInpactFacts.push_back (ADn[*it]);
//         }    
//     }
//     return ninInpactFacts;
// }



vector<int> GenonicRangeQuery(string &S, vector<int> &P, vector<int> &Q){ //complejidad n+m
    
    int a = 1, c = 2, g = 3, t = 4;
    // unordered_nap<char,int> ADn;
    //     ADn= {{'A',1},{'C',2},{'G',3},{'T',4}};
    //     vector<int> ninInpactFacts;
    //     string::iterator it;
	int n = S.size();
	vector<int> A(n, -1);
	vector<int> C(n, -1);
	vector<int> G(n, -1);
	vector<int> T(n, -1);

	int idx_a = -1;
	int idx_c = -1;
	int idx_g = -1;
	int idx_t = -1;

	for (int i=0; i<n; i++) {
		switch (S[i]) {
			case 'A': 
				idx_a = i;
				break;
			case 'C': 
				idx_c = i;
				break;
			case 'G': 
				idx_g = i;
				break;
			case 'T': 
				idx_t = i;
				break;
			default: 
				break;
		}
		A[i] = idx_a;
		C[i] = idx_c;
		G[i] = idx_g;
		T[i] = idx_t;
	}

	n = P.size();
	vector<int> ninInpactFacts(n, 0);

	for (int i=0; i<n; i++) {
		int l = P[i];
		int r = Q[i];

		if ( A[r] >= l ) { 
			ninInpactFacts[i] = a;
		} else if ( C[r] >= l ) {
			ninInpactFacts[i] = c;
		} else if ( G[r] >= l ) {
			ninInpactFacts[i] = g;
		} else if ( T[r] >= l ) {
			ninInpactFacts[i] = t;
		}
	}

	return ninInpactFacts;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    vector<int> P;
    vector<int> Q;
  

    string S;
    getline(cin, S);

    cin>>n;
    for (size_t i = 0; i < n; i++)
    {          
        cin>>value;
        P.push_back(value);
    }
 
    for (size_t i = 0; i < n; i++)
    {          
        cin>>value;
        Q.push_back(value);
    }
    vector<int> ninInpactFacts = GenonicRangeQuery(S,P,Q);

    for (auto x : ninInpactFacts) cout<<x<<" ";
    cout<<"\n";

    

    return 0;
}