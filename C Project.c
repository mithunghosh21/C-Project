#include <stdio.h>

int main() {
    int arr[75];
    int s = 0;
    int choice;



    while (1) {
        printf("Menu:\n");
        printf("1. Input value\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Sort(Ascending/Descending)\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1: {
                printf("Enter the size(1-75): ");
                scanf("%d", &s);
                if (s <= 0 || s > 75) {
                    printf("Invalid size.\n");
                    s = 0;
                    break;
                }
                printf("Enter %d values:\n", s);
                for (int i= 0; i< s; i++) {
                    printf("Value %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }


            case 2: {
                if (s == 0) {
                    printf("Array is not initialized.\n");
                    break;
                }
                int i;
                printf("Enter the index to update (0 to %d): ", s-1);
                scanf("%d", &i);
                if (i >= 0 && i < s) {
                    printf("Enter the new value: ");
                    scanf("%d", &arr[i]);
                    printf("Index %d updated.\n", i);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }


            case 3: {
                if (s == 0) {
                    printf("Array is not initialized.\n");
                    break;
                }
                int x;
                printf("Enter value to delete: ");
                scanf("%d", &x);
                int found = 0;
                for (int i= 0; i< s; i++) {
                    if (arr[i] == x) {
                        for (int j = i; j < s - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        s--;
                        found = 1;
                        printf("Value %d deleted.\n", x);
                        break;
                    }
                }
                if (!found) {
                    printf("Value not found.\n");
                }
                break;
            }


            case 4: {
                if (s == 0) {
                    printf("Array is not initialized.\n");
                    break;
                }
                printf("Array elements: ");
                for (int i= 0; i< s; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }


            case 5: {
                if (s == 0) {
                    printf("Array is not initialized.\n");
                    break;
                }
                char m;
                printf("Enter A for Ascending or D for Descending: ");
                scanf(" %c", &m);
                if (m != 'A' && m != 'a' && m != 'D' && m != 'd') {
                    printf("Invalid option. Use A or D.\n");
                    break;
                }
                for (int i= 0; i< s-1; i++) {
                    for (int j= i+1; j< s; j++) {
                        if ((m == 'A' || m == 'a') && arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        } else if ((m == 'D' || m == 'd') && arr[i] < arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Array sorted %s.\n", (m == 'A' || m == 'a') ? "ascending" : "descending");
                break;
            }


            case 6: {
                if (s == 0) {
                    printf("Array is not initialized.\n");
                    break;
                }
                int n;
                printf("Enter value to search: ");
                scanf("%d", &n);
                int indices[100], count = 0;
                for (int i= 0; i< s; i++) {
                    if (arr[i] == n) {
                        indices[count++] = i;
                    }
                }
                if (count == 0) {
                    printf("Value %d not found.\n", n);
                } else if (count == 1) {
                    printf("Value %d found at index %d.\n", n, indices[0]);
                } else {
                    printf("Value %d found at %d indices: ", n, count);
                    for (int i= 0; i< count; i++) {
                        printf("%d ", indices[i]);
                    }
                    printf("Enter the index number to select: ");
                    int selected;
                    scanf("%d", &selected);
                    int valid = 0;
                    for (int i= 0; i< count; i++) {
                        if (indices[i] == selected) {
                            printf("Selected value %d at index %d.\n", n, selected);
                            valid = 1;
                            break;
                        }
                    }
                    if (!valid) {
                        printf("Invalid index selected.\n");
                    }
                }
                break;
            }


            case 7: {
                printf("Program Stoped\n");
                return 0;
            }


            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}
