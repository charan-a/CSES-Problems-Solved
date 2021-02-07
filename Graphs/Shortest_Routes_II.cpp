#include<bits/stdc++.h>

typedef long long int ll;
#define vi vector<int>
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
#define vii vector<int,int>
#define sz(x) (int)(x).size()
#define pr_mat2(x) for(auto &i : x){ for( &j : i){ cout<<j<<" "; } cout<<endl;}cout<<endl;
#define pr_mat(x,n,m) f(1,n+1,i){ f(1,m+1,j){ cout<<x[i][j] <<" "; } cout<<endl;}cout<<endl;
#define pr_arr(x) for(auto &i : x){ cout <<i<<" "; } cout<<endl;
using namespace std;

const ll inf = 1e18 + 3;
const int MOD = 1000000007;

ll dis[503][503];

int main() {
    fast_io;
    ll n,m,q,a,b,c,var;
    cin>>n>>m>>q;
    f0(n+1,i)
        f(i,n+1,j)
            dis[i][j] = dis[j][i] = inf;
    f0(m,i){
        cin>>a>>b>>c;
        dis[a][b] = dis[b][a] = min(c,dis[a][b]);
    }
    
    f(1,n+1,v){
        f(1,n+1,i){
            f(1,n+1,j){
                dis[i][j] = min(dis[i][j], dis[i][v] + dis[v][j]);
            }
        }
    }

    f0(q,i){
        cin>>a>>b;
        if(dis[a][b] == inf) dis[a][b] = -1;
        cout<<dis[a][b]<<endl;
    }
    return 0;
}