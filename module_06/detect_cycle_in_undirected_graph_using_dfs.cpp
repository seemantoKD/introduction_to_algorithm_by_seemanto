#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool visited[101];
int parent[101];
bool cycle;

void dfs(int src)
{
    visited[src] = true;

    for(auto child : adj_list[src])
    {
        if(visited[child] && parent[src] != child)
            cycle = true;
            
        if(!visited[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cycle = false;

    for (int i = 0; i < node; i++)
        if (!visited[i])
            dfs(i);

    if (cycle)
        cout << "Cycle detected\n";
    else
        cout << "No cycle found\n";
    return 0;
}