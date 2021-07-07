#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define ll long long
#define pb push_back

struct Packet
{
	int id, arrival_t, processing_t;
	Packet(int x, int y, int z) : id(x), arrival_t(y), processing_t(z) {}
};

struct Process
{
	Packet under_prcess_packet;
	int start_time, end_time;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int buffer_limit, n_packets;
	queue<Packet> buffer;
	// Process cur_process;
	int start_t = 0, end_t = 0;
	cin >> buffer_limit >> n_packets;
	int arrival_t, processing_t, cpu_time = 0, ans[n_packets];

	cin >> arrival_t >> processing_t;
	buffer.push(Packet(0, arrival_t, processing_t));
	// start_t = arrival_t;
	// ans[0] = start_t;
	// end_t = start_t + processing_t;
	for (int i = 1; i < n_packets; i++)
	{
		cin >> arrival_t >> processing_t;
		cout << arrival_t << " " << processing_t << "\t";
		if (end_t <= arrival_t)
		{
			buffer.push(Packet(i, arrival_t, processing_t));
			// process
			while (!buffer.empty())
			{
				Packet tmp = buffer.front();
				start_t = (end_t < tmp.arrival_t ? tmp.arrival_t : end_t);
				cout << tmp.id << ", ";
				ans[tmp.id] = start_t;
				end_t = start_t + tmp.processing_t;
				if (end_t >= arrival_t)
					break;
				buffer.pop();
			}
		}
		else
		{
			cout << "*";
			// try to push to buffer
			if (buffer.size() < buffer_limit)
				buffer.push(Packet(i, arrival_t, processing_t));
			else
				ans[i] = -1;
		}
		cout << "\n";
	}

	for (auto i_ans : ans)
		cout << i_ans << "\n";
}
