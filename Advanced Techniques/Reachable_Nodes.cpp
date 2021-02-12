#include<bits/stdc++.h>
#pragma GCC target ("avx2") 
#pragma GCC optimization ("O3") 
#pragma GCC optimization ("unroll-loops")
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
const int MOD = 1e9 + 7;
const int M = 5e4+2;
vi  graph[M];
bitset<M> reach[M];
int out[M];
queue<int> que;
int main() {
    fast_io;
    ll n,m,a,b,v,x;
    cin>>n>>m;
    
    f0(m,i){
        cin>>a>>b;
        graph[b].pb(a);
        out[a]++;
    }
    f(1,n+1,i){
        if(out[i] == 0){
            reach[i][i] = 1;
            que.push(i);
        }
    }
    while(!que.empty()){
        v = que.front(); que.pop();
        for(int x : graph[v]){
            reach[x] |= reach[v] ; 
            out[x]--;
            if(out[x] == 0){
                reach[x][x] = 1;
                que.push(x);
            }
        }
    }
    f(1,n+1,i){
        cout<<reach[i].count()<<" ";
    }
    return 0;
}