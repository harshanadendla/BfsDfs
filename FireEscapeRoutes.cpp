#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

const int N=1e5+10;
int t,n,m,a,b,k,ways;
vector<int> graph[N];
vector<bool> vis(N);
int subset;

void setMemories()
{
    for(int i=0;i<N;i++)
    {
        graph[i].clear();
        vis[i]=false;
    }
    subset=1;
    k=0;
    ways=1;
}

void dfs(int u)
{
    vis[u]=true;
    k++;
    for(int i : graph[u])
    {
        if(!vis[i]) dfs(i);
    }
}

int32_t main()
{
    cin>>t;
    while(t--)
    {
        setMemories();
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) 
            {
                dfs(i);
                ways*=(k%mod);
                ways%=mod;
                subset++;
                k=0;
            }
        }
        cout<<subset-1<<" "<<ways<<"\n";
    }
    return 0;
}