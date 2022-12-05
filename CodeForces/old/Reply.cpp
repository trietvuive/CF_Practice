#include<bits/stdc++.h>
using namespace std;

struct Demon {
	int lost_stamina;
	int wait_turn;
	int recover_stamina;
	int turn_numbers;
	vector<int> fragment_accumulates;
};

vector<Demon> read_file(fstream& file_reader, int max_stamina) {
	int demonsN;
	file_reader >> demonsN;
	vector<Demon> demons;
	for (int i = 0; i < demonsN; ++i)
	{
		vector<int> fragments;
		int Sc, Tr, Sr, Na;
		file_reader >> Sc >> Tr >> Sr >> Na;
		int sm = 0;
		// accumulation of fragments after i turns
		for (int i = 0; i < Na; ++i) {
			int frag; file_reader >> frag;
			sm += frag;
			fragments.push_back(sm);
		}
		// can't even fight the demon
		if(Sc <= max_stamina)
			demons.emplace_back(Sc, Tr, Sr, Na, fragments);
	}
	file_reader.close();
	return demons;
}

int main() {
	srand(time(NULL));
	int start_stamina, max_stamina, turns;
	fstream file_reader("reply/00_example.txt");
	file_reader >> start_stamina >> max_stamina >> turns;
	vector<Demon> demons = read_file(file_reader, max_stamina);
	int score = 0;

	vector<int> permutation;
	for (int i = 0; i < demons.size(); ++i) permutation.push_back(i);
}