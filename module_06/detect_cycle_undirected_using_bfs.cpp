#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool visited[101];
int parent[101];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        // ber kore ana
        int par = q.front();
        q.pop();

        // oi node ke niye kaj

        // children push
        for (auto child : adj_list[par])
        {
            if (visited[child] && parent[par] != child)
                cycle = true;

            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
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
            bfs(i);

    if (cycle)
        cout << "Cycle detected\n";
    else
        cout << "No cycle found\n";
    return 0;
}