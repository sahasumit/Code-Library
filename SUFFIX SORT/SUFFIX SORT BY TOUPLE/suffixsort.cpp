//--------------suffix sorting-------------------
char c[mx]; //the string which will be sorted according to suffix

int n; //length of the string


int rank_to_pos[mx];//ranking of suffix , here index is used as ranking and value is where from the suffix start
int P[mxlog][mx];

// own made data type to represent a suffix
//p first index-id of suffix
//nr is used for ranking with two element based in two
struct entry
{
    int nr[2];
    int p;
} L[mx];
// comparing function for suffix
int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int stp;
// find lcp between any two suffix with complexity logn
//here u and v is the starting position of suffix
int lcp(int u, int v)
{
    if(u == v) return n - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0 && u<=n && v<=n; i--)
    {
        if(P[i][u] == P[i][v])
        {
            ret += 1<<i;
            u += 1<<i;
            v += 1<<i;
        }
    }
    return ret;
}

void suffix_sort()//control all opretaion for suffix sorting
{

//here based is one
    stp=0;

    for(int i=1; i<=n; i++)P[0][i]=c[i]-'a';
    int cnt;
    for(stp=1, cnt = 1; cnt <=n; stp++, cnt *= 2)
    {
        for(int i=1; i<=n; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <=n? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L+1,L+n+1,cmp);
        for(int i=1; i <=n; i++)
            P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
    }
    stp--;//decrease it by one
    for(int i=1; i<=n; i++)
    {
        rank_to_pos[P[stp][i]]=i;
    }

}
//----------------------end of suffix------------------
