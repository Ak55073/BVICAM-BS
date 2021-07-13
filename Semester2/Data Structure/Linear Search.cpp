#include <iostream>

using namespace std;

typedef struct {
    int bookId;
} Book;

int main() {
    int limit, srchid;
    printf("Linear search - Abhinav Kumar\n\n");

    // Size of list
    printf("Enter limit: ");
    scanf("%d", &limit);
    Book arr[limit];

    // Populating list
    printf("\nInsert item in list\n");
    for (int i = 0; i < limit; i++) {
        printf("Enter bookid: ");
        scanf("%d", &arr[i].bookId);
    }

    printf("List: ");
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i].bookId);
    }

    // Searching Item
    printf("\nEnter book ID to search: ");
    scanf("%d", &srchid);
    for (int i = 0; i < limit; i++) {
        if (arr[i].bookId == srchid) {
            printf("Book ID: %d found at %d place", srchid, i+1);
            // If found, exit main method;
            return 0;
        }
    }

    // If item not found
    printf("Book ID: %d not found in data.", srchid);

    return 0;
}
