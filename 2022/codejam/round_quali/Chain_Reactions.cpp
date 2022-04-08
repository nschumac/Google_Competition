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

int F[100001], P[100001];
vector<int> adj[100001];

long long dfs(int cur, long long &fun)
{
	if (adj[cur].size() == 0) return F[cur];

	vector<int> children;

	for (int i = 0; i < adj[cur].size(); ++i)
		children.push_back(dfs(adj[cur][i], fun));
	
	sort(children.begin(), children.end());

	for (int i = 1; i < children.size(); ++i)
		fun += children[i];

	return max(F[cur], children[0]);
}


string Solve()
{
	long long fun = 0, N = 0;

	cin >> N;

	for (int i = 1; i < N + 1; ++i)
		cin >> F[i];
	
	for (int i = 0; i < N + 1; ++i)
		adj[i].clear();

	for (int i = 1; i < N + 1; ++i)
	{
		cin >> P[i];
		adj[P[i]].push_back(i);
	}

	fun += dfs(0, fun);
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