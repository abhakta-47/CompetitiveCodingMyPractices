//robots collison
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define loop(i, n) for (int i = 0; i < n; i++)

class Robot
{
public:
    int pos, index;
    char direction;
    Robot(int p, int i, char d) : pos(p), index(i), direction(d) {}
    bool operator<(const Robot &r2) const
    {
        return (this->pos < r2.pos);
    }
};

void sol()
{
    int n, m;
    cin >> n >> m;
    int x[n], i, ans[n];
    char d[n];
    memset(ans, -1, sizeof(ans));
    set<Robot> robots;
    for (i = 0; i < n; i++)
        cin >> x[i];
    for (i = 0; i < n; i++)
        cin >> d[i];
    for (i = 0; i < n; i++)
        robots.insert(Robot(x[i], i, d[i]));

    set<Robot>::iterator leftRobot, rightRobot, toDelete;
    leftRobot = robots.begin();
    rightRobot = (++robots.begin());
    int leftPos, leftIndex, rightPos, rightIndex, t;
    char leftDirection, rightDirection;
    while (rightRobot != robots.end())
    {
        leftPos = leftRobot->pos;
        leftIndex = leftRobot->index;
        leftDirection = leftRobot->direction;

        rightPos = rightRobot->pos;
        rightIndex = rightRobot->index;
        rightDirection = rightRobot->direction;

        clog << "L: " << leftPos << " " << leftIndex << " " << leftDirection << "\n"
             << "R: " << rightPos << " " << rightIndex << " " << leftDirection << "\n";

        if (leftDirection == 'R' && rightDirection == 'L')
        {
            t = (rightPos - leftPos) / 2;
            ans[rightIndex] = t;
            ans[leftIndex] = t;

            toDelete = rightRobot;
            rightRobot++;
            robots.erase(toDelete);
            toDelete = leftRobot;
            leftRobot--;
            robots.erase(toDelete);
            clog << t << "\n";
        }
        else
        {
            leftRobot++;
            rightRobot++;
            clog << "-1\n";
        }
    }

    for (auto ans_i : ans)
        cout << ans_i << " ";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    int temp = t;
    while (t--)
    {
        clog << "Case #" << temp - t << "\n";
        sol();
        cout << "\n";
        clog << "\n";
    }
}
