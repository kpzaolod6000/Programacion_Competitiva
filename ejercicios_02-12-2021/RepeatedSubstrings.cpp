#include <bits/stdc++.h>

using namespace std;
class SuffixArray{
    public:
        static const int max_n = 100010;
        int n =-1;
        string str;

        int RA[max_n], SA[max_n];
        int tempRA[max_n], tempSA[max_n];
        int* lcp;

        void countingSort(int k){
            int i;
            int maxi = max(300,n);
            int sum = 0;
            vector<int> c(max_n);

            for (i = 0; i < n; i++) c[i+k< n ? RA[i+k] : 0]++;
            for (i = 0; i < maxi; i++)
            {
                int t = c[i];
                c[i] = sum;
                sum+=t;
            }

            for (i = 0; i < n; i++)
            {
                tempSA[c[SA[i] + k<n ? RA[SA[i] + k] : 0]++ ] = SA[i];
            }
            for ( i = 0; i < n; i++)
            {
                SA[i] = tempSA[i];
            }
        }

        void kasai(){
            int k = 0;
            this->lcp = new int[n];
            vector<int> rank(n);
            for (int i = 0; i < n; i++) rank[this->SA[i]] = i;

            for (int  i = 0; i < n; i++ , k = max(k-1,0))
            {
                if (rank[i] == n-1)
                {
                    k = 0;
                    continue;
                }
                int j = this->SA[rank[i]+1];
                while (i+k<n && j+k < n && str[i+k] == str[j+k]) k++;
                this->lcp[rank[i]] = k;
                
            }
        }
        SuffixArray(string x){
            this->str = x;
            this->str += "$";
            this->n = str.length();
            for (int i = 0; i < n; i++) RA[i] = str[i];
            for (int i = 0; i < n; i++) SA[i] = i;
            
            for (int k = 1; k < n; k *=2)
            {
                countingSort(k);
                countingSort(0);
                int r = 0;
                tempRA[SA[0]] = r;
                for (int i = 1; i < n; i++)
                {
                    tempRA[this->SA[i]] = (RA[this->SA[i]] == RA[this->SA[i-1]] && RA[this->SA[i] + k] == RA[this->SA[i-1] + k]) ? r : ++r;    
                }
                for (int i = 0; i < n; i++)
                {
                    RA[i] = tempRA[i];
                }

                if (RA[this->SA[n-1]] == n-1) break;
            }
            kasai();
            
        }
        // ~SuffixArray(){
        //     delete[] lcp;
        // }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    int nm = 1;
    string text;
    while (cin>>text)
    {
        SuffixArray* sa = new SuffixArray(text);
        
        int ans = sa->lcp[0];
        for (int i = 1; i < sa->n; i++)
        {
            if (sa->lcp[i] > sa->lcp[i-1]) ans += (sa->lcp[i] - sa->lcp[i-1]);
        }
        // printf("%ld\n", ans);
        cout<<ans<<endl;
        T--;
        if (T <= 0) break;
    }
       
    return 0;
}