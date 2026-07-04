# Decoupled Max-Heap & HeapSort in C

A clean, robust, and industry-standard implementation of a dynamic **Max-Heap** and an in-place **HeapSort** algorithm in C. 

The core filtering algorithms (`AdjustUp` and `AdjustDown`) are fully decoupled from the structural type definition. This architectural design allows the HeapSort algorithm to sort raw arrays natively without any structural wrappers, while still allowing the standard Heap APIs to perfectly reuse the underlying logic.

---

## 🚀 Features

*   **Memory Efficiency:** Built on top of a dynamic array (`realloc`) with automated scaling and strict memory safety management.
*   **Decoupled Architecture:** `HeapAdjustUp` and `HeapAdjustDown` operate directly on raw array pointers (`HPDatatype*`), optimizing code reuse and system flexibility.
*   **Dual HeapSort Analysis:** Includes two distinct heap-building methodologies for educational and performance comparison:
    1.  **Down-Adjust Building ($O(N)$):** Standard industrial approach with optimal constant-factor performance.
    2.  **Up-Adjust Building ($O(N \log N)$):** Incremental simulation approach.
*   **Defensive Programming:** Robust `assert` boundaries on all pointers and array indices to prevent runtime overflow and undefined behaviors.

---

## 🗺️ Code Structure & API Reference

### 1. Memory & Data Lifecycle
*   `void HeapInit(Heap* php)`: Initializes an empty heap.
*   `void HeapDestroy(Heap* php)`: Frees all allocated memory and resets structural properties to prevent wild pointers.

### 2. Core Heap Operations
*   `void HeapPush(Heap* php, HPDatatype x)`: Inserts a new element into the heap ($O(\log N)$).
*   `void HeapPop(Heap* php)`: Removes the maximum element (heap top) from the heap ($O(\log N)$).
*   `HPDatatype HeapTop(Heap* php)`: Retrieves the maximum element with an $O(1)$ safety check.

### 3. Core Filtering Algorithms (Decoupled)
*   `void HeapAdjustUp(HPDatatype* arr, int child)`: Sifts an element up to maintain the Max-Heap property.
*   `void HeapAdjustDown(HPDatatype* arr, int parent, int size)`: Sifts an element down within a strictly bounded scope.

### 4. Advanced Sorting
*   `void HeapSort1(HPDatatype* arr, int n)`: Sorts a raw array in ascending order using $O(N)$ Down-Adjust heap building. **(Recommended)**
*   `void HeapSort2(HPDatatype* arr, int n)`: Sorts a raw array in ascending order using $O(N \log N)$ Up-Adjust heap building.

---

## 📊 Algorithmic Performance

| Phase / Algorithm | Time Complexity | Space Complexity | Stability |
| :--- | :--- | :--- | :--- |
| **Heap Building (Down)** | $O(N)$ | $O(1)$ | Unstable |
| **Heap Building (Up)** | $O(N \log N)$ | $O(1)$ | Unstable |
| **Overall HeapSort** | $O(N \log N)$ | $O(1)$ | Unstable |

---

## 🛠️ Future Roadmap
- [x] Dynamic Array-based Max-Heap Implementation
- [x] Fully Decoupled Adjust-Down / Adjust-Up Modules
- [x] Highly Optimized In-place HeapSort ($O(N \log N)$)
- [x] Top-K Streaming Selection Engine ($O(N \log K)$ Time, $O(K)$ Space)
- [ ] Link-based Binary Tree & Recursive Traversals
