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
int team[100001];
bool vis[100001];
vi adj[100001];
int col,inv;
bool fun(int x, int col){
    vis[x] = true;
    team[x] = col;
    for(int y : adj[x]){
        if(!vis[y]){
            inv = (col == 1)? 2 : 1;
            if(!fun(y,inv))    return false;
        }else{
            if(team[x] == team[y])  return false;
        }
    }
    return true;
}

int main() {
    fast_io;
    int n,m,a,b;
    bool flag = false;
    cin>>n>>m;
    fill(team,team+n+1,0);
    f0(m,i){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    f(1,n+1,i){
        if(vis[i] == false){
            if(!fun(i,1))    
                flag = true;
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        f(1,n+1,i){
            cout<<team[i]<<" ";
        }
    }
    return 0;
}