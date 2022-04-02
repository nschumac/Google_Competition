//COMPLETED ; bruh so fucking stupid of me lmao
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


string solve()
{
	int S;
	std::multiset<int> dice;

	cin >> S;
	int b;
	for (int i = 0; i < S; ++i)
	{
		cin >> b;
		dice.insert(b);
	}
	// sorted
	int max = 1;
	for (auto it = ++dice.begin(); it != dice.end(); ++it)
	{
		if (max == *it)
			continue;
		++max;
	}
    return to_string(max);
}

int main(int argc, char *argv[])
{
    int t;

    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "case #" << i << ": " << solve() << endl;
    return 0;
}

