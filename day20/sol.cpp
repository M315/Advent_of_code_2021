#include <bits/stdc++.h>

using namespace std;

int bin_to_int(int b[])
{
	int n = 0, mult = 1;
	for(int k = 8; k >= 0; k--)
	{
		n += (b[k] * mult);
		mult *= 2;
	}
	
	return n;
}

vector<string> simulate(int i, vector<string> img, string algo)
{
	vector<string> new_img;
	
	/* As algo[0] = '#' and algo[512] = '.'
	 * this means that after every odd iteration
	 * all the outside points bright and after the even
	 * interations the outside poins are dark.
	 * 
	 * For outside I reffer to the poits that are initialy
	 * far from the img and so they are dark, and surrounded
	 * by darkness.
	 */
	if(i % 2 == 1)
	{
		string aux (img[0].size(), '#');
		for(int i = 0; i < img.size(); i++)
			new_img.push_back(aux);
	}
	else
	{
		string aux (img[0].size(), '.');
		for(int i = 0; i < img.size(); i++)
			new_img.push_back(aux);
	}
	
	for(int i = 1; i < img.size() - 1; i++)
	{
		for(int j = 1; j < img[0].size() - 1; j++)
		{
			// Get the binary index
			int bin[9] = {0,0,0,0,0,0,0,0,0};
			for(int x = 0; x <= 2; x++)
			{
				for(int y = 0; y <= 2; y++)
				{
					if(img[i - 1 + x][j - 1 + y] == '.')
					{
						bin[(3 * x) + y] = 0;
					}
					else
					{
						bin[(3 * x) + y] = 1;
					}
				}
			}
			
			int n = bin_to_int(bin);
			
			new_img[i][j] = algo[n];
		}
	}
	
	return new_img;
}

void solve(int n) 
{
	ifstream pf ("input1.txt");
	
	string algo;
	vector<string> img;
	
	// Read
	if(pf.is_open())
	{
		// Read algo
		getline(pf, algo);
		
		// Get img
		string word;
		getline(pf, word); // separation line
		// Add '.' at the start and end to make the image wider
		while(getline(pf, word)){ img.push_back("............................................................" + word + "............................................................"); }
		
		// Add lines at the start and end to make the img bigger
		for(int i = 0; i < 60; i++)
		{
			string start (img[0].size(), '.');
			string end (img[0].size(), '.');
			
			img.emplace(img.begin(), start);
			img.push_back(end);
		}
	}
	else{
		cout << "No such file" << endl;
	}
	
	for(int i = 1; i <= n; i++)
		img = simulate(i, img, algo);

	int count = 0;
	for(auto r : img)
		for(char c : r)
			if(c == '#')
				count++;
	
	cout << count << endl;
	
	return;
}

int main() {
	//solve(2);
	solve(50);

	return 0;
}
