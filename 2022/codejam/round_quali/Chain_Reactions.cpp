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

int nums[(unsigned long)10e9];

string Solve()
{
	int N;
	int fun = 0;
	unordered_map<int, int> redirections;
	std::set<int> initiator;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];
	for (int i = 0; i < N; ++i)
	{
		int buf;
		cin >> buf;
		redirections.insert(i, buf);

		// initiator pointing to void doesnt mean shit just add fun
		// dont add that to list
		if (buf != 0)
		{
			initiator.insert(i);
			initiator.erase(buf);
		}
		else
			fun += nums[i];
	}

	// filter out all initiators that have their own path
	

	
	// simulate all possible initiator start positions
	// will be slow af
	// maybe it will pass the first sample
	// goes to a mil real quick
	for (int i = 0; i < initiator.size(); i++)
	{


	}

	int max = 0;



	
    return to_string(fun);
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}

