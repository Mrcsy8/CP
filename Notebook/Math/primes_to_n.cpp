vector<bool> prime;
void primes_to_n(ll n){
    prime.resize(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}