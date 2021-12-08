/*
 * Encode the sevent segments as:
 * 
 * 		0
 * 1		2
 * 		3
 * 4		5
 * 		6
 * 
 * Ans store it in a vector, where we will put the possible values of each possition.
 */ 



#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b)
{
    return (a.size() < b.size());
}

int segment_value(vector<vector<bool>> segment, string s)
{
	if(s.size() == 2)
		return 1;
	
	if(s.size() == 3)
		return 7;
		
	if(s.size() == 4)
		return 4;
	
	if(s.size() == 7)
		return 8;
	
	if(s.size() == 5)
	{
		int id1 = 0;
		for(int i = 0; i < 7; i++)
			if(segment[1][i])
				id1 = i;
		
		int id4 = 0;
		for(int i = 0; i < 7; i++)
			if(segment[4][i])
				id4 = i;
		
		for(char c : s)
		{
			if((int)c - 97 == id1)
				return 5;
			
			if((int)c - 97 == id4)
				return 2;
		}
		
		return 3;
	}
	
	if(s.size() == 6)
	{
		int id3 = 0;
		for(int i = 0; i < 7; i++)
			if(segment[3][i])
				id3 = i;
		
		bool is_zero = true;
		for(char c : s)
		{
			if((int)c - 97 == id3)
				is_zero = false;
		}
		
		if(is_zero)
			return 0;
		
		int id2 = 0;
		for(int i = 0; i < 7; i++)
			if(segment[2][i])
				id2 = i;
		
		for(char c : s)
		{
			if((int)c - 97 == id2)
				return 9;
		}
		
		return 6;
	}
	
	return -1;
}

void solve2() {
	ifstream pf ("input1.txt");
	
	if(pf.is_open())
	{
		long long int sum = 0;
		
		for(int k = 0; k < 200; k++)
		{
			string s;
			
			vector<string> words;
			
			while(getline(pf, s, ' '))
			{
				if(s.size() == 1)
					break;
				
				words.push_back(s);
			}
			
			sort(words.begin(), words.end(), comp);
			
			vector<vector<bool>> segment;
			for(int i = 0; i < 7; i++)
			{
				vector<bool> s (7, false);
				segment.push_back(s);
			}
			
			int c1, c2, c3, c4, c5;
			
			// Use the 1 (2 segments, 2 - 5)
			c1 = (int)words[0][0] - 97;
			c2 = (int)words[0][1] - 97;
			
			segment[2][c1] = true;
			segment[2][c2] = true;
			
			segment[5][c1] = true;
			segment[5][c2] = true;
			
			// Use the 7 (3 segments, 0 - 2 - 5) and get the value of 0
			c1 = (int)words[1][0] - 97;
			c2 = (int)words[1][1] - 97;
			c3 = (int)words[1][2] - 97;
			
			if(!segment[2][c1] && !segment[5][c1])
				segment[0][c1] = true;
			
			if(!segment[2][c2] && !segment[5][c2])
				segment[0][c2] = true;
			
			if(!segment[2][c3] && !segment[5][c3])
				segment[0][c3] = true;
			
			// Use 4 (4 segments, 1 - 2 - 3 - 5) and get two possible values for 1 and 3
			c1 = (int)words[2][0] - 97;
			c2 = (int)words[2][1] - 97;
			c3 = (int)words[2][2] - 97;
			c4 = (int)words[2][3] - 97;
			
			if(!segment[2][c1] && !segment[5][c1])
			{
				segment[1][c1] = true;
				segment[3][c1] = true;
			}
			
			if(!segment[2][c2] && !segment[5][c2])
			{
				segment[1][c2] = true;
				segment[3][c2] = true;
			}
			
			if(!segment[2][c3] && !segment[5][c3])
			{
				segment[1][c3] = true;
				segment[3][c3] = true;
			}
			
			if(!segment[2][c4] && !segment[5][c4])
			{
				segment[1][c4] = true;
				segment[3][c4] = true;
			}
			
			/* Use 2, 3 and 5 (all with 5 segments) to determinate 3 and 6
			 * As we know 0 and know to candidates for 3.
			 * When get 3 we get 1 as well
			 * Then using 5 we get 5 and 2
			 * And finaly using 2 we get 4
			 */
			 
			 vector<bool> w3 (7, false);
			 for(char c : words[3])
				 w3[(int)c - 97] = true;
			 
			 vector<bool> w4 (7, false);
			 for(char c : words[4])
				 w4[(int)c - 97] = true;
			
			vector<bool> w5 (7, false);
			 for(char c : words[5])
				 w5[(int)c - 97] = true;
				 
			// Look for common letters
			for(int i = 0; i < 7; i++)
			{
				if(w3[i] && w4[i] && w5[i])
				{
					// Up
					if(segment[0][i])
					{
						c1 = i;
					}
					// Middle
					else if(segment[3][i])
					{
						c2 = i;
					}
					//Bottom
					else
					{
						c3 = i;
					}
				}
			}
			
			// Bot
			segment[6][c3] = true;
			
			// We know 1 now
			segment[1][c2] = false;
			
			// Middle
			for(int i = 0; i < 7; i++)
				if(i != c2)
					segment[3][i] = false;
			
			// Find 5
			vector<bool> five;
			
			int id1;
			for(int i = 0; i < 7; i++)
				if(segment[1][i])
					id1 = i;
			
			if(w3[id1])
				five = w3;
			
			if(w4[id1])
				five = w4;
			
			if(w5[id1])
				five = w5;
			
			for(int i = 0; i < 7; i++)
				if(segment[5][i] && five[i])
					c5 = i;
			
			//Determine 5
			for(int i = 0; i < 7; i++)
				if(i != c5)
					segment[5][i] = false;
			
			// Determine 2
			segment[2][c5] = false;
			
			for(int j = 0; j < 7; j++)
			{
				bool ctrl = true;
				for(int i = 0; i < 7; i++)
					if(segment[i][j])
						ctrl = false;
				
				if(ctrl)
					id1 = j;
			}
			
			segment[4][id1] = true;
			
			// Get the values after |
			
			int mult = 1000, val = 0;
			for(int i = 0; i < 3; i++)
			{
				getline(pf, s, ' ');
				val += (segment_value(segment, s) * mult);
				mult /= 10;
			}
			getline(pf, s, '\n');
			val += segment_value(segment, s);
			
			sum += val;
		}
		
		cout << sum << endl;
	}
	else{
		cout << "No such file" << endl;
	}
	
	return;
}

void solve1() {
	ifstream pf ("input1.txt");
	
	vector<int> sizes (9, 0);
	
	if(pf.is_open())
	{
		string s;
		
		while(getline(pf, s, '|'))
		{
			for(int i = 0; i < 4; i++)
			{
				getline(pf, s, ' ');
				if(s.size() < 9)
					sizes[s.size()]++;
			}
			getline(pf, s, '\n');
			if(s.size() < 9)
				sizes[s.size()]++;
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	int count = sizes[2] + sizes[3] + sizes[4] + sizes[7];
	
	cout << count << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
