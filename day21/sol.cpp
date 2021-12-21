#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<vector<pair<long long, long long>>>>> DP;

pair<long long, long long> wins(int p1, int p2, int s1, int s2)
{
	// Player 1 won
	if(s1 >= 21)
		return {1, 0};
		
	// Player 2 won
	if(s2 >= 21)
		return {0, 1};
		
	// If we have already seen the stage use it
	if(DP[p1][p2][s1][s2].first != 0 || DP[p1][p2][s1][s2].second != 0)
		return DP[p1][p2][s1][s2];
		
	// Init wins for the possition to 0
	pair<long long, long long> ans = {0, 0};
	
	// Roll the 3 dices
	for(int d1 = 1; d1 <= 3; d1++)
		for(int d2 = 1; d2 <= 3; d2++)
			for(int d3 = 1; d3 <= 3; d3++)
			{
				// Compute the possition and the score for every 3 roll outcome
				int new_p1 = (p1 + d1 + d2 + d3) % 10;
				int new_s1 = s1 + new_p1 + 1;
				
				// Make the other player play
				pair<long long, long long> w = wins(p2, new_p1, s2, new_s1);
				
				// Add the results to the current posstion answer
				// The results from the other player play are swhifted for the current player
				ans.first += w.second;
				ans.second += w.first;
			}
			
	// Store the result to DP
	DP[p1][p2][s1][s2].first = ans.first;
	DP[p1][p2][s1][s2].second = ans.second;
	
	return ans;
}

void solve2() 
{
	// DP with a matrix 10 (pos p1) x 10 (pos p2) x 20 (score p1) x 20 (socre p2)
	// Every entry in DP is a pair of p1 winning times, p2 winning times
	
	// Initialize the whole DP to 0,0
	for(int pos1 = 0; pos1 < 10; pos1++)
	{
		vector<vector<vector<pair<long long, long long>>>> aux1;
		for(int pos2 = 0; pos2 < 10; pos2++)
		{
			vector<vector<pair<long long, long long>>> aux2;
			for(int s1 = 0; s1 < 21; s1++)
			{
				vector<pair<long long, long long>> aux3;
				for(int s2 = 0; s2 < 21; s2++)
				{
					aux3.push_back({0, 0});
				}
				aux2.push_back(aux3);
			}
			aux1.push_back(aux2);
		}
		DP.push_back(aux1);
	}
	
	pair<long long, long long> ans = wins(4 - 1, 10 - 1, 0, 0);
	
	cout << max(ans.first, ans.second) << endl;
	
	return;
}

void simulate_turn(int *playing, int *rolls, int *die, int *p1, int *p2,  int *s1, int *s2)
{
	if(*playing == 0)
	{
		for(int i = 0; i < 3; i++)
		{
			*rolls += 1;
			*p1 = (*p1 + *die) % 10;
			*die = (*die + 1) % 100;
		}
		
		if(*p1 == 0)
		{
			*s1 += 10;
		}
		else
		{
			*s1 += *p1;
		}
		
		*playing = 1;
	}
	else
	{
		for(int i = 0; i < 3; i++)
		{
			*rolls += 1;
			*p2 = (*p2 + *die) % 10;
			*die = (*die + 1) % 100;
		}
		
		if(*p2 == 0)
		{
			*s2 += 10;
		}
		else
		{
			*s2 += *p2;
		}
	
		*playing = 0;
	}
}

void solve1() 
{
	int p1 = 4, p2 = 10;
	int s1 = 0, s2 = 0;
	int rolls = 0, die = 1;
	int playing = 0;
	
	while(s1 < 1000 && s2 < 1000)
		simulate_turn(&playing, &rolls, &die, &p1, &p2, &s1, &s2);
	
	cout << playing << endl;
	cout << rolls << endl;
	cout << die << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	
	cout << rolls * min(s1, s2) << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
