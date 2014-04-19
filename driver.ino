
#include <Arduino.h>
#include "TimerOne.h"

#include "driver.h"
#include "copilot.h"

uint8 taskDone = 1;
uint8 isrTriggered = 0;
uint8 missedTiming = 0;

void isr(void);

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  pinMode(MR_PIN_NUM, OUTPUT);
  digitalWrite(MR_PIN_NUM, LOW);
  digitalWrite(MR_PIN_NUM, HIGH);

  pinMode(OE_PIN_NUM, OUTPUT);
  digitalWrite(OE_PIN_NUM, HIGH);

  pinMode(SEROUT_PIN_NUM, OUTPUT);
  digitalWrite(SEROUT_PIN_NUM, LOW);

  pinMode(SRCLK_PIN_NUM, OUTPUT);
  digitalWrite(SRCLK_PIN_NUM, LOW);

  pinMode(STORCLK_PIN_NUM, OUTPUT);
  digitalWrite(STORCLK_PIN_NUM, LOW);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(isr);
}

void loop()
{
  if (isrTriggered)
  {
    isrTriggered = 0;
    step();
    taskDone = 1;
  }
  
  if (missedTiming)
  {
    digitalWrite(13, HIGH);
  }
}

void shiftOut(uint32 output)
{
  char shiftReg;
  char bitIndex;
  char outBit;
  char outputValue;

  //storage register low, clock low.
  CLEAR_PINS_0_7(STORCLK | SRCLK);

  for (shiftReg = 0; shiftReg < NUM_SHIFT_REGS; shiftReg++)
  {
    outputValue = output >> ((NUM_SHIFT_REGS - shiftReg - 1) * 8);

    for (bitIndex = 0; bitIndex < 8; bitIndex++)
    {
      outBit = 1 &
               (outputValue  >>
                (8 - bitIndex - 1));

      //Set serial input line.
      if (outBit)
      {
        SET_PINS_0_7(SEROUT);
      }
      else
      {
        CLEAR_PINS_0_7(SEROUT);
      }

      SET_PINS_0_7(SRCLK); //rising edge commits bit
      CLEAR_PINS_0_7(SRCLK); //go low on clock

      CLEAR_PINS_0_7(SEROUT); //from tutorial, prevents "bleed through"
    }
  }

  SET_PINS_0_7(OE);      //output off
  SET_PINS_0_7(STORCLK); //storage register commit bits
  CLEAR_PINS_0_7(OE);    //output enable
}

void isr(void)
{
  if (!taskDone)
  {
    missedTiming = 1;
  }
  isrTriggered = 1;
  taskDone = 0;
}
