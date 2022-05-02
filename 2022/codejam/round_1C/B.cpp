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
    string answer = "";
	int N, K;

	cin >> N>> K;

	ll sum;
	ll mul;

	for (int i = 0, f; i < N; ++i)
	{
		cin >> f;
		sum += f;
		mul += f * f;
	}
	sum *= sum;

	double root;
	if (mul != sum)
		root = sqrt(mul - sum);
	else
		return std::to_string(sum);
	if (ll(root) == root)
		return std::to_string(sum += root * root);
	return "IMPOSSIBLE";
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}

