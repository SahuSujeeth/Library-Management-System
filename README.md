# 📚 Library Management System in C

This is a simple **Library Management System** implemented in C.  
It allows users to **add, view, search, and delete books** using a console-based interface.  

---

## ✨ Features

- 📖 **Add Book** → Enter book title & author, automatically assigns unique ID.  
- 📚 **View Books** → Display all books with ID, Title, Author, and Availability.  
- 🔍 **Search Book** → Search by **title or author** (partial matches allowed).  
- ❌ **Delete Book** → Delete a book by its ID.  
- 🎯 Supports up to **100 books** (can be increased by changing `MAX_BOOKS`).  

---

## ⚡ How to Compile & Run

1. Open terminal in the folder containing the file (e.g., `library.c`).  
2. Compile the program:  

   ```bash
   gcc library.c -o library
   ./a.exe
   ```

---

## 📸 Sample Run
```
Library Management System
1. Add Book
2. View All Books
3. Search Book
4. Delete Book
5. Exit
Enter your choice: 1

Enter book title: The Alchemist
Enter author name: Paulo Coelho
Book added successfully!

Library Management System
1. Add Book
2. View All Books
3. Search Book
4. Delete Book
5. Exit
Enter your choice: 2

Library Books:
ID   Title                         Author             Available
----------------------------------------------------------
1    The Art of Being Alone       Renuka Gavrani       Yes
```

