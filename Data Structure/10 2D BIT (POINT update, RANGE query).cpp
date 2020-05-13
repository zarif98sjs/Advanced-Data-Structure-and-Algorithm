
/**

2D BIT

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1024+5;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int n;
int ara[nmax][nmax];



/** 2D BIT / FENWICK TREE **/
/*** 1 based indexing ***/

int BIT[nmax][nmax];
inline int lowbit(int x)
{
    return x&(-x);
}

inline void update(int x,int y,int val) /** POINT update , adds to the current value . Point = {x,y} **/
{
    for(int i = x; i <= n; i += lowbit(i))
        for(int j = y; j <= n; j += lowbit(j))
            BIT[i][j] += val;
}

inline int query(int x,int y) /** RANGE Sum . Range  = [{1,1} , {x,y}] **/
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            sum += BIT[i][j];

    return sum;
}

int main()
{
    //freopen("OUT.txt","w",stdout);

    n = 3;

    int val = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            //cin>>val;
            val++;
            ara[i][j] = val;
            update(i,j,ara[i][j]); /** Initial Update **/
        }


    int query_count;
    cin>>query_count;

    while(query_count--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            /** Add val to {x,y} **/
            int x,y,val;
            cin>>x>>y>>val;

            update(x,y,val);
        }
        else
        {
            /** Sum of Range = [{x1,y1} , {x2,y2}] **/
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;

            int v1 = query(x2, y2);
            int v2 = query(x2, y1-1);
            int v3 = query(x1-1, y2);
            int v4 = query(x1-1, y1-1);
            int ans = v1 - v2 - v3 + v4;
            cout<<"Sum : "<<ans<<endl;
        }
    }



    return 0;
}

