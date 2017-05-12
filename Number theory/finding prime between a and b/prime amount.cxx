#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

#define nln        puts("")                         ///prLLInewline
#define getLLI(a)  scanf("%d",&a);
#define max3(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define min3(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(LLI i=1;i<=n;i++)
#define FOR0(i,n)  for(LLI i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(LLI i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (LLI)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long LLI
#define LLI        long long
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

LLI Set(LLI N,LLI pos)
{
    return N=N | (1<<pos);
}
LLI reset(LLI N,LLI pos)
{
    return N= N & ~(1<<pos);
}
bool check(LLI N,LLI pos)
{
    return (bool)(N & (1<<pos));
}
void CI(LLI &_x)
{
    scanf("%lld",&_x);
}

void CO(LLI &_x)
{
    cout<<_x;
}

template<typename T> void getarray(T a[],LLI n)
{
    for(LLI i=0; i<n; i++) cin>>a[i];
}
template<typename T> void prLLIarray(T a[],LLI n)
{
    for(LLI i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

const double EPS=1e-9;                              ///constatnts
const LLI INF=0x7f7f7f7f;

LLI dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
LLI dc8[8]= {0,0,-1,1,1,1,-1,-1};
LLI dr4[4]= {0,0,1,-1};                      ///4 direction move
LLI dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
LLI kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
LLI kn8c[8]= {2,1,-1,-2,-2,-1,1,2};

#define mx 50000
bool statue[mx];
vector<LLI>prime;
void sieve()
{
    memset(statue,true,sizeof statue);
    LLI sq=sqrt(mx);
    for(LLI i=3; i<=sq; i+=2)
        if(statue[i]==true)
            for(LLI j=i*i; j<=mx; j+=i+i)
                statue[j]=false;
    prime.push_back(2);
    for(LLI i=3; i<=mx; i+=2)
        if(statue[i]==true)
            prime.push_back(i);


}
bool ans[100000+5];
LLI a,b;
LLI func()
{
  //  if(b-a==0)
    //    return 0;
    memset(ans,0,sizeof ans);
    LLI sq=sqrt(b);
   if(a<2)a=2;
   //I need to start counting from 2

    for(LLI i=0; prime[i]<=sq; i++)
    {
       // puts("FF");
        //cout<<prime[i]<<"\n";
        LLI num=prime[i]*(a/prime[i]);


        if(num<a)
            num+=prime[i];

        if(num==prime[i])
            num*=2;
        for(LLI j=num;j<=b;j+=prime[i]){
//if(j-a>=a&&j-a<=b)
             ans[j-a]=1;
             //cout<<j<<"\n";
        }
       // break;

    }
    LLI kount=0;
   // cout<<b-a<<"\n";
    for(LLI i=0;i<=(b-a);i++)
    {
     if(ans[i]==0)kount++;
    }
        return kount;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    sieve();
    //for(LLI i=0;prime[i]<20;i++)
    //  cout<<prime[i]<<"\n";
    LLI kase=1,t;
    CI(t);
    while(t--)
    {

        CI(a);
        CI(b);

        cout<<"Case "<<kase++<<": "<<func()<<"\n";
    }
    return 0;
}


