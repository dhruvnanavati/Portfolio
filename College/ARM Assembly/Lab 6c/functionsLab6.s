// Dhruv Nanavati
// May 14, 2020

		.syntax		unified
		.cpu		cortex-m4
		.text

	// void PutNibble(void *nibbles, uint32_t which, uint32_t value) ;
		.global		PutNibble
		.thumb_func
	PutNibble:
		LDR 		R3,=2
		UDIV		R12,R1,R3			//Divides which by 2 to find the index of the nibble byte
		LDRB		R3,[R0,R12]		//Loading the byte
		AND			R1,1					//if which is even sets which to 0, else to 1
		CMP			R1,0
		ITE			EQ
		BFIEQ		R3,R2,0,4			//stores value at the first nibble if which is even
		BFINE		R3,R2,4,4			//stores value at second nibble if which is odd
		STRB		R3,[R0,R12]		//stores byte in memory
		BX LR


	// uint32_t GetNibble(void *nibbles, uint32_t which) ;
		.global		GetNibble
		.thumb_func
	GetNibble:
		LDR 		R3,=2
		UDIV		R2,R1,R3			//Divides which by 2 to find the index of the nibble byte
		LDRB		R0,[R0,R2]		//Loading the byte
		AND			R1,1
		CMP			R1,0
		ITE			EQ
		UBFXEQ	R0,R0,0,4			//sets R0 to the first nibble
		UBFXNE	R0,R0,4,4			//sets R0 to the second nibble
		BX LR


		.end
