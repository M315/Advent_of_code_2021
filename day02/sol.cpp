#include <bits/stdc++.h>

using namespace std;

void solve2() {
	ifstream pf ("input1.txt");
	
	int horizontal = 0, depth = 0, aim = 0;
	
	if(pf.is_open())
	{
		string word;
		int x;
		
		while(getline(pf, word, ' '))
		{
			pf >> x;
			
			if(word[0] == 'f')
			{
				horizontal += x;
				depth += (aim * x);
			}
			
			if(word[0] == 'd')
				aim += x;
				
			if(word[0] == 'u')
				aim -= x;
				
			getline(pf, word);
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	cout << horizontal * depth << endl;

	return;
}

void solve1() {
	ifstream pf ("input1.txt");
	
	int horizontal = 0, depth = 0;
	
	if(pf.is_open())
	{
		string word;
		int x;
		
		while(getline(pf, word, ' '))
		{
			pf >> x;
			
			if(word[0] == 'f')
				horizontal += x;
			
			if(word[0] == 'd')
				depth += x;
				
			if(word[0] == 'u')
				depth -= x;
				
			getline(pf, word);
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	cout << horizontal * depth << endl;

	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
