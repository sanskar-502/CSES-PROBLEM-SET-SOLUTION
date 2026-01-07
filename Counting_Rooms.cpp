#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

#define len(x) int((x).size())
#define pb push_back

bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

/* Result and Observations


*/
vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isSafe(int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
}

void dfs(int i, int j, vector<vector<bool>> & visited, int n, int m, vector<vector<int>> &arr ){

    visited[i][j]= true;

    for(auto & dir : directions){
        int x = i + dir[0];
        int y= j + dir[1];
        
        if(isSafe(x, y, n, m) && arr[x][y]==1 && !visited[x][y]){
            dfs(x, y, visited, n, m, arr);
        }
    }
}


void bfs(int i, int j, vector<vector<bool>> &visited, int n, int m, vector<vector<int>> &arr) {

    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto &dir : directions) {
            int x = r + dir[0];
            int y = c + dir[1];

            if (isSafe(x, y, n, m) && arr[x][y] == 1 && !visited[x][y]) {
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

void sanskar_502() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>>arr(n, vector<int>(m));

    for(int i=0; i<n; i++){       // 1 room  and 0 wall
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            if(x == '#')
                arr[i][j]=0;
            else
                arr[i][j]=1;
        }
    }

    vector<vector<bool>> visited(n, vector<bool> (m, false));

    int cnt=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]== 1 ){
                if(!visited[i][j]){
                    bfs(i, j, visited, n, m, arr);
                    cnt++;
                }
            }
        }
    }

    cout<<cnt<<endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        sanskar_502();
}

/*
    Golden Rules:
    Solutions are simple.
    Proofs are simple.
    Implementations are simple.
*/