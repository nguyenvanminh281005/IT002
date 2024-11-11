#include <bits/stdc++.h>
using namespace std;
#define ppi pair<int, int>

void oti(ppi inp)
{
    int hi = __gcd(inp.first,inp.second);
    inp.first/=hi;
    inp.second/=hi;
    if (inp.second == 1) 
    {
        cout<<inp.first;
    }
    else if (inp.first == 0)
    {
        cout<<0;
    }
    else
    {
        cout<<inp.first<<"/"<<inp.second<<endl;
    }
}

int main()
{
    ppi a,b,sum,cur,acc,did;
    cin>>a.first>>a.second>>b.first>>b.second;

    sum.first = a.first*b.second + a.second*b.first;
    sum.second = a.second*b.second;
    
    cur.first = a.first*b.second - a.second*b.first;
    cur.second = a.second*b.second;

    acc.first = a.first*b.first;
    acc.second = a.second*b.second;

    did.first = a.first*b.second;
    did.second = a.second*b.first;

    oti(sum);
    oti(cur);
    oti(acc);
    oti(did);

    return 0;
}