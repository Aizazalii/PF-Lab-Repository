#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNumber;
    char departure[50];
    char destination[50];
    char date[20];
    int seats;
};

void bookSeat(struct Flight *f) {
    if (f->seats > 0) {
        f->seats--;
        printf("Seat booked successfully!\n");
    } else {
        printf("Sorry, no seats available.\n");
    }
}

void displayFlight(struct Flight f) {
    printf("\n--- Flight Details ---\n");
    printf("Flight Number: %d\n", f.flightNumber);
    printf("From: %s\n", f.departure);
    printf("To: %s\n", f.destination);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.seats);
}

int main() {
    struct Flight f1 = {101, "Karachi", "Lahore", "20-11-2026", 5};
    int choice;

    while (1) {
        printf("\n1. Display Flight Details\n2. Book a Seat\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayFlight(f1);
        } else if (choice == 2) {
            bookSeat(&f1);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}