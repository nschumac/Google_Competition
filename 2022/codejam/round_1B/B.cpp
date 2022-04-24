#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


string Solve()
{
	int N;

	cin >> N;

	std::deque<int> deq;

	for (int i = 0, f; i < N; ++i)
	{
		cin >> f;
		deq.push_back(f);
	}

	int count = 0;
	int max = INT_MIN;
	int val = 0;

	while (!deq.empty())
	{
		if (deq.front() <= deq.back())
		{
			val = deq.front();
			deq.pop_front();
		}
		else
		{
			val = deq.back();
			deq.pop_back();
		}
		if (val >= max)
		{
			max = val;
			count++;
		}
	}
    return to_string(count);
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}

