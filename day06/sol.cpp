#include <bits/stdc++.h>

using namespace std;

vector<long long int> simulate_day(vector<long long int> fish)
{
	vector<long long int> new_fish (9);
	
	long long int aux = fish[0];
	for(int i = 1; i < fish.size(); i++)
	{
		new_fish[i-1] = fish[i];
	}
	
	new_fish[6] += aux;
	new_fish[8] = aux;
	
	return new_fish;
}

void solve2() {
	ifstream pf ("input1.txt");
	
	vector<long long int> fish (9, 0);
	
	if(pf.is_open())
	{
		char num[16];
		
		while(pf.getline(num, 16, ','))
		{
			fish[atoi(num)]++;
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	for(int i = 0; i < 256; i++)
		fish = simulate_day(fish);
	
	long long int sum = 0;
	for(int i = 0; i <= 8; i++)
		sum += fish[i];

	cout << sum << endl;
	
	return;
}

vector<int> simulate_day1(vector<int> fish)
{
	vector<int> new_fish = fish;
	
	for(int i = 0; i < fish.size(); i++)
	{
		if(fish[i])
		{
			new_fish[i]--;
		}
		else
		{
			new_fish[i] = 6;
			new_fish.push_back(8);
		}
	}
	
	return new_fish;
}

void solve1() {
	ifstream pf ("input1.txt");
	
	vector<int> fish;
	
	if(pf.is_open())
	{
		char num[16];
		
		while(pf.getline(num, 16, ','))
		{
			fish.push_back(atoi(num));
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	for(int i = 0; i < 80; i++)
		fish = simulate_day1(fish);

	cout << fish.size() << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
