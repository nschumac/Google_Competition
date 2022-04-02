//COMPLETED
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
	int colors[3][4];

	for (int i = 0; i < 3; ++i)
		cin >> colors[i][0] >> colors[i][1] >> colors[i][2] >> colors[i][3];

	int goal = (int)10e5;
	for (int i = 0; i < 4; ++i)
	{
		int min = INT32_MAX;
		for (int j = 0; j < 3; ++j)
		{
			if (colors[j][i] < min)
				min = colors[j][i];
		}
		if (goal <= min)
			min = goal;
		answer += " ";
		answer += to_string(min);
		goal -= min;
	}
    return (goal == 0 ? answer : "IMPOSSIBLE");
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}

