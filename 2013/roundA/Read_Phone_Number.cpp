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

string arr[] = {"double", "triple", "quadruple", "quintuple", "sextuple", "octuple", "nonuple", "decuple"};
string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string Solve()
{
    string answer = "";

	string N, Format;
	int mul_count = 0;
	char curNum = 0;
	int fc = 0;
	int f = 0;

	cin >> N;
	cin >> Format;

	for (int i = 0; i < N.length(); i++)
	{
		if (fc <= 0)
		{
			fc = atoi(Format.c_str()); 
			Format = Format.substr(Format.find('-'));
		}

		curNum = N[i];
		mul_count = 1;

		while (fc-- > 0 && N[i + 1] == curNum)
		{
			i++;
			mul_count++;
		}			
		if (mul_count == 1 || mul_count > 10)
		{
			while (mul_count--)
			{
				answer += num[curNum - '0'];
				answer += " ";
			}
		}
		else
		{
			answer += arr[mul_count - 2];
			answer += " ";
			answer += num[curNum - '0'];
			answer += " ";
		}
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
