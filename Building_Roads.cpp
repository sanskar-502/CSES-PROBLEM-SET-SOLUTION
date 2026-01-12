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

n cities
m roads 

so minimum number oof required road must be n-1 

*/


int find(int i, vector<int>& parent) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i], parent);
}

void Union(int i, int j, vector<int>& parent, vector<int>& rank) {
    int x_parent = find(i, parent);
    int y_parent = find(j, parent);

    if (x_parent == y_parent)
        return;

    if (rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if (rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[y_parent] = x_parent;
        rank[x_parent]++;
    }
}



void sanskar_502() {
    int n, m;
    cin>>n>>m;

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0); 

    for (int i = 0; i < n+1; ++i)
        parent[i] = i;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;

        Union(a,b, parent, rank);
    }

    // n parents then  n-1  roads extra required

    set<int> ans;

    for(int i=1; i<=n; i++){
        ans.insert(find(i, parent));
    }


    cout<<ans.size()-1<<nl;
    
    int prev = -1;
    for(auto &it : ans){
        if( prev == -1){
            prev= it;
            continue;
        }

        cout<<prev<<sp<<it<<nl;
        prev=it;
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