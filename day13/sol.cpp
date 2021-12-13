#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fold(vector<vector<int>> map, bool dir, int line)
{
	int n = map.size(), m = map[0].size();
	vector<vector<int>> new_map;
	
	// Y fold
	if(dir)
	{
		for(int i = 0; i < line; i++)
			new_map.push_back(map[i]);
		
		for(int i = line + 1; i < n; i++)
			for(int j = 0; j < m; j++)
				new_map[line - (i - line)][j] += map[i][j];
		
	}
	// X fold
	else
	{
		for(int i = 0; i < n; i++)
		{
			vector<int> aux (line, 0);
			new_map.push_back(aux);
		}
		
		// Rightside
		for(int i = 0; i < n; i++)
			for(int j = 0; j < line; j++)
				new_map[i][j] += map[i][j];
		
		// Leftside
		for(int i = 0; i < n; i++)
			for(int j = line + 1; j < m; j++)
				new_map[i][line - (j - line)] += map[i][j];
	}
	
	return new_map;
}

void solve2() 
{
	ifstream pf ("input1.txt");
	
	int n = 890;
	int m = 1311;
	
	vector<vector<int>> map;
	
	for(int i = 0; i < n; i++)
	{
		vector<int> aux (m, 0);
		map.push_back(aux);
	}
	
	// List of folds, 0 = x, 1 = y
	vector<pair<bool, int>> folds;
	
	// Read points and folds
	if(pf.is_open())
	{
		// Points
		for(int i = 0; i < 782; i++)
		{
			char c = ',';
			int x, y;
			
			pf >> x >> c >> y;
			
			map[y][x] = 1;
		}
		
		// Folds
		for(int i = 783; i < 795; i++)
		{
			char c = ',';
			char dir;
			int line;
			
			pf >> dir >> c >> line;
			
			if(dir == 'x')
			{
				folds.push_back({false, line});
			}
			else
			{
				folds.push_back({true, line});
			}
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	for(auto f : folds)
		map = fold(map, f.first, f.second);
	
	for(int i = 0; i < map.size(); i++)
	{
		for(int j = 0; j < map[i].size(); j++)
			if(map[i][j])
			{
				cout << "# ";
			}
			else
			{
				cout << ". ";
			}
		cout << endl;
	}
	
	return;
}

void solve1() 
{
	ifstream pf ("input1.txt");
	
	int n = 890;
	int m = 1311;
	
	vector<vector<int>> map;
	
	for(int i = 0; i < n; i++)
	{
		vector<int> aux (m, 0);
		map.push_back(aux);
	}
	
	// List of folds, 0 = x, 1 = y
	vector<pair<bool, int>> folds;
	
	// Read points and folds
	if(pf.is_open())
	{
		// Points
		for(int i = 0; i < 782; i++)
		{
			char c = ',';
			int x, y;
			
			pf >> x >> c >> y;
			
			map[y][x] = 1;
		}
		
		// Folds
		for(int i = 783; i < 795; i++)
		{
			char c = ',';
			char dir;
			int line;
			
			pf >> dir >> c >> line;
			
			if(dir == 'x')
			{
				folds.push_back({false, line});
			}
			else
			{
				folds.push_back({true, line});
			}
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	map = fold(map, folds[0].first, folds[0].second);
	
	int dots = 0;
	for(int i = 0; i < map.size(); i++)
		for(int j = 0; j < map[i].size(); j++)
			if(map[i][j])
				dots++;
			
	cout << dots << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
