#include <iostream>
#include<map>
#include<list>
using namespace std;

void ad_matrix(int n)
{
    int arr[100][100];
    // arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        // arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }


    int i, j,w;
    cout << "enter the node between edges" << endl;
    cin >> i >> j>>w;
    while (i != -1 && j != -1)
    {
        arr[i - 1][j - 1] = w;
        arr[j - 1][i - 1] = w;

        cout << "enter the node between edges" << endl;
        cin >> i >> j>>w;
    }

    cout << "matrix display" << endl;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }
}

class ad_list{
    public:
    map<int , list<int> > adj;

    void create(int u , int v , int direcn){
        //for direction = 0 , it is directed
        //for direction = 1 , it is undirected
        adj[u].push_back(v);

        if(direcn == 1){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto & value : adj){
            cout<<value.first<<" ";
            for(auto & j : value.second){
                cout<<j<<" ";
            }
           cout<<endl;
        }
    }
};

int main()
{
    cout << "no. of edges" << endl;
    int n;
    cin >> n;
    ad_matrix(n);
    
    // ad_list ad;
    // for(int i = 0 ; i < n ; i++){
    //     cout<<"edge no "<<i+1<<endl;
    //     int u , v ;
    //     int d = 1 ;
    //     cin>>u>>v;
    //     ad.create(u, v, d);
    // }

    // ad.print();
     return 0;
}