#include <iostream>
#include <string>
using namespace std;

int max(int a , int b)
{
	return (a > b) ? a : b;
}

void printLCS(string s1, string s2)
{
	int m = s1.length();
	int n = s2.length();
	int t[m + 1][n + 1], i, j;
	for (i = 0 ; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	int l = t[m][n];
	char lcs[l + 1];
	lcs[l] = '\0';
	for (i = 0 ; i <= m; i++)
	{
		for (j = 0 ; j <= n ; j++)
			cout << " " << t[i][j];
		cout << endl;
	}

	i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			lcs[l - 1] = s1[i - 1];
			i--;
			j--;
			l--;
		}
		else if (t[i - 1][j] > t[i][j - 1])
			i--;
		else
			j--;
	}
	cout << "\n LCS: " << lcs;
}

int main()
{
	string s1, s2;
	cout << " Enter 1st String: ";
	cin >> s1;
	cout << " Enter 2nd String: ";
	cin >> s2;
	printLCS(s1, s2);
	return 0;
}
