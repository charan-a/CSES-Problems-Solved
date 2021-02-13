#include<bits/stdc++.h>
//#pragma GCC target ("avx2")
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
int sub[lmt];
 
int trav(int nd){
 
    for(int ch : tree[nd]){
        sub[nd] += 1 + trav(ch);
    }
    return sub[nd];
}
 
int main() {
    fast_io;
    int n,x;
    cin>>n;
    f(2,n+1,i){
        cin>>x;
        tree[x].pb(i);
    }
    //fill(sub,sub+n+1,1);
    trav(1);
    f(1,n+1,i){
        cout<<sub[i]<<" ";
    }
    return 0;
}