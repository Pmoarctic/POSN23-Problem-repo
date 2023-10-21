#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        mp[temp] = 1;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int sum;
        cin >> sum;
        int check = 0;

        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if (it->first == sum - it->first) {
                break;
            }

            if (mp.find(sum - it->first) != mp.end()) {
                check = 1;
                cout << "YES\n";
                break;
            }
        }

        if (check == 0) {
            cout << "NO\n";
        }
    }

    return 0;
}
