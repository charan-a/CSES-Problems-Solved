#include<bits/stdc++.h>

#define ll long long;
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define f first
#define s second
// #define f(a,b,i) for(int i = a; i < b; i++)
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

char mat[1001][1001];
bool vis[1001][1001];
int path[1001][1001];
int n,m,x,y;
int row[] = {1,0,-1,0};
int col[] = {0,-1,0,1};
char dir[] = {'D','L','U','R'};
queue<pii> que;
pii temp;

void bfs(int x,int y){
    pii p = mp(x,y);
    que.push(p);
    vis[x][y] = true;
    while(!que.empty()){
        temp = que.front(); que.pop();
        f0(4,i){
            pii pp = mp(temp.f + row[i], temp.s + col[i]);
            x = pp.f; y = pp.s;
            if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] == '#' || vis[x][y])
                continue;
            else if(mat[x][y] == 'B'){
                vis[x][y] = true;
                path[x][y] = i;
                return;
            }
            vis[x][y] = true;
            path[x][y] = i;
            que.push(pp);
        }
    }
}

int main(){
    fast_io;
    int val;
    pii start, end;
    cin>>n>>m;
    f0(n,i)
        f0(m,j)
            cin>>mat[i][j];
    f0(n,i)
        f0(m,j){
            if(mat[i][j] == 'A'){
                start = mp(i,j);
            }else if(mat[i][j] == 'B')
                end = mp(i,j);
        }
    
    bfs(start.f,start.s);
    if(vis[end.f][end.s]){
        cout<<"YES"<<endl;
        vi steps;
        while(start != end){    
            val = path[end.f][end.s]; 
            steps.pb(val);
            end = mp(end.f - row[val], end.s - col[val]);
        }
        reverse(all(steps));
        cout<<sz(steps)<<endl;
        for(int z : steps)
            cout<<dir[z];
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}
