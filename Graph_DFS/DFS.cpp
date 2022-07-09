#include <iostream>
#include <vector>
using namespace std;

int n, m, a;
vector <int> k[105];
bool visit[105];

void DFS(int u)
{
    visit[u] = true;
    cout << u << ' ';
    for(int i = 0; i < k[u].size(); i++){
        if(!visit[k[u][i]])
            DFS(k[u][i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("DFS.inp", "r", stdin);
    freopen("DFS.out", "w", stdout);

    cin >> n >> m >> a;
    for(int i = 1 ; i <= m; i++){
        int u, v;
        cin >> u >> v;
        k[u].push_back(v);
        k[v].push_back(u);
    }
    DFS(a);
    return 0;
}

