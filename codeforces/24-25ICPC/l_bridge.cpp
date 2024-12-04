#include <bits/stdc++.h>
using namespace std;

// A Dequeue (Double ended queue) based method for printing 
// maximum element of all subarrays of size k
void printKMax(int n, int a[], int k) {
  
    deque<int> q(k);

    int i;
    for (i = 0; i < k; ++i) {
      
        while (!q.empty() && a[i] >= a[q.back()]) {
          
            q.pop_back();
        }
        q.push_back(i);
    }

    for (; i < n; ++i) {
      
        cout << a[q.front()] << " ";

        while (!q.empty() && q.front() <= i - k) {
          
            q.pop_front();
        }

        while (!q.empty() && a[i] >= a[q.back()]) {
            q.pop_back();
        }

        q.push_back(i);
    }

    cout << a[q.front()];
}

// Driver's code
int main() {
    vector<int> a = {12, 1, 78, 90, 57, 89, 56};
    int k = 3;

    // Function call
    printKMax(a, k);
    return 0;
}