#include <bits/stdc++.h>

using namespace std;

char text[1000010];

int brokenKeyboard(int n_key){

    int max_substring = 0;
    int subS_cnt[128];
    int start = 0,c_end = n_key-1;
    int n_text = strlen(text);
    //cout<<n_text<<endl;
    int k_u = 0;
    int cnt_aux = 0;
    //int aux_m = 0;
    
    for (int i = 0; i < 128; ++i) subS_cnt[i] = 0;

    //printf("%d\n", n_text);
    for (int i = 0; i < n_key; ++i){
        if(subS_cnt[text[i]] == 0) {k_u++;}
        subS_cnt[text[i]]++;
    }

    
    while(c_end < n_text-2){

        while(k_u <= n_key && (c_end < n_text-2))
        {
            c_end++;   
            if(subS_cnt[text[c_end]] == 0){
                k_u++;
            }
            subS_cnt[text[c_end]]++;
        }
        
        if(k_u > n_key){
            start++;
        }

        
        if((c_end - start + 1) > max_substring){
            max_substring = c_end - start + 1;
        }

        
        if(subS_cnt[text[start-1]] > 0){
            subS_cnt[text[start-1]]--;
            cnt_aux = subS_cnt[text[start-1]];
            if(cnt_aux == 0){
                k_u--;
            }
        }
    }
    return max_substring;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
      
        scanf("%d", &n_key);
        getchar();

        if(n_key != 0){
            
            cin.ignore();
            int max_substring;
            if (fgets(text, 1000010, stdin) != NULL){
                //string text = cin_text;
                max_substring = brokenKeyboard(n_key);
                //break;
            }
            cout<<max_substring<<endl;
            //printf("%d\n", max_substring);
        }
        else
        {
            break;
        }
    }
        
    return 0;
}
