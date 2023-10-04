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

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/f14f4bd1-e05b-4c84-9bdc-aab5ff83e646)


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
	asm (
            "and %0, x30, 1"
            : "=r"(sensor_value)
        );

       
        

        // Check if soil moisture is below the threshold
        if (sensor_value == 1) {
            // If moisture is below the threshold, set the motor control register to 1 (motor on)
            dummy=0xFFFFFFFD;
            asm(
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "or %0, x30,2"                 // output at 2nd bit , that switches on the motor
            :"=r"(dummy)
            :"r"(*MOTOR_CTRL)
        );
        } 
        else {
            // If moisture is above the threshold, set the motor control register to 0 (motor off)
            dummy=0xFFFFFFFD;
            asm(
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "or %0, x30,0"            //// output at 2nd bit , that switches off the motor
            :"=r"(dummy)
            :"r"(*MOTOR_CTRL)
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
  24:	02f71263          	bne	a4,a5,48 <.L2>
  28:	ffd00793          	li	a5,-3
  2c:	fef42223          	sw	a5,-28(s0)
  30:	fe042783          	lw	a5,-32(s0)
  34:	0007a783          	lw	a5,0(a5)
  38:	00ff7f33          	and	t5,t5,a5
  3c:	002f6793          	ori	a5,t5,2
  40:	fef42223          	sw	a5,-28(s0)
  44:	0200006f          	j	64 <.L3>

00000048 <.L2>:
  48:	ffd00793          	li	a5,-3
  4c:	fef42223          	sw	a5,-28(s0)
  50:	fe042783          	lw	a5,-32(s0)
  54:	0007a783          	lw	a5,0(a5)
  58:	00ff7f33          	and	t5,t5,a5
  5c:	000f6793          	ori	a5,t5,0
  60:	fef42223          	sw	a5,-28(s0)

00000064 <.L3>:
  64:	00000793          	li	a5,0
  68:	00078513          	mv	a0,a5
  6c:	01c12403          	lw	s0,28(sp)
  70:	02010113          	addi	sp,sp,32
  74:	00008067          	ret

```

Number of different instructions: 11
List of unique instructions:
and
li
sw
andi
mv
lw
addi
j
ori
ret
bne

# Word of Thanks

I sciencerly thank Mr. Kunal Gosh(Founder/VSD) for helping me out to complete this flow smoothly.

## Reference

* https://github.com/The-OpenROAD-Project/OpenSTA.git
* https://github.com/kunalg123
* https://www.vsdiat.com
* https://github.com/SakethGajawada/RISCV-GNU


