#include <bits/stdc++.h>

using namespace std;

bool simulate_step(vector<string>& floor)
{
	bool change = false;
	vector<string> copy (floor);
	int n = floor.size(), m = floor[0].size();
	
	// East move
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m - 1; j++)
		{
			if(copy[i][j] == '>' && copy[i][j + 1] == '.')
			{
				change = true;
				floor[i][j] = '.';
				floor[i][j + 1] = '>';
			}
		}
		
		if(copy[i][m - 1] == '>' && copy[i][0] == '.')
		{
			change = true;
			floor[i][m - 1] = '.';
			floor[i][0] = '>';
		}
	}
	
	copy = floor;
	
	// South move
	for(int j = 0; j < m; j++)
	{
		for(int i = 0; i < n - 1; i++)
		{
			if(copy[i][j] == 'v' && copy[i + 1][j] == '.')
			{
				change = true;
				floor[i][j] = '.';
				floor[i + 1][j] = 'v';
			}
		}
		
		if(copy[n - 1][j] == 'v' && copy[0][j] == '.')
		{
			change = true;
			floor[n - 1][j] = '.';
			floor[0][j] = 'v';
		}
	}
	
	return change;
}

void solve1() 
{
	vector<string> floor;
	
	ifstream pf ("input1.txt");
	
	if(pf.is_open())
	{
		string line;
		
		while(getline(pf, line))
			floor.push_back(line);
	}
	else
	{
		cout << "No such file" << endl;
	}
	
	int step = 1;
	while(simulate_step(floor))
		step++;
	
	cout << step << endl;
	
	return;
}

int main() {
	solve1();
	//solve2();

	return 0;
}
