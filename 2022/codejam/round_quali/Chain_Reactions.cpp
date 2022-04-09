// simple dfs on the root gets the right answer
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <unistd.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

long long dfs(int cur, vector<int> &values, vector< set<int> > &adj, long long &fun)
{
	if (adj[cur].size() == 0) return values[cur];

	multiset<int> children;

	for (auto it = adj[cur].begin(); it != adj[cur].end(); ++it)
		children.insert(dfs(*it, values, adj, fun));
	
	for (auto it = ++children.begin(); it != children.end(); ++it)
		fun += *it;
	return max(values[cur], *children.begin());
}


string Solve()
{
	long long fun = 0;

	int N;
	vector<int> values;
	vector< set<int> > adj;

	cin >> N;

	values.resize(N + 1);
	adj.resize(N + 1);

	// base
	values[0] = 0;

	for (int i = 1, buf; i < N + 1; ++i)
	{
	    cin >> buf;
	    values[i] =  buf;
	}
		

	for (int i = 1, buf; i < N + 1; ++i)
	{
		cin >> buf;
		adj[buf].insert(i);
	}

	fun += dfs(0, values, adj, fun);
	return to_string(fun);
}

int main(int argc, char* argv[])
{
	int T;

	cin >> T;
	for (int i = 1; i <= T; i++)
		cout << "Case #" << i << ": " << Solve() << endl;
	return 0;
}