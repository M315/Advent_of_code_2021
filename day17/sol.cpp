/*
 * The x velocity goes down and eventuali stops,
 * so for the first part would be wise to look for the first x that
 * falls vertically.
 * The x velocity stops after x steps, where x is the initial velocity.
 * So x_max	= x * x - sum k from 1 to x - 1
 * 			= x * x - triangluar(x - 1)
 * 			= triangular(x)
 * 
 * Now to compute y after n steps assuming we start at 0
 * y = n * y0' - triangular(n - 1)
 * 
 * Given y0', the highest point will be were n = y0'
 * So the highest poit will be: triangular(y0')
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int X1 = 156;
int X2 = 202;
int Y1 = -69;
int Y2 = -110;

// Generate the first n triangluar numbers
vector<long long> triangular(long long n)
{
	vector<long long> tri;
	
	long long val = 0;
	for(long long i = 0; i <= n; i++)
	{
		val += i;
		tri.push_back(val);
	}
	
	return tri;
}

int will_reach(int vx, int vy)
{
	int x = 0, y = 0;
	
	while(x <= X2 && y >= Y2)
	{
		
		if(x >= X1 && x <= X2 && y <= Y1 && y >= Y2)
			return 1;
		
		x += vx;
		vx = max(0, vx - 1);
		
		y += vy;
		vy--;
	}
	
	return 0;
}

void solve2() 
{
	vector<long long> tri = triangular(10000);
	
	// We know that the largest y will be 109 and the smallest -110
	// The smallest x will be 18 and the lergest 202
	
	// As there are not many options lets brute force it
	int sum = 0;
	for(int x = 18; x <= 202; x++)
		for(int y = -110; y <= 109; y++)
			sum += will_reach(x, y);
	
	cout << sum << endl;
	
	return;
}

void solve1() 
{
	vector<long long> tri = triangular(10000);
	
	// Find the x to fall veticaly
	int x = 1;
	while(true)
	{
		if(tri[x] >= X1 && tri[x] <= X2)
			break;
		
		if(tri[x] > X2)
		{
			cout << "There's no vertical x" << endl;
			break;
		}
		
		x++;
	}
	
	// Find the y
	long long y = 110;
	while(true)
	{
		// There hav to pass at least x steps
		int n = x;
		while(n < tri.size() && y * n - tri[n - 1] > Y2)
			n++;
		
		if(y * n - tri[n - 1] <= Y1 && y * n - tri[n - 1] >= Y2)
			break;
		
		y--;
	}
	
	// Max height
	cout << tri[y] << endl;
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
