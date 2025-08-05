#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    int * arr;
    int size, total;

    public:
    MaxHeap(int n) {
        arr = new int[n];
        size = 0, total = n;
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && arr[left] > arr[largest]) largest = left;
        if(right < size && arr[right] > arr[largest]) largest = right;

        if(largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void insert(int num) {
        if(size == total) {
            cout << "Heap OverFlow\n";
            return;
        }
        cout << num << " is inserted into heap\n";

        arr[size] = num;
        int index = size;
        size ++;

        while(index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
    }

    void pop() {
        if(size == 0) {
            cout << "Heap UnderFlow\n";
            return;
        }
        cout << arr[0] << " is deleted from heap\n";

        arr[0] = arr[size - 1];
        size --;

        if(size == 0) return;
        heapify(0);

    }
    void top() {
        if(size == 0) {
            cout << "Heap is Empty!\n";
            return;
        }
        cout << arr[0] << " is the largest element int the Heap";
        return;
    }
};

int main() {
    int n;
    cin >> n;
    MaxHeap H(n);

    while(1) {
        string operation;
        cin >> operation;

        if(operation == "insert") {
            int val;
            cin >> val;
            H.insert(val);
        }
        else if(operation == "pop") {
            H.pop();
        }
        else if(operation == "top") {
            H.top();
        }
        else {
            cout << "Program Terminated!";
            break;
        }
    }
}
