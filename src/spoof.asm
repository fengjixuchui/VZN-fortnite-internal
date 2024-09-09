.code

RetSpoofInit proc
	movq xmm15, rcx
	ret
RetSpoofInit endp

RetSpoofStub proc
	sub  rsp, 0A0h
	push rsi
	push rdi
	push rcx
	lea  rsi, [rsp+0B8h]
	lea  rdi, [rsp+18h]
	mov  rcx, 0A0h
	rep  movsb
	pop  rcx
	pop  rdi
	pop  rsi
	push rax
	mov  rax, 01337133713371337h
	mov  [rsp+8], rax
	pop  rax
	movq rax, xmm15
	jmp  rax
RetSpoofStub endp

end