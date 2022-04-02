// COMPLETE
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


string Solve()
{
	stringstream ss;

	int R, C;
	cin >> R >> C;

	ss << endl;
	for (int i = 0; i < R * 2 + 1; ++i)
	{
		for (int j = 0; j < C * 2 + 1; ++j)
		{
			if ((i <= 1 && j <= 1) || (i % 2 && j % 2))
				ss << ".";
			else if (i % 2 == 0) // ungerade row
				ss << (j % 2 ? "-" : "+");
			else
				ss << "|";
			
		}
		ss << endl;
	}
    return ss.str();
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}
