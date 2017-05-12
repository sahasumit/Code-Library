int mapping_node(int a)
{
    if(a<=0)
    {
        a*=-1;

        return  (2*a)-1;

    }
    else
    {

        return (2*a)-2;
    }

}
#define mx  8005
vector<int>G[mx*2],G_I[2*mx];
int timer=0;
bool visit[mx*2];
int F[mx*2];
int node,edge;
void clr()
{

    FOR0(i,2*mx)
    {
        visit[i]=0;

        G[i].clear();
        G_I[i].clear();
    }
    timer=0;

}

void dfs1(int u)
{
    visit[u]=1;

    for(int i=0; i<G[u].size(); i++)
    {

        int v=G[u][i];
        if(visit[v])continue;
        dfs1(v);
    }
    timer++;
    F[u]=timer;

}
int SC[2*mx];
void dfs2(int u,int cp)
{

    visit[u]=1;
    SC[u]=cp;
    for(int i=0; i<G_I[u].size(); i++)
    {
        int v=G_I[u][i];
        if(visit[v])continue;
        dfs2(v,cp);
    }

}
void scc()
{
    for(int i=0; i<(node*2); i++)
        if(visit[i]==0)
            dfs1(i);
    vector<pair<int,int> >V;
    for(int i=0; i<(2*node); i++)
        V.PB(MP(F[i],i));
    sort(ALL(V));
    reverse(ALL(V));
    memset(visit,0,sizeof visit);
    int comp=0;
    for(int i=0; i<(2*node); i++)
        if(visit[V[i].ss]==0)
        {

            dfs2(V[i].ss,comp);
        comp++;
        }

}
void print(){

for(int i=0;i<(2*node);i++)
cout<<i<<" "<<SC[i]<<"\n";


}

void sat_2()
{
//puts("OKK");

vector<int>res;
int k=1;
    for(int i=0; i<(2*node); i+=2)
    {
        if(SC[i]==SC[i+1])
        {

            puts("No");
            return ;
        }
        if(SC[i]>SC[i+1]){
        res.PB(k);
//        cout<<"DD "<<i+1<<" "<<k<<"\n";

        }
        k++;

    }
    puts("Yes");

cout<<res.size();
for(int i=0;i<res.size();i++)cout<<" "<<res[i];
puts("");


}

/*

helping condition for building graph
--------------------------------------
void mustTrue ( int a ) 
{        
        ///A is True
        scc.adj[a^1].pb ( a );
}

void orClause ( int a, int b ) 
{       /// A || B clause
        //!a->b !b->a
        scc.adj[a^1].pb ( b );
        scc.adj[b^1].pb ( a );
}
    
void xorClause ( int a, int b ) 
{
        //  A^B
        
        orClause( a, b );
        orClause( a^1, b^1 );
}

void andClause ( int a, int b )
{
         //A && B
        scc.adj[a].pb ( b );
        scc.adj[b].pb ( a );
}
 void notAndClause ( int a, int b ) 
{          
        
        scc.adj[a].pb ( b ^ 1 );
        scc.adj[b].pb ( a ^ 1 );
 }

*/
int main()
{
    int t,kase=1;
    cin>>t;
    while(t--)
    {
        clr();

        cin>>edge>>node;
        FOR0(i,edge)
        {
            int a,b;
            cin>>a>>b;
//            cout<<mapping_node(-a)<<" "<<mapping_node(b)<<"\n";
//                        cout<<mapping_node(b)<<" "<<mapping_node(-a)<<"\n";
            G[mapping_node(-a)].PB(mapping_node(b));
            G_I[mapping_node(b)].PB(mapping_node(-a));

            G[mapping_node(-b)].PB(mapping_node(a));
            G_I[mapping_node(a)].PB(mapping_node(-b));

        }

        scc();
//        print();
        cout<<"Case "<<kase++<<": ";
        sat_2();



    }


}

