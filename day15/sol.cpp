#include <bits/stdc++.h>

using namespace std;

int dijktra(vector<vector<int>>& map)
{
	int n = map.size(), m = map[0].size();
	
	vector<vector<bool>> visited;
	for(int i = 0; i < n; i++)
	{
		vector<bool> v (m, false);
		visited.push_back(v);
	}
	
	// 0: dist, 1: i, 2: j
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > Q;
	
	vector<int> v (3, 0);
	Q.push(v);
	
	while(Q.size())
	{
		vector<int> u = Q.top();
		int d = u[0], i = u[1], j = u[2];
		
		Q.pop();
		
		if(visited[i][j])
			continue;
		
		// Check if its de solution
		if(i == n - 1 && j == m - 1)
		{
			//path(map, parent);
			return d;
		}
		
		visited[i][j] = true;
		
		// Check neighbours
		if(i > 0)
		{
			if(!visited[i - 1][j])
			{
				vector<int> v (3, 0);
				v[0] = d + map[i - 1][j];
				v[1] = i - 1;
				v[2] = j;
				
				Q.push(v);
			}
		}
		
		if(i < n - 1)
		{
			if(!visited[i + 1][j])
			{
				vector<int> v (3, 0);
				v[0] = d + map[i + 1][j];
				v[1] = i + 1;
				v[2] = j;
				
				Q.push(v);
			}
		}
		
		if(j > 0)
		{
			if(!visited[i][j - 1])
			{
				vector<int> v (3, 0);
				v[0] = d + map[i][j - 1];
				v[1] = i;
				v[2] = j - 1;
				
				Q.push(v);
			}
		}
		
		if(j < m - 1)
		{
			if(!visited[i][j + 1])
			{
				vector<int> v (3, 0);
				v[0] = d + map[i][j + 1];
				v[1] = i;
				v[2] = j + 1;
				
				Q.push(v);
			}
		}
	}
	
	return 0;
}

void solve2() 
{
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	vector<vector<int>> map;
	
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
			
			map.push_back(vec);
		}
		
		map.pop_back();
	}
	else{
		cout << "No such file" << endl;
	}
	
	int n = map.size(), m = map[0].size();
	
	// Generate the big map
	vector<vector<int>> big_map;
	
	// Frist lines
	for(int i = 0; i < n; i++)
	{
		vector<int> vec (m * 5);
		
		// 1
		for(int j = 0; j < m; j++)
			vec[j] = map[i][j];
		
		// 2
		for(int j = 0; j < m; j++)
		{
			vec[m + j] = vec[j] + 1;
			
			if(vec[m + j] == 10)
				vec[m + j] = 1;
		}
		
		// 3
		for(int j = 0; j < m; j++)
		{
			vec[(2 * m) + j] = vec[m + j] + 1;
			
			if(vec[(2 * m) + j] == 10)
				vec[(2 * m) + j] = 1;
		}
		
		// 4
		for(int j = 0; j < m; j++)
		{
			vec[(3 * m) + j] = vec[(2 * m) + j] + 1;
			
			if(vec[(3 * m) + j] == 10)
				vec[(3 * m) + j] = 1;
		}
		
		// 5
		for(int j = 0; j < m; j++)
		{
			vec[(4 * m) + j] = vec[(3 * m) + j] + 1;
			
			if(vec[(4 * m) + j] == 10)
				vec[(4 * m) + j] = 1;
		}
		
		big_map.push_back(vec);
	}
	
	// Second lines
	for(int i = 0; i < n; i++)
	{
		vector<int> vec (m * 5);
		
		// 1
		for(int j = 0; j < m; j++)
		{
			vec[j] = map[i][j] + 1;
			
			if(vec[j] == 10)
				vec[j] = 1;
		}
		
		// 2
		for(int j = 0; j < m; j++)
		{
			vec[m + j] = vec[j] + 1;
			
			if(vec[m + j] == 10)
				vec[m + j] = 1;
		}
		
		// 3
		for(int j = 0; j < m; j++)
		{
			vec[(2 * m) + j] = vec[m + j] + 1;
			
			if(vec[(2 * m) + j] == 10)
				vec[(2 * m) + j] = 1;
		}
		
		// 4
		for(int j = 0; j < m; j++)
		{
			vec[(3 * m) + j] = vec[(2 * m) + j] + 1;
			
			if(vec[(3 * m) + j] == 10)
				vec[(3 * m) + j] = 1;
		}
		
		// 5
		for(int j = 0; j < m; j++)
		{
			vec[(4 * m) + j] = vec[(3 * m) + j] + 1;
			
			if(vec[(4 * m) + j] == 10)
				vec[(4 * m) + j] = 1;
		}
		
		big_map.push_back(vec);
	}
	
	// Third lines
	for(int i = 0; i < n; i++)
	{
		vector<int> vec (m * 5);
		
		// 1
		for(int j = 0; j < m; j++)
		{
			vec[j] = big_map[n + i][j] + 1;
			
			if(vec[j] == 10)
				vec[j] = 1;
		}
		
		// 2
		for(int j = 0; j < m; j++)
		{
			vec[m + j] = vec[j] + 1;
			
			if(vec[m + j] == 10)
				vec[m + j] = 1;
		}
		
		// 3
		for(int j = 0; j < m; j++)
		{
			vec[(2 * m) + j] = vec[m + j] + 1;
			
			if(vec[(2 * m) + j] == 10)
				vec[(2 * m) + j] = 1;
		}
		
		// 4
		for(int j = 0; j < m; j++)
		{
			vec[(3 * m) + j] = vec[(2 * m) + j] + 1;
			
			if(vec[(3 * m) + j] == 10)
				vec[(3 * m) + j] = 1;
		}
		
		// 5
		for(int j = 0; j < m; j++)
		{
			vec[(4 * m) + j] = vec[(3 * m) + j] + 1;
			
			if(vec[(4 * m) + j] == 10)
				vec[(4 * m) + j] = 1;
		}
		
		big_map.push_back(vec);
	}
	
	// Fourth lines
	for(int i = 0; i < n; i++)
	{
		vector<int> vec (m * 5);
		
		// 1
		for(int j = 0; j < m; j++)
		{
			vec[j] = big_map[(2 * n) + i][j] + 1;
			
			if(vec[j] == 10)
				vec[j] = 1;
		}
		
		// 2
		for(int j = 0; j < m; j++)
		{
			vec[m + j] = vec[j] + 1;
			
			if(vec[m + j] == 10)
				vec[m + j] = 1;
		}
		
		// 3
		for(int j = 0; j < m; j++)
		{
			vec[(2 * m) + j] = vec[m + j] + 1;
			
			if(vec[(2 * m) + j] == 10)
				vec[(2 * m) + j] = 1;
		}
		
		// 4
		for(int j = 0; j < m; j++)
		{
			vec[(3 * m) + j] = vec[(2 * m) + j] + 1;
			
			if(vec[(3 * m) + j] == 10)
				vec[(3 * m) + j] = 1;
		}
		
		// 5
		for(int j = 0; j < m; j++)
		{
			vec[(4 * m) + j] = vec[(3 * m) + j] + 1;
			
			if(vec[(4 * m) + j] == 10)
				vec[(4 * m) + j] = 1;
		}
		
		big_map.push_back(vec);
	}
	
	// Fifth lines
	for(int i = 0; i < n; i++)
	{
		vector<int> vec (m * 5);
		
		// 1
		for(int j = 0; j < m; j++)
		{
			vec[j] = big_map[(3 * n) + i][j] + 1;
			
			if(vec[j] == 10)
				vec[j] = 1;
		}
		
		// 2
		for(int j = 0; j < m; j++)
		{
			vec[m + j] = vec[j] + 1;
			
			if(vec[m + j] == 10)
				vec[m + j] = 1;
		}
		
		// 3
		for(int j = 0; j < m; j++)
		{
			vec[(2 * m) + j] = vec[m + j] + 1;
			
			if(vec[(2 * m) + j] == 10)
				vec[(2 * m) + j] = 1;
		}
		
		// 4
		for(int j = 0; j < m; j++)
		{
			vec[(3 * m) + j] = vec[(2 * m) + j] + 1;
			
			if(vec[(3 * m) + j] == 10)
				vec[(3 * m) + j] = 1;
		}
		
		// 5
		for(int j = 0; j < m; j++)
		{
			vec[(4 * m) + j] = vec[(3 * m) + j] + 1;
			
			if(vec[(4 * m) + j] == 10)
				vec[(4 * m) + j] = 1;
		}
		
		big_map.push_back(vec);
	}
	
	cout << dijktra(big_map) << endl;
	
	return;
}

void solve1() 
{
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	vector<vector<int>> map;
	
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
			
			map.push_back(vec);
		}
		
		map.pop_back();
	}
	else{
		cout << "No such file" << endl;
	}
	
	cout << dijktra(map) << endl;
	
	return;
}


int main() {
	//solve1();
	solve2();

	return 0;
}
