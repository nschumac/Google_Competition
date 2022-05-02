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

int check_word(string const &word)
{
	int arr[26] = {0};

	for (int i = 0; i < word.length(); ++i)
	{
		if (i != 0 && word[i] != word[i - 1] && arr[word[i] - 'A'])
			return 0;
		arr[word[i] - 'A'] = 1;
	}
	return 1;
}

pair<int, string> solveWords(int i, vector<int> const &idc, vector<string> &input)
{
	if (idc.size() == 1)
		return make_pair(1, input[idc[0]]);
	
	int id = -1;
	string answer;
	for (int i = 0; i < idc.size(); ++i)
	{
		if (input[idc[i]][0] != input[idc[i]].back())
		{
			if (id != -1)
				return make_pair(0, "IMPOSSIBLE");
			id = idc[i];
		}
		else
			answer += input[idc[i]];
	}

	return ( i ? make_pair(1, input[id] + answer) :  make_pair(1, answer + input[id]) );
}

string Solve()
{
	int N;

	cin >> N;

	std::vector<std::string> input;
	std::vector<std::string> input2;
	std::unordered_map<char, std::vector<int> > start;
	std::unordered_map<char, std::vector<int> > end;
	std::unordered_map<char, std::vector<int> > end2;
	input.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
		if (!check_word(input[i]))
			return "IMPOSSIBLE";
		start[input[i][0]].push_back(i);
	}

	pair<int, string> solved;
	for (auto &it : start)
	{
		solved = solveWords(0, it.second, input);
		if (!solved.first)
			return solved.second;
		input2.push_back(solved.second);
		end[input2.back().back()].push_back(input2.size() - 1);
	}
	input.clear();

	for (auto &it : end)
	{
		solved = solveWords(1, it.second, input2);
		if (!solved.first)
			return solved.second;
		input.push_back(solved.second);
		end2[input.back().back()].push_back(input.size() - 1);
		start[input.back().back()].push_back(input.size() - 1);
	}

	


	string answer = "";
	for (int i = 0; i < input2.size(); ++i)
		answer += input2[i];
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

