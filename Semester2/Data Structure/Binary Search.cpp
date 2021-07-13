#include <iostream>

using namespace std;

typedef struct {
    int bookId;
} Book;

int main() {
    int limit, srchid;
    printf("Binary search - Abhinav Kumar\n\n");

    // Size of list
    printf("\nEnter limit: ");
    scanf("%d", &limit);
    Book arr[limit];

    // Populating list
    printf("\nInsert item\n");
    for (int i = 0; i < limit; i++) {
        printf("Enter bookid: ");
        scanf("%d", &arr[i].bookId);
    }

    // Sorting list - compulsory for binary search
    for (int i = 0; i < limit; i++) {
        for (int j = i+1; j < limit; j++) {
            if(arr[i].bookId > arr[j].bookId) {
                Book temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted: ");
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i].bookId);
    }

    // Searching Item
    printf("\nEnter book ID to search: ");
    scanf("%d", &srchid);
    int start = 0;
    int last = limit;
    int mid;
    for (int i = 0; i < limit/2; i++) {
        mid = (start+last) / 2;
        if (arr[mid].bookId == srchid){
            printf("Book ID: %d found in ind %d.", srchid, mid+1);
            // If found, exit main method;
            return 0;
        }
        if(arr[mid].bookId<srchid){
            start = mid;
        } else{
            last = mid;
        }
    }

    // If item not found
    printf("Book ID: %d not found in data.", srchid);
    return 0;
}
