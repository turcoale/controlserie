/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TIMER.C
**     Project   : controlserie
**     Processor : MC9S08SH8CPJ
**     Component : FreeCntr
**     Version   : Component 01.112, Driver 01.09, CPU db: 3.00.062
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 12/15/2015, 2:57 AM
**     Abstract  :
**         This device "FreeCntr" implements a free running counter for
**         time measurement.
**     Settings  :
**         Timer name                  : RTC (8-bit)
**         Compare name                : RTCmod
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 244 Hz
**           Period
**             Xtal ticks              : 31232
**             microseconds            : 999424
**             milliseconds            : 999
**             seconds                 : 1
**             seconds (real)          : 0.999424
**             Hz                      : 1
**           Frequency of counting (Bus clock / prescaler)
**             Hz                      : 244
**
**         Initialization:
**              Timer                  : Enabled
**
**         Timer registers
**              Counter                : RTCCNT    [$006D]
**              Mode                   : RTCSC     [$006C]
**              Run                    : RTCSC     [$006C]
**              Prescaler              : RTCSC     [$006C]
**              Compare                : RTCMOD    [$006E]
**
**         User handling procedure     : not specified
**     Contents  :
**         Reset           - byte TIMER_Reset(void);
**         GetCounterValue - byte TIMER_GetCounterValue(TIMER_TTimerValue *Value);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE TIMER. */

#include "TIMER.h"


/*** Internal macros and method prototypes ***/

/*
** ===================================================================
**     Method      :  SetCV (component FreeCntr)
**
**     Description :
**         The method computes and sets compare/modulo/reload value for 
**         time measuring.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define TIMER_SetCV(_Val) \
  (RTCMOD = (TIMER_TTimerValue)(_Val))


/*** End of Internal methods declarations ***/


/*
** ===================================================================
**     Method      :  TIMER_Reset (component FreeCntr)
**
**     Description :
**         This method resets the timer-counter (sets to zero for
**         up-counting HW or to appropriate value for down-counting HW).
**         The method is available only if the counter register can be
**         set by software and the counter is not shared.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte TIMER_Reset(word *Value)

**      This method is implemented as a macro. See header module. **
*/

/*
** ===================================================================
**     Method      :  TIMER_GetCounterValue (component FreeCntr)
**
**     Description :
**         This method returns a content of counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the returned 8-bit value.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte TIMER_GetCounterValue(TIMER_TTimerValue *Value)

**      This method is implemented as a macro. See header module. **
*/

/*
** ===================================================================
**     Method      :  TIMER_Init (component FreeCntr)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TIMER_Init(void)
{
  /* RTCSC: RTIF=0,RTCLKS=0,RTIE=0,RTCPS=0 */
  setReg8(RTCSC, 0x00);                /* Stop HW */ 
  TIMER_SetCV(0xF3);                   /* Inicialize appropriate value to the compare/modulo/reload register */
  /* RTCSC: RTIF=1,RTCLKS=2,RTIE=0,RTCPS=4 */
  setReg8(RTCSC, 0xC4);                /* Run RTC (select clock source, set frequency and enable interrupt) */ 
}

/* END TIMER. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.07 [04.34]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
