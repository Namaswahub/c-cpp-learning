#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100

struct stock {
    char name[100];
    int model_number;
    int quantity;  
    float price;
};

struct stock stocks[MAX_STOCKS];
int numStocks = 0;

// Store management income and outcome stocks
void addStock() {
    if (numStocks == MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    struct stock newStock;

    printf("Enter stock name: ");
    scanf("%99s", newStock.name);

    printf("Enter model number: ");
    scanf("%d", &newStock.model_number);

    printf("Enter quantity: ");
    scanf("%d", &newStock.quantity);

    printf("Enter price: ");
    scanf("%f", &newStock.price);

    stocks[numStocks++] = newStock;

    printf("Stock added successfully.\n");
}

void displayStocks() {
    printf("Stocks:\n");
    printf("--------------------------------------------------------\n");
    printf("Name\t\tModel number\tQuantity\tPrice\n");
    printf("--------------------------------------------------------\n");

    int i;
    for (i = 0; i < numStocks; i++) {
        printf("%s\t\t%d\t\t%d\t\t%.2f\n", stocks[i].name, stocks[i].model_number, stocks[i].quantity, stocks[i].price);
    }

    printf("--------------------------------------------------------\n");
}

// Implement other functions for updating and deleting stocks as needed.

int main() {
    int choice;

    while (1) {
        printf("\nStock Management System\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                displayStocks();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}



