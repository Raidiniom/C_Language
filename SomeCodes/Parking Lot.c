#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef char String[50];

// Structures
typedef struct {
    int hour;
    int mins;
} Time;

typedef struct {
    char type;
    String plateNum;
    String color;
    String model;
} Vehicle;

typedef struct {
    Vehicle vehicle;
    Time timeIn;
    Time timeOut;
} ParkingInfo;

typedef struct {
    ParkingInfo *slot;
    int count;
    int max;
} ParkingArea, ParkingHistory;

// Function Prototype
Time createTime(int hour, int mins);
Vehicle createVehicle(char type, String plateNum, String color, String model);
ParkingInfo createParkingInfo(Vehicle vehicle, Time in, Time out);
ParkingHistory createParkingHistory(int max);
bool checkOutVehicle(ParkingArea *pa, ParkingHistory *ph, String plateNum);
void initParkingArea(ParkingArea *initialize, int max);
bool park(ParkingArea *pa, ParkingInfo pi, int location);
bool parkIn(ParkingArea *pa, Vehicle c, Time in, int location);
bool parkOut(ParkingArea *pa, Time in, String plateNum);
int timeDiff(Time in, Time out);
void parkingReceipt(ParkingInfo pi);
void displayParkingArea(ParkingArea parking);


// Main
int main()
{
    int garage, location;
    String serPlateNum;
    ParkingArea building;
    ParkingHistory list;

    printf("Enter the number of parkings slots: ");
    scanf("%d", &garage);

    // Doing the stuff here!
    initParkingArea(&building, garage);
    list = createParkingHistory(garage);

    displayParkingArea(building);

    printf("\n\nestacionamento? ");
    scanf("%d", &location);

    parkIn(&building, createVehicle('B', "VRLR 22", "Rose Gold Pink", "Cadillac CTS"), createTime(3, 55), location);

    displayParkingArea(building);

    printf("\n\nestacionamento? ");
    scanf("%d", &location);

    parkIn(&building, createVehicle('A', "JMG 23", "Blue", "Tucson"), createTime(4, 20), location);

    displayParkingArea(building);

    parkOut(&building, createTime(12, 20), "VRLR 22");
    parkOut(&building, createTime(7, 10), "JMG 23");

    checkOutVehicle(&building, &list, "VRLR 22");
    checkOutVehicle(&building, &list, "JMG 23");

    printf("\n\nBuilding -vvvv\n");
    displayParkingArea(building);

    printf("\n\nHistory List -vvvv\n");
    displayParkingArea(list);

    printf("\n\nPrinted Receipt/s -vvvv\n");
    for(int i = 0; i < list.count; ++i)
    {
        if(list.slot[i].vehicle.type != ' ')
        {
            parkingReceipt(list.slot[i]);
        }
    }

    return 0;
}

// Functions
Time createTime(int hour, int mins)
{
    Time initialize;

    initialize.hour = hour;
    initialize.mins = mins;

    return initialize;
}

Vehicle createVehicle(char type, String plateNum, String color, String model)
{
    Vehicle initialize;

    initialize.type = type;
    strcpy(initialize.plateNum, plateNum);
    strcpy(initialize.color, color);
    strcpy(initialize.model, model);

    return initialize;
}

ParkingInfo createParkingInfo(Vehicle vehicle, Time in, Time out)
{
    ParkingInfo initialize;

    initialize.vehicle = vehicle;
    initialize.timeIn = in;
    initialize.timeOut = out;

    return initialize;
}

ParkingHistory createParkingHistory(int max)
{
    ParkingHistory initialize;

    initialize.count = 0;
    initialize.max = max;
    initialize.slot = malloc(sizeof(ParkingInfo) * max);

    return initialize;
}

void initParkingArea(ParkingArea *pa, int max)
{
    pa->count = 0;
    pa->max = max;
    pa->slot = malloc(sizeof(ParkingInfo) * max);

    for(int i = 0; i < max; ++i)
    {
        pa->slot[i] = createParkingInfo(createVehicle(' ', "", "", ""), createTime(0, 0), createTime(0, 0));
    }
}

bool park(ParkingArea *pa, ParkingInfo pi, int location)
{
    if(toupper(pa->slot[location].vehicle.type) == ' ')
    {
        pa->slot[location] = pi;
        return true;
    }
    else
    {
        return false;
    }
}

bool parkIn(ParkingArea *pa, Vehicle c, Time in, int location)
{
    if(toupper(pa->slot[location].vehicle.type) == ' ')
    {
        pa->slot[location] = createParkingInfo(c, in, createTime(0, 0));
        return true;
    }
    else
    {
        return false;
    }
}

bool parkOut(ParkingArea *pa, Time out, String plateNum)
{
    for(int i = 0; i < pa->max; ++i)
    {
        if(strcmp(pa->slot[i].vehicle.plateNum, plateNum) == 0)
        {
            if(pa->slot[i].vehicle.type != ' ')
            {
                pa->slot[i].timeOut = out;
                return true;
            }
        }
    }
    return false;
}

int timeDiff(Time in, Time out)
{
    return (out.hour - in.hour);
}

bool checkOutVehicle(ParkingArea *pa, ParkingHistory *ph, String plateNum)
{
    for(int i = 0; i < ph->max; ++i)
    {
        if(strcmp(pa->slot[i].vehicle.plateNum, plateNum) == 0)
        {
            ph->slot[(ph->count)++] = pa->slot[i];
            pa->slot[i] = createParkingInfo(createVehicle(' ', "", "", ""), createTime(0, 0), createTime(0, 0));
            return true;
        }
    }
    return false;
}

void parkingReceipt(ParkingInfo pi)
{
    int firstfee = 0, hoursparked = timeDiff(pi.timeIn, pi.timeOut), additionalfee = 0, totalfee = 0;
    printf("\n\nParking Receipt\n");
    printf("TYPE: %c\n", pi.vehicle.type);
    printf("VEHICLE: %s - %s - %s\n", pi.vehicle.plateNum, pi.vehicle.color, pi.vehicle.model);
    printf("TIME IN: %d : %d\n", pi.timeIn.hour, pi.timeIn.mins);
    printf("TIME OUT: %d : %d\n", pi.timeOut.hour, pi.timeOut.mins);
    printf("TOTAL TIME: %d hours\n", hoursparked);

    if(toupper(pi.vehicle.type) == 'A')
    {
        firstfee = 30;
    }
    else if(toupper(pi.vehicle.type) == 'B')
    {
        firstfee = 40;
    }
    else if(toupper(pi.vehicle.type) == 'C')
    {
        firstfee = 100;
    }

    printf("Initial Charge(first 3 hours): Php%d.00\n", firstfee);


    if(hoursparked > 3)
    {
        additionalfee = (5 * (hoursparked - 3));
    }
    else
    {
        additionalfee = 0;
    }

    printf("Additional Charge: Php%d.00\n", additionalfee);

    totalfee = firstfee + additionalfee;

    printf("Total Charge: Php%d.00\n", totalfee);
}

void displayParkingArea(ParkingArea parking)
{
    printf("%10s | %s | %s | %s\n", "Slot #", "Status", "Time In", "Time Out");
    for(int i = 0; i < parking.max; ++i)
    {
        if(parking.slot[i].vehicle.type != ' ')
        {
            printf("%5s %d%4s| %s - %s - %s | %d : %d | %d : %d\n", "", i, "", parking.slot[i].vehicle.plateNum, parking.slot[i].vehicle.color, parking.slot[i].vehicle.model, parking.slot[i].timeIn.hour, parking.slot[i].timeIn.mins, parking.slot[i].timeOut.hour, parking.slot[i].timeOut.mins);
        }
        else
        {
            printf("%5s %d%4s| available\n", "", i, "");
        }
    }
}
