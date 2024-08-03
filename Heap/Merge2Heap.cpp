#include <iostream>
#include <queue>

using namespace std;

// Function to merge two max heaps by inserting elements from heap2 into heap1
void mergeHeaps(priority_queue<int>& heap1, priority_queue<int> heap2) {
    // Insert elements from heap2 into heap1
    while (!heap2.empty()) {
        heap1.push(heap2.top());
        heap2.pop();
    }
}

int main() {
    // Create two max heaps
    priority_queue<int> heap1;
    priority_queue<int> heap2;

    // Populate heaps with some values
    heap1.push(10);
    heap1.push(5);
    heap1.push(3);

    heap2.push(8);
    heap2.push(7);
    heap2.push(6);

    // Merge the heaps
    mergeHeaps(heap1, heap2);

    // Print the merged heap
    cout << "Merged Max Heap: ";
    while (!heap1.empty()) {
        cout << heap1.top() << " ";
        heap1.pop();
    }
    cout << endl;

    return 0;
}



//second solution 

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm> // For make_heap

// using namespace std;

// // Function to extract all elements from a priority_queue
// vector<int> extractAllElements(priority_queue<int> heap) {
//     vector<int> elements;
//     while (!heap.empty()) {
//         elements.push_back(heap.top());
//         heap.pop();
//     }
//     return elements;
// }

// // Function to build a max heap from a vector of elements
// void buildMaxHeap(vector<int>& elements) {
//     make_heap(elements.begin(), elements.end());
// }

// // Function to merge two max heaps
// priority_queue<int> mergeHeaps(priority_queue<int> heap1, priority_queue<int> heap2) {
//     vector<int> allElements;

//     // Extract elements from both heaps
//     vector<int> elements1 = extractAllElements(heap1);
//     vector<int> elements2 = extractAllElements(heap2);

//     // Combine elements
//     allElements.insert(allElements.end(), elements1.begin(), elements1.end());
//     allElements.insert(allElements.end(), elements2.begin(), elements2.end());

//     // Build a new max heap
//     buildMaxHeap(allElements);

//     // Convert vector to priority_queue
//     priority_queue<int> mergedHeap;
//     for (int elem : allElements) {
//         mergedHeap.push(elem);
//     }

//     return mergedHeap;
// }

// int main() {
//     // Create two max heaps
//     priority_queue<int> heap1;
//     priority_queue<int> heap2;

//     // Populate heaps with some values
//     heap1.push(10);
//     heap1.push(5);
//     heap1.push(3);

//     heap2.push(8);
//     heap2.push(7);
//     heap2.push(6);

//     // Merge the heaps
//     priority_queue<int> mergedHeap = mergeHeaps(heap1, heap2);

//     // Print the merged heap
//     cout << "Merged Max Heap: ";
//     while (!mergedHeap.empty()) {
//         cout << mergedHeap.top() << " ";
//         mergedHeap.pop();
//     }
//     cout << endl;

//     return 0;
// }
