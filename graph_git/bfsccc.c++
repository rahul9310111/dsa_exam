#include<bits/stdc++.h>
 

using namespace std;

class graph{
    public:
    int vertices;
    map<int , list<int>> adj;
    
    graph(int v){
        vertices = v;
    }
    


    void create(int u , int v , bool direc){
        adj[u].push_back(v);

        if(direc == 0 ){
            adj[v].push_back(u);
        }
    }

    void bfs(int start , vector<int> &connected,vector<bool>& visited){
            queue<int> q;
            q.push(start);
            visited[start] = true;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it : adj[temp]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=  true;
                }
            }
        }

    }

    void dfs(int start , vector<int> & visited , vector<int> &ans){
        ans.push_back(start);
        visited[start] = true;
        for(auto it : adj[start]){
            if(!visited[it]){
                dfs(it,visited,ans);
            }
        }
    }

    vector<vector<int>> dfe_com(){
        vector<vector<int>> total;
        
        vector<bool> visited(vertices , false);

        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                vector<int> ans;
                dfs(i, visited, ans);
                total.push_back(ans);
            }
        }
    return total;
    }

    void complete(){

        int count = 0;
        vector<bool> visited(vertices, false);
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                vector<int> connected;
                bfs(i,connected , visited);

                cout<<"connected component "<<endl;
                for(auto it : connected){
                    cout<<"( "<<it<<" )";
                }
                count++;
                cout<<endl;
            }
        }

        cout<<"total no of onnected component is "<<count<<endl;
    }



    

};

int main() {
    // int n ;
    // cout<<"enter the no of node"<<endl;
    // cin>>n;

    // int m ; 
    // cout<<"enter the no edges"<<endl;
    // cin>>m;
    // graph g;

    // for(int i = 0 ; i < m ; i ++){
    //     int u , v;
    //     cin >> u >> v;
    //     g.create(u,v,0);
    // }

    // // g.print(

    return 0;
}