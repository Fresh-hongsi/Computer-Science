.section ".text"
fmt1:	.asciz	"Enter 5 integer number\n"
fmt2: 	.asciz	"%d"
fmt3:	.asciz	"Total = %d\n"
fmt4:	.asciz	"%d %d %d %d %d\n"
	.align 4
	
	n_s = -4
	array_s=-24	
	total_s=-28
	i_s = -32
	.global main

main:	save	%sp,	-(92+4+20+8)&-8,	%sp	
	mov	%g0,	%l0	! %l0는 i	
	mov	5,	%l1	! %l1는 n				
	mov	%g0,	%l2	! %l2는 total			
	st	%l0,	[%fp+i_s]			! i 초기화 저장
	st	%l1,	[%fp+n_s]	 		! n 초기화 저장
	st	%l2,	[%fp+total_s]			! total 초기화 저장
	
	set	fmt1,	%o0
	call	printf
	nop

	ld	[%fp+i_s],	%l0
	ld	[%fp+n_s],	%l1

	ba	forInputTest
	nop

	

forInputLoop: 
	
	set	fmt2,	%o0
	add	%fp,	array_s,	%o1
	sll	%l0,	2,	%o2
	add	%o1,	%o2,	%o1
	call	scanf
	nop
	
inc_i:	
	inc	%l0			! i++
	
forInputTest:
	
	cmp	%l0,	%l1		! i < n
	bl	forInputLoop
	nop

	ld	[%fp+n_s],	%o0
	add	%fp,	array_s,	%o1
	call	sum
	nop

	st	%o0,	[%fp+total_s]
	
	set	fmt3,	%o0
	ld	[%fp+total_s],	%o1
	call	printf
	nop

	ret
	restore

	



subTotal_s = -4
sum:	save	%sp,	-(92+4)&-8,	%sp
	mov	%i0,	%l0	!%l0은	n
	mov	%g0,	%l1	!%l1은 total
	st	%l1,	[%fp+subTotal_s]
	mov	%i1,	%l2	!%l2는 array주소값
	ba	whileSumTest
	nop

	
whileSumLoop:
	sub	%l0,	1,	%l0
	ld	[%fp+subTotal_s],	%o0
	sll	%l0,	2,	%l3
	add	%i1,	%l3,	%l4
	ld	[%l4],	%o1
	add	%o0,	%o1,	%o0
	st	%o0,	[%fp+subTotal_s]

	

whileSumTest:
	cmp	%l0,	%g0
	bg	whileSumLoop
	nop	
	
	ld	[%fp+subTotal_s],	%i0
	ret
	restore
	


