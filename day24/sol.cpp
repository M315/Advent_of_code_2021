/*
 * The input is assembly like, and after it gets each digit perform a similar operation.
 * So the idea is to rewrite the funcition to cpp, in this case.
 * Then relize that the only variable that changes in all cases is z.
 * And that there is a comparison between the digit and x.
 * Also in some steps z is reduced.
 * 
 * So the idea is to pick the digits that makes z not grow too much in order to reach 0 at the end.
 * Simulate the code with some digits and pick those that make z smaller.
 */

#include <bits/stdc++.h>

using namespace std;

void solve2() 
{	
	int w[14] = { 2, 1, 1, 9, 1, 8, 6, 0, 0, 6, 0, 0, 4, 1};
	int a[14] = {10,12,13,13,14,-2,11,-15,-10,10,-10,-4,-1,-1};
	int b[14] = { 0, 6, 4, 2, 9, 1,10, 6, 4, 6, 3, 9,15, 5};
	int d[14] = { 1, 1, 1, 1, 1,26, 1,26,26, 1,26,26,26,26};
	int x = 0;
	long long int z = 0, m = INT_MAX;
	
	for(w[7] = 1; w[7] < 10; w[7]++)
	{
		for(w[8] = 1; w[8] < 10; w[8]++)
		{
			for(w[9] = 1; w[9] < 10; w[9]++)
			{
				for(w[10] = 1; w[10] < 10; w[10]++)
				{
					for(w[11] = 1; w[11] < 10; w[11]++)
					{
						for(w[12] = 1; w[12] < 10; w[12]++)
						{
							for(w[13] = 1; w[13] < 10; w[13]++)
							{	
								z = 0;
								for(int k = 0; k < 14; k++)
								{
									x = (z % 26) + a[k];
									z = z / d[k];
									
									if(x != w[k])
									{
										z = z * 26;
										z = z + w[k] + b[k];
									}
								}
								if(z < m)
								{
									m = z;
									//cout << w[1] << w[2] << w[7] << w[8] << w[10] << w[11] << w[12] << w[13] << " - " << z << endl;
									for(int n : w)
										cout << n;
									cout << " - " << z << endl;
									if(z == 0)
										return;
								}
							}
						}
					}
				}
			}
		}
	}
	
	return;
}

void solve1() 
{
	int w[14] = { 9, 4, 9, 9, 2, 9, 9, 4, 1, 9, 5, 9, 9, 9};
	int a[14] = {10,12,13,13,14,-2,11,-15,-10,10,-10,-4,-1,-1};
	int b[14] = { 0, 6, 4, 2, 9, 1,10, 6, 4, 6, 3, 9,15, 5};
	int d[14] = { 1, 1, 1, 1, 1,26, 1,26,26, 1,26,26,26,26};
	int x = 0;
	long long int z = 0, m = INT_MAX;
	
	for(w[1] = 9; w[1] > 0; w[1]--)
	{
		for(w[2] = 9; w[2] > 0; w[2]--)
		{
			for(w[3] = 9; w[3] > 0; w[3]--)
			{
				for(w[11] = 9; w[11] > 0; w[11]--)
				{
					for(w[12] = 9; w[12] > 0; w[12]--)
					{
						for(w[13] = 9; w[13] > 0; w[13]--)
						{
							z = 0;
							for(int k = 0; k < 14; k++)
							{
								x = (z % 26) + a[k];
								z = z / d[k];
								
								if(x != w[k])
								{
									z = z * 26;
									z = z + w[k] + b[k];
								}
							}
							if(z < m)
							{
								m = z;
								cout << w[1] << w[2] << w[3] << w[11] << w[12] << w[13] << " - " << z << endl;
								if(z == 0)
									for(int n : w)
										cout << n;
								cout << endl;
							}
						}
					}
				}
			}
		}
	}
	
	return;
}

int main() {
	//solve1();
	solve2();

	return 0;
}
