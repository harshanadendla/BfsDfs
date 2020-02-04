// bfs is my thing when i dont forget vis...damn that lunchtime...costed me -40..instead of +...ok..parla...keep going

#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

void pre()
{
    for (int i = 1000; i <= 9999; i++)  
    {  
        bool flag = 1; 
  
        for (int j = 2; j <= i / 2; ++j)  
        { 
            if (i % j == 0)  
            { 
                flag = 0; 
                break; 
            } 
        } 
        if (flag == 1) primes.push_back(i); 
    }
}

bool oneDigitChange(int a,int b)
{
    int count=0;
    while(a>0)
    {
        if(a%10 == b%10) count++;
        a/=10;
        b/=10;
    }
    return (count==3);
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    pre();
    vector<bool> vis(10000,false);
    int t,p1,p2;
    cin>>t;

    queue<pair<int,int>> q;

    while(t--)
    {
        cin>>p1>>p2;
        if(p1==p2)
        {
            cout<<"0\n";
        }
        else
        {
            bool flag=false;
            for(int i=0;i<10000;i++) vis[i]=false;
            q=queue<pair<int,int>>();
            q.push(make_pair(p1,0));
            while(!q.empty())
            {
                pair<int,int> p=q.front();
                q.pop();
                if(p.first==p2)
                {
                    flag=true;
                    cout<<p.second<<"\n";
                    break;
                }
                if(vis[p.first]) continue;
                vis[p.first]=true;
                for(int i : primes)
                {
                    if(oneDigitChange(p.first,i) && !vis[i])
                    {
                        q.push(make_pair(i,p.second+1));
                    }
                }
            }
            if(!flag) cout<<"Impossible\n";
        }
    }
    return 0;
}
