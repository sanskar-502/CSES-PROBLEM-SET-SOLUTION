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

vector<vector<int>> directions = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}};  // L R U D

map<pair<int,int>, char> mp = {
    {{0, -1}, 'L'},
    {{0,  1}, 'R'},
    {{-1, 0}, 'U'},
    {{1,  0}, 'D'}
};


bool isSafe(int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
}

string res= "";

void dfs(int i, int j, vector<vector<bool>> & visited, int n, int m, vector<vector<int>> &arr, pair<int ,int> start, pair<int ,int> end, string &s ){

    visited[i][j]= true;

    if (end.first == i && end.second == j) {
    if (res == "" || s.size() < res.size())
        res = s;
        visited[i][j] = false; 
        return;           
    }


    for(auto & dir : directions){
        int x = i + dir[0];
        int y= j + dir[1];
        
        if(isSafe(x, y, n, m) && arr[x][y] !=0 && !visited[x][y]){

            s += mp[{dir[0], dir[1]}];
            dfs(x, y, visited, n, m, arr, start, end, s);
            s.pop_back();
        }
    }

    visited[i][j] = false;
}

string buildPath(pair<int,int> start, pair<int,int> end, vector<vector<pii>> &parent, vector<vector<char>> &moveTaken) {

    string path;
    pair<int,int> cur = end;

    while (cur != start) {
        path.push_back(moveTaken[cur.first][cur.second]);
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());
    return path;
}


bool bfs(pair<int,int> start, pair<int,int> end, int n, int m, vector<vector<int>> &arr, vector<vector<bool>> &visited, vector<vector<pii>> &parent, vector<vector<char>> &moveTaken) {

    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (i == end.first && j == end.second)
            return true;   // shortest path found

        for (auto &dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (isSafe(x, y, n, m) &&
                arr[x][y] != 0 &&
                !visited[x][y]) {

                visited[x][y] = true;
                parent[x][y] = {i, j};
                moveTaken[x][y] = mp[{dir[0], dir[1]}];
                q.push({x, y});
            }
        }
    }
    return false;
}

void sanskar_502() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    pair<int ,int> start = {-1, -1};
    pair<int, int> end   = {-1, -1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x;
            cin >> x;
            if(x == '#') arr[i][j] = 0;
            else if(x == '.') arr[i][j] = 1;
            else if(x == 'A'){
                arr[i][j] = -1;
                start = {i, j};
            }
            else if(x == 'B'){
                arr[i][j] = -2;
                end = {i, j};
            }
        }
    }

    if(start.first == -1 || end.first == -1){
        cout << "NO\n";
        return;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    vector<vector<char>> moveTaken(n, vector<char>(m));

    bool found = bfs(start, end, n, m, arr, visited, parent, moveTaken);

    if (!found) {
        cout << "NO\n";
    } else {
        string res = buildPath(start, end, parent, moveTaken);
        cout << "YES\n";
        cout << res.size() << '\n';
        cout << res << '\n';
    }
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