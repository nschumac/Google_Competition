// Fails but has the right answer | TIME LIMIT EXCEEDED
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct node
{
	int to;
	std::set<int> from;
	int _value;
};

int doPath(int idx, std::map<int, node>& nodes, int val)
{
	// change all froms to -1
	for (auto it = nodes[idx].from.begin(); it != nodes[idx].from.end(); ++it)
		nodes[*it].to = -1;
	if (nodes[idx].to == -1)
		return nodes[idx]._value;
	int val2 = doPath(nodes[idx].to, nodes, nodes[idx]._value);
	return max(val,val2);
}

int solveRecursively(int cur, std::set<int> Inits, std::map<int, node> nodes)
{
	int fun = 0;
	int maxval = 0;
	Inits.erase(cur);
	fun = doPath(cur, nodes, nodes[cur]._value);
	for (auto it = Inits.begin(); it != Inits.end(); ++it)
		maxval = max(maxval, solveRecursively(*it, Inits, nodes));
	return fun + maxval;
}


string Solve()
{
	int N;
	int fun = 0;
	int buf;
	cin >> N;

	std::map<int, node> nodes;
	std::set<int>	Initiators;

	for (int i = 0; i < N; ++i)
	{
		cin >> buf;
		nodes.insert(make_pair(i, node()));
		nodes[i]._value = buf;
		Initiators.insert(i);
	}

	// fill in indexes
	for (int i = 0; i < N; ++i)
	{
		cin >> buf;
		// convert input to index
		--buf;
		nodes[i].to = buf;
		if (buf == -1)
			continue;
		// insert from
		nodes[buf].from.insert(i);
		//remove index because its being pointed too
		Initiators.erase(buf);
	}

	int addition = 0;
	// shorten paths that only have one Initiator
	for (auto it = Initiators.begin(); it != Initiators.end(); ++it)
	{
		int next = nodes[*it].to;
		if (next == -1)
		{
			addition += nodes[*it]._value;
			nodes.erase(*it);
			Initiators.erase(it--);
			continue;
		}
		while (true)
		{
			// follow reaction check if there are multiple pointing to that node
			if (nodes[next].from.size() > 1)
				break;
			nodes[*it]._value = max(nodes[next]._value, nodes[*it]._value);
			int buf = nodes[next].to;

			nodes[*it].to = buf;
			nodes[buf].from.erase(next);
			nodes[buf].from.insert(*it);

			nodes.erase(next);
			next = buf;
			// hit void
			if (buf == -1)
			{
				fun += nodes[*it]._value;
				nodes.erase(*it);
				Initiators.erase(it--);
				break;
			}
		}
	}

	// should be a bit more clean now
	for (auto it = Initiators.begin(); it != Initiators.end(); ++it)
		fun = max(fun, solveRecursively(*it, Initiators, nodes));

	return to_string(fun + addition);
}

int main(int argc, char* argv[])
{
	int T;

	cin >> T;
	for (int i = 1; i <= T; i++)
		cout << "Case #" << i << ": " << Solve() << endl;
	return 0;
}