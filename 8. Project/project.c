#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10
#define MAX_NAME_LENGTH 20
#define MAX_DATE_LENGTH 13

struct Customer
{
    char customerName[MAX_CUSTOMERS][MAX_NAME_LENGTH];
    char date[MAX_CUSTOMERS][MAX_DATE_LENGTH];
    int vehicleNumber[MAX_CUSTOMERS];
};

struct Customer customers;

static int slots[] = {5, 5, 20, 15};
int prices[] = {200, 150, 50, 100};
int earnings = 0;

struct Reservation
{
    char customerName[MAX_NAME_LENGTH];
    int vehicleType;
    char date[MAX_DATE_LENGTH];
};

struct Reservation reservations[MAX_CUSTOMERS];
int numReservations = 0;

struct Admin
{
    char username[20];
    char password[20];
};

struct Admin admin = {"prem", "1234"};

void print_receipt(int index, int fees)
{
    printf("\n\nHere's your receipt!\n");
    printf("***************************************\n");
    printf("************Parking receipt************\n");
    printf("\nCustomer name: %s\n", customers.customerName[index]);
    printf("Vehicle number: %d\n", customers.vehicleNumber[index]);
    printf("Parking Date: %s\n", customers.date[index]);
    printf("Parking payment: %d\n\n", fees);
    printf("***Thank you for using Parking System***\n");
    printf("**************Visit again**************\n");
    printf("***************************************\n");
}

void park_vehicle(int vehicle_type,int fees)
{
    if (slots[vehicle_type - 1] == 0)
    {
        printf("\nSorry! Parking slot is not available for this vehicle type\n");
        return;
    }

    //int fees;
    int index = slots[vehicle_type - 1] - 1;

    printf("Enter your name: ");
    scanf("%19s", customers.customerName[index]);
    printf("Enter vehicle number: ");
    scanf("%d", &customers.vehicleNumber[index]);
    printf("Enter today's date: ");
    scanf("%12s", customers.date[index]);

    switch (vehicle_type)
    {
    case 1:
        printf("Parking Fee: 200");
        fees += 200;
        break;
    case 2:
        printf("Parking Fee: 150");
        fees += 150;
        break;
    case 3:
        printf("Parking Fee: 50");
        fees += 50;
        break;
    case 4:
        printf("Parking Fee: 100");
        fees += 100;
        break;
    default:
        printf("Invalid vehicle type\n");
        return;
    }

    print_receipt(index, fees);
    slots[vehicle_type - 1]--;
}

void check_vehicle()
{
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int vehicleNumber;

    printf("\nEnter your details\n");
    printf("Enter Name: ");
    scanf("%19s", name);
    printf("Enter vehicle number: ");
    scanf("%d", &vehicleNumber);
    printf("Enter date: ");
    scanf("%12s", date);

    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        if (strcmp(name, customers.customerName[i]) == 0 &&
            vehicleNumber == customers.vehicleNumber[i] &&
            strcmp(date, customers.date[i]) == 0)
        {
            printf("\nYour vehicle is available here\n");
            return;
        }
    }
    printf("\nSorry! Your vehicle is not available here\n");
}

void check_insight(int fees)
{
    printf("\n*************Today's insight***************\n");
    printf("Total earnings: %d\n", ((5-slots[0])*200)+((5-slots[1])*150)+((20-slots[2])*50)+((15-slots[3])*100));
    printf("Total Bus parked: %d\n", 5-slots[0]);
    printf("Total Car parked: %d\n", 5-slots[1]);
    printf("Total Bike parked: %d\n", 20-slots[2]);
    printf("Total Auto parked: %d\n", 15-slots[3]);
}

void make_reservation()
{
    if (numReservations >= MAX_CUSTOMERS)
    {
        printf("\nSorry! No more reservations can be made.\n");
        return;
    }

    int vehicle_type;
    printf("\n1. Bus    2. Car    3. Bike    4. Auto\n");
    printf("Which vehicle do you want to reserve: ");
    scanf("%d", &vehicle_type);

    if (vehicle_type < 1 || vehicle_type > 4)
    {
        printf("Invalid vehicle choice\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%19s", reservations[numReservations].customerName);
    reservations[numReservations].vehicleType = vehicle_type;
    printf("Enter reservation date: ");
    scanf("%12s", reservations[numReservations].date);

    printf("Reservation successful!\n");
    numReservations++;
}

int admin_login()
{
    char username[20];
    char password[20];

    printf("Enter admin username: ");
    scanf("%19s", username);
    printf("Enter admin password: ");
    scanf("%19s", password);

    if (strcmp(username, admin.username) == 0 && strcmp(password, admin.password) == 0)
    {
        return 1; // Admin login successful
    }
    else
    {
        printf("Admin login failed\n");
        return 0; // Admin login failed
    }
}

void admin_panel(int fees)
{
    int admin_choice;

    do
    {
        printf("\nAdmin Panel\n");
        printf("Enter 1 to view today's insight\n");
        printf("Enter 2 to exit Admin Panel\n");
        printf("Please choose an option: ");
        scanf("%d", &admin_choice);

        switch (admin_choice)
        {
        case 1:
            check_insight(fees);
            break;
        case 2:
            printf("Exiting Admin Panel\n");
            break;
        default:
            printf("Invalid choice, please try again\n");
            break;
        }
    } while (admin_choice != 2);
}

int main()
{
    int choice;
    static int fees;
    printf("\n*************Welcome to  parking management system*************\n");
    printf("This is the vehicle fees chart\n");
    printf("Bus fees 200               Car fees 150\n");
    printf("Bike fees 50               Auto fees 100\n");

    do
    {
        printf("\nEnter 1 to park your vehicle\n");
        printf("Enter 2 to check your vehicle\n");
        printf("Enter 3 to make a reservation\n");
        printf("Enter 4 to access Admin Panel\n");
        printf("Enter 5 to exit\n");
        printf("Please choose any option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n1. Bus    2. Car    3. Bike    4. Auto\n");
            printf("Which vehicle do you want to park: ");
            int vehicle_type;
            scanf("%d", &vehicle_type);

            if (vehicle_type >= 1 && vehicle_type <= 4)
            {
                park_vehicle(vehicle_type,fees);
            }
            else
            {
                printf("Invalid vehicle choice\n");
            }
            break;
        case 2:
            check_vehicle();
            break;
        case 3:
            make_reservation();
            break;
        case 4:
            if (admin_login())
            {
                admin_panel(fees);
            }
            break;
        case 5:
            printf("Thank you for using our parking stand\n");
            break;
        default:
            printf("Invalid choice, please try again\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

