#include <bits/stdc++.h>

using namespace std;

int simulate(vector<vector<int>>& octopus)
{
	int n = octopus.size(), m = octopus[0].size();
	
	vector<vector<bool>> has_popped;
	for(int i = 0; i < n; i++)
	{
		vector<bool> vec (m, false);
		has_popped.push_back(vec);
	}
	
	vector<pair<int, int>> is_popping;
	
	// Increase everything by 1
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			octopus[i][j]++;
			if(octopus[i][j] >= 10)
			{
				has_popped[i][j] = true;
				is_popping.push_back({i, j});
			}
		}
	}
	
	// Pop the popping ones
	while(is_popping.size())
	{
		auto p = is_popping.back();
		int i = p.first, j = p.second;
		
		is_popping.pop_back();
		
		if(i > 0)
		{
			octopus[i-1][j]++;
			if(octopus[i-1][j] >= 10 && !has_popped[i-1][j])
			{
				has_popped[i-1][j] = true;
				is_popping.push_back({i-1, j});
			}
		}
		
		if(i < n -1)
		{
			octopus[i+1][j]++;
			if(octopus[i+1][j] >= 10 && !has_popped[i+1][j])
			{
				has_popped[i+1][j] = true;
				is_popping.push_back({i+1, j});
			}
		}
		
		if(j > 0)
		{
			octopus[i][j-1]++;
			if(octopus[i][j-1] >= 10 && !has_popped[i][j-1])
			{
				has_popped[i][j-1] = true;
				is_popping.push_back({i, j-1});
			}
		}
		
		if(j < m - 1)
		{
			octopus[i][j+1]++;
			if(octopus[i][j+1] >= 10 && !has_popped[i][j+1])
			{
				has_popped[i][j+1] = true;
				is_popping.push_back({i, j+1});
			}
		}
		
		// Diagonals
		if(i > 0 && j > 0)
		{
			octopus[i-1][j-1]++;
			if(octopus[i-1][j-1] >= 10 && !has_popped[i-1][j-1])
			{
				has_popped[i-1][j-1] = true;
				is_popping.push_back({i-1, j-1});
			}
		}
		
		if(i > 0 && j < m - 1)
		{
			octopus[i-1][j+1]++;
			if(octopus[i-1][j+1] >= 10 && !has_popped[i-1][j+1])
			{
				has_popped[i-1][j+1] = true;
				is_popping.push_back({i-1, j+1});
			}
		}
		
		if(i < n -1 && j > 0)
		{
			octopus[i+1][j-1]++;
			if(octopus[i+1][j-1] >= 10 && !has_popped[i+1][j-1])
			{
				has_popped[i+1][j-1] = true;
				is_popping.push_back({i+1, j-1});
			}
		}
		
		if(i < n - 1 && j < m - 1)
		{
			octopus[i+1][j+1]++;
			if(octopus[i+1][j+1] >= 10 && !has_popped[i+1][j+1])
			{
				has_popped[i+1][j+1] = true;
				is_popping.push_back({i+1, j+1});
			}
		}
	}
	
	// Set the popped ones to 0 and count pops
	int pop = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j =0; j < m; j++)
		{
			if(has_popped[i][j])
			{
				octopus[i][j] = 0;
				pop++;
			}
		}
	}
	
	return pop;
}

void solve2() 
{
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	vector<vector<int>> octopus;
	
	// Read
	if(pf != NULL)
	{
		char c = '0';
		
		while(c != EOF)
		{
			vector<int> vec;
			c = fgetc(pf);
			
			while(c != '\n' && c != EOF)
			{
				vec.push_back((int)c - 48);
				c = fgetc(pf);
			}
			
			octopus.push_back(vec);
		}
		
		octopus.pop_back();
	}
	else{
		cout << "No such file" << endl;
	}
	
	int n = octopus.size(), m = octopus[0].size();
	int k = 0, popped = 0;
	
	while(popped != n * m)
	{
		popped = simulate(octopus);
		k++;
	}
	
	cout << k << endl;
	
	return;
}

void solve1() 
{
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	vector<vector<int>> octopus;
	
	// Read
	if(pf != NULL)
	{
		char c = '0';
		
		while(c != EOF)
		{
			vector<int> vec;
			c = fgetc(pf);
			
			while(c != '\n' && c != EOF)
			{
				vec.push_back((int)c - 48);
				c = fgetc(pf);
			}
			
			octopus.push_back(vec);
		}
		
		octopus.pop_back();
	}
	else{
		cout << "No such file" << endl;
	}
	
	int popped = 0;
	for(int k = 0; k < 100; k++)
	{
		popped += simulate(octopus);
	}
	
	cout << popped << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
