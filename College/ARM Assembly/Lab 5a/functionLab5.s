// Dhruv Nanavati
// May 7, 2020

		.syntax		unified
		.cpu		cortex-m4
		.text

	// void MatrixMultiply(int32_t A[3][3], int32_t B[3][3], int32_t C[3][3]) ;
		.global		MatrixMultiply
		.thumb_func
	MatrixMultiply:
	    	PUSH	{R4-R10,LR}
				MOV		R7,R0
				MOV		R8,R1
				MOV		R9,R2


				LDR		R4,=0		//initializes the row counter
loop1:	CMP		R4,2
				BGT		L3

				LDR		R5,=0		//initializes col counter
loop2:	CMP		R5,2
				BGT		next1
				LDR		R10,=3
				MLA		R10,R4,R10,R5		//finds the index of [row][col] with row*3+col
				LDR   R1,=0
				STR		R1,[R7,R10,LSL 2]		//stores 0 in the spot a[row][col]

				LDR		R6,=0
loop3:	CMP		R6,2
				BGT		next2
				LDR		R0,[R7,R10,LSL 2]
				LDR   R2,=3
				MLA		R1,R4,R2,R6
				LDR		R1,[R8,R1,LSL 2]
				MLA		R2,R6,R2,R5
				LDR		R2,[R9,R2,LSL 2]
				BL		MultAndAdd
				STR		R0,[R7,R10,LSL 2]
				ADD		R6,R6,1
				B			loop3

next2:	ADD		R5,R5,1
				B			loop2

next1:	ADD 	R4,R4,1
				B			loop1

L3:			POP		{R4-R10,LR}
				BX		LR

		.end
