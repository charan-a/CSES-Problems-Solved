#include<bits/stdc++.h>

#define ll long long;
#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define f(a,b,i) for(int i = a; i < b; i++)
#define f0(a,i) for(int i = 0; i < a; i++)
#define fe(a,b,i) for(int i = a; i <= b ; i++)
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define pr(x) cout<< x <<endl
#define vii vector<int,int>
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1000000007;
int dis[100001];
int path[100001];
vector<int> adj[100001];

int main() {
    fast_io;
    int n,m,a,b,val,x;
    cin>>n>>m;
    pii node;
    fill(dis,dis+n+2,INT_MAX);
    fill(path,path+n+2,-1);
    priority_queue< pii,vector<pii>, greater<pii> > heap;
    f0(m,i){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dis[1] = 0;path[0] = -2;path[1] = 0;
    heap.push(mp(1,1));
    while(!heap.empty()){
        node = heap.top();heap.pop();
        val = node.ff;
        for(int x : adj[node.ss]){
            if(dis[x] > val + 1){
                path[x] = node.ss;
                dis[x] = val + 1;
                heap.push(mp(dis[x],x));
            }
        }
    }
    if(dis[n] != INT_MAX){
        cout<<dis[n]<<endl;
        vi ans;
        x = n;
        while(path[x] != -2){
            ans.pb(x);
            x = path[x];
        }
        reverse(all(ans));
        f0(sz(ans),i)
            cout<<ans[i]<<" ";
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}