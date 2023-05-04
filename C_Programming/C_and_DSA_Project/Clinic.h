/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Clinic.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAR 24, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU GCC
 * ----------------------------------------------------------------------------------
 */

#ifndef CLINIC_H
#define CLINIC_H

/* Gender Macros */
#define MALE    'm'
#define FEMALE  'f'

/* User Mode */
#define ADMIN   'a'
#define USER    'u'

/* Number Of Password Trials */
#define NUM_OF_TRIALS   3

/* Admin Password */
#define CLINIC_ADMIN_PASSWORD   1234

/* Clinic Patient Struct */
typedef struct Clinic_Patient Clinic_Patient;
struct Clinic_Patient
{
    u8 ID;
    u8 Name[20];
    u8 Age;
    u8 Gender;
    Clinic_Patient * PointerToNextNode;
};

/* Admin Functions' Prototypes */
void Clinic_voidAddNewPatient(u8 Copy_u8ID);
void Clinic_voidEditPatientRecord(u8 Copy_u8ID);
void Clinic_voidReserveSlotWithDoctor(u8 Copy_u8ID);
void Clinic_voidCancelReservation(u8 Copy_u8ID);

/* User Functions' Prototypes */
void Clinic_voidViewPatientRecord(u8 Copy_u8ID);
void Clinic_voidViewTodaysReservations(void);

/* Search for Patient */
static void Clinic_voidSearchForPatient(u8 Copy_u8ID, Clinic_Patient ** TempPatientPtr);

/* Ente Mode */
void Clinic_voidEnterMode(u8 * Copy_u8pMode);

#endif /* CLINIC_H */