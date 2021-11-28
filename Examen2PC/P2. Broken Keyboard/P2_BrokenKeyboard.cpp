#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        
        int n_key;
        cin>>n_key;
        

        if(n_key == 0) break;
        else
        {
            
            char cin_text[1000010];
            cin.ignore();
            if (fgets(cin_text, 1000010, stdin) != NULL){
                string text = cin_text;
                int max_substring = 0;
            
                vector<int> subS_cnt(128);
                int start = 0,end = n_key-1;
                int n_text = text.length();
                int k_u = 0;
                int cnt_aux = 0;
                //int aux_m = 0;
                
                for (int i = 0; i < 128; ++i) subS_cnt[i] = 0;

                for (int i = 0; i < n_key; ++i){
                    if(subS_cnt[text[i]] == 0) {k_u++;}
                    subS_cnt[text[i]]++;
                }

                
                while(end < n_text-2){
            
                    while(k_u <= n_key && (end < n_text-2))
                    {
                        end++;   
                        if(subS_cnt[text[end]] == 0){
                            k_u++;
                        }
                        subS_cnt[text[end]]++;
                    }
                    
                    if(k_u > n_key){
                        start++;
                    }

                    
                    if((end - start + 1) > max_substring){
                        max_substring = end - start + 1;
                    }

                    
                    if(subS_cnt[text[start-1]] > 0){
                        subS_cnt[text[start-1]]--;
                        cnt_aux = subS_cnt[text[start-1]];
                        if(cnt_aux == 0){
                            k_u--;
                        }
                    }
                }
                
                printf("%d\n", max_substring);
                //break;
            }
        }
    }
        
    return 0;
}
