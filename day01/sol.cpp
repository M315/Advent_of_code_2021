#include <bits/stdc++.h>

using namespace std;

void solve2() {
	ifstream pf ("input1.txt");
	
	int count = 0;
	if(pf.is_open())
	{
		int a, b, c, d;
		
		pf >> a;
		pf >> b;
		pf >> c;
		
		while(pf.good())
		{
			pf >> d;
			if(d > a){ count++; }
			
			a = b;
			b = c;
			c = d;
		}
		
		//Subtrack one to the count cause the last emptyline is counted and makes an extra count.
		if(d > a){ count--; }
	}
	else{
		cout << "No such file" << endl;
	}
	
	cout << count << endl;

	return;
}

void solve1() {
	ifstream pf ("input1.txt");
	
	int count = 0;
	if(pf.is_open())
	{
		int curr, last;
		
		pf >> last;
		
		while(pf)
		{
			pf >> curr;
			if(curr > last){ count++; }
			
			last = curr;
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	cout << count << endl;

	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
