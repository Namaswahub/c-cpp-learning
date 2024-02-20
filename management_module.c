#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int partNumber;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Part;

Part parts[MAX_PARTS];
int numParts = 0;

void addPart() {
    if (numParts == MAX_PARTS) {
        printf("Maximum number of parts reached.\n");
        return;
    }

    Part newPart;
    printf("Enter part number: ");
    scanf("%d", &newPart.partNumber);

    // Check if part already exists
       int i;
    for ( i = 0; i < numParts; i++) {
        if (parts[i].partNumber == newPart.partNumber) {
            printf("Part already exists.\n");
            return;
        }
    }

    printf("Enter part name: ");
    scanf("%s", newPart.name);

    printf("Enter quantity: ");
    scanf("%d", &newPart.quantity);

    printf("Enter price: ");
    scanf("%f", &newPart.price);

    parts[numParts++] = newPart;
    printf("Part added successfully.\n");
}

void sellPart() {
    int partNumber;
    printf("Enter part number to sell: ");
    scanf("%d", &partNumber);
      int i;
    for ( i = 0; i < numParts; i++) {
        if (parts[i].partNumber == partNumber) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if (parts[i].quantity < quantity) {
                printf("Insufficient quantity.\n");
                return;
            }

            parts[i].quantity -= quantity;
            printf("Sale successful.\n");
            return;
        }
    }

    printf("Part not found.\n");
}

void displayStock() {
    printf("Stock:\n");
    int i;
    for ( i = 0; i < numParts; i++) {
        printf("Part Number: %d\n", parts[i].partNumber);
        printf("Name: %s\n", parts[i].name);
        printf("Quantity: %d\n", parts[i].quantity);
        printf("Price: %.2f\n", parts[i].price);
        printf("----------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add a part\n");
        printf("2. Sell a part\n");
        printf("3. Display stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPart();
                break;
            case 2:
                sellPart();
                break;
            case 3:
                displayStock();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}