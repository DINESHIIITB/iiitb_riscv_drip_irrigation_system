# iiitb_riscv_drip_irrigation_system

# Project Overview

The objective of this project is to design a contactless water level indicator system for automated drip irrigation. Our focus is to implement this innovative solution using a RISC-V processor, a departure from traditional Arduino boards. The primary motivation for this endeavor is to enhance efficiency and precision in the irrigation process, particularly for applications like drip irrigation systems.

# Requirements 

The project requires very few components and the connection is also very simple. The components are listed below:

```
RISCV  
moisture sensor
5v relay module 
6v Mini water pump with small pipe 
Connecting wires
5v battery
```

# Block Diagram

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/f14f4bd1-e05b-4c84-9bdc-aab5ff83e646)


# Code

```
// Function to monitor water level and control the buzzer
int main()  {

    int moisture_threshold=500;  // Adjust as needed
    int sensor_value;
    int MOTOR_CTRL;
    int dummy;
    
    
        while(1) {
        // Read sensor data into x30
	asm volatile(
            "and %0, x30, 1"
            : "=r"(sensor_value)
        );

       
        

        // Check if soil moisture is below the threshold
        if (sensor_value == 1) {
            // If moisture is below the threshold, set the motor control register to 1 (motor on)
            dummy=0xFFFFFFFD;
            asm volatile(
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "or x30, x30,2"                 // output at 2nd bit , that switches on the motor
            :
            :"r"(dummy)
            :"x30"
        );
        } 
        else {
            // If moisture is above the threshold, set the motor control register to 0 (motor off)
            dummy=0xFFFFFFFD;
            asm volatile( 
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "or x30, x30,0"            //// output at 2nd bit , that switches off the motor
            :
            :"r"(dummy)
            :"x30"
        );
        }

    return 0;
}

}



```

# Assembly Code

```

Disassembly of section .text:
drip_irrigation.o:     file format elf32-littleriscv


00010074 <main>:
   10074:	fe010113          	add	sp,sp,-32
   10078:	00812e23          	sw	s0,28(sp)
   1007c:	02010413          	add	s0,sp,32
   10080:	1f400793          	li	a5,500
   10084:	fef42623          	sw	a5,-20(s0)
   10088:	001f7793          	and	a5,t5,1
   1008c:	fef42423          	sw	a5,-24(s0)
   10090:	fe842703          	lw	a4,-24(s0)
   10094:	00100793          	li	a5,1
   10098:	00f71e63          	bne	a4,a5,100b4 <main+0x40>
   1009c:	ffd00793          	li	a5,-3
   100a0:	fef42223          	sw	a5,-28(s0)
   100a4:	fe442783          	lw	a5,-28(s0)
   100a8:	00ff7f33          	and	t5,t5,a5
   100ac:	002f6f13          	or	t5,t5,2
   100b0:	0180006f          	j	100c8 <main+0x54>
   100b4:	ffd00793          	li	a5,-3
   100b8:	fef42223          	sw	a5,-28(s0)
   100bc:	fe442783          	lw	a5,-28(s0)
   100c0:	00ff7f33          	and	t5,t5,a5
   100c4:	000f6f13          	or	t5,t5,0
   100c8:	00000793          	li	a5,0
   100cc:	00078513          	mv	a0,a5
   100d0:	01c12403          	lw	s0,28(sp)
   100d4:	02010113          	add	sp,sp,32
   100d8:	00008067          	ret



```

Number of different instructions: 10
List of unique instructions:
```
or
add
j
li
ret
mv
and
bne
lw
sw
```


![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/b417dbf5-d76a-48cd-9f71-dc9fc682def3)


![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/ae995d15-ed25-44b9-8121-497b6129348a)


# Word of Thanks

I sciencerly thank Mr. Kunal Gosh(Founder/VSD) for helping me out to complete this flow smoothly.

## Reference

* https://github.com/The-OpenROAD-Project/OpenSTA.git
* https://github.com/kunalg123
* https://www.vsdiat.com
* https://github.com/SakethGajawada/RISCV-GNU


