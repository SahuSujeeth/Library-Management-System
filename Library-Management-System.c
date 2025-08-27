#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int is_available;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = book_count + 1;

    printf("Enter book title: ");
    getchar(); // Consume newline left in the buffer
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.is_available = 1; // Initially available

    library[book_count] = newBook;
    book_count++;

    printf("Book added successfully!\n\n");
}

void viewBooks() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Library Books:\n");
    printf("ID\tTitle\t\t\tAuthor\t\tAvailable\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", library[i].id, library[i].title,
               library[i].author, library[i].is_available ? "Yes" : "No");
    }
    printf("\n");
}

void searchBook() {
    char query[100];
    printf("Enter book title or author to search: ");
    getchar(); // Consume newline
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    printf("Search Results:\n");
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].author, query)) {
            printf("ID: %d, Title: %s, Author: %s, Available: %s\n", library[i].id,
                   library[i].title, library[i].author,
                   library[i].is_available ? "Yes" : "No");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found.\n");
    }
    printf("\n");
}

void deleteBook() {
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < book_count - 1; i++) {
        library[i] = library[i + 1];
    }
    book_count--;

    printf("Book deleted successfully!\n\n");
}

void menu() {
    printf("Library Management System\n");
    printf("1. Add Book\n");
    printf("2. View All Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}