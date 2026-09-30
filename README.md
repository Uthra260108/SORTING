Sorting Algorithms in C

A simple C program that implements and demonstrates multiple sorting algorithms using a menu-driven approach. The user can enter an array of integers and choose any sorting algorithm to sort the array in ascending order.

Sorting Algorithms Included

Insertion Sort – Builds the sorted array one element at a time.

Merge Sort – Uses the divide-and-conquer technique to split and merge the array.

Heap Sort – Uses a binary heap data structure to sort the elements.

Quick Sort 1 – Quick sort using the first element as the pivot.

Quick Sort 2 – Quick sort using a two-pointer partitioning method.

Counting Sort – Sorts non-negative integers using a counting array.

Features

Menu-driven interface

Easy-to-understand C implementation

Supports arrays of up to 100 elements

Displays the sorted array after execution

Contains multiple commonly used sorting techniques in a single program

How to Run
1. Clone the repository
git clone https://github.com/your-username/sorting-algorithms-c.git

2. Navigate to the project directory
cd sorting-algorithms-c

3. Compile the program

Using GCC:

gcc sorting.c -o sorting

4. Run the program
./sorting


On Windows:

sorting.exe

Example
Enter number of elements: 5
Enter elements: 64 25 12 22 11

===== SORTING MENU =====
1. Insertion Sort
2. Merge Sort
3. Heap Sort
4. Quick Sort - 1
5. Quick Sort - 2
6. Counting Sort
Enter your choice: 2

Sorted array: 11 12 22 25 64

Time Complexity
Algorithm	Best Case	Average Case	Worst Case
Insertion Sort	O(n)	O(n²)	O(n²)
Merge Sort	O(n log n)	O(n log n)	O(n log n)
Heap Sort	O(n log n)	O(n log n)	O(n log n)
Quick Sort 1	O(n log n)	O(n log n)	O(n²)
Quick Sort 2	O(n log n)	O(n log n)	O(n²)
Counting Sort	O(n + k)	O(n + k)	O(n + k)

Where n is the number of elements and k is the range of input values for Counting Sort.

Space Complexity
Algorithm	Space Complexity
Insertion Sort	O(1)
Merge Sort	O(n)
Heap Sort	O(log n)
Quick Sort 1	O(log n) average
Quick Sort 2	O(log n) average
Counting Sort	O(n + k)
Important Note

The current Counting Sort implementation is designed for non-negative integers and uses a counting array of size 100. Therefore, input values should be within the supported range.

Purpose

This project is intended for learning and practicing fundamental sorting algorithms in C, particularly for understanding their implementation, working principles, and time complexity.

License

This project is open for educational and learning purposes.
