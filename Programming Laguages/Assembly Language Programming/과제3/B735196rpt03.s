prtfmt1:	.asciz	"곱셈 할 두수를 입력하시오: "
prtfmt2:	.asciz	"두수의 곱: %u\n"
scfmt:		.asciz	"%u"
	.align 4
	L=31
	.global	main
	.global	printf
	.global	scanf

main:	save	%sp,	-96,	%sp
	mov	0,	%l0	
	mov	1,	%l1	
	mov	0,	%l2
	not	%l2,	%l2
	sll	%l2,	31,	%l2
	
	mov	0,	%l3	
	set	prtfmt1,	%o0
	call	printf
	nop

	set	scfmt,	%o0		
	add	%fp,	-4,	%o1
	call 	scanf
	nop
	ld	[%fp-4],	%l4

	set	scfmt,	%o0		
	add	%fp,	-8,	%o1
	call 	scanf
	nop
	ld	[%fp-8],	%l5
		

loop:	subcc	%l3,	L,	%g0
	bg	next_r
	nop
	ba	firIf
	nop

firIf:	and	%l5,	%l1,	%l6
	subcc	%l6,	%l1,	%g0
	bne	secIf
	nop
	add	%l0,	%l4,	%l0
	ba	secIf
	nop
	
secIf:	and	%l0,	%l1,	%l7
	subcc	%l7,	%l1,	%g0
	bne	else
	nop
	srl	%l5,	1,	%l5
	or	%l5,	%l2,	%l5
	srl	%l0,	1,	%l0
	inc	%l3
	ba	loop
	nop

else:	srl	%l5,	1,	%l5
	srl	%l0,	1,	%l0
	inc	%l3
	ba	loop
	nop

next_r:	set	prtfmt2,	%o0
	mov	%l5,	%o1
	call	printf
	nop
	ret
	restore
