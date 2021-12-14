#include "bits/stdc++.h"

using namespace std;

void makeGraph(vector<vector<int>>& graph,int m){
    int f,t,c;
    for(int i=0;i<m;i++){
        cin>>f>>t>>c;
        graph[f][t]=graph[t][f]=c;
    }
}
void printVec(vector<vector<int>> graph){
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[0].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int dilkstra(vector<vector<int>> graph){
    int totalCost=0;
    int totalLine=0;
    int trueline[graph.size()];
    int formline[graph.size()];
    int truetable[graph.size()];
    memset(truetable,0,sizeof(truetable));
    memset(trueline,-1,sizeof(trueline));
    memset(formline,-1,sizeof(formline));
    trueline[0]=formline[0]=0;
    truetable[0]=0;
    while(totalLine<graph.size()-1){
        //find start point
        int mincost=INT_MAX;
        int mincostP=0;
        for(int i=0;i<graph.size();i++){
            if(trueline[i]!=-1&&trueline[i]<mincost&&truetable[i]==0){
                mincost=trueline[i];
                mincostP=i;
            }
        }
        truetable[mincostP]=1;
        totalLine++;
        totalCost+=graph[mincostP][formline[mincostP]];
        //connect
        for(int i=0;i<graph.size();i++){
            if(truetable[i]==0&&graph[mincostP][i]!=-1){
                if(trueline[i]==-1||graph[mincostP][i]<trueline[i]){
                    if(trueline[i]==-1){
                        formline[i]=mincostP;
                        trueline[i]=graph[mincostP][i];
                        continue;
                    }
                    trueline[i]+=graph[mincostP][i];
                    formline[i]=mincostP;
                }
            }
        }
    }
    //write
    cout<<endl<<endl;
    for(int i=0;i<graph.size();i++){
        cout<<i<<" "<<trueline[i]<<" "<<formline[i]<<endl;
    }
    cout<<"TotalCost : "<<totalCost<<endl;
}

int main()
{
    int n,m; //n :point m:line
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(n,-1));
    makeGraph(graph,m);
    dilkstra(graph);

    return 0;
}
