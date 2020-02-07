// rey bafoon ga.....unweighted graph or....limited number of adjacencies ichi...min path or shortest path ante....bfs chesi chavu

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int32_t main()
{
    fastIO();
    string s;
    cin>>s; 
    int n=s.size();

    vector<int> sameValue[10];
    vector<bool> vis(n,false);
    queue<pair<int,int>> q;

    for(int i=1;i<n;i++)
    {
        sameValue[s[i]-'0'].pb(i);
    }

    q.push(make_pair(0,0));
    vis[0]=true;
    while(!q.empty())
    {
        auto p=q.front();
        if(p.f==n-1)
        {
            cout<<p.s<<"\n";
            break;
        }
        q.pop();
        for(int idx : sameValue[s[p.f]-'0'])
        {
            if(!vis[idx])
            {
                vis[idx]=true;
                q.push(make_pair(idx,p.s+1));
            }
        }
        sameValue[s[p.f]-'0'].clear();
        if(p.f-1>=0 && !vis[p.f-1])
        {
            q.push(make_pair(p.f-1,p.s+1));
            vis[p.f-1]=true;
        }

        if(p.f+1<n && !vis[p.f+1])
        {
            q.push(make_pair(p.f+1,p.s+1));
            vis[p.f+1]=true;
        }
    }
    return 0;
}
