#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long x0, n;
		cin >> x0 >> n;
		// a pattern can be seen once you try to brute-force the solutions (view the image this repository)
		// the original number, x0, repeats every after 4 numbers in the sequence
		// we know that mod 4 contains the set of numbers that are STRICTLY less than 4
		// [0, 4) or {0, 1, 2, 3}
		
		// for every number in the set it will produce the following result:
		
		// if n mod 4 is equal to 0:
		// the answer is always the original number, x0
		
		// if n mod 4 is equal to 1:
		// there are two possible cases depending on its parity
		// if x0 is even:
		// the answer is always x0 - n
		// if x0 is odd:
		// the answer is always x0 + n
		
		// if n mod 4 is equal to 2:
		// the are two possible cases depending on its parity
		// if x0 is even:
		// the answer is always x0 + 1
		// if x0 is odd:
		// the answer is always x0 - 1
		
		// if n mod 4 is equal to 3:
		// as can be observed in the pattern, the value that we 
		// need to add to x0 is a multiple of 4
		
		// for example:
		// let x0 = 10, n = 3
		// the answer is 14 because:
		// = ceil(3 / 4)
		// = 1
		// and 4(1) = 4
		// therefore, 10 + 4 = 14
		
		// another example:
		// let x0 = 10, n = 7
		// the answer is 18 because:
		// = ceil(7 / 4)
		// = 2
		// and 4(2) = 8
		// therefore, 10 + 8 = 18
		
		// let m = the number that we computed above
		// there are two possible cases depending on its parity
		// if x0 is even:
		// the answer is always x0 + m
		// if x0 is odd:
		// the answer is always x0 - m
		
		long long ans = 0;
		if (n % 4 == 0) {
			ans = x0;
		} else if (n % 4 == 1) {
			ans = (x0 % 2 == 0 ? x0 - n : x0 + n);
		} else if (n % 4 == 2) {
			ans = (x0 % 2 == 0 ? x0 + 1 : x0 - 1);
		} else {
			long long m = ((n + 3) / 4) * 4;
			ans = (x0 % 2 == 0 ? x0 + m : x0 - m);
		}
		cout << ans << '\n';
	}
	return 0;
}
