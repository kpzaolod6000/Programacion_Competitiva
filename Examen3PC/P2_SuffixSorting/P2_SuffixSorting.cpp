#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 200010          
char text[MAX_N];               
int n;                       
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];                

char text_aux[MAX_N];               
int m;

int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];

void countingSort(int val) {       
    int sum, max_ = max(300, n);
    memset(c, 0, sizeof c);        
    for (size_t i = 0; i < n; i++) c[i + val < n ? RA[i + val] : 0]++;
    for (size_t i = sum = 0; i < max_; i++) {
        int t = c[i]; 
        c[i] = sum; 
        sum += t;
    }
    for (size_t i = 0; i < n; i++)  tempSA[c[SA[i]+val < n ? RA[SA[i]+val] : 0]++] = SA[i];
    for (size_t i = 0; i < n; i++)  SA[i] = tempSA[i];                
}

void SuffixArray() {       
    int  r;
    for (size_t i = 0; i < n; i++) RA[i] = text[i];       
    for (size_t i = 0; i < n; i++) SA[i] = i;
    for (int k = 1; k < n; k <<= 1) { 
        countingSort(k);  
        countingSort(0);        
        tempRA[SA[0]] = r = 0;
        for (size_t i = 1; i < n; i++) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (size_t i = 0; i < n; i++)      
        RA[i] = tempRA[i];
       
        if (RA[SA[n-1]] == n-1) break;
    } 
}


ii LRS() {           
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++)
        if (LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

ii LCS() {                 
    int idx = 0, maxLCP = -1;
    for (size_t i = 1; i < n; i++)
        if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

int main() {
    
	while(fgets(text, sizeof text, stdin)!=NULL){
        n = (int)strlen(text);

        text[--n] = '$';
        SuffixArray();
        int q;
        cin>>q;
        
        int indx;
        for(int i=0;i<q;i++){
            cin>>indx;
            cout<<SA[indx]<<" ";
        }
        cout<<endl;
        fgets(text_aux, sizeof text_aux, stdin);
	}
}