#include <bits/stdc++.h>

using namespace std;

deque<int> left;
deque<int> right;

void updateDeques(){
    
    int diff = ::left.size() - ::right.size();
	if (diff < 0) {//if  right is larger than left
		double d = (double)diff / -2;
		for (size_t i = 0; i < ceil(d); i++) {
			::left.push_back(::right.front());
			::right.pop_front();
		}
	}
	else if (diff > 1) {//if  left is larger than right
		double d = (double)diff / 2;
		for (size_t i = 0; i < floor(d); i++) {
			::right.push_front(::left.back());
			::left.pop_back();
		}
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries,val;
    cin>>queries;
    string text;  

    for (size_t i = 0; i < queries; i++)
    {
        cin>>text;
        cin>>val;
        if(text == "push_back"){
            ::right.push_back(val);
			updateDeques();
        }else if(text == "push_front"){
            ::left.push_front(val);
			updateDeques();
        }else if(text == "push_middle"){
            ::left.push_back(val);
			updateDeques();
        }else if(text == "get"){
            if (::left.size() > val){
                cout << ::left[val] << "\n";
            }
            else{
                cout << ::right[val - ::left.size()] << "\n";
            }
        }

    }
    return 0;
}
