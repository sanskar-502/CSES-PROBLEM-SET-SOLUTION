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
here it is undirected graph without any weight so simple bfs work here

*/

void bfs(int node, unordered_map<int, vector<int>> & adj, int n, vector<int> &parent, bool &flag){

    queue<int> q;
    q.push(node);
    vector<bool> visited(n + 1, false);
    parent[node] = -1;


    while(!q.empty()){
        int N= q.size();

        while(N--){
            int front = q.front();
            q.pop();

             if(front == n){
                flag= true;
                return;
            }

            for (auto& neigh : adj[front]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    parent[neigh] = front;
                    q.push(neigh);
            }
        } 
      }
    }
}


void sanskar_502() {
    int n;
    int m;
    cin>>n>>m;

    unordered_map<int, vector<int>> adj;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n+1, -1);

    bool flag= false;

    bfs(1, adj, n, parent, flag);

    if(flag== false){
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }

    vector<int> ans;
    ans.push_back(n);

    int i= n;

    while(i != 1){
        i= parent[i];
        ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<nl;

    for(auto &ele : ans){
        cout<<ele<<sp;
    }

    cout<<endl;
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