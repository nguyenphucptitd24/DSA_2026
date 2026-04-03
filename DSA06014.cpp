#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000005;
bool is_prime[MAX];

void sieve() {
    fill(is_prime, is_prime + MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool found = false;

        for (int i = 2; i <= n / 2; i++) {
            if (is_prime[i] && is_prime[n - i]) {
                cout << i << " " << n - i << endl;
                found = true;
                break; 
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}