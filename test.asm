.text
.addrsig_sym print_int
.addrsig_sym print_float
.addrsig_sym print_char
.addrsig_sym get_int
.addrsig_sym get_float
.addrsig_sym get_char
.globl main
main:
  addi sp, sp, -32
  sd s4, 16(sp)
  sd s3, 24(sp)
.entry:
  addi s4, sp, 12
  sw 0, 0(s4)
  li t1, 11
  addi t2, t1, 0
  addi t3, t2, 0
  addi t4, t3, 0
  addi t5, t4, 0
  addi t6, t5, 0
  sw t6, 0(s4)
  lw a3, 0(s4)
  addi a4, a3, 0
  addi a5, a4, 0
  addi s3, a5, 0
  li a0, 3
  addi a1, a0, 0
  addi a2, a1, 0
  rem a6, s3, a2
  addi a7, a6, 0
  addi t0, a7, 0
  ld s4, 16(sp)
  ld s3, 24(sp)
  mv a0, t0
  addi sp, sp, 32
  ret

.data
