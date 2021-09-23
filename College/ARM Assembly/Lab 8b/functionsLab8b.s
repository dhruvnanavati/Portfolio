// Dhruv Nanavati
// May 28, 2020

		.syntax		unified
		.cpu		cortex-m4
		.text

  // float Root1(float a, float b, float c) ;
		.global		Root1
		.thumb_func
	Root1:
    PUSH        {R4,R5,LR}

    VMOV        R4,S0
    VMOV        R5,S1
    BL          Discriminant  // Calls Discriminant and return value is in S0
    VMOV        S1,R4
    VMOV        S2,R5
    VSQRT.F32   S0,S0         // sqrt(Discriminant)
    VNEG.F32    S2,S2         // -b
    VADD.F32    S0,S2,S0      // -b + sqrt(Discriminant)
    VMOV        S3,2.0
    VMUL.F32    S1,S1,S3      // 2a
    VDIV.F32    S0,S0,S1      // ( -b + sqrt(Discriminant) ) / 2a

    POP         {R4,R5,PC}


	// float Root2(float a, float b, float c) ;
		.global		Root2
		.thumb_func
	Root2:
    PUSH        {R4,R5,LR}

    VMOV        R4,S0
    VMOV        R5,S1
    BL          Discriminant  // Calls Discriminant and return value is in S0
    VMOV        S1,R4
    VMOV        S2,R5
    VSQRT.F32   S0,S0         // sqrt(Discriminant)
    VNEG.F32    S2,S2         // -b
    VSUB.F32    S0,S2,S0      // -b - sqrt(Discriminant)
    VMOV        S3,2.0
    VMUL.F32    S1,S1,S3      // 2a
    VDIV.F32    S0,S0,S1      // ( -b - sqrt(Discriminant) ) / 2a

    POP         {R4,R5,PC}


	// float Quadratic(float x, float a, float b, float c) ;
		.global		Quadratic
		.thumb_func
	Quadratic:
    VMUL.F32    S4,S0,S0    // x^2
    VMUL.F32    S4,S4,S1    // ax^2
    VMUL.F32    S2,S2,S0    // bx
    VADD.F32    S0,S4,S2    // ax^2 + bx
    VADD.F32    S0,S0,S3    // ax^2 + bx + c

    BX          LR


  // float Discriminant(float a, float b, float c) ;
		.global		Discriminant
		.thumb_func
	Discriminant:
    VMUL.F32    S1,S1,S1    // b^2
    VMOV        S3,4.0
    VMUL.F32    S0,S0,S3    // 4a
    VMUL.F32    S0,S0,S2    // 4ac
    VSUB.F32    S0,S1,S0    // b^2 - 4ac

    BX          LR

		.end
