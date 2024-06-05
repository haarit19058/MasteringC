# Basics of Time Complexity and Space Complexity

# Notes
- How to include the stl library
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
return 0;
}
```
- the stl library contains all the necessary header files like vectors, strings etc.

# Sorting

## O(n$^2$) Algorithms

### 1. Bubble Sort (In-Place)
```cpp
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
```

### 2. Insertion Sort (In-Place)
```cpp
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
```

### 3. Selection Sort (In-Place)
```cpp
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
```

### 4. Merge Sort (Not In-Place)
```cpp
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
```

### 5. Quick Sort (In-Place)
```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
```

### 6. Binary Search
```cpp
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = binarySearch(arr, 0, arr.size() - 1, x);
    if (result != -1)
        cout << "Element is present at index " << result;
    else
        cout << "Element is not present in array";
    return 0;
}
```

### 7. Finding kth Minimum Element (QuickSelect)
```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(vector<int>& arr, int l, int r, int k) {
    if (l <= r) {
        int pi = partition(arr, l, r);
        if (pi == k)
            return arr[pi];
        else if (pi < k)
            return quickSelect(arr, pi + 1, r, k);
        else
            return quickSelect(arr, l, pi - 1, k);
    }
    return -1;
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 2;
    cout << "K-th minimum element is " << quickSelect(arr, 0, arr.size() - 1, k);
    return 0;
}
```

### 8. Finding kth Maximum Element (QuickSelect)
```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(vector<int>& arr, int l, int r, int k) {
    if (l <= r) {
        int pi = partition(arr, l, r);
        if (pi == k)
            return arr[pi];
        else if (pi < k)
            return quickSelect(arr, pi + 1, r, k);
        else
            return quickSelect(arr, l, pi - 1, k);
    }
    return -1;
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 2;
    cout << "K-th maximum element is " << quickSelect(arr, 0, arr.size() - 1, k);
    return 0;
}
```

### Time and Space Complexity Table

| Algorithm                 | Best Time Complexity | Average Time Complexity | Worst Time Complexity | Space Complexity         |
| ------------------------- | -------------------- | ----------------------- | --------------------- | ------------------------ |
| Bubble Sort               | \(O(n)\)             | \(O(n^2)\)              | \(O(n^2)\)            | \(O(1)\) (in-place)      |
| Insertion Sort            | \(O(n)\)             | \(O(n^2)\)              | \(O(n^2)\)            | \(O(1)\) (in-place)      |
| Selection Sort            | \(O(n^2)\)           | \(O(n^2)\)              | \(O(n^2)\)            | \(O(1)\) (in-place)      |
| Merge Sort                | \(O(n \log n)\)      | \(O(n \log n)\)         | \(O(n \log n)\)       | \(O(n)\) (not in-place)  |
| Quick Sort                | \(O(n \log n)\)      | \(O(n \log n)\)         | \(O(n^2)\)            | \(O(\log n)\) (in-place) |
| Binary Search             | \(O(1)\)             | \(O(\log n)\)           | \(O(\log n)\)         | \(O(1)\)                 |
| QuickSelect (kth min/max) | \(O(n)\)             | \(O(n)\)                | \(O(n^2)\)            | \(O(\log n)\) (in-place) |



# STL


## Vectors

`vector<int>` in C++ is a part of the Standard Template Library (STL). It is a dynamic array that can grow and shrink in size automatically. `vector<int>` specifically is a vector that stores elements of type `int`. Here are the key details and functionalities of `vector<int>`:

### Basic Characteristics

1. **Dynamic Size**: Unlike arrays in C++ which have a fixed size, vectors can dynamically resize themselves when elements are added or removed.
2. **Contiguous Storage**: Elements in a vector are stored in contiguous memory locations, just like arrays, which allows direct access via an index.
3. **STL Container**: `vector<int>` is part of the STL and includes functionalities provided by other STL containers like lists, sets, etc.

### Key Operations

- **Creation and Initialization**:
  ```cpp
  #include <vector>
  
  std::vector<int> vec;                 // Creates an empty vector
  std::vector<int> vec(10);             // Creates a vector with 10 elements, initialized to 0
  std::vector<int> vec(10, 5);          // Creates a vector with 10 elements, each initialized to 5
  std::vector<int> vec = {1, 2, 3, 4};  // Creates a vector and initializes it with the given values
  ```

- **Accessing Elements**:
  ```cpp
  int val = vec[0];                     // Access element at index 0
  int val = vec.at(0);                  // Access element at index 0 with bounds checking
  int first = vec.front();              // Access the first element
  int last = vec.back();                // Access the last element
  ```

- **Modifying Elements**:
  ```cpp
  vec[0] = 10;                          // Modify element at index 0
  vec.push_back(5);                     // Add element to the end
  vec.pop_back();                       // Remove last element
  ```

- **Iterators**:
  ```cpp
  for (auto it = vec.begin(); it != vec.end(); ++it) {
      std::cout << *it << " ";
  }
  
  for (int val : vec) {                 // Range-based for loop (C++11)
      std::cout << val << " ";
  }
  ```

- **Capacity Functions**:
  ```cpp
  size_t size = vec.size();             // Get the number of elements
  size_t capacity = vec.capacity();     // Get the current capacity
  bool isEmpty = vec.empty();           // Check if the vector is empty
  vec.reserve(100);                     // Request that the vector capacity be at least enough to contain 100 elements
  vec.resize(20);                       // Resize the vector to contain 20 elements
  ```

- **Modifiers**:
  ```cpp
  vec.clear();                          // Removes all elements
  vec.insert(vec.begin(), 3);           // Insert element at the beginning
  vec.erase(vec.begin());               // Erase the first element
  ```

### Example Usage

Here's a simple example to demonstrate some of these operations:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Accessing elements
    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    // Modifying elements
    vec[0] = 10;
    vec.push_back(6);

    // Iterating through the vector
    std::cout << "Vector elements: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Using capacity functions
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    // Resizing the vector
    vec.resize(3);
    std::cout << "Vector after resizing: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

		vec.clear();

    return 0;
}
```

### Important Points

1. **Performance**: Vectors provide fast random access (constant time complexity, O(1)) but inserting or deleting elements in the middle of the vector can be slow (linear time complexity, O(n)) because it may require shifting elements.
2. **Memory Management**: Vectors manage memory automatically. When the capacity of a vector is exceeded, it reallocates memory to accommodate new elements, which can involve copying the elements to a new memory location.
3. **Iterators**: Vectors provide iterators that can be used to traverse the elements, similar to pointers in arrays.

### Use Cases

Vectors are suitable for scenarios where:

- The size of the container needs to be dynamic.
- Fast random access to elements is required.
- The number of insertions and deletions is relatively small compared to the number of accesses.

In summary, `vector<int>` in C++ is a versatile and powerful data structure that combines the benefits of dynamic arrays with the ease of use provided by the STL.


## STL functions

- try creating your own vector class using oops in c++

## sort in stl

```cpp
std::sort();

int main(){
int n=7;
int a[]={2,4,1,0,3,1,9};
sort(a,a+n);//sorts the array from a to a+n   inplace
return 0;
}
```


The `sort` function in the Standard Template Library (STL) of C++ is a powerful and versatile tool for sorting elements in containers like arrays, vectors, and other sequence containers. Here’s a detailed overview of the `sort` function, including its usage, underlying algorithm, customization options, and more.

### Overview

The `sort` function is included in the `<algorithm>` header and is used to sort elements in a range. It uses a highly optimized implementation of the Introsort algorithm, which is a hybrid sorting algorithm combining Quick Sort, Heap Sort, and Insertion Sort.

### Syntax

```cpp
#include <algorithm>

void sort(RandomIt first, RandomIt last);
void sort(RandomIt first, RandomIt last, Compare comp);
```

- **first**: Iterator to the beginning of the range to be sorted.
- **last**: Iterator to the end of the range to be sorted.
- **comp**: Comparison function object (optional).

### Basic Usage

Here’s a simple example of using `sort` to sort a vector of integers:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Sort in ascending order
    std::sort(vec.begin(), vec.end());

    std::cout << "Sorted vector: ";
	//printing all the elements of the array
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Custom Comparator

The `sort` function can also use a custom comparator to define the sorting order. The comparator should return `true` if the first argument is considered to go before the second.

Example of sorting in descending order:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool customCompare(int a, int b) {
    return a > b; // For descending order
}

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Sort in descending order using custom comparator
    std::sort(vec.begin(), vec.end(), customCompare);

    std::cout << "Sorted vector (descending): ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Understanding Introsort

Introsort is the algorithm used by `std::sort` in C++ STL. It begins with Quick Sort and switches to Heap Sort when the recursion depth exceeds a level based on the number of elements being sorted. It switches to Insertion Sort for small subarrays.

- **Quick Sort**: Efficient on average but can degrade to O(n^2) in the worst case.
- **Heap Sort**: Guarantees O(n log n) time complexity, used as a fallback to avoid Quick Sort's worst case.
- **Insertion Sort**: Efficient for small data sets, used for sorting small subarrays.

### Complexity

- **Time Complexity**:
  - **Best Case**: \(O(n \log n)\)
  - **Average Case**: \(O(n \log n)\)
  - **Worst Case**: \(O(n \log n)\) due to the fallback to Heap Sort

- **Space Complexity**: \(O(\log n)\) due to the recursive nature of Quick Sort.

### Practical Examples

1. **Sorting a Range in an Array**:
   ```cpp
   #include <iostream>
   #include <algorithm>

   int main() {
       int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
       int n = sizeof(arr) / sizeof(arr[0]);

       std::sort(arr, arr + n);

       std::cout << "Sorted array: ";
       for (int i = 0; i < n; ++i) {
           std::cout << arr[i] << " ";
       }
       std::cout << std::endl;

       return 0;
   }
   ```

2. **Sorting a Part of a Vector**:
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   int main() {
       std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};

       // Sort a subrange [2, 7) in the vector
       std::sort(vec.begin() + 2, vec.begin() + 7);

       std::cout << "Partially sorted vector: ";
       for (int val : vec) {
           std::cout << val << " ";
       }
       std::cout << std::endl;

       return 0;
   }
   ```

3. **Sorting with Custom Comparator for Structs**:
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   struct Point {
       int x, y;
   };

   bool comparePoints(const Point &a, const Point &b) {
       return a.x < b.x; // Sort by x coordinate
   }

   int main() {
       std::vector<Point> points = {{3, 2}, {1, 5}, {4, 3}, {2, 8}, {5, 1}};

       std::sort(points.begin(), points.end(), comparePoints);

       std::cout << "Sorted points: ";
       for (const Point &p : points) {
           std::cout << "(" << p.x << ", " << p.y << ") ";
       }
       std::cout << std::endl;

       return 0;
   }
   ```

### Conclusion

The `std::sort` function in C++ STL is a highly efficient and versatile sorting utility. It can handle various data types, including primitive types and user-defined types with custom comparators. By understanding how to use `std::sort`, you can easily integrate efficient sorting capabilities into your C++ programs.

Vectors

- sort, random_shuffle, reverse
- max_element(),min_element()
- v.erase(v.begin()+3,v.begin+7)  the range is open from both ends


Vectors in C++ provide a wide range of functions for manipulation, access, and iteration of elements. Here are some important functions provided by the `std::vector` class in C++:

### Element Access

1. **`operator[]`**: Access element at position (no bounds checking).
2. **`at()`**: Access element at position (with bounds checking).
3. **`front()`**: Access the first element.
4. **`back()`**: Access the last element.

### Capacity

5. **`size()`**: Return the number of elements in the vector.
6. **`empty()`**: Check if the vector is empty.
7. **`resize()`**: Change the size of the vector.
8. **`capacity()`**: Return the number of elements that the vector can hold without reallocation.
9. **`reserve()`**: Request a change in capacity.

### Modifiers

10. **`push_back()`**: Add element to the end of the vector.
11. **`pop_back()`**: Remove element from the end of the vector.
12. **`insert()`**: Insert elements at a specific position.
13. **`erase()`**: Remove elements from a specific position or range.
14. **`clear()`**: Remove all elements from the vector.

### Iterators

15. **`begin()`**: Return an iterator to the beginning of the vector.
16. **`end()`**: Return an iterator to the end of the vector.
17. **`rbegin()`**: Return a reverse iterator to the beginning of the vector.
18. **`rend()`**: Return a reverse iterator to the end of the vector.

### Miscellaneous

19. **`swap()`**: Swap the contents of two vectors.
20. **`emplace_back()`**: Construct and add element to the end of the vector (in-place construction).

These are some of the most commonly used functions provided by the `std::vector` class. They enable efficient manipulation and access to elements within the vector. Understanding these functions allows you to work effectively with vectors in C++

## imp function of stl

The Standard Template Library (STL) in C++ provides a wide range of containers and algorithms to work with. Here's a list of important functions and classes from the STL, categorized by containers, algorithms, and other utilities:

### Containers

1. **`std::vector`**: Dynamic array.
2. **`std::deque`**: Double-ended queue.
3. **`std::list`**: Doubly linked list.
4. **`std::forward_list`**: Singly linked list.
5. **`std::set`**: Ordered set (no duplicates).
6. **`std::multiset`**: Ordered multiset (allows duplicates).
7. **`std::map`**: Ordered map (key-value pairs, no duplicates).
8. **`std::multimap`**: Ordered multimap (key-value pairs, allows duplicates).
9. **`std::unordered_set`**: Unordered set (no duplicates).
10. **`std::unordered_multiset`**: Unordered multiset (allows duplicates).
11. **`std::unordered_map`**: Unordered map (key-value pairs, no duplicates).
12. **`std::unordered_multimap`**: Unordered multimap (key-value pairs, allows duplicates).
13. **`std::stack`**: LIFO (last-in, first-out) stack.
14. **`std::queue`**: FIFO (first-in, first-out) queue.
15. **`std::priority_queue`**: Priority queue (heap).

### Algorithms

1. **Sorting**:
   - `std::sort`
   - `std::stable_sort`
   - `std::partial_sort`
   - `std::nth_element`
2. **Searching**:
   - `std::find`
   - `std::binary_search`
   - `std::lower_bound`
   - `std::upper_bound`
   - `std::equal_range`
3. **Modifying**:
   - `std::copy`
   - `std::copy_if`
   - `std::transform`
   - `std::fill`
   - `std::replace`
4. **Numeric**:
   - `std::accumulate`
   - `std::inner_product`
   - `std::partial_sum`
   - `std::adjacent_difference`
5. **Set Operations**:
   - `std::set_union`
   - `std::set_intersection`
   - `std::set_difference`
   - `std::set_symmetric_difference`
6. **Heap**:
   - `std::make_heap`
   - `std::push_heap`
   - `std::pop_heap`
   - `std::sort_heap`
7. **Permutations**:
   - `std::next_permutation`
   - `std::prev_permutation`
8. **Miscellaneous**:
   - `std::reverse`
   - `std::rotate`
   - `std::shuffle`
   - `std::unique`

### Utilities

1. **Iterators**:
   - `std::begin`
   - `std::end`
   - `std::advance`
   - `std::distance`
2. **Functors**:
   - `std::less`
   - `std::greater`
   - `std::function`
   - `std::bind`
3. **Memory**:
   - `std::unique_ptr`
   - `std::shared_ptr`
   - `std::weak_ptr`
   - `std::make_unique` (C++14)
   - `std::make_shared` (C++11)
4. **Strings**:
   - `std::string`
   - `std::getline`
   - `std::to_string`
   - `std::stoi`, `std::stod`, etc.
5. **Random Numbers**:
   - `std::rand`
   - `std::srand`
   - `<random>` library (C++11)

### Miscellaneous

1. **`std::pair`**: Simple pair of values.
2. **`std::tuple`**: Collection of heterogeneous values.
3. **`std::chrono`**: Time utilities (C++11).
4. **`std::thread`**: Threading support (C++11).

These are some of the most commonly used functions and classes from the STL. They provide powerful tools for a wide range of tasks in C++ programming, from data manipulation to algorithm implementation and more.

## Pair

`std::pair` is a simple utility class template provided by the Standard Template Library (STL) in C++. It allows you to store a pair of values, each of potentially different types. Here's a detailed overview of `std::pair`, including its definition, constructors, accessors, and important member functions:

### Definition

```cpp
template <class T1, class T2>
struct pair {
    T1 first;   // The first element of the pair
    T2 second;  // The second element of the pair
};
```

- `T1` and `T2` are the types of the first and second elements, respectively.
- `first` and `second` are public member variables of the `pair` struct.

### Constructors

1. **Default Constructor**:
   ```cpp
   pair();
   ```
   Constructs a pair with default-initialized elements.

2. **Value Initialization Constructor**:
   ```cpp
   pair(const T1& a, const T2& b);
   ```
   Constructs a pair with the specified values.

### Accessors

- **`first`**: Returns a reference to the first element of the pair.
- **`second`**: Returns a reference to the second element of the pair.

### Important Member Functions

1. **`operator==` and `operator!=`**:
   - Allows comparison of two pairs for equality and inequality.
   ```cpp
   bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
   bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
   ```

2. **`make_pair`** (Non-member Function):
   - Constructs a pair with the specified values (type deduction).
   ```cpp
   template <class T1, class T2>
   pair<T1, T2> make_pair(T1&& x, T2&& y);
   ```

### Example Usage

```cpp
#include <iostream>
#include <utility>

int main() {
    std::pair<int, double> myPair(5, 3.14);

    std::cout << "First element: " << myPair.first << std::endl;
    std::cout << "Second element: " << myPair.second << std::endl;

    // Comparison
    std::pair<int, double> otherPair(5, 3.14);
    if (myPair == otherPair) {
        std::cout << "Pairs are equal" << std::endl;
    } else {
        std::cout << "Pairs are not equal" << std::endl;
    }

    // make_pair example
    auto anotherPair = std::make_pair(10, 2.71);
    std::cout << "First element of anotherPair: " << anotherPair.first << std::endl;
    std::cout << "Second element of anotherPair: " << anotherPair.second << std::endl;

    return 0;
}
```

### Notes

- `std::pair` is commonly used to return multiple values from functions or to store pairs of related data.
- It is widely used in conjunction with other STL containers like `std::map` and `std::unordered_map` to represent key-value pairs.
- The `first` and `second` elements of a pair are accessed using the dot (`.`) operator.

### Summary

`std::pair` is a simple but powerful utility class provided by the STL in C++. It allows you to conveniently store and access pairs of values, providing a flexible and efficient way to work with related data in your programs.

## Tuples

`std::tuple` is a versatile container provided by the Standard Template Library (STL) in C++. It allows you to store multiple heterogeneous values as a single entity. Here's a detailed overview of `std::tuple`, including its definition, constructors, accessors, and important member functions:

### Definition

```cpp
template <class... Types>
class tuple;
```

- `Types...` is a parameter pack representing the types of elements stored in the tuple.

### Constructors

1. **Default Constructor**:
   ```cpp
   tuple();
   ```
   Constructs a tuple with default-initialized elements.

2. **Value Initialization Constructor**:
   ```cpp
   tuple(const Types&... args);
   ```
   Constructs a tuple with the specified values.

### Accessors

3. **`std::get`** (Function Template):
   - Accesses the element at the specified index in the tuple.
   ```cpp
   template <size_t Index, class... Types>
   constexpr typename tuple_element<Index, tuple<Types...>>::type&
   get(tuple<Types...>& t);
   ```
   Example usage:
   ```cpp
   std::tuple<int, double, std::string> myTuple(10, 3.14, "hello");
   int intValue = std::get<0>(myTuple);  // Accessing the first element
   double doubleValue = std::get<1>(myTuple);  // Accessing the second element
   ```

### Important Member Functions

4. **`std::tie`** (Function Template):
   - Creates a tuple of references to the specified variables.
   ```cpp
   template <class... Types>
   constexpr tuple<Types&...> tie(Types&... args) noexcept;
   ```
   Example usage:
   ```cpp
   int a = 10;
   double b = 3.14;
   std::string c = "hello";
   auto myTiedTuple = std::tie(a, b, c);
   ```

5. **`std::make_tuple`** (Function Template):
   - Constructs a tuple with the specified values (type deduction).
   ```cpp
   template <class... Types>
   constexpr tuple<Types...> make_tuple(Types&&... args);
   ```
   Example usage:
   ```cpp
   auto myTuple = std::make_tuple(10, 3.14, "hello");
   ```

6. **`std::tuple_size`** (Primary Template):
   - Gets the number of elements in a tuple.
   ```cpp
   template <class T>
   struct tuple_size;
   ```
   Example usage:
   ```cpp
   std::tuple<int, double, std::string> myTuple;
   size_t tupleSize = std::tuple_size<decltype(myTuple)>::value;
   ```

7. **`std::tuple_element`** (Primary Template):
   - Accesses the type of the element at the specified index in a tuple.
   ```cpp
   template <size_t Index, class T>
   struct tuple_element;
   ```
   Example usage:
   ```cpp
   std::tuple<int, double, std::string> myTuple;
   using ThirdType = std::tuple_element<2, decltype(myTuple)>::type;
   ```

### Notes

- `std::tuple` provides a convenient way to work with multiple values of different types as a single unit.
- Elements in a tuple are accessed using `std::get` by specifying the index of the element.
- `std::tie` is useful for creating tuples of references to variables for functions that return multiple values.
- `std::make_tuple` simplifies the construction of tuples by deducing the types of the elements from the provided arguments.

### Summary

`std::tuple` is a powerful and flexible container in C++ that allows you to store multiple values of different types. It provides a wide range of functionality for creating, accessing, and manipulating tuples, making it a valuable tool for various programming tasks.


## Vector of vectors and vector of pairs and vector of tuples
vector of pairs acts like dictionary
it is not necessary that in pair the datatype of both elements are same


Sure, let's dive into the details of `vector` of `vectors`, `vector` of `pairs`, and `vector` of `tuples` in C++.

### Vector of Vectors (`std::vector<std::vector<T>>`)

A vector of vectors is a two-dimensional dynamic array, where each element is itself a vector. This allows for storing a matrix or a grid-like structure.

#### Basic Usage:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Element at row 1, column 2: " << matrix[1][2] << std::endl;

    return 0;
}
```

#### Important Functions and Methods:
1. **Accessing Elements**:
   - `matrix[i][j]`: Accesses the element at row `i` and column `j`.

2. **Pushing Elements**:
   - `push_back()`: Adds a new row to the vector of vectors.

3. **Size and Capacity**:
   - `size()`: Returns the number of rows.
   - `capacity()`: Returns the number of rows the vector can hold before reallocation.

4. **Resizing**:
   - `resize()`: Changes the number of rows.

5. **Iterating**:
   - Using nested loops or iterators to iterate over elements.

### Vector of Pairs (`std::vector<std::pair<T1, T2>>`)

A vector of pairs stores a collection of pairs, where each pair consists of two elements of potentially different types.

#### Basic Usage:
```cpp
#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::vector<std::pair<int, std::string>> students = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"}
    };

    for (const auto& student : students) {
        std::cout << "ID: " << student.first << ", Name: " << student.second << std::endl;
    }

    return 0;
}
```

#### Important Functions and Methods:
1. **Accessing Elements**:
   - `pair.first` and `pair.second`: Access the first and second elements of the pair.

2. **Pushing Elements**:
   - `emplace_back()`, `push_back()`: Adds a new pair to the vector of pairs.

3. **Size and Capacity**:
   - `size()`: Returns the number of pairs.
   - `capacity()`: Returns the number of pairs the vector can hold before reallocation.

4. **Iterating**:
   - Using range-based for loop or iterators to iterate over pairs.

### Vector of Tuples (`std::vector<std::tuple<T1, T2, ..., Tn>>`)

A vector of tuples stores a collection of tuples, where each tuple can hold multiple elements of potentially different types.

#### Basic Usage:
```cpp
#include <iostream>
#include <vector>
#include <tuple>

int main() {
    std::vector<std::tuple<int, double, std::string>> data = {
        std::make_tuple(1, 3.14, "hello"),
        std::make_tuple(2, 2.71, "world")
    };

    for (const auto& item : data) {
        std::cout << "Tuple: " << std::get<0>(item) << ", "
                  << std::get<1>(item) << ", "
                  << std::get<2>(item) << std::endl;
    }

    return 0;
}
```

#### Important Functions and Methods:
1. **Accessing Elements**:
   - `std::get<>()`: Access elements of a tuple by index.

2. **Pushing Elements**:
   - `emplace_back()`, `push_back()`: Adds a new tuple to the vector of tuples.

3. **Size and Capacity**:
   - `size()`: Returns the number of tuples.
   - `capacity()`: Returns the number of tuples the vector can hold before reallocation.

4. **Iterating**:
   - Using range-based for loop or iterators to iterate over tuples.

These data structures offer flexibility and convenience in organizing and manipulating data in C++, depending on the specific requirements of your program.



## Strings

Strings in C++ are represented by the `std::string` class, which is part of the Standard Template Library (STL). `std::string` provides a convenient and efficient way to work with strings of characters. Here's an overview of `std::string`, including its definition, constructors, member functions, and common operations:

### Definition

```cpp
#include <string>

std::string str;  // Declaration of a string variable
```

### Constructors

1. **Default Constructor**:
   ```cpp
   std::string();
   ```
   - Constructs an empty string.

2. **Initialization Constructor**:
   ```cpp
   std::string(const char* s);
   std::string(const std::string& str);
   ```
   - Constructs a string from a null-terminated character array or another string.

### Member Functions and Operations

1. **Accessors**
   - `size()`, `length()`: Returns the length of the string.
   - `empty()`: Checks if the string is empty.
   - `at()`, `operator[]`: Accesses individual characters in the string.
   - `c_str()`: Returns a pointer to a null-terminated character array with data equivalent to those stored in the string.

2. **Modifiers**
   - `append()`, `+=`: Appends additional characters to the string.
   - `clear()`: Clears the contents of the string.
   - `erase()`: Erases characters from the string.
   - `insert()`: Inserts characters into the string.
   - `replace()`: Replaces a portion of the string with different characters.
   - `resize()`: Resizes the string to a specified length.
   - `swap()`: Swaps the contents of two strings.

3. **Substrings and Searching**
   - `substr()`: Extracts a substring from the string.
   - `find()`, `rfind()`, `find_first_of()`, `find_last_of()`, `find_first_not_of()`, `find_last_not_of()`: Search for substrings or characters within the string.

4. **Comparisons**
   - `compare()`: Compares two strings lexicographically.

5. **Conversion**
   - `to_string()`: Converts numerical values to string.

### Example Usage

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";
    std::cout << "Length of string: " << str.length() << std::endl;
    std::cout << "Character at index 7: " << str[7] << std::endl;

    str.append(" Welcome!");  // Appending additional characters
    std::cout << "Modified string: " << str << std::endl;

    std::string substring = str.substr(7, 5);  // Extracting a substring
    std::cout << "Substring: " << substring << std::endl;

    if (str.find("world") != std::string::npos) {
        std::cout << "'world' found in the string." << std::endl;
    }

    return 0;
}
```

### Notes

- `std::string` handles memory management for character storage, making it safer and more convenient than C-style strings.
- Operations on `std::string` are generally efficient and optimized, allowing for fast string manipulation.

### Summary

`std::string` in C++ is a powerful and flexible class for working with strings of characters. It offers a wide range of member functions and operations for string manipulation, making it suitable for various applications ranging from simple text processing to complex data manipulation.

## Sets 
- see what are ordered and unordered sets

Certainly! Sets in C++ are a part of the Standard Template Library (STL) and are implemented in the `std::set` container. Sets are associative containers that store unique elements in a sorted order. Here's an in-depth look at sets in C++, including their features, operations, and complexities:

### Definition and Declaration

```cpp
#include <set>

std::set<int> mySet; // Declaration of an empty set of integers
```

### Features

1. **Uniqueness**: Sets contain only unique elements. Duplicate elements are automatically removed.

2. **Ordered**: Elements in a set are always sorted in ascending order by default. The sorting order can be customized using comparators.

3. **Associative**: Sets are associative containers, which means each element is associated with a key value.

### Operations

1. **Insertion**:
   - `insert()`: Inserts elements into the set.
   ```cpp
   mySet.insert(10);
   mySet.insert(20);
   ```

2. **Deletion**:
   - `erase()`: Removes elements from the set.
   ```cpp
   mySet.erase(10);
   ```

3. **Search**:
   - `find()`: Searches for an element in the set.
   ```cpp
   auto it = mySet.find(10);
   if (it != mySet.end()) {
       // Element found
   }
   ```

4. **Iterators**:
   - `begin()`, `end()`: Returns iterators to the beginning and end of the set.
   ```cpp
   for (auto it = mySet.begin(); it != mySet.end(); ++it) {
       // Access element using *it
   }
   ```

5. **Size and Capacity**:
   - `size()`: Returns the number of elements in the set.
   ```cpp
   int size = mySet.size();
   ```

6. **Clearing**:
   - `clear()`: Removes all elements from the set.
   ```cpp
   mySet.clear();
   ```

7. **Counting**:
   - `count()`: Returns the number of occurrences of a specific element in the set (1 for present, 0 for absent).
   ```cpp
   int count = mySet.count(10);
   ```

### Complexity

- **Insertion, Deletion, and Search**: \(O(\log n)\) on average, where \(n\) is the number of elements in the set.
- **Iterating through the set**: Linear time complexity, \(O(n)\).

### Example Usage

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {5, 10, 15, 20};

    mySet.insert(25);
    mySet.erase(10);

    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    if (mySet.find(15) != mySet.end()) {
        std::cout << "Element 15 found" << std::endl;
    }

    int count = mySet.count(5);
    std::cout << "Count of 5: " << count << std::endl;

    return 0;
}
```

### Notes

- Sets are implemented using binary search trees (usually red-black trees) which provide efficient insertion, deletion, and search operations.
- Sets are widely used for tasks requiring unique elements and maintaining them in a sorted order.

### Summary

Sets in C++ provide an efficient way to store unique elements in a sorted order. They offer various operations for insertion, deletion, search, and iteration, making them suitable for a wide range of applications requiring ordered collections of elements. Understanding sets and their operations is essential for effective use of the C++ STL.




## Unordered Sets

## Multiset

## Iterators in sets

## Maps and Unordered maps
- similar to dictionary in python

# Advanced Data Sturctures
## Deque

## Stack

## Que

## Priority Que

## Bit Set

## Policy Based Data Structure (PDBS)

