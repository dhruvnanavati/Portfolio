// Dhruv Nanavati
// May 21, 2020

		.syntax		unified
		.cpu		cortex-m4
		.text

	// uint32_t Zeller1(uint32_t k, uint32_t m, uint32_t D, uint32_t C) ;
		.global		Zeller1
		.thumb_func
	Zeller1:
		PUSH    {R4-R7}
    MOV     R4,R0             //k
    MOV     R5,R1             //m
    MOV     R6,R2             //D
    MOV     R7,R3             //C
    LDR     R0,=13            //13m
    MUL     R0,R0,R5
    SUB     R0,R0,1           //13m-1
    LDR     R1,=5
    UDIV    R0,R0,R1          //R0/5
    ADD     R0,R0,R4          //k + R0 + D
    ADD     R0,R0,R6
    LDR     R1,=4             //(D/4) + (C/4)
    UDIV    R2,R6,R1
    UDIV    R1,R7,R1
    ADD     R1,R1,R2
    ADD     R0,R0,R1          //R0 + R1  Adding two sides together
    SUB     R0,R0,R7,LSL 1    //R0 - 2C
    LDR     R1,=7             //Finds the remainder of R0 / 7 and put it in R0
    SDIV    R2,R0,R1
    MLS     R0,R1,R2,R0
    CMP     R0,0              //If remainder < 0, adds 7 to remainder
    IT      LT
    ADDLT   R0,R0,R1

    POP   {R4-R7}
    BX    LR

  // uint32_t Zeller2(uint32_t k, uint32_t m, uint32_t D, uint32_t C) ;
		.global		Zeller2
		.thumb_func
	Zeller2:
    PUSH    {R4-R7}
    MOV     R4,R0           //k
    MOV     R5,R1           //m
    MOV     R6,R2           //D
    MOV     R7,R3           //C
    LDR     R0,=13          //13m
    MUL     R0,R0,R5
    SUB     R0,R0,1         //13m - 1
    LDR     R1,=858993460   //Loads (2^32)/5 rounded into R1
    SMMUL   R0,R0,R1        //Multiplies R0 and R1 to get R0/5
    ADD     R0,R0,R4        //k + R0 + D
    ADD     R0,R0,R6
    LSR     R2,R6,2         //(D/4) + (C/4)
    LSR     R1,R7,2
    ADD     R1,R1,R2
    ADD     R0,R0,R1        //R0 + R1 Adding two sides together
    SUB     R0,R0,R7,LSL 1  //R0 - 2C
    LDR     R1,=613566757   //Loads (2^32)/7 into R1
    SMMUL   R2,R0,R1        //Multiplies R0 and R1 to get R0/7
    LDR     R1,=7
    MLS     R0,R1,R2,R0     //Subtracts R2 from R1 to get remainder
    CMP     R0,0            //If remainder < 0, adds 7 to remainder
    IT      LT
    ADDLT   R0,R0,R7

    POP   {R4-R7}
		BX    LR

	// uint32_t Zeller3(uint32_t k, uint32_t m, uint32_t D, uint32_t C) ;
		.global		Zeller3
		.thumb_func
	Zeller3:
    PUSH    {R4-R7}
    MOV     R4,R0             //k
    MOV     R5,R1             //m
    MOV     R6,R2             //D
    MOV     R7,R3             //C
    LSL     R0,R5,3           //8m + 4m + m
    ADD     R0,R0,R5,LSL 2
    ADD     R0,R0,R5
    SUB     R0,R0,1           //13m - 1
    LDR     R1,=5             //(13m-1)/5
    UDIV    R0,R0,R1
    ADD     R0,R0,R4          //k + R0 + D
    ADD     R0,R0,R6
    LDR     R1,=4             //(D/4) + (C/4)
    UDIV    R2,R6,R1
    UDIV    R1,R7,R1
    ADD     R1,R1,R2
    ADD     R0,R0,R1          //R0 + R1 Adding the two sides together
    SUB     R0,R0,R7,LSL 1    //R0 - 2C
    LDR     R1,=7             //Finds the remainder of R0 / 7 and put it in R0
    SDIV    R2,R0,R1
    LSL     R3,R2,2           //4x + 2x + x
    ADD     R3,R3,R2,LSL 1
    ADD     R3,R3,R2
    SUB     R0,R0,R3
    CMP     R0,0              //If remainder < 0, adds 7 to remainder
    IT      LT
    ADDLT   R0,R0,R1

    POP     {R4-R7}

		BX      LR


		.end
