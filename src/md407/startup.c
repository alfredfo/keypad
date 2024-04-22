__attribute__((naked))
__attribute__((section(".start_section")))
void _start(void) {
  __asm volatile("ldr r0, =stack_top\n");
  __asm volatile("mov sp, r0\n");
  __asm volatile("bl main \n");
  __asm volatile("b .\n");
}
