#include <bits/stdc++.h>
using namespace std;


int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToSuffix(string exp){
    string result = "";
    stack<char> operator_;
    char ch;

    for (size_t i = 0; i < exp.size(); i++)
    {
        ch = exp[i];
        if (isalnum(ch))
        {
            result += ch;
        }
        else if (ch == '(') operator_.push('(');
        else if (ch == ')') {
            while(operator_.top() != '(')
			{
				result += operator_.top();
				operator_.pop();
			}
			operator_.pop();//retirando "("
        }
        else{
            if (!operator_.empty())
            {
                while(!operator_.empty() && prec(exp[i]) <= prec(operator_.top())) {
				    result += operator_.top();
				    operator_.pop();
			    }
			    operator_.push(ch);
            }
            operator_.push(ch);
            
        }
    }
    while(!operator_.empty()) {
		result += operator_.top();
		operator_.pop();
	}

	cout << result << endl;
    

    return result;

}
int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    string text;
    while (n>=0)
    {
        getline(cin, text);
        for(auto x : infixToSuffix(text)) cout<<x<<" ";
        
        cout<<"\n";
        n--; 
    }

    return 0;
    
}

