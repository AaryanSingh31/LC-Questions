#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    // Left half -> Max Heap
    // Top() = Largest element of the left half
    priority_queue<int> maxHeap;

    // Right half -> Min Heap
    // Top() = Smallest element of the right half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int num) {

        // ---------------- STEP 1 : INSERTION ----------------
        // If maxHeap is empty OR new number belongs to the left half,
        // insert it into maxHeap.
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        // Otherwise, insert it into the right half.
        else {
            minHeap.push(num);
        }

        // ---------------- STEP 2 : SIZE BALANCING ----------------
        // We always maintain:
        //
        // 1. maxHeap.size() == minHeap.size()
        //                OR
        // 2. maxHeap.size() == minHeap.size() + 1
        //
        // i.e. Left half is either equal in size to the right half
        // or has exactly one extra element.

        // If left half becomes too large,
        // move its boundary element (largest element)
        // to the right half.
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // If right half becomes larger than left half,
        // move its boundary element (smallest element)
        // to the left half.
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        // ---------------- MEDIAN ----------------
        // Even number of elements:
        // Median = Average of both boundary elements.
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // Odd number of elements:
        // Left half always contains one extra element,
        // therefore its top is the median.
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 *
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double median = obj->findMedian();
 */