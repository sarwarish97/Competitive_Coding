#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long 
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define i_os ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
#define INF (ll)1e18 + 100
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define MAX 1e6
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x − 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/
#define o_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

struct Query {
	ll l,r,c;
};

struct subset {
	ll parent;
};

void initialise(subset* s,ll n){
	REP(i,0,n){
		s[i].parent = i;
	}
}

ll find(ll x,subset* s){
	if(s[x].parent==x)
		return x;
	s[x].parent = find(s[x].parent,s);
	return s[x].parent;
}

int main()
{
	// We have a segment of length L, each element initially has the color 0. 
	// We have to repaint the subarray [l,r] with the color c for each query (l,r,c). 
	// At the end we want to find the final color of each cell. 
	// We assume that we know all the queries in advance, i.e. the task is offline.
	ll L;
	cin>>L;
	subset s[L];
	initialise(subset,L);
	// parent[v] stores the pointer to the next cell which further leads to the representative of the set which is an unpainted cell
	
	ll q;
	cin>>q;
	vector<ll> answer(L,0);
	vector<Query> query(q);

	REPI(i,0,q){
    	ll l = query[i].l;
    	ll r = query[i].r;
    	ll c = query[i].c;
    	for(ll v = find(l,s); v <= r; v = find(v,s)){
        	answer[v] = c;
        	s[v].parent = v + 1;
    	}
	}
	return 0;
}