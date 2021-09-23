// Dhruv Nanavati
// April 16, 2020

		.syntax		unified
		.cpu		cortex-m4
		.text

	// int32_t Add(int32_t a, int32_t b);
		.global		Add
		.thumb_func
	Add:
		ADD			R0,R0,R1
		BX			LR

	// int32_t Less1(int32_t a);
		.global		Less1
		.thumb_func
	Less1:
		SUB 	R0,R0,1
		BX		LR

	// int32_t Square2x(int32_t x);
		.global		Square2x
		.thumb_func
	Square2x:
		ADD	R0,R0,R0	//Adds R0 + R0 to the R0 directory
		B		Square		//Calls Square(R0) as Unconditional Branch

	// int32_t Last(int32_t x);
		.global		Last
		.thumb_func
	Last:
		PUSH		{R4,LR}			//Pushes original R4 into stack
		MOV			R4,R0
		BL			SquareRoot	//Calls SquareRoot(R0), sets R0 to return address
		ADD			R0,R0,R4
		POP			{R4,PC}			//Recovers R4 and Returns

		.end
