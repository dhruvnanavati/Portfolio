// Dhruv Nanavati
// June 4, 2020

		.syntax		unified
		.cpu		cortex-m4
		.text

  // Q16 Q16Divide(Q16 dividend, Q16 divisor) ;
		.global		Q16Divide
		.thumb_func
	Q16Divide:
		EOR			R2,R0,R1					// R2 = sign

		EOR			R3,R0,R0,ASR 31		// if (dividend < 0) dividend = -dividend ;
		ADD			R0,R3,R0,LSR 31

		EOR			R3,R1,R1,ASR 31		// if (divisor < 0) divisor = -divisor ;
		ADD			R1,R3,R1,LSR 31

		UDIV		R3,R0,R1					// R3 = quotient
		MLS			R0,R1,R3,R0				// R0 = remainder;

		.REPT		16								// Loops 16 times
		LSL			R3,1							// quotient = quotient << 1 ;
		LSL			R0,1							// remainder = remainder << 1 ;

		CMP			R0,R1
		ITT			HS								// if (remainder >= divisor)
		SUBHS		R0,R0,R1					// remainder -= divisor ;
		ADDHS		R3,R3,1						// quotient++ ;

		.ENDR

		EOR			R0,R3,R2,ASR 31		// if (sign < 0) quotient = -quotient ;
		ADD			R0,R0,R2,LSR 31

		BX			LR
	.end
