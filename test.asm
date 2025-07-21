.text
.addrsig_sym print_int
.addrsig_sym print_float
.addrsig_sym print_char
.addrsig_sym get_int
.addrsig_sym get_float
.addrsig_sym get_char
.globl main
main:
  addi sp, sp, -80
  sd s8, 32(sp)
  sd s9, 24(sp)
  sd s7, 40(sp)
  sd s6, 48(sp)
  sd s5, 56(sp)
  sd s4, 64(sp)
  sd s3, 72(sp)
.entry:
  addi s9, sp, 4
  addi s6, sp, 12
  addi s8, sp, 8
  addi s5, sp, 20
  addi s4, sp, 16
  sw 0, 0(s9)
  sw 8, 0(s6)
  sw 12, 0(s8)
  lw t2, 0(s6)
  addi t3, t2, 0
  addi t4, t3, 0
  addi t5, t4, 0
  addi s7, t5, 0
  lw a6, 0(s8)
  addi a7, a6, 0
  addi t0, a7, 0
  addi t1, t0, 0
  add t6, t1, s7
  addi s3, t6, 0
  sw s3, 0(s9)
  lw a0, 0(s9)
  addi a1, a0, 0
  addi a2, a1, 0
  addi a3, a2, 0
  addi a4, a3, 0
  addi a5, a4, 0
  ld s8, 32(sp)
  ld s9, 24(sp)
  ld s7, 40(sp)
  ld s6, 48(sp)
  ld s5, 56(sp)
  ld s4, 64(sp)
  ld s3, 72(sp)
  mv a0, a5
  addi sp, sp, 80
  ret

.data
