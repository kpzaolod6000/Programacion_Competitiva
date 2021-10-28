#include <bits/stdc++.h>
//con @ se altera la entrada
using namespace std;

string CapsLock(string text) {
    string result = "";
    queue<char> buffer;
    bool isEnable = false;
    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == '$')
        {
            while (!buffer.empty())
            {
                result += buffer.front();
                buffer.pop();
            }
            
        }else if (text[i] == '@'){

            for (size_t x = 0; x < text.size(); x++)
            {
                buffer.push(toupper(buffer.front()));
                buffer.pop();
            }
            
            isEnable = isEnable == true ? false : true;
        }else{
            if (isEnable) buffer.push(toupper(text[i]));
            else buffer.push(text[i]);
        }
        
    }
    


    return result;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text;
    cin>>text;
    
    
    // for(auto x : H) cout<<x<<" ";
    cout<<CapsLock(text)<<"\n";
    return 0;
    
}

