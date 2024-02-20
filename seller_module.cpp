#include <stdio.h>

// Structure to hold information about a spare parts
typedef struct {
    int code;
    char name[50];
    float price;
    char modelNumber[20]; 
} SparePart;

// Function to display the available spare parts
void displaySpareParts(SparePart parts[], int numParts) {
    printf("Available Spare Parts:\n");
    printf("Code\tName\t\tPrice\tModel Number\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < numParts; i++) {
        printf("%d\t%s\t\t%.2f\t%s\n", parts[i].code, parts[i].name, parts[i].price, parts[i].modelNumber);
    }
    printf("----------------------------------------------\n");
}

// Function to calculate the total cost of selected spare parts
float calculateTotalCost(SparePart parts[], int numParts, int codes[], int quantities[], int numSelected) {
    float totalCost = 0.0;
    for (int i = 0; i < numSelected; i++) {
        int code = codes[i];
        int quantity = quantities[i];
        
        // Find the spare part in the array
        SparePart part;
        int found = 0;
        for (int j = 0; j < numParts; j++) {
            if (parts[j].code == code) {
                part = parts[j];
                found = 1;
                break;
            }
        }
        
        // If the part is found, calculate its cost and add to the total
        if (found) {
            float partCost = part.price * quantity;
            totalCost += partCost;
            printf("%d x %s (%.2f) = %.2f\n", quantity, part.name, part.price, partCost);
        }
    }
    return totalCost;
}

int main() {
    SparePart parts[10] = {
        {101, "Spark Plug", 4000, "SP001"},
   	    {102, "Fuel Injector", 2500, "FE002"},
        {102, "Air Filter a", 800, "AF002a"},
   	    {102, "Air Filter b" , 1200, "AF002b"},
    	{102, "Air Filter c", 3000, "AF002c"},
        {103, "Oil Filter a", 1200, "OF003"},
   	    {103, "Oil Filter b", 3000, "OF003"},
        {104, "Brake Pads", 4500, "BP004"},
        {105, "Head Gasket", 4500, "HB005"},
		{106, "Fogg Light Bulbs",1800, "FL006"},
    };
    int numParts = 10;
    
    int maxSelected = 20; // Maximum number of parts a customer can select
    int codes[maxSelected];
    int quantities[maxSelected];
    int numSelected = 0;
    
    int code, quantity;
    char choice;
    
    displaySpareParts(parts, numParts);
    
    // Customer selects parts
    do {
        printf("\nEnter part code: ");
        scanf("%d", &code);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        codes[numSelected] = code;
        quantities[numSelected] = quantity;
        numSelected++;
        
        printf("Do you want to select more parts? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    // Generate receipt and calculate total cost
    printf("\n\n********** Receipt **********\n");
    float totalCost = calculateTotalCost(parts, numParts, codes, quantities, numSelected);
    printf("\nTotal Cost: %.2f\n", totalCost);
    printf("*****************************\n");
    
    return 0;
}