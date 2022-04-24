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
	int idx;

	string input;
	cin >> input;
	for (int i = 0; i < input.length(); ++i)
	{
		if (i < input.length() - 1 && input[i] < input[i + 1])
		{
			answer += input[i];
			answer += input[i];
		}
		else if (i < input.length() - 1 && input[i] == input[i + 1])
		{
			int c = i + 1;
			while (c < input.length() && input[i] == input[c])
				c++;
			if (c == input.length())
			{
				answer.append(input.substr(i));
				return answer;
			}
			if (input[i] < input[c])
				answer.append(input.substr(i, c - i));
			answer.append(input.substr(i, c - i));
			i = c - 1;
		}
		else
			answer += input[i];
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

