// bfs anta le...dfs kadu....howle ga....dfs at everey node badulu bfs ani konchem kooda alochinchala howle//
// howle....bfs lo queue and vis clear cheyyali//

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5;
int t,n,a,b,idx,maxlen;
vector<int> graph[N];
vector<bool> vis(N);
queue<pair<int,int>> q;

int bfs(int u)
{
    q=queue<pair<int,int>>();
    q.push(make_pair(u,0));
    for(int i=0;i<n;i++) vis[i]=false;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        vis[p.first]=true;
        if(maxlen<p.second)
        {
            maxlen=p.second;
            idx=p.first;
        }
        for(int i : graph[p.first])
        {
            if(!vis[i]) q.push(make_pair(i,p.second+1));
        }
    }
    return idx;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        maxlen=0;
        cin>>n;
        for(int i=0;i<n;i++) 
        {
            graph[i].clear();
            vis[i]=false;
        }
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs(bfs(0));
        cout<<(maxlen+1)/2<<"\n";
    }
    return 0;
}
