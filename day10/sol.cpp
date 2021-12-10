/*
 * Lets assing a number from 0 to 3 to the different brackets:
 * 0 : (
 * 1 : [
 * 2 : {
 * 3 : <
 */
 
#include <bits/stdc++.h>

using namespace std;

long long int complete(string s)
{
	vector<char> open_brackets;
	
	for(char c : s)
	{
		switch(c)
		{
			case '(':
				open_brackets.push_back(c);
				break;
			
			case ')':
				open_brackets.pop_back();
				break;
				
			case '[':
				open_brackets.push_back(c);
				break;
		
			case ']':
				open_brackets.pop_back();
				break;
		
			case '{':
				open_brackets.push_back(c);
				break;
		
			case '}':
				open_brackets.pop_back();
				break;
				
			case '<':
				open_brackets.push_back(c);
				break;
				
			case '>':
				open_brackets.pop_back();
				break;
		}
	}
	
	long long int score = 0;
	
	for(int i = open_brackets.size() - 1; i >= 0; i--)
	{
		score *= 5;
		
		switch(open_brackets[i])
		{
			case '(':
				score += 1;
				break;
				
			case '[':
				score += 2;
				break;
		
			case '{':
				score += 3;
				break;
				
			case '<':
				score += 4;
				break;
		}
	}
	
	return score;
}

bool is_corrupted(string s)
{
	vector<char> open_brackets;
	
	for(char c : s)
	{
		switch(c)
		{
			case '(':
				open_brackets.push_back(c);
				break;
			
			case ')':
				if(open_brackets[open_brackets.size() - 1] == '(')
				{
					open_brackets.pop_back();
				}
				else
				{
					return true;
				}
				break;
				
			case '[':
				open_brackets.push_back(c);
				break;
		
			case ']':
				if(open_brackets[open_brackets.size() - 1] == '[')
				{
					open_brackets.pop_back();
				}
				else
				{
					return true;
				}
				break;
		
			case '{':
				open_brackets.push_back(c);
				break;
		
			case '}':
				if(open_brackets[open_brackets.size() - 1] == '{')
				{
					open_brackets.pop_back();
				}
				else
				{
					return true;
				}
				break;
				
			case '<':
				open_brackets.push_back(c);
				break;
				
			case '>':
				if(open_brackets[open_brackets.size() - 1] == '<')
				{
					open_brackets.pop_back();
				}
				else
				{
					return true;
				}
				break;
		}
	}
		
	return false;
}

void solve2() 
{
	ifstream pf ("input1.txt");
	
	if(pf.is_open())
	{
		vector<long long int> scores;
		
		string brackets;
		
		while(getline(pf, brackets))
			if(is_corrupted(brackets) == false)
				scores.push_back(complete(brackets));
		
		sort(scores.begin(), scores.end());
		
		cout << scores[scores.size() / 2] << endl;
	}
	else{
		cout << "No such file" << endl;
	}

	return;
}

int corrupted(string s)
{
	vector<char> open_brackets;
	
	for(char c : s)
	{
		switch(c)
		{
			case '(':
				open_brackets.push_back(c);
				break;
			
			case ')':
				if(open_brackets[open_brackets.size() - 1] == '(')
				{
					open_brackets.pop_back();
				}
				else
				{
					return 3;
				}
				break;
				
			case '[':
				open_brackets.push_back(c);
				break;
		
			case ']':
				if(open_brackets[open_brackets.size() - 1] == '[')
				{
					open_brackets.pop_back();
				}
				else
				{
					return 57;
				}
				break;
		
			case '{':
				open_brackets.push_back(c);
				break;
		
			case '}':
				if(open_brackets[open_brackets.size() - 1] == '{')
				{
					open_brackets.pop_back();
				}
				else
				{
					return 1197;
				}
				break;
				
			case '<':
				open_brackets.push_back(c);
				break;
				
			case '>':
				if(open_brackets[open_brackets.size() - 1] == '<')
				{
					open_brackets.pop_back();
				}
				else
				{
					return 25137;
				}
				break;
		}
	}
		
	return 0;
}

void solve1() 
{
	ifstream pf ("input1.txt");
	
	if(pf.is_open())
	{
		long long int sum_err = 0;
		
		string brackets;
		
		while(getline(pf, brackets))
			sum_err += corrupted(brackets);
		
		cout << sum_err << endl;
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
