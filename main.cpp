#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>,
                   decltype([](const int a, const int b) { return a > b; })>
        pq;
    pq.push(5);
    pq.push(1);
    pq.push(3);
    cout << pq.top() << endl;
    return 0;
}