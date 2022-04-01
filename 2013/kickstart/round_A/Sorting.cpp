#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//Alex is ODD
//BOB is EVEN

int books[1001] = {0};

string Solve()
{
    string answer = "";
	multiset<int> bookset;
	int N, B;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> books[i];
		bookset.insert(books[i]);
	}
	multiset<int>::iterator Alex = bookset.begin();
	multiset<int>::reverse_iterator Bob = bookset.rbegin();
	for (int i = 0; i < N; i++)
	{
		if (books[i] % 2) // ODD
		{
			while ((*Alex % 2) == 0)
				Alex++;
			answer += to_string(*(Alex++));
		}
		else
		{
			while ((*Bob % 2) != 0)
				Bob++;
			answer += to_string(*(Bob++));
		}
		if (i + 1 < N)
			answer += " ";
	}
    return answer;
}

int main(int argc, char *argv[])
{
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << Solve() << endl;
    return 0;
}
