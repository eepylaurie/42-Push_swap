*This project has been created as part of the 42 curriculum by lmatthes.*

# Push_swap

## Description

`Push_swap` is a program that sorts a list of integers using **two stacks** and a **restricted set of operations**.

The program receives a sequence of integers, places them in stack **A**, and prints the operations required to sort the stack in ascending order.

### Allowed Operations

| Operation | Effect on Stack A | Effect on Stack B | Description |
| --------- | ----------------- | ----------------- | ----------- |
| `sa` | swap top 2 elements | - | Swap the first 2 elements of stack A. |
| `sb` | - | swap top 2 elements | Swap the first 2 elements of stack B. |
| `ss` | swap top 2 elements | swap top 2 elements | Perform `sa` and `sb` simultaneously. |
| `pa` | push from B to A | pop top | Move the top element of B to the top of A. |
| `pb` | pop top | push from A to B | Move the top element of A to the top of B. |
| `ra` | rotate up | - | Move the top element from A to the bottom. |
| `rb` | - | rotate up | Move the top element from B to the bottom. |
| `rr` | rotate up | rotate up | Perform `ra` and `rb` simultaneously. |
| `rra` | rotate down | - | Move the bottom element of A to the top. |
| `rrb` | - | rotate down | Move the bottom element of B to the top. |
| `rrr` | rotate down | rotate down | Perform `rra` and `rrb` simultaneously. |

## Algorithm Overview

This project uses a **chunk-based sorting strategy**.

### 1. Indexing

All input values are mapped to their **rank** in the sorted array (from `0` to `n - 1`).
This simplifies comparisons and allows the algorithm to work with normalized values.

### 2. Chunk Push (A → B)

The full range of indices is split into **chunks**.
Values belonging to the current chunk are pushed from stack **A** to stack **B**.
While pushing, smaller values in the chunk are rotated inside **B** to keep the stack partially ordered.

### 3. Pull Back (B → A)

Once all chunks have been pushed, stack **B** contains all the values.
The algorithm repeatedly brings the **largest value** in **B** to the top and pushes it back to **A**, rebuilding the sorted stack.

This approach allows large inputs to be sorted efficiently within the required operation limits.

## Data Structures

Each stack is implemented as a **doubly linked list**.

``` C
typedef struct	s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;
```

- `val` is the original value
- `idx` is the sorted index
- `next`/`prev` allow forward and reverse rotations
- `top`, `bot` and `size` allow fast stack operations

## Instructions

### Build

``` bash
make
```

This creates the `push_swap` executable.

### Run

``` bash
./pushswap 3 2 1
```

Example output:

``` bash
sa
rra
```

To verify correctness using the checker:

``` bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

If the output is correct, the checker prints:

``` bash
OK
```

### Clean / Rebuild

``` bash
make clean
make fclean
make re
```

## Resources

- [Push swap 42 visualizer](https://push-swap42-visualizer.vercel.app/)
- [Linked List in C](https://www.geeksforgeeks.org/c/linked-list-in-c/)
- [Doubly Linked List in C](https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/)

### AI Usage

AI assistance was used **only for learning support**, including:

- understanding chunk-based sorting strategies
- clarifying data structure behavior

**All algorithm design, code logic, and implementation were written and understood by me.**