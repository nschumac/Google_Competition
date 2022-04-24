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

string Solve()
{
	ull pumps = 0;

	int N, P;
	cin >> N >> P;

	std::multiset<ll> p;
	ll base = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int c = 0, f; c < P; ++c)
		{
			cin >> f;
			p.insert(f);
		}
		pumps += min(abs(*p.rbegin() - base), abs(*p.begin() - base));
		if (abs(*p.rbegin() - base) < abs(*p.begin() - base))
			base = *p.begin();
		else
			base = *p.rbegin();
		pumps += abs(*p.rbegin() - *p.begin());
		p.clear();
	}
    return to_string(pumps);
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}

