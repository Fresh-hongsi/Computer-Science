	.section	".data"
five:	.double	0r5.0
nine:	.double	0r9.0
thirtytwo:	.double	0r32.0
	.align	8

	.section	".text"
prtfmt01:	.asciz	"화씨 온도를 입력하시오: "
prtfmt02:	.asciz	"섭씨 온도는 %f도입니다.\n"
scfmt:	.asciz	"%lf"
	.align 4

f_s = -16
c_s= -8

	.global main

main:
	save	%sp,	-(92+16)&-8,	%sp
	mov	%g0,	%l1	!%l1은 f
	mov	%g0,	%l2	!%l2는 c
	st	%l1,	[%fp+f_s]			! f 초기화 저장
	st	%l2,	[%fp+c_s]	 		! c 초기화 저장
	
	set	prtfmt01,	%o0
	call	printf
	nop

	set	scfmt,	%o0
	add	%fp,	f_s,	%o1
	call	scanf
	nop

	ldd	[%fp+f_s],	%o0	
	call	ftoc
	nop

	std	%o0,	[%fp+c_s]
	
	set	prtfmt02,	%o0
	ld	[%fp+c_s],	%o1
	ld	[%fp+c_s+4],	%o2
	call	printf
	nop
	ret
	restore


ftoc:	save	%sp,	-(92+8)&-8,	%sp
	std	%i0,	[%fp-8]
	ldd	[%fp-8],	%f0	!%f0%f1
	
set	five,	%l0
	ldd	[%l0],	%f2

	set	nine,	%l1
	ldd	[%l1],	%f4

	set	thirtytwo,	%l2
	ldd	[%l2],	%f6

	fdivd	%f2,	%f4,	%f4
	fsubd	%f0,	%f6,	%f0

	fmuld	%f4,	%f0,	%f0
	std	%f0,	[%fp-8]
	ldd	[%fp-8],	%i0
	
	ret
	restore

	


		

