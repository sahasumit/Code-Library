#include<stdio.h>
#include<string.h>
#define mx 1000
int n=7;
int value[]={-100000,5,0,9,2,7,3,4};
int dp[mx],dir[mx];
int longest(int u)
{
    if(dp[u]!=-1) return dp[u];
    int maxi=0;
    for(int v=u+1;v<=n;v++) //১ম শর্ত,v>u
    {
        if(value[v]>value[u]) //২য় শর্ত, value[v]>value[u]
        {
            if(longest(v)>maxi) //সর্বোচ্চ মানটা নিবো
            {
                maxi=longest(v);
                                dir[u]=v;

            }
        }
    }
    dp[u]=1+maxi; //১ যোগ হবে কারণ u নম্বর নোডটাও পাথের মধ্যে আছে
    return dp[u];
}
int main()
{
//    READ("in");
    memset(dp,-1,sizeof dp);
        memset(dir,-1,sizeof dir);
    int LIS=0,start;
    for(int i=1;i<=n;i++)
    {
        printf("longest path from: %d\n",longest(i));
        if(longest(i)>LIS)
        {
            LIS=longest(i);
            start=i;
        }
    }
    printf("LIS = %d Starting point %d\n",LIS,start);

    return 0;
}
