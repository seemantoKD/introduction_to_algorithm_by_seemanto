#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool visited[101];
int path[101];
bool cycle;

void dfs(int src)
{
    visited[src] = true;
    path[src] = true;

    for (auto child : adj_list[src])
    {
        if (visited[child] && path[child])
            cycle = true;

        if (!visited[child])
        {
            dfs(child);
        }
    }
    // return -> ekhan theke backtrack shuru , backtrack shru hoile sathe sathe path_visited false hobe
    path[src] = false;
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
    }

    memset(visited, false, sizeof(visited));
    memset(path, false, sizeof(path));
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