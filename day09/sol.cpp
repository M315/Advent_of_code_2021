#include <bits/stdc++.h>

using namespace std;

void solve2() {
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	vector<vector<int>> map;
	
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
			
			map.push_back(vec);
		}
		
		map.pop_back();
	}
	else{
		cout << "No such file" << endl;
	}
	
	fclose(pf);
	
	
	int n = map.size(), m = map[0].size();
	
	// Get the lower points
	vector<pair<int, int>> low_points;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			bool ctrl = true;
			
			if(i > 0 && map[i][j] >= map[i-1][j]) { ctrl = false; }
			if(i < n - 1 && map[i][j] >= map[i+1][j]) { ctrl = false; }
			if(j > 0 && map[i][j] >= map[i][j-1]) { ctrl = false; }
			if(j < m - 1 && map[i][j] >= map[i][j+1]) { ctrl = false; }
			
			if(ctrl)
				low_points.push_back({i, j});
		}
	}
	
	// Find the basins and its size use DFS
	vector<int> basin_sizes;
	
	vector<vector<bool>> unused;
	for(int i = 0; i < n; i++)
	{
		vector<bool> b (m, true);
		unused.push_back(b);
	}
	
	for(auto p : low_points)
	{
		vector<pair<int, int>> active_points;
		active_points.push_back(p);
		
		unused[p.first][p.second] = false;
		
		int size = 0;
		
		while(active_points.size())
		{
			int i = active_points[active_points.size() - 1].first;
			int j = active_points[active_points.size() - 1].second;
			
			size++;
			active_points.pop_back();
			
			if(i > 0 && map[i-1][j] != 9 && unused[i-1][j]) 
			{ 
				active_points.push_back({i-1, j});
				unused[i-1][j] = false;
			}
			
			if(i < n - 1 && map[i+1][j] != 9 && unused[i+1][j]) 
			{ 
				active_points.push_back({i+1, j});
				unused[i+1][j] = false;
			}
			
			if(j > 0 && map[i][j-1] != 9 && unused[i][j-1]) 
			{ 
				active_points.push_back({i, j-1});
				unused[i][j-1] = false;
			}
			
			if(j < m - 1 && map[i][j+1] != 9 && unused[i][j+1]) 
			{ 
				active_points.push_back({i, j+1});
				unused[i][j+1] = false;
			}
		}
		
		basin_sizes.push_back(size);
	}
	
	sort(basin_sizes.begin(), basin_sizes.end());
	
	long long int mult = 1;
	for(int i = basin_sizes.size() - 1; i >= basin_sizes.size() - 3; i--)
		mult *= basin_sizes[i];
	
	cout << mult << endl;
	
	return;
}

void solve1() {
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	vector<vector<int>> map;
	
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
			
			map.push_back(vec);
		}
		
		map.pop_back();
	}
	else{
		cout << "No such file" << endl;
	}
	
	fclose(pf);
	
	
	int sum = 0, n = map.size(), m = map[0].size();
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			bool ctrl = true;
			
			if(i > 0 && map[i][j] >= map[i-1][j]) { ctrl = false; }
			if(i < n - 1 && map[i][j] >= map[i+1][j]) { ctrl = false; }
			if(j > 0 && map[i][j] >= map[i][j-1]) { ctrl = false; }
			if(j < m - 1 && map[i][j] >= map[i][j+1]) { ctrl = false; }
			
			if(ctrl)
				sum += 1 + map[i][j];
		}
	}
	
	cout << sum << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
