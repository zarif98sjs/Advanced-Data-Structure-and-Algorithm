
/**

Complexity : O(ElogE)

Works fine with negative edges.

**/


/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e3+7;
const LL LINF = 1e17;


struct Edge {
	int src, dest, weight;
};

// Comparison object to be used to order the Edges
struct compare1
{
	inline bool operator() (Edge const &a, Edge const &b)
	{
		return (a.weight > b.weight);
	}
};

struct compare2
{
	inline bool operator() (Edge const &a, Edge const &b)
	{
		return (a.weight < b.weight);
	}
};

class DisjointSet
{
	unordered_map<int, int> parent;
public:

	void makeSet(int N)
	{
		for (int i = 1; i <= N; i++) /** 1 based indexing **/
			parent[i] = i;
	}

	int Find(int k)
	{
		// if k is root
		if (parent[k] == k)
			return k;

		return parent[k] = Find(parent[k]);
	}

	void Union(int a, int b)
	{
		int x = Find(a);
		int y = Find(b);

		parent[x] = y;
	}
};

vector<Edge> KruskalAlgoMinST(vector<Edge> edges, int N)
{
    sort(edges.begin(), edges.end(), compare1()); /** Sorted in the opposite way because of POP_BACK implementation  , use compare2 for Maximum Spanning Tree **/

	vector<Edge> MST;

	DisjointSet ds;
	ds.makeSet(N);

	/** MST contains exactly V-1 edges **/
	while (MST.size() != N - 1)
	{
		/** consider next edge with minimum weight from the graph **/
		Edge next_edge = edges.back();
		edges.pop_back();

		/** find root of the sets to which two endpoint vertices of next_edge belongs **/
		int x = ds.Find(next_edge.src);
		int y = ds.Find(next_edge.dest);

		/** if both endpoints have different parents, they belong to different connected components and can be included in MST **/
		if (x != y)
		{
			MST.push_back(next_edge);
			ds.Union(x, y);
		}
	}
	return MST;
}

int nodes,num_edges;

vector<Edge>adj;

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    cin>>nodes>>num_edges;

    for(int i=1;i<=num_edges;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        adj.push_back({a,b,w}); /** although undirected , edge is pushed once to avoid cycle of x->y & y->x **/
    }

    vector<Edge>MinST = KruskalAlgoMinST(adj,nodes);

    LL mininum_spanning_tree_value = 0;

    for(auto e:MinST)
        mininum_spanning_tree_value += e.weight;

    cout<<mininum_spanning_tree_value<<endl;

    return 0;
}


