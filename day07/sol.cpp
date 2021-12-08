#include <bits/stdc++.h>

using namespace std;

vector<int> triangular(int n)
{
	vector<int> ret (n, 0);
	
	for(int i = 1; i < n; i++)
	{
		ret[i] = i + ret[i-1];
	}
	
	return ret;
}

void solve1() {
	ifstream pf ("input1.txt");
	
	map<int, int> crab;
	
	if(pf.is_open())
	{
		char num[16];
		
		while(pf.getline(num, 16, ','))
		{
			crab[atoi(num)]++;
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	vector<int> tri = triangular(2000);
	long long int m = INT_MAX;
	for(int k = 0; k < 2000; k++)
	{
		long long int sum = 0;
		for(auto c : crab)
		{
			if(c.first > k)
			{
				sum += tri[(c.first - k)] * c.second;
			}
			else
			{
				sum += tri[(k - c.first)] * c.second;
			}
		}
		
		if(m > sum){ m = sum; }
	}
	
	cout << m << endl;
	
	return;
}

int main() {
	solve1();
	//solve2();

	return 0;
}
