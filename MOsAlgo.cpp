#include<bits/stdc++.h>
using namespace std;

#define ll long long

class SqrtDecomposition {
    vector<ll> data, blockValue;
    ll n, blockSize, blockCount;

public:
    // Build in O(n)
    SqrtDecomposition(const vector<ll>& v) {
        data = v;
        n = data.size();
        blockSize = sqrt(n);
        blockCount = (n + blockSize - 1) / blockSize;

        blockValue.assign(blockCount, 0LL);
        for(int i = 0; i < n; i++) {
            blockValue[i / blockSize] += data[i];
        }
    }

    // Point update: data[index] = value
    void update(int index, ll value) {
        int block = index / blockSize;
        blockValue[block] += value - data[index];
        data[index] = value;
    }

    // Range sum query from l to r (inclusive)
    ll query(int l, int r) {
        ll sum = 0;
        ll startBlock = l / blockSize;
        ll endBlock = r / blockSize;

        if (startBlock == endBlock) {
            for (int i = l; i <= r; i++) {
                sum += data[i];
            }
        } else {
            for (int i = l; i < (startBlock + 1) * blockSize; i++) {
                sum += data[i];
            }
            for (int b = startBlock + 1; b < endBlock; b++) {
                sum += blockValue[b];
            }
            for (int i = endBlock * blockSize; i <= r; i++) {
                sum += data[i];
            }
        }
        return sum;
    }
};


int main() {

}
