#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, x, n) for (int i = x; i < n; i++)

// U = Uncolored
// R = Red
// Y = Yellow
// B = Blue
// O = Orange
// P = Purple
// G = Green
// A = Gray

// Red + Yellow = Orange
// Red + Blue = Purple
// Yellow + Blue = Green
// Red + Yellow + Blue = Gray

void sol() {
    ll n;
    cin >> n;
    string painting;
    cin >> painting;
    bool strokes[n][3];
    for (int i = 0; i < n; i++) {
        strokes[i][0] = 0;
        strokes[i][2] = 0;
        strokes[i][1] = 0;
        // cout << painting[i];
        switch (painting[i]) {
        case 'R':
            strokes[i][0] = true;
            break;
        case 'Y':
            strokes[i][1] = true;
            break;
        case 'B':
            strokes[i][2] = true;
            break;
        case 'O':
            strokes[i][0] = true;
            strokes[i][1] = true;
            break;
        case 'P':
            strokes[i][0] = true;
            strokes[i][2] = true;
            break;
        case 'G':
            strokes[i][1] = true;
            strokes[i][2] = true;
            break;
        case 'A':
            strokes[i][0] = true;
            strokes[i][1] = true;
            strokes[i][2] = true;
            break;
        default:
            break;
        }
    }
    int ans = 0;
    for (int c = 0; c < 3; c++) {
        // cout << "\n" << c << ": ";
        for (int i = 0; i < n - 1; i++) {
            if (strokes[i][c] != strokes[i + 1][c] && strokes[i][c]) {
                // cout << i << ",";
                ++ans;
            }
        }

        if (strokes[n - 1][c]) {
            // cout << n - 2 << ", ";
            ++ans;
        }
    }
    cout << ans;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        sol();
        // clog<<"\n";
        cout << "\n";
    }
}
