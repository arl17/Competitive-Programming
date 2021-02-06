/*given an array of integers we have to find the 
pair of elements whose product is a perfect square*/

source--> "https://www.geeksforgeeks.org/count-of-pairs-in-an-array-whose-product-is-a-perfect-square/"

int prime[100001] = { 0 }; 
 
int k[100001] = { 0 }; 
 
void Sieve() 
{ 
	// Initialize k[i] to i 
	for (ll i = 1; i < 100001; i++) 
		k[i] = i; 

	// Prime Sieve 
	for (ll i = 2; i < 100001; i++) { 

		// If i is prime then remove all 
		// factors of prime from it 
		if (prime[i] == 0) 
			for (ll j = i; j < 100001; j += i) { 

				// Update that j is not 
				// prime 
				prime[j] = 1; 

				// Remove all square divisors 
				// i.e. if k[j] is divisible 
				// by i*i then divide it by i*i 
				while (k[j] % (i * i) == 0) 
					k[j] /= (i * i); 
			} 
	} 
} 

// Function that return total count 
// of pairs with pefect square product 
ll countPairs(int arr[], int n) 
{ 
	// Map used to store the frequency of k 
	unordered_map<int, int> freq; 

	// Store the frequency of k 
	for (ll i = 0; i < n; i++) { 
		freq[k[arr[i]]]++; 
	} 

	int sum = 0; 

	// The total number of pairs is the 
	// summation of (fi * (fi - 1))/2 
	for (auto i : freq) { 
		sum += ((i.second - 1) * i.second) / 2; 
	} 

	return sum; 
} 
