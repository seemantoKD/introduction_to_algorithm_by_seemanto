#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin>>node>>edge;

    vector<pair<int,int>>adj_list[node];
    while(edge--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    for(int i = 0;i<node;i++)
    {
        cout<<i<<" -> ";
        for(auto val : adj_list[i])
            cout<<val.first<<" "<<val.second<<' ';
        cout<<endl;
    }
    return 0;
}