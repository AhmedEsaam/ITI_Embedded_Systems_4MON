/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Clinic.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAR 24, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIB/STD_TYPES.h"
#include "Clinic.h"

Clinic_Patient * HEAD   = NULL;
Clinic_Patient * TOP    = NULL;

u8 Clinic_u8Reservations[5] = {0};

void Clinic_voidAddNewPatient(u8 Copy_u8ID)
{
    /* Check if ID Already Exists */
    Clinic_Patient * TempPatient;
    Clinic_voidSearchForPatient(Copy_u8ID, &TempPatient);

    if(TempPatient != NULL) /* ID Exists */
    {
        printf("ID Already Exists\n");
    }
    else
    {
        /* Declare And Reserve A New Node Pointer To Struct */
        Clinic_Patient *Local_pNewPatient = (Clinic_Patient *)malloc(sizeof(Clinic_Patient));
        /* Filling New Patient's Information */
        Local_pNewPatient -> ID = Copy_u8ID;
        printf("Please Enter Patient Name: \t");
        scanf("%s", &(Local_pNewPatient -> Name));
        printf("Please Enter Patient Age: \t");
        scanf("%d", &(Local_pNewPatient -> Age));
        printf("Please Enter Patient Gender ('m': Male, 'f': Female): ");
        fflush(stdin);
        scanf("%c", &(Local_pNewPatient -> Gender));
        
        Local_pNewPatient -> PointerToNextNode = NULL;

        if (HEAD == NULL)
        {
            /* HEAD And TOP Pointers Point To The First Created Node */
            HEAD = Local_pNewPatient;
            TOP = Local_pNewPatient;
        }
        else
        {
            /* TOP Node Pointer To Next Node Points To The Created Node */
            TOP -> PointerToNextNode = Local_pNewPatient;
            /* TOP Points To The Created Node*/
            TOP = Local_pNewPatient;
        }

        printf("\nPatient Added Successfully\n");
    }
}

void Clinic_voidEditPatientRecord(u8 Copy_u8ID)
{
    /* Check if ID already Exists */
    Clinic_Patient * TempPatient;
    Clinic_voidSearchForPatient(Copy_u8ID, &TempPatient);

    if(TempPatient == NULL)
    {
        printf("Incorrect ID\n");
    }
    else
    {
        /* Filling New Patient's Information */
        printf("Please Enter Patient Name: \t");
        scanf("%s", &(TempPatient -> Name));
        printf("Please Enter Patient Age: \t");
        scanf("%d", &(TempPatient -> Age));
        printf("Please Enter Patient Gender ('M': Male, 'F': Female): ");
        fflush(stdin);
        scanf("%c", &(TempPatient -> Gender));

        printf("\nPatient Record Edited Successfully.\n");
    }
}

const u8 *Clinic_u8Slots[5] = 
{
    "2 PM - 2:30 PM", 
    "2:30 PM - 3 PM", 
    "3 PM - 3:30 PM", 
    "4 PM - 4:30 PM", 
    "4:30 PM - 5 PM" 
};

void Clinic_voidReserveSlotWithDoctor(u8 Copy_u8ID)
{
    /* Check if ID already Exists */
    Clinic_Patient * TempPatient;
    Clinic_voidSearchForPatient(Copy_u8ID, &TempPatient);

    if(TempPatient == NULL)
    {
        printf("Incorrect ID\n");
    }
    else
    {
        /* Print Available Solts */
        printf("Today's Available Slots: \n");
        u8 Local_u8Counter, Local_u8NoAvailableSlotsFlag = 1;
        for(Local_u8Counter = 0; Local_u8Counter < 5; Local_u8Counter++)
        {
            /* Check if Slot is Empty */
            if(Clinic_u8Reservations[Local_u8Counter] == 0)
            {
                printf("%d: [%s]\n", Local_u8Counter, Clinic_u8Slots[Local_u8Counter]);
                Local_u8NoAvailableSlotsFlag = 0;
            }
            else
            {
                /* Do Nothing */
            }
        }
        if(Local_u8NoAvailableSlotsFlag) /* No Available Solts */
        {
            printf("Sorry, No Available Slots\n");
        }
        else
        {
            /* Enter Slot Number From Available Solts */
            u8 Local_u8SlotNum;
            printf("Please Enter Slot Number: \t");
            fflush(stdin);
            scanf("%d", &Local_u8SlotNum);
            /* Check if Entered Slot Number > Slots Available */
            if(Local_u8SlotNum > 4)
            {
                printf("\nIncorrect Slot Number\n");
            }
            else
            {
                /* Reserve Slot With Doctor With Patient ID Attached To It */
                Clinic_u8Reservations[Local_u8SlotNum] = Copy_u8ID;
                printf("\nReservation Done Successfully.\n");
            }
        }
    }
}

void Clinic_voidCancelReservation(u8 Copy_u8ID)
{
    /* Check if ID already Exists */
    Clinic_Patient * TempPatient;
    Clinic_voidSearchForPatient(Copy_u8ID, &TempPatient);

    if(TempPatient == NULL)
    {
        printf("Incorrect ID\n");
    }
    else
    {
        /* Cancel Reservation */
        u8 Local_u8Counter;
        for(Local_u8Counter = 0; Local_u8Counter < 5; Local_u8Counter++)
        {
            /* Search For Patient ID in Today's Reservations */
            if(Clinic_u8Reservations[Local_u8Counter] == Copy_u8ID)
            {
                /* Cancel Reservation By Putting Zero in The Reservation Array */
                Clinic_u8Reservations[Local_u8Counter] = 0;
                printf("\nReservation Cancelled Successfully.\n");
                return;
            }
        }
        /* No Reservation Found For This ID */
        printf("\nNo Reservation For This Patient ID\n");
    }
}

void Clinic_voidViewPatientRecord(u8 Copy_u8ID)
{
    /* Check if ID already Exists */
    Clinic_Patient * TempPatient;
    Clinic_voidSearchForPatient(Copy_u8ID, &TempPatient);

    if(TempPatient == NULL)
    {
        printf("Incorrect ID\n");
    }
    else
    {
        /* Print Patient Record */
        printf("\nPatient ID: \t%d\n", TempPatient -> ID);
        printf("Patient Name: \t%s\n", TempPatient -> Name);
        printf("Patient Age: \t%d\n", TempPatient -> Age);
        printf("Patient Gender:\t%s\n", ((TempPatient -> Gender) == MALE)? "Male" : "Female");
    }
}

void Clinic_voidViewTodaysReservations(void)
{
    /* Print Today's reservations */
    printf("Today's Reservations: \n");
    u8 Local_u8Counter;
    for(Local_u8Counter = 0; Local_u8Counter < 5; Local_u8Counter++)
    {
        /* Prit Slot */
        printf("[%s] : ", Clinic_u8Slots[Local_u8Counter]);
        if(Clinic_u8Reservations[Local_u8Counter] != 0)
        {
            /* Print Patient ID Attached To This Slot In The Reservation */
            printf("ID %d\n", Clinic_u8Reservations[Local_u8Counter]);
        }
        else
        {
            /* State That This Slot Is Available For Reservation */
            printf("Available\n");
        }
    }
}

static void Clinic_voidSearchForPatient(u8 Copy_u8ID, Clinic_Patient ** TempPatientPtr)
{
    /* MDeclare Temp Patient Pounter To Struct*/
    Clinic_Patient * TempPatient;
    TempPatient = HEAD;

    /* Loop Till Reach The Searched Node */
    while((TempPatient != NULL) && (TempPatient -> ID != Copy_u8ID))
    {
        TempPatient = TempPatient -> PointerToNextNode;
    }
    
    /* Check If ID Does Not Exist Or Pointer Is NULL */
    if ((TempPatient == NULL) || (TempPatient -> ID != Copy_u8ID))
    {
        *TempPatientPtr = NULL;
    }
    else
    {
        /* Return Pointer To The Searched Patient Struct Node */
        *TempPatientPtr = TempPatient;
    }
}

void Clinic_voidEnterMode(u8 * Copy_u8pMode)
{
    /* Enter Mode */
    printf("\nPlease Enter Mode (a: Admin / u: User): ");
    fflush(stdin);
    scanf("%c", Copy_u8pMode);
    if (*Copy_u8pMode == ADMIN)
    {
        printf("\n**************************** Admin Mode *************************\n");
    }
    else if(*Copy_u8pMode == USER)
    {
        printf("\n***************************** User Mode *************************\n");
        printf("\nWelcome User!\n");

    }
}

