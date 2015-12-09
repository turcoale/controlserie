PS2 = 1; // bits 2-0  PS2:PS0: Prescaler Rate Select bits
 OPTION_REG.PS1 = 1;
 OPTION_REG.PS0 = 1;
 TMR0 = 177; // preset for timer register

 // Interrupt Registers
 INTCON = 0;           // clear the interrpt control register
 INTCON.TMR0IE = 1;        // bit5 TMR0 Overflow Interrupt Enable bit...1 = Enables the TMR0 interrupt
 INTCON.TMR0IF = 0;        // bit2 clear timer 0 interrupt flag
 INTCON.GIE = 1;           // bit7 global interrupt enable
}

/***** Inicializaciones *****/
void Ini ()
{
 LED1 = 1;
 LED2 = 0;
 LED3 = 0;
 LED4 = 0;
 LED5 = 0;
 LEA1 = 0;
 SD1 = 0;
 SD2 = 0;
 BUZ = 0;

 ContmSeg = 0;
 ContSegParada = 200;
 cont45seg = 0;

 ContFallasED1 = 0;
 ContFallasED2 = 0;
 ContFallasED3 = 0;
 ContFallasED4 = 0;
 ContFallasED5 = 0;
 ContFallasEA1 = 0;
 SegFallaED1 = 0;
 SegFallaED2 = 0;
 SegFallaED3 = 0;
 SegFallaED4 = 0;
 SegFallaED5 = 0;
 SegFallaEA1 = 0;

}

/***** INTERRUPCIONES *****/
void interrupt ()
{
 if (INTCON.TMR0IF ==1) // timer 0 interrupt flag
 { // interrupci