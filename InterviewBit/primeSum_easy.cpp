// 
// 
// Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
// 
// NOTE A solution will always exist. read Goldbach’s conjecture
// 
// Example:
// 
// 
// Input : 4
// Output: 2 + 2 = 4
// 
// If there are more than one solutions possible, return the lexicographically smaller solution.
// 
// If [a, b] is one solution with a <= b,
// and [c,d] is another solution with c <= d, then
// 
// [a, b] < [c, d] 
// 
// If a < c OR a==c AND b < d. 
// 

int mx = 1000001;
vector<int> GetPrimes(int N){
    vector<bool> primes(N, true);
    vector<int> prime;
    for (int i = 3; i <= N; i+=2){
        if (!primes[i]) continue;
        for (int  j = 3*i; j <= N; j+=2*i){
            primes[j]= false;
        }
    }
    prime.reserve(N/3);
    prime.push_back(2);
    for (int i =3; i <=N; i+=2) if (primes[i]) prime.push_back(i);
    return prime;
}

bool checkPrime(const vector<int> &prime, int N){
    if (binary_search(prime.begin(), prime.end(), N)) return true;
    for (int i = 0; prime[i] <= N/ prime[i]; ++i){
        if(N%prime[i]==0) return false;
    }
    return true;
}
vector<int> Solution::primesum(int A) {
    vector<int> primes = GetPrimes(min(mx, A));
    for (auto var : primes){
        if (checkPrime(primes, A - var)){
            return vector<int> { var, A - var};
        }
    }
}
