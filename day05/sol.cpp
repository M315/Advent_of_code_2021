#include <bits/stdc++.h>

using namespace std;

void solve2() {
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	// Create a map 1000 x 1000 initialize to 0
	int n = 1000;
	vector<vector<int>> map;
	for(int i = 0; i < n; i++)
	{
		vector<int> row (n, 0);
		map.push_back(row);
	}
	
	if(pf != NULL)
	{
		int x1, x2, y1, y2;
		while(fscanf(pf, "%d,%d -> %d,%d\n", &x1, &x2, &y1, &y2) != EOF)
		{
			if(x1 == y1)
			{
				// Update the col
				if(x2 <= y2)
				{
					for(int j = x2; j <= y2; j++)
						map[x1][j]++;
				}
				else
				{
					for(int j = y2; j <= x2; j++)
						map[x1][j]++;
				}
			}
			
			else if(x2 == y2)
			{
				// Update the row
				if(x1 <= y1)
				{
					for(int i = x1; i <= y1; i++)
						map[i][x2]++;
				}
				else
				{
					for(int i = y1; i <= x1; i++)
						map[i][x2]++;
				}
			}
			
			else if((x1 - y1) == (x2 - y2))
			{
				// Update diagonal (possitive slope)
				if(x1 <= y1)
				{
					for(int i = x1, j = x2; i <= y1 && j <= y2; i++, j++)
						map[i][j]++;
				}
				else
				{
					for(int i = y1, j = y2; i <= x1 && j <= x2; i++, j++)
						map[i][j]++;
				}
			}
			
			else if((x1 - y1) == (y2 - x2))
			{
				// Update diagonal (negative slope)
				if(x1 <= y1)
				{
					for(int i = x1, j = x2; i <= y1 && j >= y2; i++, j--)
						map[i][j]++;
				}
				else
				{
					for(int i = y1, j = y2; i <= x1 && j >= x2; i++, j--)
						map[i][j]++;
				}
			}
		}
		
		int count = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(map[i][j] >= 2)
					count++;
		
		cout << count << endl;
	}
	else{
		cout << "No such file" << endl;
	}

	return;
}

void solve1() {
	FILE *pf;
	pf = fopen("input1.txt", "r");
	
	// Create a map 1000 x 1000 initialize to 0
	int n = 1000;
	vector<vector<int>> map;
	for(int i = 0; i < n; i++)
	{
		vector<int> row (n, 0);
		map.push_back(row);
	}
	
	if(pf != NULL)
	{
		int x1, x2, y1, y2;
		while(fscanf(pf, "%d,%d -> %d,%d\n", &x1, &x2, &y1, &y2) != EOF)
		{
			if(x1 == y1)
			{
				// Update the col
				if(x2 <= y2)
				{
					for(int j = x2; j <= y2; j++)
						map[x1][j]++;
				}
				else
				{
					for(int j = y2; j <= x2; j++)
						map[x1][j]++;
				}
			}
			
			else if(x2 == y2)
			{
				// Update the row
				if(x1 <= y1)
				{
					for(int i = x1; i <= y1; i++)
						map[i][x2]++;
				}
				else
				{
					for(int i = y1; i <= x1; i++)
						map[i][x2]++;
				}
			}
		}
		
		int count = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(map[i][j] >= 2)
					count++;
		
		cout << count << endl;
	}
	else{
		cout << "No such file" << endl;
	}

	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
