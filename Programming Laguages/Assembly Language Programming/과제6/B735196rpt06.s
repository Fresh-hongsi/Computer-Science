.section ".text"
fmt1:	.asciz	">> 직원의 정보(이름, ID, 급여)를 입력하세요. <<\n"
fmt2: 	.asciz	"%d번: "
fmt3:	.asciz	"%s %s %d"
fmt4:	.asciz	"\n----------------------------------------\n"
fmt5:	.asciz	"급여가 %d만원(평균) 이상인 직원 정보 "
fmt6: 	.asciz	"\t%s,\t %d만원 \n"
fmt7:	.asciz "%s %s %d\n"
fmt8: 	.asciz "%d만원\n"
fmt9:	.asciz	"----------------------------------------\n"
	.align 4
	
	SIZE = 5
	name = 0	
	id = 12		
	aver_s = -124
	sum_s = -128
	i_s = -132
	salary = 20		
	emp = -120	!emp[5] : 24(구조체 크기) * 5(구조체 배열 크기) = 120바이트
	.global main

main:	save	%sp,	-(96+120+8)&-8,	%sp	! 12는 average, sum 위한 변수
	mov	%g0,	%l1				! %l1 -> average
	mov	%g0,	%l2				! %l2 -> sum
	st	%l1,	[%fp+aver_s]			! average 초기화 저장
	st	%l2,	[%fp+sum_s]	 		! sum 초기화 저장
	mov	emp,	%l5	! %l5는 구조체 크기 24씩 줄어드는 변수
	
	set	fmt1,	%o0
	call	printf
	nop

	ba	forInputTest	! employee[i]
	mov	%g0,	%l0	! i=0

forInputLoop: 
	set	fmt2,	%o0
	add	%l0,	1,	%o1	
	call	printf
	nop

	set	fmt3,	%o0		
	add	%fp,	%l5,	%o1	! %o1 -> employee[i].name
	add	%o1,	id,	%o2	! %o2 -> employee[i].id
	call	scanf
	add	%o1, 	salary,	%o3	! %o3 ->employee[i].salary

	add	%fp,	%l5,	%l3	
	ld	[%l3+salary],	%o4	! employee[i].salary를 load
	ld	[%fp+sum_s],	%o5	! sum 값 load
	add	%o4,	%o5,	%o5	! sum += employee[i].salary
	st	%o5,	[%fp+sum_s]	! sum 값 store

inc_i:	
	inc	%l0			! i++
	add	%l5,	24,	%l5	! 다음 employee[i] 계산

forInputTest:
	cmp	%l0,	SIZE		! i < SIZE
	bl	forInputLoop
	nop

	ld	[%fp+aver_s],	%l4	! average값 load
	ld	[%fp+sum_s],	%o0	! sum값 load
	mov	SIZE,	%o1		
	call	.div			! average = sum / SIZE
	nop

	mov	%o0,	%l4		 
	st	%l4,	[%fp+aver_s]	! average값 store	
	
	set 	fmt4,	%o0
	call	printf
	nop

	set	fmt5,	%o0
	ld	[%fp+aver_s],	%o1	! average값 load
	call	printf
	nop

	set 	fmt4,	%o0
	call	printf
	nop

	mov	emp,	%l5		! employee[0]부터 다시 접근해야하므로 %l5를 다시 세팅해줌

	ba 	secondForTest
	mov	%g0,	%l0		! i=0

secondForLoop:
	add	%fp,	%l5,	%l3	
	ld	[%l3+salary],	%l3	! employee[i].salary를 load
	ld	[%fp+aver_s],	%l4	! average값 load
	cmp	%l3,	%l4		! employee[i].salary < average면 분기
	bl	inc_2			
	nop
	
	set 	fmt6,	%o0
	add	%fp,	%l5,	%l3	
	add	%l3,	id,	%o1	! employee[i].id
	ld	[%l3+salary],	%o2	! employee[i].salary
	call	printf
	nop
inc_2:
	inc	%l0
	add	%l5,	24,	%l5	! 다음 employee[i] 계산

	
secondForTest:
	cmp	%l0,	SIZE		
	bl	secondForLoop		
	nop

	set	fmt9,	%o0
	call	printf
	nop


	ret
	restore



