#include<bits/stdc++.h>
//#pragma GCC target ("avx2") 
// #pragma GCC optimization ("O3") 
// #pragma GCC optimization ("unroll-loops")
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define f(a,b,i) for(int i = a; i < b; i++)
#define fr(a,b,i) for(int i = a; i > b; i--)
#define f0(a,i) for(int i = 0; i < a; i++)
#define fe(a,b,i) for(int i = a; i <= b ; i++)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset(x, 0 , sizeof(x));
#define read(x) int x; cin >> x
#define pr(x) cout<< x <<endl
#define endl "\n"
#define sz(x) (int)(x).size()
#define pr_mat2(x) for(auto &i : x){ for( &j : i){ cout<<j<<" "; } cout<<endl;}cout<<endl;
#define pr_mat(x,n,m) f(1,n+1,i){ f(1,m+1,j){ cout<<x[i][j] <<" "; } cout<<endl;}cout<<endl;
#define pr_arr(x) for(auto &i : x){ cout <<i<<" "; } cout<<endl;
using namespace std;
const ll inf = 1e18+1;
const int MOD = 1e9+7;
const int lmt = 2e5+2;

int up[lmt][19];
vi tree[lmt];
int in[lmt];
int out[lmt];
int lvl[lmt];
int timer;

void dfs(int nd , int par, int dth){
    in[nd] = ++timer;
    up[nd][0] = par;
    lvl[nd] = dth;
    f(1,19,i)   up[nd][i] = up[up[nd][i-1]][i-1];
    
    for(auto x : tree[nd])
        if(x != par)    dfs(x,nd,dth+1);
    
    out[nd] = ++timer;
}


int ispar(int x ,int y){
    return ( in[x] <= in[y] && out[x] >= out[y] );
}

int ans(int a, int b){
    if(ispar(a,b))
        return a;
    if(ispar(b,a))
        return b;
    fr(18,-1,i){
        if(!ispar(up[a][i],b))
            a = up[a][i];
    }
    return up[a][0];

}

int main() {
    fastio
    int n,q,x,a,b,pt,val;
    cin>>n>>q;
    f(2,n+1,i){
        cin>>x;
        tree[i].pb(x);
        tree[x].pb(i);
    }
    dfs(1,1,0);
    while(q--){
        cin>>a>>b;
        pt = ans(a,b);
        val = 2*lvl[pt] - lvl[a] - lvl[b];
        cout<<val<<endl;
    }
    return 0;
}