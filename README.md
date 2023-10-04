# iiitb_riscv_drip_irrigation_system

# Project Overview

The objective of this project is to design a contactless water level indicator system for automated drip irrigation. Our focus is to implement this innovative solution using a RISC-V processor, a departure from traditional Arduino boards. The primary motivation for this endeavor is to enhance efficiency and precision in the irrigation process, particularly for applications like drip irrigation systems.

# Requirements 

The project requires very few components and the connection is also very simple. The components are listed below:

Arduino 
moisture sensor
5v relay module 
6v Mini water pump with small pipe 
Connecting wires
5v battery 

# Block Diagram

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/bcda04e7-79c9-460b-944b-07b6de727518)


# Code

```
#include <stdio.h>

// Function to monitor water level and control the buzzer
int main()  {

    int moisture_threshold=500;  // Adjust as needed
    int sensor_value;
    int* MOTOR_CTRL;
    int dummy;
    
    
        while(1) {
        // Read sensor data into x10
	asm volatile(
            "and %0, x30, 1"
            : "=r"(sensor_value)
        );

       
        

        // Check if soil moisture is below the threshold
        if (sensor_value == 1) {
            // If moisture is below the threshold, set the motor control register to 1 (motor on)
            dummy=0xFFFFFFFD;
            asm(
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "or x30, x30,2"                 // output at 2nd bit , that switches on the motor
            :"=r"(dummy)
        );
        } 
        else {
            // If moisture is above the threshold, set the motor control register to 0 (motor off)
            dummy=0xFFFFFFFD;
            asm(
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "or x30, x30,0"            //// output at 2nd bit , that switches off the motor
            :"=r"(dummy)
        );
        }

    return 0;
}

}


```

# Assembly Code

```

drip_irrigation.o:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <main>:
   0:	fe010113          	addi	sp,sp,-32
   4:	00812e23          	sw	s0,28(sp)
   8:	02010413          	addi	s0,sp,32
   c:	1f400793          	li	a5,500
  10:	fef42623          	sw	a5,-20(s0)
  14:	001f7793          	andi	a5,t5,1
  18:	fef42423          	sw	a5,-24(s0)
  1c:	fe842703          	lw	a4,-24(s0)
  20:	00100793          	li	a5,1
  24:	00f71e63          	bne	a4,a5,40 <.L2>
  28:	ffd00793          	li	a5,-3
  2c:	fef42223          	sw	a5,-28(s0)
  30:	00ff7f33          	and	t5,t5,a5
  34:	002f6f13          	ori	t5,t5,2
  38:	fef42223          	sw	a5,-28(s0)
  3c:	0180006f          	j	54 <.L3>

00000040 <.L2>:
  40:	ffd00793          	li	a5,-3
  44:	fef42223          	sw	a5,-28(s0)
  48:	00ff7f33          	and	t5,t5,a5
  4c:	000f6f13          	ori	t5,t5,0
  50:	fef42223          	sw	a5,-28(s0)

00000054 <.L3>:
  54:	00000793          	li	a5,0
  58:	00078513          	mv	a0,a5
  5c:	01c12403          	lw	s0,28(sp)
  60:	02010113          	addi	sp,sp,32
  64:	00008067          	ret

```



