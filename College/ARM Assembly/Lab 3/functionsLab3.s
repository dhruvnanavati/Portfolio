// Dhruv Nanavati
// April 23, 2020

		.syntax		unified
		.cpu		cortex-m4
		.text

	// void UseLDRB(void *dst, void *src);
		.global		UseLDRB
		.thumb_func
	UseLDRB:
    .REPT 512         //inserts 512 copies of the LRDH and STRH instructions
    LDRB  R2,[R1],1   //loads dereferenced data of R1 into R2 and increments after by 1 byte
    STRB  R2,[R0],1   //stores R2 into the dereferenced value of dst and increments after by 1 byte
    .ENDR
    BX    LR


	// void UseLDRH(void *dst, void *src);
		.global		UseLDRH
		.thumb_func
	UseLDRH:
    .REPT 256         //inserts 256 copies of the LRDH and STRH instructions
    LDRH  R2,[R1],2   //loads 2 bytes at a time
    STRH  R2,[R0],2   //stores 2 bytes at a time
    .ENDR
    BX    LR


	// void UseLDR(void *dst, void *src);
		.global		UseLDR
		.thumb_func
	UseLDR:
    .REPT 128         //inserts 128 copies
    LDR   R2,[R1],4   //loads 4 bytes at a time
    STR   R2,[R0],4   //stores 4 bytes at a time
    .ENDR
    BX    LR


	// void UseLDRD(void *dst, void *src);
		.global		UseLDRD
		.thumb_func
	UseLDRD:
    .REPT 64          //64 copies
    LDRD  R2,R3,[R1],8   //loads 8 bytes at a time
    STRD  R2,R3,[R0],8   //stores 8 bytes at a time
    .ENDR
    BX    LR


  // void UseLDM(void *dst, void *src);
		.global		UseLDM
		.thumb_func
	UseLDM:
    PUSH {R4-R9}        //protects R4-R9 registers
    .REPT 16            //16 copies of the LDMIA and STMIA instructions
    LDMIA R1!,{R2-R9}   //loads 32 bytes into R2-R9 registers and updates
    STMIA R0!,{R2-R9}   //stores the data from R2-R9 into the R0 address
    .ENDR
    POP   {R4-R9}       //restores R4-R9
    BX    LR

		.end
