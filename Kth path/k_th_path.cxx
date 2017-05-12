struct Node
{

    int city,cost;
    Node() {}
    Node(int city,int cost):city(city),cost(cost) {}
    bool operator < (const Node &a) const
    {

        return cost>a.cost;
    }
};
int vis[mx];
int d[15][mx];
void ssp(int src,int k_th)
{

    FOR0(i,node+1)
    FOR0(j,k+1)
    d[j][i]=1<<30;
    memset(vis,0,sizeof vis);

    priority_queue<Node>PQ;
    PQ.push(Node(src,0));
    while(!PQ.empty())
    {
        Node f=PQ.top();
        PQ.pop();
        if(vis[f.city]>k_th)continue;
        d[vis[f.city]][f.city]=f.cost;
        vis[f.city]+=1;
        int u=f.city;
        for(int i=0;i<G[u].size();i++){

        int v=G[u][i];
        int c=dis[u][i];
        PQ.push(Node(v,f.cost+c));

        }
    }
    if(d[k_th-1][des]==(1<<30))puts("-1");
    else
    cout<<d[k_th-1][des]<<"\n";
}
