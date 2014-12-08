#include <iostream>
#include <string.h>
using namespace std;

int LargestPal(string s, int n)
{
	if (n == 0)
		return 0;
	int max = 1, start = 0, low, high;
	for (int i = 0; i < n; i++)
	{
		low = i - 1;
		high = i;
		while ( low >= 0 && high < n && s[low] == s[high])
		{
			if (high - low + 1 > max)
			{
				max = high - low + 1;
				start = low;
			}
			--low, high++;
		}
		low = i - 1;
		high = i + 1;
		while ( low >= 0 && high < n && s[low] == s[high])
		{
			if (high - low + 1 > max)
			{
				max = high - low + 1;
				start = low;
			}
			--low, high++;

		}
	}
	cout << "\n\t Longest Palindrome: ";

	for (int i = start; i < start + max; i++)
	{
		cout << s[i];
	}
	return max;
}

int main()
{
	string s;
	cout << "\n\t Enter the String: ";
	cin >> s;
	cout << "\n\t Length = " << LargestPal(s, s.size()) << "\n\n";
	return 0;
}
