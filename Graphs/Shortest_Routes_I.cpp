#include<bits/stdc++.h>
typedef long long int ll;

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
// #define pr_mat(x,n,m) f(1,n+1,i){f(1,m+1,j){ cout<<x[i][j]<<" "; } cout<<endl;}cout<<endl;

using namespace std;

const int MOD = 1000000007;
ll dis[100001];
ll diff[10001][10001];
vector<int> adj[100001];

int main(){
    fast_io;
    ll n,m,a,b,c,val,temp;
    cin>>n>>m;
    pii node;
    f0(n+1,i)   dis[i] = 10002;
    f0(n+1,i){
        fill_n(diff[i],diff[n]+m+1,INT_MAX);
    }
    priority_queue< pii,vector<pii>, greater<pii> > heap;
    f0(m,i){
        cin>>a>>b>>c;
        adj[a].pb(b);
        if(c > diff[a][b]) c = diff[a][b];
        diff[a][b] = c;
    }
    
    heap.push(mp(0,1));
    dis[1] = 0;
    while(!heap.empty()){
        node = heap.top();heap.pop();
        val = node.ff;
        for(int x : adj[node.ss]){
            temp = diff[node.ss][x];
            if(dis[x] > val + temp){
                dis[x] = val + temp;
                heap.push(mp(dis[x],x));
            }
        }
    }
    f(1,n+1,i){
        cout<<dis[i]<<" ";
    }
    return 0;
}