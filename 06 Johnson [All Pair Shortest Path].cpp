
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PDI pair<double,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second


#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e3+7;
const int INF = 1e9;
const LL LINF = 1e17;

#define INFI 999999
double eps = 1e-6;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

struct Edge
{
    int u,v;
    double w;
};

int nVertices,m;

vector<Edge>adjList[nmax];
double distanceMatrix[nmax][nmax];
int parentMatrix[nmax][nmax];

vector<double> dist(nmax);

void dijkstra(int source)
{
    for(int i=0; i<nVertices; i++)
        dist[i] = INFI;

    priority_queue< PDI,vector<PDI>,greater<PDI> >PQ;

    dist[source] = 0;
    PQ.push({dist[source],source});

    while(!PQ.empty())
    {
        int now = PQ.top().second;
        PQ.pop();

        int len = adjList[now].size();
        for(int i=0; i<len; i++)
        {
            int next = adjList[now][i].v;
            double ndis = abs(adjList[now][i].w);

            if(dist[now]+ndis<dist[next])
            {
                dist[next] = dist[now]+ndis;
                parentMatrix[source][next] = now;
                PQ.push({dist[next],next});
            }
        }
    }
}

bool bellman_ford(int source)
{
    bool is_neg_cycle;

    for(int i=0; i<nVertices; i++)
        dist[i] = INFI;

    dist[source] = 0;

    for(int i=0; i<nVertices; i++) /** n-1 + 1 **/
    {
        is_neg_cycle = false;

        for(int now=0; now<nVertices; now++)
        {
            int len = adjList[now].size();

            for(int j=0; j<len; j++)
            {
                int next = adjList[now][j].v;
                double ndis = adjList[now][j].w;

                if(dist[now]!=INFI && dist[now]+ndis<dist[next])
                {
                    dist[next] = dist[now]+ndis;
                    is_neg_cycle = true;
                }
            }
        }
    }
    if(is_neg_cycle)
        return true;

    return false;
}
void johnsonsAlgo()
{
    nVertices++;

    for(int i=0; i<nVertices-1; i++)
        adjList[nVertices-1].push_back({nVertices-1,i,0});

    bool isNegCycle = bellman_ford(nVertices-1);

    if(isNegCycle)
    {
        /** Readjust wrights **/

        cout<<"Johnson's Algorithm implemented"<<endl;
        cout<<"Negative Cycle Exists"<<endl;
        return;
    }

    nVertices--;

    vector<double> h = dist;

    for(int u=0; u<nVertices; u++)
    {
        int len = adjList[u].size();
        for(int j=0; j<len; j++)
        {
            int v = adjList[u][j].v;
            adjList[u][j].w = adjList[u][j].w + h[u] - h[v];
            parentMatrix[u][v] = u;
        }
    }

    for(int u=0; u<nVertices; u++)
    {
        dijkstra(u);
        for(int v=0; v<nVertices; v++)
            distanceMatrix[u][v] = dist[v] + h[v]-h[u];
    }

    for(int u=0; u<nVertices; u++)
    {
        int len = adjList[u].size();
        for(int j=0; j<len; j++)
        {
            int v = adjList[u][j].v;
            adjList[u][j].w = adjList[u][j].w + h[v] - h[u];
        }
    }
    cout<<"Johnson's Algorithm implemented"<<endl;
}


void printShortestPath(int s,int t)
{
    double tempdistanceMatrix[nVertices][nVertices];

    for(int u=0; u<nVertices; u++)
    {
        int len = adjList[u].size();

        for(int j=0; j<len; j++)
        {
            int v = adjList[u][j].v;
            tempdistanceMatrix[u][v] = adjList[u][j].w;
        }
    }
    int src = s , des = t;

    vector<int>path;
    while(parentMatrix[s][t]!=s)
    {
        path.push_back(parentMatrix[s][t]);
        t = parentMatrix[s][t];
    }

    reverse(path.begin(),path.end());
    int sz = path.size();

    if(abs(distanceMatrix[src][des]-INFI)<eps)
        return;

    /** Answer **/

    printf("Shortest Path Weight : %.2f\n",distanceMatrix[src][des]);

    cout<<"Path : "<<src+1<<" -> "; /** 1 indexing for answer **/
    for(int x:path)
    {
        printf("%d(%.2f) -> ",x+1,tempdistanceMatrix[s][x]); /** 1 indexing for answer **/
        s = x;
    }

    printf("%d(%.2f)\n",des+1,tempdistanceMatrix[s][des]); /** 1 indexing for answer **/
}

void init()
{
    for(int i=0; i<nVertices; i++)
    {
        for(int j=0; j<nVertices; j++)
        {
            distanceMatrix[i][j] = INFI;
            parentMatrix[i][j] = -1;
        }
    }
}

void printDistanceMatrix()
{
    cout<<"Distance Matrix:"<<endl;
    for(int i=0; i<nVertices; i++)
    {
        for(int j=0; j<nVertices; j++)
        {
            if(abs(distanceMatrix[i][j]-INFI)<eps)
                cout<<"INF\t";
            else
                printf("%.2f\t",distanceMatrix[i][j]);
        }
        cout<<endl;
    }
}

void printPredecessorMatrix()
{
    cout<<"Predecessor Matrix:"<<endl;
    for(int i=0; i<nVertices; i++)
    {
        for(int j=0; j<nVertices; j++)
        {
            if(parentMatrix[i][j]==-1)
                cout<<"NIL\t";
            else
                cout<<parentMatrix[i][j]+1<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    //optimizeIO();

    cin>>nVertices>>m;

    for(int i=0; i<m; i++)
    {
        int a,b;
        double w;
        cin>>a>>b>>w;

        a--,b--; /** making 0 based **/

        adjList[a].push_back({a,b,w});  /** Directed **/
        //adj[b].push_back({a,w});
    }

    init();

    johnsonsAlgo();

    while(1)
    {
        int COMMAND;
        cin>>COMMAND;

        if(COMMAND==1) printDistanceMatrix();
        if(COMMAND==2) printPredecessorMatrix();
        if(COMMAND==3)
        {
            int src,des;
            cin>>src>>des;
            src--,des--; /** making 0 based **/

            printShortestPath(src,des);
        }

    }


    return 0;
}


