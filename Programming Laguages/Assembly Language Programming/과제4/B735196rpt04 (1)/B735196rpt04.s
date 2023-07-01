prtfmt1:	.asciz	"두 정수를 입력하시오: "
prtfmt2:	.asciz	"최대공약수는 %d입니다.\n"
scfmt:		.asciz	"%d"
	

	.align 4
	.global	main
	.global	printf
	.global	scanf

main:	save	%sp,	-96,	%sp
	mov	1,	%l0			
		
	set	prtfmt1,	%o0
	call	printf
	nop

	set	scfmt,	%o0		
	add	%fp,	-4,	%o1
	call 	scanf
	nop
	ld	[%fp-4],	%l1	

	set	scfmt,	%o0		
	add	%fp,	-8,	%o1
	call 	scanf
	nop
	ld	[%fp-8],	%l2	
		

loop:	cmp	%l1,	%l2
	be	SecIf
	nop

	
	ba	FirIf
	nop

FirIf:	cmp	%l1,	%l2
	ble	FirElse
	nop

	sub	%l1,	%l2,	%l3	
	mov	%l2,	%l1
	mov	%l3,	%l2
	mov	%g0,	%l0
	
	ba	loop
	nop
	
FirElse:sub	%l2,	%l1,	%l3
	mov	%l1,	%l2
	mov	%l3,	%l1

	ba	loop
	nop


	
SecIf:	cmp	%l0,	1
	bne	SecElse
	nop
	set	prtfmt2,	%o0
	mov	%l1,	%o1
	call	printf
	nop
	ba	End
	nop

SecElse: set	prtfmt2,	%o0
	mov	%l2,	%o1
	call	printf
	nop

End: 	ret
	restore



