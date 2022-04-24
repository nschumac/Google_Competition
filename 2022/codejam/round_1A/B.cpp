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

	int N;
	cin >> N;

	vector<int> mine(N);
	for (int i = 0; i < N; ++i)
	{
		mine[i] = i + 1;
		cout << i + 1 << endl;
	}

	vector<int> judge(N);
	for (auto& i : judge) cin >> i;

	set<int> both;

	both.insert(mine.begin(), mine.end());
	both.insert(judge.begin(), judge.end());

	

    return answer;
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        Solve();
    return 0;
}

