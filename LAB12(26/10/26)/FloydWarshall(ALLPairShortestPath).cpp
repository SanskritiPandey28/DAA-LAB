#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void floydWarshall(vector<vector<int>>&dist,int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dist[i][k]!= INF && dist[k][j]!= INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dist(n,vector<int>(n,INF));

    for(int i = 0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;

        dist[u][v] = min(dist[u][v],w);
    }

    for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++){
            if(dist[i][j]==INF)cout<<"INF";
            else cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}