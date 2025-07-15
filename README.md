
---

## 🧠 Data Structures Descriptions

### 1. Dynamic Array
A dynamic array automatically resizes itself when capacity is reached. It uses a resizing strategy to allocate more memory when needed.

- **Time Complexity**:
  - Access: `O(1)`
  - Insert (at end): `O(1)` (amortized)
  - Delete (from end): `O(1)`
  - Resize: `O(n)`
- **Space Complexity**: `O(n)`

---

### 2. Singly Linked List
A sequence of nodes where each node points to the next. Insertions and deletions at the end require traversal.

- **Time Complexity**:
  - Insert (end): `O(n)`
  - Delete (end): `O(n)`
  - Access by index: `O(n)`
- **Space Complexity**: `O(n)`

---

### 3. Stack using Array
A last-in-first-out (LIFO) structure backed by a dynamic array.

- **Time Complexity**:
  - Push: `O(1)` (amortized)
  - Pop: `O(1)`
  - Peek: `O(1)`
- **Space Complexity**: `O(n)`

---

### 4. Stack using Linked List
A LIFO structure implemented using singly linked list with `push` and `pop` at the head.

- **Time Complexity**:
  - Push: `O(1)`
  - Pop: `O(1)`
  - Peek: `O(1)`
- **Space Complexity**: `O(n)`

---

## ✅ Usage Example (main file)

The file `Taske_1_da.cpp` demonstrates usage and testing of all implemented structures including:

- Insertion, deletion, update, and printing for:
  - Dynamic arrays
  - Linked lists
  - Stack (array-based)
  - Stack (linked list-based)

---

## ▶️ How to Compile and Run

```bash
g++ Taske_1_da.cpp -o runme
./runme
