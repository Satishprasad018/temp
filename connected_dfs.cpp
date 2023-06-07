#include<iostream>
using namespace std;
int visited[10];
void dfs(int n,int a[10][10],int source)
{
    int i;
    visited[source]=1;
    for(i=1; i<=n; i++)
        if(a[source][i]==1 && visited[i]==0)
            dfs(n,a,i);
}
int main()
{
    int i,j,source,n,a[10][10],count=0;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the adjacency matrix :\n";
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            cin>>a[i][j];

    for(source=1; source<=n; source++)
    {
        for(i=1; i<=n; i++)
            visited[i]=0;
        dfs(n,a,source);
    }

    for(i=1; i<=n; i++)
        if(visited[i]) count++;
    if(count==n)
        cout<<"The graph is connected.\n";
    else
        cout<<"The graph is NOT connected.\n";
    return 0;
}
