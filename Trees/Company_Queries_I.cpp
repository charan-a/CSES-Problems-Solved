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

int blift[200005][20];
vi tree[200005];

void dfs(int nd , int par){
    blift[nd][0] = par;
    f(1,20,i){
        if(blift[nd][i-1] != -1)
            blift[nd][i] = blift[blift[nd][i-1]][i-1];
        else
            blift[nd][i] = -1;
    }
    for(auto x : tree[nd]){
        if(x != par)
            dfs(x,nd);
    }
}

int qry(int nd, int h, int t){
    if(h == 0 || nd == -1)
        return nd;
    while((1<<t) > h )
        t--;
    return qry(blift[nd][t], h - (1<<t), t);
}

int main() {
    fastio
    int n,q,x,a,h;
    cin>>n>>q;
    f(2,n+1,i){
        cin>>x;
        tree[i].pb(x);
        tree[x].pb(i);
    }
    dfs(1,-1);
    while(q--){
        cin>>a>>h;
        cout<<qry(a,h,19)<<endl;
    }
    return 0;
}