#ifndef RCC_INT_H
#define RCC_INT_H



#define  RCC_AHP1     0
#define  RCC_AHP2     1
#define  RCC_APB1     2
#define  RCC_APB2     3

#define     RCC_GPIOA       0
#define     RCC_GPIOB       1
#define     RCC_GPIOC       2

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusID , u8 Copy_u8PeriphralID);
void MRCC_voidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PeriphralID);


#endif
