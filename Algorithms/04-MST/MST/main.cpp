#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct edge{
    int x,y;
    int cost;
};

int cmp(edge e1,edge e2){
    return e1.cost<e2.cost;
}

int findCost(vector<int>& graph,int n){
    if(graph[n]==n)
        return n;

    return 0;
}

int main()
{
    int m,n;
    cin>>m>>n;//m=edge count,n=line count
    int todo=m-1;
    vector<int> graph(m,0);
    vector<edge> edgepool;

    for(int i=0;i<m;i++){
        graph[i]=i;
    }
    int x,y,z;
    for(int i=0;i<n;i++){

        cin>>x>>y>>z;
        edgepool.push_back({x,y,z});
    }
    for(edge tmp:edgepool){
        x=findCost(graph,tmp.x);
        y=findCost(graph,tmp.y);
        if(x==y)
            continue;

    }
    return 0;
}
