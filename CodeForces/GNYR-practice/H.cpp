#include <bits/stdc++.h>

#define INF 1000000000
typedef long long ll; 

using namespace std;

int NT, NP, NS, NR;

struct Team {
	int total_problems;
    int time_sum;
    int team_num;

	vector<int> penalty_time;
	set<int, greater<int>> sorted_time;
	vector<bool> solved;


    Team(int team_num) {
		total_problems = 0;
        time_sum = 0;
        this->team_num = team_num;
		penalty_time.resize(NP+1, 0);
		solved.resize(NP+1, false);
    }

    bool operator<(const Team& other) const {
		if(total_problems != other.total_problems) {
			return total_problems > other.total_problems;
		}

        if (time_sum != other.time_sum) {
            return time_sum < other.time_sum;
        }

		return sorted_time < other.sorted_time;
    }
	
	bool operator == (const Team& other) const {
		return total_problems == other.total_problems &&
			time_sum == other.time_sum &&
			sorted_time == other.sorted_time;
	}

	bool operator != (const Team& other) const {
		return !(*this == other);
	}

	void process_submission(int problem, int time, bool correct) {
		if(solved[problem]) {
			return;
		}

		else if(!correct) {
			penalty_time[problem] += 20;
		}

		else if(correct) {
			solved[problem] = true;
			time_sum += penalty_time[problem] + time;
			sorted_time.insert(penalty_time[problem] + time);
			total_problems++;
		}
	}

};

void print(Team& t, int rank) {
	string rank_str = to_string(rank);
	string team_num = to_string(t.team_num);
	string total_problems = to_string(t.total_problems);
	string time_sum = to_string(t.time_sum);

	string output = rank_str;
	while(output.size() < 4) output += " ";

	output += team_num;
	while(output.size() < 8) output += " ";

	while(output.size() + total_problems.size() < 11) output += " ";
	output += total_problems;

	while(output.size() + time_sum.size() < 16) output += " ";
	output += time_sum;

	cout << output << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> NT >> NP >> NS >> NR;
	vector<Team> teams;
	for(int i = 1; i <= NT; i++)
		teams.push_back(Team(i));

	for(int i = 0; i < NS; ++i) {
		int team, problem, time, judge;
		cin >> team >> problem >> time >> judge;
		teams[team-1].process_submission(problem, time, judge);
	}

	stable_sort(teams.begin(), teams.end());
	int rank = 1, idx = 0;

	while(idx < teams.size() && rank <= NR) {
		print(teams[idx], rank);
		if(teams[idx] != teams[idx+1]) 
			rank = idx + 2;

		idx++;
	}

    return 0;
}
