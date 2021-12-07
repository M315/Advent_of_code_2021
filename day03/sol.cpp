#include <bits/stdc++.h>

using namespace std;

void solve2() {
	vector<vector<int>> nums;
	int n = 12, gamma = 0, epsilon = 0;
	int bits[n];
	
	// Gamma - Oxigen
	ifstream pf ("input1.txt");
	
	if(pf.is_open())
	{
		string word;
		
		getline(pf, word);
		
		vector<int> aux (n);
		
		for(int i = 0; i < n; i++)
		{
			bits[i] = (int)word[i] - 48;
			aux[i] = (int)word[i] - 48;
		}
		nums.push_back(aux);
		
		while(getline(pf, word))
		{
			for(int i = 0; i < n; i++)
			{
				bits[i] += ((int)word[i] - 48);
				aux[i] = (int)word[i] - 48;
			}
			
			nums.push_back(aux);
		}
		
		int index = 0;
		
		while(index < n)
		{	
			int mc = 1;
			
			if(bits[index] < (nums.size() + 1) / 2){ mc = 0; }
			
			vector<vector<int>> new_nums;
			
			for(int i = 0; i < nums.size(); i++)
			{
				if(nums[i][index] == mc)
				{
					new_nums.push_back(nums[i]);
				}
				else
				{
					for(int j = index + 1; j < n; j++)
					{
						bits[j] -= nums[i][j];
					}
				}
			}
			
			nums = new_nums;
			if(nums.size() == 1)
			{
				// To decimal
				int mult = 1;
				for(int i = n - 1; i >= 0; i--)
				{
					gamma += nums[0][i] * mult;
					mult *= 2;
				}
				
				break;
			}
			
			index++;
		}
	
	}
	else{
		cout << "No such file" << endl;
	}
	
	pf.close();
	nums.clear();
	
	// Epsilon - CO2
	pf.open ("input1.txt");
	
	if(pf.is_open())
	{
		string word;
		
		getline(pf, word);
		
		vector<int> aux (n);
		
		for(int i = 0; i < n; i++)
		{
			bits[i] = (int)word[i] - 48;
			aux[i] = (int)word[i] - 48;
		}
		nums.push_back(aux);
		
		while(getline(pf, word))
		{
			for(int i = 0; i < n; i++)
			{
				bits[i] += ((int)word[i] - 48);
				aux[i] = (int)word[i] - 48;
			}
			
			nums.push_back(aux);
		}
		
		int index = 0;
		
		while(index < n)
		{	
			int lc = 1;
			
			if(bits[index] >= (nums.size() + 1) / 2){ lc = 0; }
			
			vector<vector<int>> new_nums;
			
			for(int i = 0; i < nums.size(); i++)
			{
				if(nums[i][index] == lc)
				{
					new_nums.push_back(nums[i]);
				}
				else
				{
					for(int j = index + 1; j < n; j++)
					{
						bits[j] -= nums[i][j];
					}
				}
			}
			
			nums = new_nums;
			if(nums.size() == 1)
			{
				// To decimal
				int mult = 1;
				for(int i = n - 1; i >= 0; i--)
				{
					epsilon += nums[0][i] * mult;
					mult *= 2;
				}
				
				break;
			}
			
			index++;
		}
	
	}
	else{
		cout << "No such file" << endl;
	}
	
	cout << gamma << " * " << epsilon << " = " << gamma * epsilon << endl;

	return;
}

void solve1() {
	ifstream pf ("input1.txt");
	
	int bits[12];
	int count = 0;
	
	if(pf.is_open())
	{
		string word;
		
		getline(pf, word);
		
		count++;
		
		for(int i = 0; i < 12; i++)
			bits[i] = (int)word[i] - 48;
		
		while(getline(pf, word))
		{
			count++;
			
			for(int i = 0; i < 12; i++)
				bits[i] += ((int)word[i] - 48);
		}
		
		int mult = 1, gamma = 0, epsilon = 0;
		for(int i = 11; i >= 0; i--)
		{
			if(bits[i] >= count / 2)
			{
				gamma += mult;
			}
			else
			{
				epsilon += mult;
			}
			
			mult *= 2;
		}
		
		cout << gamma << " * " << epsilon << " = " << gamma * epsilon << endl;
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
