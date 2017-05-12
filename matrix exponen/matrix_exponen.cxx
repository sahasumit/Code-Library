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

#define nln        puts("")                         ///printnewline
#define getint(a)  scanf("%d",&a);
#define max3(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define min3(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(int i=1;i<=n;i++)
#define FOR0(i,n)  for(int i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(int i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (int)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long int
#define LLI        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
void CI(int &_x)
{
    scanf("%d",&_x);
}

void CO(int &_x)
{
    cout<<_x;
}

template<typename T> void getarray(T a[],int n)
{
    for(int i=0; i<n; i++) cin>>a[i];
}
template<typename T> void printarray(T a[],int n)
{
    for(int i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

const double EPS=1e-9;                              ///constatnts
const int INF=0x7f7f7f7f;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};
int a,b,n,m;
int mod;
struct matrix
{
    int r,c;
    int v[5][5];

};

matrix mult(matrix &a,matrix &b)
{

    matrix mm;
    mm.r=a.r;
    mm.c=b.c;
    for(int i=0; i<mm.r; i++)
        for(int j=0; j<mm.c; j++)
        {

            int sum=0;
            for(int k=0; k<a.c; k++)
            {
                sum+=a.v[i][k]*b.v[k][j];
                sum=sum%mod;

            }
            mm.v[i][j]=sum;

        }
return mm;

}
string binary(int p) {
  string ret = "";
  while (p > 0) {
    ret += (p % 2 == 0) ? "0" : "1";
    p /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

matrix pow(matrix &mat, int p) {
  string bin = binary(p);
  matrix ret = mat;
  for (int i = 1; i < bin.size(); i++) {
    ret = mult(ret, ret);
    if (bin[i] == '1') {
      ret = mult(ret, mat);
    }
  }
  return ret;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int t;
    cin>>t;
    mat.v[0][0]=1;
    mat.v[0][1]=1;
    mat.v[1][0]=1;
    mat.v[1][1]=0;
    mat.r=2,mat.c=2;

    while(t--)
    {

        cin>>a>>b>>n>>m;
        matrix mmm;
        mmm.r=2,mmm.c=1,mmm.v[0][0]=b;
        mmm.v[1][0]=a;
        mod=1;
        for(int i=0; i<m; i++)
            mod=mod*10;
        a=a%mod;
        b=b%mod;
        if(n==0)
        cout<<a<<"\n";
        else if(n==1)
        cout<<b<<"\n";
        else{

        matrix temp=pow(mat,n-1);
        temp=mult(temp,mmm);
        int ans=temp.v[0][0];
        ans=ans%mod;
        cout<<ans<<"\n";

        }


    }


    return 0;
}

