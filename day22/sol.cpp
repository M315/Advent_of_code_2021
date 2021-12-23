#include <bits/stdc++.h>

using namespace std;

// Intersection of 2 cuboids, if they have mesure 0 or are invalid retur all 0
vector<int> intersection(vector<int> a, vector<int> b)
{
	vector<int> cube (6, 0);
	
	// X
	cube[0] = max(a[1], b[1]);
	cube[1] = min(a[2], b[2]);
	
	if(cube[0] >= cube[1])
	{
		for(int i = 0; i < 6; i++)
			cube[i] = 0;
		return cube;
	}
	
	// Y
	cube[2] = max(a[3], b[3]);
	cube[3] = min(a[4], b[4]);
	
	if(cube[2] >= cube[3])
	{
		for(int i = 0; i < 6; i++)
			cube[i] = 0;
		return cube;
	}
	
	// Z
	cube[4] = max(a[5], b[5]);
	cube[5] = min(a[6], b[6]);
	
	if(cube[4] >= cube[5])
	{
		for(int i = 0; i < 6; i++)
			cube[i] = 0;
		return cube;
	}
	
	return cube;
}

// Compute the volume of a cuboid
long long int volume(vector<int> cube)
{
	long long int v = (cube[2] - cube[1]);
	v *= (cube[4] - cube[3]);
	v *= (cube[6] - cube[5]);
	
	return v;
}

void solve2() 
{
	vector<vector<int>> in_cubes;
	
	ifstream pf ("input1.txt");
	
	if(pf.is_open())
	{
		string line;
		while(getline(pf, line))
		{
			// Cube = (on, x1, x2, y1, y2, z1, z2)
			vector<int> cube;
			int index;
			
			if(line[1] == 'n')
			{
				cube.push_back(1);
				index = 5;
			}
			else
			{
				cube.push_back(0);
				index = 6;
			}
			
			// Read x1
			string aux = "";
			while(line[index] != '.')
				aux += line[index++];
			cube.push_back(stoi(aux));
			
			while(line[index] == '.')
				index++;
			
			// Read x2
			aux = "";
			while(line[index] != ',')
				aux += line[index++];
			cube.push_back(stoi(aux) + 1);
			
			// Read y1
			index += 3;
			aux = "";
			while(line[index] != '.')
				aux += line[index++];
			cube.push_back(stoi(aux));
			
			while(line[index] == '.')
				index++;
			
			// Read y2
			aux = "";
			while(line[index] != ',')
				aux += line[index++];
			cube.push_back(stoi(aux) + 1);
			
			// Read z1
			index += 3;
			aux = "";
			while(line[index] != '.')
				aux += line[index++];
			cube.push_back(stoi(aux));
			
			while(line[index] == '.')
				index++;
			
			// Read z2
			aux = "";
			while(index < line.size() && line[index] != '\n')
				aux += line[index++];
			cube.push_back(stoi(aux) + 1);
			
			in_cubes.push_back(cube);
		}
	}
	else
	{
		cout << "No such file" << endl;
	}
	
	// Use the inclusion and exclusion principle
	// The key part is not keeping the "bad" or 0 mesure intersections (From disjoint sets) as the number of cubes will grow too fast
	
	// List with the cuboids already procesed
	vector<vector<int>> cubes;
	
	// For each cuboid in the input
	for(int k = 0; k < in_cubes.size(); k++)
	{
		// If its on
		if(in_cubes[k][0])
		{
			// Add the cuboid to the list
			cubes.push_back(in_cubes[k]);
			
			// For every other cuboid already in the list
			int n = cubes.size() - 1;
			for(int i = 0; i < n; i++)
			{
				// Compute the interesection with the new one
				vector<int> int_cube = intersection(in_cubes[k], cubes[i]);
				
				// If are disjoint then contiue
				if(int_cube[0] == 0 && int_cube[1] == 0 && int_cube[2] == 0 && int_cube[3] == 0 && int_cube[4] == 0 && int_cube[5] == 0)
					continue;
					
				if(cubes[i][0])
				{
					// If both are on keep the intersaction as off
					int_cube.insert(int_cube.begin(), 0);
				}
				else
				{
					// If one is on and the other is off keep the intersaction as on
					int_cube.insert(int_cube.begin(), 1);
				}
				cubes.push_back(int_cube);
			}
		}
		else
		{
			// For every cuboid already in the list
			int n = cubes.size();
			for(int i = 0; i < n; i++)
			{
				// Compute the interesection with the new one
				vector<int> int_cube = intersection(in_cubes[k], cubes[i]);
				
				// If are disjoint then contiue
				if(int_cube[0] == 0 && int_cube[1] == 0 && int_cube[2] == 0 && int_cube[3] == 0 && int_cube[4] == 0 && int_cube[5] == 0)
					continue;
				
				if(cubes[i][0])
				{
					// If both are off keep the intersaction as off
					int_cube.insert(int_cube.begin(), 0);
				}
				else
				{
					// If one is on and the other is off keep the intersaction as on
					int_cube.insert(int_cube.begin(), 1);
				}
				cubes.push_back(int_cube);
			}
		}
		//cout << k + 1 << " " << cubes.size() << endl;
	}
	
	long long int ans = 0;
	
	for(auto cube : cubes)
	{
		if(cube[0])
		{
			// Add the on cuboids
			ans += volume(cube);
		}
		else
		{
			// Subtract the off cuboids
			ans -= volume(cube);
		}
	}
		
	cout << ans << endl;
		
	return;
}

void solve1() 
{
	vector<vector<vector<bool>>> reactor;
	for(int i = 0; i <= 100; i++)
	{
		vector<vector<bool>> aux1;
		for(int j = 0; j <= 100; j++)
		{
			vector<bool> aux2 (101, false);
			aux1.push_back(aux2);
		}
		reactor.push_back(aux1);
	}
	
	ifstream pf ("input1.txt");
	
	if(pf.is_open())
	{
		for(int t = 0; t < 20; t++)
		{
			string line;
			
			getline(pf, line);
			
			bool change;
			int index;
			
			if(line[1] == 'n')
			{
				change = true;
				index = 5;
			}
			else
			{
				change = false;
				index = 6;
			}
				
			int x1, x2, y1, y2, z1, z2;
			
			// Read x1
			string aux = "";
			while(line[index] != '.')
				aux += line[index++];
			x1 = stoi(aux) + 50;
			
			while(line[index] == '.')
				index++;
			
			// Read x2
			aux = "";
			while(line[index] != ',')
				aux += line[index++];
			x2 = stoi(aux) + 50;
			
			// Read y1
			index += 3;
			aux = "";
			while(line[index] != '.')
				aux += line[index++];
			y1 = stoi(aux) + 50;
			
			while(line[index] == '.')
				index++;
			
			// Read y2
			aux = "";
			while(line[index] != ',')
				aux += line[index++];
			y2 = stoi(aux) + 50;
			
			// Read z1
			index += 3;
			aux = "";
			while(line[index] != '.')
				aux += line[index++];
			z1 = stoi(aux) + 50;
			
			while(line[index] == '.')
				index++;
			
			// Read z2
			aux = "";
			while(line[index] != '\n')
				aux += line[index++];
			z2 = stoi(aux) + 50;
			
			for(int i = x1; i <= x2; i++)
				for(int j = y1; j <= y2; j++)
					for(int k = z1; k <= z2; k++)
						reactor[i][j][k] = change;
		}
	}
	else
	{
		cout << "No such file" << endl;
	}
	
	int count = 0;
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			for(int k = 0; k <= 100; k++)
				if(reactor[i][j][k])
					count++;

	cout << count << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
