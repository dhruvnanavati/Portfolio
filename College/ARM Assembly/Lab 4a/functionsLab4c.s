//Dhruv Nanavati
//March 22, 2020

    .syntax		unified
    .cpu		cortex-m4
    .text

    .global		MxPlusB
    .thumb_func
  // int32_t MxPlusB(int32_t x, int32_t mtop, int32_t mbtm, int32_t b);
  MxPlusB:
    PUSH  {R4}        //Preserve R4
    LDR   R4,=2       //Loads constant 2 into R4
    MUL   R1,R1,R0
    MUL   R0,R1,R2    //Multiplies dvnd and dvsr and puts product in R0
    ASR   R0,31       //((dvnd*dvsr) >> 31)
    MUL   R0,R0,R2    //Multiplies R0 by dvsr
    LSL   R0,1        //R0 << 1
    ADD   R0,R0,R2    //R0 + dvsr
    SDIV  R0,R0,R4    //Divides by 2
    ADD   R0,R0,R1    //Gets quotient by adding R0 and R1
    SDIV  R0,R0,R2    //Divides quotient by dvsr
    ADD   R0,R0,R3    //R0 + R3 Adding quotient and b to get the return value
    POP   {R4}
    BX    LR



    .end
