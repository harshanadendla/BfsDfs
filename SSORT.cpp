// bavundi...arthamaindi...min num of swaps is sigma(k-1) where k=number of v in each component.
// for  min cost...minV is added k-1 times and rest all other elements will be added once....minV can be minV of that particular comp
// or the minV of overall graph...compare the cost and take the min one.
// kottaga nerchukunna line while(cin>>n && n){ //wah }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;

vector<int> a(N),b(N);
vector<bool> vis(N);
int minV=1000;
int sum=0;
int ans=0;
int k=0;
unordered_map<int,int> idx;

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int n,t=1;
    while(cin>>n && n)
    {
        ans=0;
        idx.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            vis[i]=false;
        }
        sort(b.begin()+1,b.begin()+n+1);
        for(int i=1;i<=n;i++)
        {
            idx[b[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                // dfs(a[i]);
                if(idx[a[i]]==i)
                {
                    vis[i]=true;
                    continue;
                }
                sum=0;
                minV=a[i];
                k=0;
                int j=i;
                while(!vis[j])
                {
                    sum+=a[j];
                    minV=min(minV,a[j]);
                    k++;
                    vis[j]=true;
                    // graph cycle sums lo next idx step last lo undali.
                    j=idx[a[j]];
                }
                sum-=minV;
                int x=2*(b[1]+minV)+(k-1)*b[1];
                if((k-1)*minV < x)
                {
                    ans+=(sum+(k-1)*minV);
                }
                else
                {
                    ans+=(sum+x);
                }
            }
        }
        cout<<"Case "<<t<<": "<<ans<<"\n\n";
        t++;
    }
    return 0;
}
