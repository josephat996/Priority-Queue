
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) break;

            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty.");
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() const {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty.");
        }
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;

    // Insert elements
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);

    // Display the top element
    cout << "Top element: " << pq.top() << endl;

    // Remove elements and display the top each time
    while (!pq.empty()) {
        cout << "Removing: " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
