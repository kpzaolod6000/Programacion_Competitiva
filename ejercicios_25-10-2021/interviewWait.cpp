#include <bits/stdc++.h>
using namespace std;

int interviewWait(vector<int>& timeWait) {
    deque<char> timeW;
    int left,right;
    for(int i = 0; i < timeWait.size(); i++) timeW.push_back(timeWait[i]);
    int interTime = 0;

    for (size_t i = 0; i < timeW.size(); i++)
    {
        left = timeW.front();
        right = timeW.back();
        int minTime = min(left,right);
        if (minTime != -1)
        {
            if (minTime == left) timeW.pop_front();
            else if (minTime == right) timeW.pop_back();
            interTime += minTime;
        }else return interTime;
    }
    
    return interTime;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> timeWait(n);
    for (int i = 0; i < n; i++) cin>>timeWait[i];
    cout<<interviewWait(timeWait)<<"\n";

    return 0;
    
}

