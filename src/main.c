/*
   taken from https://github.com/dwelch67/stm32_samples/blob/master/NUCLEO-F031K6/blinker01/blinker01.c
   */
#define BASE_GPIO_ADDR (*(unsigned char *)0x40000000)
#define BASE_GPIOC_ADDR (*(unsigned char *)0x48000800)
#define BASE_GPIOB_ADD (*(unsigned char *)0x48000400)
#define RCC_ADD (*(unsigned char *)0x40021000)


// RCC ADDR 0x4002 1000 - 0x4002 13FF

// GPIOB ADDR 0x4800 0400 - 0x4800 07FF
// GPIOC ADDR 0x4800 0800 - 0x4800 0BFF

// Configuration Registers
// GPIOx_MODER
// GPIOx_OTYPER
// GPIOx_OSPEEDR
// GPIOx_PUPDR

// Data Registers
// GPIOx_IDR
// GPIOx_ODR

// Set/Reset Register
// GPIOx_BSRR

// Locking Register
// GPIOx_LCKR

// Alternate function selection registers
// GPIOx_AFRH
// GPIOx_AFRL

void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void dummy ( unsigned int );


int main(void) {
  // Initialization

  unsigned int ra;
  unsigned int rx;

  ra=GET32(RCC_ADD +0x14);
  ra|=1<<18; //enable port b
  PUT32(RCC_ADD +0x14,ra);
  //moder
  ra=GET32(BASE_GPIOB_ADD +0x00);
  ra&=~(3<<6); //PB3
  ra|=1<<6; //PB3
  PUT32(BASE_GPIOB_ADD +0x00,ra);
  //OTYPER
  ra=GET32(BASE_GPIOB_ADD +0x04);
  ra&=~(1<<3); //PB3
  PUT32(BASE_GPIOB_ADD +0x04,ra);
  //ospeedr
  ra=GET32(BASE_GPIOB_ADD +0x08);
  ra|=3<<6; //PB3
  PUT32(BASE_GPIOB_ADD +0x08,ra);
  //pupdr
  ra=GET32(BASE_GPIOB_ADD +0x0C);
  ra&=~(3<<6); //PB3
  PUT32(BASE_GPIOB_ADD +0x0C,ra);

                                                                        for(rx=0;;rx++){
    PUT32(BASE_GPIOB_ADD +0x18,(1<<3));
    for(ra=0;ra<200000;ra++) dummy(ra);
    PUT32(BASE_GPIOB_ADD +0x18,(1<<(3+16)));
    for(ra=0;ra<200000;ra++) dummy(ra);
  }
                                                                        return(0);
  while(1);
}

