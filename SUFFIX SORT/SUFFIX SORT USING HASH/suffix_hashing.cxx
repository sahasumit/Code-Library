//------------------------suffix sorting and hashing ---------------


//func for generating power
// n is the number ,p is power and m is mod
LLI bigmod(LLI n,LLI p,LLI m)
{
    if(p==0)return 1;

    if(p%2==1)return (n*bigmod(n,p-1,m))%m;
    else
    {

        LLI temp=bigmod(n,p/2,m);
        return (temp*temp)%m;
    }
}
//func for finding inverse modulo
// find inverse modulo of n according to m
LLI modinverse(LLI n,LLI m)
{
    return bigmod(n,m-2,m);

}
// two dimension based hash
// first hash using base1 and mod1
// second hash using base2 and mod2
// pp[][] stores pre calc value and inv[][] stores inverse mod value of pp[][]
#define mod   1000000007ll

LLI mod1=mod, mod2=mod + 2;
LLI base1 = 87, base2 = 83;
LLI pp[2][mx], hsh[2][mx], inv[2][mx];
void pre_calc_hash()
{
    pp[0][0]=1,pp[1][0]=1;
    for(int i=1; i<mx; i++)
    {
        pp[0][i]=(pp[0][i-1]*base1)%mod1;
        pp[1][i]=(pp[1][i-1]*base2)%mod2;
    }
    for(int i=0; i<mx; i++)
    {
        inv[0][i]=modinverse(pp[0][i],mod1);
        inv[1][i]=modinverse(pp[1][i],mod2);
    }
}
//-----end_pre_calc_of hash;

char c[mx]; //the string which will be sorted according to suffix

int n; //length of the string
LLI hashh[2][mx]; // store final value of hashing


//this func generate hash value of string c and stores int hashh[][]
void make_hash()
{
    // n=length of string c
    for(int i=1; i<=n; i++)
    {
        hashh[0][i]=(hashh[0][i-1]+(pp[0][i]*c[i])%mod1)%mod1;
        hashh[1][i]=(hashh[1][i-1]+(pp[1][i]*c[i])%mod2)%mod2;
    }

}
//check two substring using hash value
//one string start from x and another string start from y
// length of both string is z
inline bool ch(int x,int y,int z)
{
    // v1 value from x accroding two first hash
    // v2 value from y accroding two first hash
    // p1 value from x accroding two second hash
    // p2 value from y accroding two second hash

    int v1=((hashh[0][x+z-1]-hashh[0][x-1]+mod1)*inv[0][x-1])%mod1;
    int v2=((hashh[0][y+z-1]-hashh[0][y-1]+mod1)*inv[0][y-1])%mod1;
    int p1=((hashh[1][x+z-1]-hashh[1][x-1]+mod2)*inv[1][x-1])%mod2;
    int p2=((hashh[1][y+z-1]-hashh[1][y-1]+mod2)*inv[1][y-1])%mod2;
    if(v1==v2&&p1==p2)return true;
    else return false;
}

//comparing function for suffix sorting
// compare between suffix starting from x and starting from y
// compare two suffix which one is lexiographcially sorter using hash value and binary search

inline bool boo(int x,int y)
{
    int r=n-max(x,y)+1;
    if (ch(x,y,r)) return x<y;
    int m,l=0;
    while (l<r)
    {
        m=(l+r)/2;
        if (ch(x,y,m))  l=m+1;
        else            r=m;
    }
    l--;
    return c[x+l]<c[y+l];
}

int rank_to_pos[mx];//ranking of suffix , here index is used as ranking and value is where from the suffix start

void suffix_sort()//control all opretaion for suffix sorting
{
    //here we will sort suffix of string c
    // string is based with 1
    //all array are also based with 1
    pre_calc_hash();//pre calculating value for hashing .note : call this func before test case

    make_hash();// making hash of string


    for (int i=1; i<=n; i++) rank_to_pos[i]=i; //intially ranking for suffix

    sort(rank_to_pos+1,rank_to_pos+n+1,boo);// sort the suffix


}
//----------------------end of suffix sorting using hash------------------
