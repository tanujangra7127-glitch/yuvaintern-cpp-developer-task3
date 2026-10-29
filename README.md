Week 3: Advanced Data Structures in C++

Project Overview

This project implements a custom Doubly Linked List in C++. It demonstrates important data structure operations, pointer manipulation, sorting, searching, and memory management.

Features

- Insert elements at the beginning and end.
- Insert an element at a specific index.
- Delete an element by value.
- Search for an element and return its index.
- Sort elements in ascending order.
- Display the list in forward and backward directions.
- Clear the list and release allocated memory.
- Handle invalid indexes and missing values.

Technologies Used

- C++
- Object-Oriented Programming
- Pointers and Dynamic Memory Allocation
- Doubly Linked List
- Insertion Sort and Linear Search

Project Structure

Week3-Advanced-Data-Structures/
├── main.cpp
├── README.md
└── Week3_Project_Report.docx

Requirements

- A C++ compiler such as GCC or MinGW.
- A code editor or terminal.

How to Compile and Run

Step 1: Compile

Open a terminal in the project folder and run:

g++ -std=c++17 -Wall -Wextra main.cpp -o week3

Step 2: Execute

Windows:

week3.exe

Linux/macOS:

./week3

Testing

The program demonstrates the following test cases:

1. Inserting elements at different positions.
2. Displaying elements in both directions.
3. Searching for an existing value.
4. Sorting values in ascending order.
5. Removing an existing value.
6. Handling a value that does not exist.
7. Clearing the list and checking its size.

Time Complexity

Operation| Complexity
Insert at beginning/end| O(1)
Insert at an index| O(n)
Search| O(n)
Delete by value| O(n)
Insertion sort| O(n²)
Display list| O(n)

Learning Outcomes

This project improves understanding of linked lists, pointer relationships, dynamic memory allocation, sorting algorithms, searching techniques, and safe memory cleanup in C++.

Author

Tanu Jangra

Internship

Yuva Intern – Junior C++ Developer

Conclusion

The project demonstrates a custom doubly linked list with essential operations and basic memory safety. It provides practical experience in implementing and maintaining data structures using C++.