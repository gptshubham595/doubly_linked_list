# doubly_linked_list

## Introduction

This assignment is a C programming project where you write a program that simulates the organization of
the virtual memory in a running process. In practice, you will create a dynamic doubly linked list for storing
integers. The integers will be stored and removed into two stacks, which will grow and shrink during the
program execution. In particular,

- the first stack will contain odd positive integers, e.g. 1, 3, or 9, start at the head of the list, and grow
towards the tail,

- the second stack will contain even nonnegative integers, e.g. 0, 2, or 8, start at the tail of the list, and
grow towards the head,

- between the two lists, the program will maintain a free gap, i.e. a set of free nodes, simulating the free
memory gap between the heap and the stack in a process virtual address space.

Integers will be capped at some given value, MAX, fixed at the beginning of the program and the user will
control the number of integers pushed to and pulled from the list from the terminal. Here is an illustrative
diagram of the list that your program is supposed to build:

<object data="./c_project[9420].pdf" type="application/pdf" width="700px" height="700px">
    <embed src="./c_project[9420].pdf">
        <p>This browser does not support PDFs. Please download the PDF to view it: <a href="./c_project[9420].pdf">Download PDF</a>.</p>
    </embed>
</object>
