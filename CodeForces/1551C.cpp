#include<bits/stdc++.h>
using namespace std;

int count(const string& s, char c)
{
	int count = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == c)++count;
	return count - (s.size() - count);
}
int max_story(vector<string> words, char c)
{
	sort(words.begin(), words.end(), [&](const string& a, const string& b) {
		return count(a, c) > count(b, c);
		});
	int balance = count(words[0], c);
	int idx = 0;
	while (balance > 0 && ++idx < words.size())
		balance += count(words[idx], c);
	return idx;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<string> words;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			words.push_back(s);
		}
		int story = 0;
		story = max(story, max_story(words, 'a'));
		story = max(story, max_story(words, 'b'));
		story = max(story, max_story(words, 'c'));
		story = max(story, max_story(words, 'd'));
		story = max(story, max_story(words, 'e'));
		cout << story << endl;
	}
}
