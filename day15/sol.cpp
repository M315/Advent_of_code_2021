#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
	return a[0] > b[0];
}

int is_in_queue(vector<vector<int>> Q, int i, int j)
{
	int in = -1;
	for(int k = 0; k < Q.size(); k++)
	{
		if(Q[k][1] == i && Q[k][2] == j)
		{
			in = k;
			break;
		}
	}
	
	return in;
}

void path(vector<vector<int>>& map, vector<vector<int>> parent)
{
	int n = map.size(), m = map[0].size();
	
	int i = n - 1, j = m - 1;
	
	int d = 0;
	
	while(parent[i][j] != 0)
	{
		d += map[i][j];
		
		map[i][j] = 0;
		if(parent[i][j] == 1)
			i++;
		else if(parent[i][j] == -1)
			i--;
		else if(parent[i][j] == 2)
			j++;
		else if(parent[i][j] == -2)
			j--;
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}

int dijktra(vector<vector<int>>& map)
{
	int n = map.size(), m = map[0].size();
	
	// 0: dist, 1: i, 2: j
	vector<vector<int>> Q;
	
	// -1,1 i-ways, -2,2 j-ways
	vector<vector<int>> parent = map;
	
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j++)
		{
			vector<int> vec;
			
			// Dist
			vec.push_back(INT_MAX);
			
			// i, j
			vec.push_back(i);
			vec.push_back(j);
			
			Q.push_back(vec);
			
			// parents
			parent[i][j] = 0;
		}
	}
	
	// dist source = 0
	Q[0][0] = 0;
	
	while(Q.size())
	{
		// Sort the vector
		sort(Q.begin(), Q.end(), comp);
		
		vector<int> u = Q.back();
		int dist = u[0], i = u[1], j = u[2];
		
		Q.pop_back();
		
		// Check if its de solution
		if(i == n - 1 && j == m - 1)
		{
			path(map, parent);
			return dist;
		}
		
		// Check neighbours
		if(i > 0)
		{
			int k = is_in_queue(Q, i - 1, j);
			if(k != -1){
				int alt = dist + map[i - 1][j];
				
				if(alt < Q[k][0])
				{
					Q[k][0] = alt;
					parent[i - 1][j] = 1;
				}
			}
		}
		
		if(i < n - 1)
		{
			int k = is_in_queue(Q, i + 1, j);
			if(k != -1){
				int alt = dist + map[i + 1][j];
				
				if(alt < Q[k][0])
				{
					Q[k][0] = alt;
					parent[i + 1][j] = -1;
				}
			}
		}
		
		if(j < 0)
		{
			int k = is_in_queue(Q, i, j - 1);
			if(k != -1){
				int alt = dist + map[i][j - 1];
				
				if(alt < Q[k][0])
				{
					Q[k][0] = alt;
					parent[i][j - 1] = 2;
				}
			}
		}
		
		if(j < m - 1)
		{
			int k = is_in_queue(Q, i, j + 1);
			if(k != -1){
				int alt = dist + map[i][j + 1];
				
				if(alt < Q[k][0])
				{
					Q[k][0] = alt;
					parent[i][j + 1] = -2;
				}
			}
		}
	}
	
	return 0;
}

void solve1() 
{
	FILE *pf;
	pf = fopen("input_test.txt", "r");
	
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
	solve1();
	//solve2();

	return 0;
}
