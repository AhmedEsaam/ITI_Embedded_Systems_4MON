/*
 * ----------------------------------------------------------------------------------
 * Filename     :	App.c
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

static u8 Local_u8pMode;
static u32 Local_u8pPassword;
static u8 Local_u8PatientID;

static u8 Local_u8AdminQueryNum;
static u8 Local_u8UserQueryNum;
static u8 Local_u8Counter;
    
void main(void)
{    
    /* Enter Mode */
    Clinic_voidEnterMode(&Local_u8pMode);

    while(1)
    {
        if (Local_u8pMode == ADMIN) /* Admin Mode */
        {
            if(Local_u8pPassword != CLINIC_ADMIN_PASSWORD)
            {
                /* Ask Admin To Enter Password For The Number of Trials */
                for(Local_u8Counter = 0; Local_u8Counter < NUM_OF_TRIALS; Local_u8Counter++)
                {
                    printf("\nPlease Enter Password: \t");
                    fflush(stdin);
                    scanf("%d", &Local_u8pPassword);

                    /* Check If Entered Password Is Correct */
                    if(Local_u8pPassword == CLINIC_ADMIN_PASSWORD)
                    {
                        printf("\nWelcome Admin!\n");
                        break;
                    } 
                    else
                    {
                        printf("Incorrect Password\n");
                    }
                }
            }

            /* List Admin Options */
            if(Local_u8pPassword == CLINIC_ADMIN_PASSWORD)
            {
                /* Admin Mode Activated */
                printf("\nWhat Do You Want To Do:\n");
                printf("1: Add New Patient Record\n");
                printf("2: Edit Patient Record\n");
                printf("3: Reserve A Slot With The Doctor\n");
                printf("4: Cancel Reservation\n");
                printf("u: Switch To User Mode\n");
                printf("\nPlease Enter Inquiry Number: \t");
                fflush(stdin);
                scanf("%c", &Local_u8AdminQueryNum);

                switch (Local_u8AdminQueryNum)
                {
                case '1':
                    printf("\n------------------ Adding New Patient ------------------\n");
                    printf("\nPlease Enter Patient ID: \t");
                    scanf("%d", &Local_u8PatientID);
                    Clinic_voidAddNewPatient(Local_u8PatientID);
                    printf("--------------------------------------------------------\n");
                    break;
                case '2':
                    printf("\n------------------ Edit Patient Record -----------------\n");
                    printf("\nPlease Enter Patient ID: \t");
                    scanf("%d", &Local_u8PatientID);
                    Clinic_voidEditPatientRecord(Local_u8PatientID);
                    printf("--------------------------------------------------------\n");
                    break;
                case '3':
                    printf("\n--------------- Reserve Slot With Doctor --------------\n");
                    printf("\nPlease Enter Patient ID: \t");
                    scanf("%d", &Local_u8PatientID);
                    Clinic_voidReserveSlotWithDoctor(Local_u8PatientID);
                    printf("--------------------------------------------------------\n");
                    break;
                case '4':
                    printf("\n------------------ Cancel Reservation -----------------\n");
                    printf("\nPlease Enter Patient ID: \t");
                    scanf("%d", &Local_u8PatientID);
                    Clinic_voidCancelReservation(Local_u8PatientID);
                    printf("-------------------------------------------------------\n");
                    break;
                case 'u':
                    Local_u8pMode = USER;
                    printf("\n**************************** User Mode *************************\n");
                    printf("\nWelcome User!\n");
                    Local_u8pPassword = '\0';
                    break;
                default:
                    printf("Incorrect Inquiry Number\n");
                    break;
                }
            }   
            else
            {
                /* Admin Entered Incorrect Passsword for The Number of Trials */
                printf("\nYou Entered Incorrect Password For %d Times\nThank You\n", NUM_OF_TRIALS);
                break;
            }     

        }
        else if (Local_u8pMode == USER) /* User Mode */
        {
            /* List User Options */
            printf("\nWhat Do You Want To Do:\n");
            printf("1: View Patient Record\n");
            printf("2: View Today's Reservations\n");
            printf("a: Switch To Admin Mode\n");
            printf("\nPlease Enter Inquiry Number: \t");
            fflush(stdin);
            scanf("%c", &Local_u8UserQueryNum);

            switch (Local_u8UserQueryNum)
            {
            case '1':
                printf("\n------------------ View Patient Record ------------------\n");
                /* Enter Patient ID */
                printf("Please Enter Patient ID: \t");
                fflush(stdin);
                scanf("%d", &Local_u8PatientID);
                Clinic_voidViewPatientRecord(Local_u8PatientID);
                printf("---------------------------------------------------------\n");
                break;
            case '2':
                printf("\n--------------- View Today's Reservations --------------\n");
                Clinic_voidViewTodaysReservations();
                printf("--------------------------------------------------------\n");
                break;
            case 'a':
                Local_u8pMode = ADMIN;
                printf("\n**************************** Admin Mode *************************\n");
                break;
            default:
                printf("Incorrect Inquiry Number\n");
                break;
            }
        }
        else
        {
            /* User Entered Incorrect Mode */
            printf("Incorrect Mode, Please Try Again\n");
            Clinic_voidEnterMode(&Local_u8pMode);
        }
    }
}
