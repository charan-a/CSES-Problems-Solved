#include<bits/stdc++.h>
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
typedef long long int ll;
 
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define f(a,b,i) for(int i = a; i < b; i++)
#define f0(a,i) for(int i = 0; i < a; i++)
#define fe(a,b,i) for(int i = a; i <= b ; i++)
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define pr(x) cout<< x <<endl
#define endl "\n"
#define vii vector<int,int>
#define sz(x) (int)(x).size()
#define pr_mat2(x) for(auto &i : x){ for( &j : i){ cout<<j<<" "; } cout<<endl;}cout<<endl;
#define pr_mat(x,n,m) f(1,n+1,i){ f(1,m+1,j){ cout<<x[i][j] <<" "; } cout<<endl;}cout<<endl;
#define pr_arr(x) for(auto &i : x){ cout <<i<<" "; } cout<<endl;
using namespace std;
const ll inf = 1e18+1;
const int MOD = 1000000007;
const int lmt = 2e5+2;
vi tree[lmt];
int dp[lmt][2];
bool vis[lmt];
int l,tot,cnt;
 
void sol(int nd, int prt){
        vis[nd] = true;
        for(int ch : tree[nd]){
            if(ch == prt) continue;
            sol(ch,nd);
            dp[nd][0] += dp[ch][1];
        }
        for(int ch : tree[nd]){
            if(ch == prt) continue;
            dp[nd][1] = max(dp[nd][1], 1 + dp[nd][0] - dp[ch][1] + dp[ch][0]);
        }
}
 
int main() {
    fast_io;
    int n,a,b,mx = 0,t;
    cin>>n;
//    fill(vis,vis+n+1,false);
    f0(n-1,i){
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    f(1,n+1,i){
        if(!vis[i])
            sol(i,-1);
    }
    f(1,n+1,i)
        mx = max(mx,max(dp[i][0],dp[i][1]));
    cout<<mx<<endl;
 
    return 0;
}