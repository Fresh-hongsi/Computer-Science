prtffmt:.asciz	"%dth 문자 = %c\n"
scffmt:	.asciz	"%s"
	.align	4
	 
	L=4 
	A=4
	.global main	
	.global	printf
	.global	scanf

main:	save	%sp,	-96,	%sp
	mov	1,	%l0
	mov	A,	%l1

 	set	scffmt,	%o0
	add	%fp,	-4,	%o1
	call	scanf
	nop
	ld	[%fp-4],	%l2
	
	
	
loop:	subcc	%l0,	L,	%g0
	bg	next_r
	nop

	set	prtffmt,	%o0
	mov	%l1,	%o1
	mov 	%l2,	%o2
	call 	printf
	nop
	
	sra	%l2,	8,	%l2
	inc	%l0
	dec	%l1
	ba 	loop
	nop
	
next_r:	ret
	restore
	
