#include<bits/stdc++.h>


#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define bsm bitset<M>
using namespace std;
const int M = 3005;
const ll inf = 1e18+1;
const int MOD = 1000000007;

int main() {
    fast_io;
    int n,cnt;
    unsigned long long int var;
    cin>>n;
    bsm row[n+1];
    f0(n,i)
        cin>>row[i];
    
    var = 0;
    f(0,n,i){
        f(i+1,n,j){
            cnt = (row[i]&row[j]).count();
            var += cnt*(cnt-1)/2;
        }
    }
    cout<<var<<endl;
    return 0;
}