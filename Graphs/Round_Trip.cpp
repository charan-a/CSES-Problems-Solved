#include<bits/stdc++.h>

#define ll long long;
#define vi vector<int>
#define pii pair<int, int>
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
int vis[100001];
int parent[100001];
vi adj[100001];
int start,dest,temp;
vi path;

bool dfs(int x, int p){
    vis[x] = true;
    parent[x] = p;
    for(int ch : adj[x]){
        
        if(ch == p) continue;
        if(vis[ch]){
            start = ch; dest = x;
            return true;
        }
        if(!vis[ch]){
            if(dfs(ch,x))   return true;
        }
        
    }
    return false;
}

int main() {
    fast_io;
    int n,m,a,b,l;
    bool flag = false;
    cin>>n>>m;
    f0(m,i){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    f(1,n+1,i){
        if(!vis[i] && dfs(i,-1)){
            flag = true;
            break;
        }
    }
    // dfs(1,-1);
    // f(1,n+1,j){
    //     cout<<parent[j]<<" ";
    // }
    // f(1,n+1,i){
    //     cout<<i<<": ";
    //     for(int x : adj[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    if(flag){
        temp = dest;
        path.pb(dest);
        while(start != dest){
            path.pb(parent[dest]);
            dest = parent[dest];
        }
        path.pb(temp);
        cout<<sz(path)<<endl;
        f0(sz(path),i){
            cout<<path[i]<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}