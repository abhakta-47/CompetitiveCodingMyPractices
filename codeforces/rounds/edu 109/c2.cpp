#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

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

int n, m;
set<Robot> robots[2]; //, robots_left[2], robots_right[2];
vector<int> ans;

void sol2(int pairity)
{

    if (robots[pairity].size() <= 1)
        return;

    set<Robot>::iterator leftRobot, rightRobot, toDelete;

    leftRobot = robots[pairity].begin();
    rightRobot = (++robots[pairity].begin());

    int leftPos, leftIndex, rightPos, rightIndex, t;
    char leftDirection, rightDirection;

    cerr << "opp dir\n";
    while (rightRobot != robots[pairity].end())
    {
        leftPos = leftRobot->pos;
        leftIndex = leftRobot->index;
        leftDirection = leftRobot->direction;

        rightPos = rightRobot->pos;
        rightIndex = rightRobot->index;
        rightDirection = rightRobot->direction;

        cerr << "L: " << leftPos << " " << leftIndex << " " << leftDirection << "\n"
             << "R: " << rightPos << " " << rightIndex << " " << leftDirection << "\n";

        if (leftDirection == 'R' && rightDirection == 'L')
        {
            t = (rightPos - leftPos) / 2;
            ans[rightIndex] = t;
            ans[leftIndex] = t;

            toDelete = rightRobot;
            rightRobot++;
            robots[pairity].erase(toDelete);
            toDelete = leftRobot;
            leftRobot--;
            robots[pairity].erase(toDelete);
            cerr << t << "\n";
        }
        else
        {
            leftRobot++;
            rightRobot++;
            cerr << "-1\n";
        }
        break;
    }

    cerr << "same dir\n";
    for (auto robot = robots[pairity].begin(); robot != robots[pairity].end(); robot++)
    {
        leftPos = robot->pos;
        leftIndex = robot->index;
        leftDirection = robot->direction;

        ++robot;
        if (robot == robots[pairity].end())
            break;
        rightPos = robot->pos;
        rightIndex = robot->index;
        rightDirection = robot->direction;

        cerr << "L: " << leftPos << " " << leftIndex << " " << leftDirection << "\n"
             << "R: " << rightPos << " " << rightIndex << " " << rightDirection << "\n";

        if (rightDirection == 'L')
            t = (rightPos + leftPos) / 2;
        else
            t = (2 * m - rightPos - leftPos) / 2;
        ans[rightIndex] = t;
        ans[leftIndex] = t;

        // toDelete = rightRobot;
        // rightRobot++;
        // robots[pairity].erase(toDelete);
        // toDelete = leftRobot;
        // leftRobot--;
        // robots[pairity].erase(toDelete);
        cerr << t << "\n";
    }
}

void sol()
{
    cin >> n >> m;

    // todo clear global variables
    robots[0].clear();
    robots[1].clear();
    ans.clear();
    ans.resize(n, -1);
    // robots_left[0].clear();
    // robots_right.clear();
    //ans.

    int pos[n], i;
    char directions[n];
    for (i = 0; i < n; i++)
        cin >> pos[i];
    for (i = 0; i < n; i++)
        cin >> directions[i];

    for (i = 0; i < n; i++)
    {
        // cerr << pos[i] << " " << i << " " << directions[i] << "\n";
        robots[pos[i] % 2].insert(Robot(pos[i], i, directions[i]));
        // if (directions[i] == 'L')
        //     robots_left[pos[i] % 2].insert(Robot(pos[i], i, directions[i]));
        // else
        //     robots_right[pos[i] % 2].insert(Robot(pos[i], i, directions[i]));
    }

    // for (auto robot : robots[0])
    // {
    //     cerr << robot.pos << " " << robot.index << " " << robot.direction << "\n";
    // }

    sol2(0);
    sol2(1);

    for (auto ans_itr : ans)
        cout << ans_itr << " ";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    //t=1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cerr << "Case #" << i << ":\n";
        sol();
        cout << "\n";
        cerr << "\n";
    }
}
