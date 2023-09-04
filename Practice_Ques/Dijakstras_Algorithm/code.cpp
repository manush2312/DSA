#include<iostream>
using namespace std;

int findMinVertex(int visited[], int distance[], int n)
{
    int minIndex, minval=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && distance[i]<minval)
        {
            minval=distance[i];
            minIndex=i;
        }
    }

    return minIndex;
}

//5 6 1 2 10 2 3 50 4 3 20 4 5 60 1 5 100 1 4 30

int main()
{
    int v,e;
    cout<<"Enter vertices and edges"<<endl;
    cin>>v>>e;
    int a[20][20];

    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            a[i][j]=0;
        }
    }

    for(int i=1;i<=e;i++)
    {
        int s,d,len;
        cout<<"enter source destination and path length"<<endl;
        cin>>s>>d>>len;
        a[s][d]=len;
    }

    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int visited[10];
    for(int i=1;i<=v;i++)
    {
        visited[i]=0;
    }
    int sv;

    cout<<"Enter start vertex"<<endl;
    cin>>sv;

    int distance[10];
    for(int i=1;i<=v;i++)
    {
        if(i!=sv)
            distance[i]=INT_MAX;
    }

    for(int i=1;i<=v;i++)
    {
        int curr=findMinVertex(visited, distance, v);
        visited[curr]=1;
        for(int j=1;j<=v;j++)
        {
            if(visited[i]==0 && a[curr][j]!=0)
            if(distance[i]>distance[curr]+a[curr][j])
                distance[i]=distance[curr]+a[curr][j];
        }
    }

    for(int i=1;i<=v;i++)
    {
        cout<<i<<"->";

        if(distance[i]==INT_MAX)
            cout<<"Unreachable"<<endl;
        else
            cout<<distance[i]<<" "<<endl;;
    }

    return 0;

}
