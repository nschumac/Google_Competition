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

int weights[101];

string Solve()
{

	int E, W;
	cin >> E >> W;

	vector< vector<int> > exercises(E, vector<int>(W));

	for (int i = 0; i < E; ++i)
		for (int j = 0; j < W; ++j)
			cin >> exercises[i][j];

	long long amount = 0;

	

    return ;
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}

