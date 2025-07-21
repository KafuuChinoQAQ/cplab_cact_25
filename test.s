	.text
	.file	"test.ll"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	movl	$1, -40(%rsp)
	movl	$2, -36(%rsp)
	movl	$3, -32(%rsp)
	movl	$4, -28(%rsp)
	movl	$5, -24(%rsp)
	movl	$6, -20(%rsp)
	movl	$7, -16(%rsp)
	movl	$8, -12(%rsp)
	movl	-32(%rsp), %eax
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
