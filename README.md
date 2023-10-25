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
// #include<stdio.h>
int main()  {

    int sensor_value;
    int motor;
    int dummy;
    int i;
    int rain_sensor_ip;
    int test,test1;
    
    
        //for (int j=0; j<15;j++) 
        while(1){
        
	/*
       if(j<10)
			sensor_value=1;
	else
			sensor_value=0;
			*/

		asm volatile(
		"or x30, x30, %1\n\t"
		"andi %0, x30, 0x01\n\t"
		: "=r" (rain_sensor_ip)
		: "r" (sensor_value)
		: "x30"
		);
	

 
       
        if (sensor_value == 1) {
            // If moisture is below the threshold, set the motor control register to 1 (motor on)
            dummy=0xFFFFFFFD;
          //  printf("water \n");
          motor = 1; 
       
            asm volatile(
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "ori x30, x30,2"                 // output at 2nd bit , that switches on the motor
            :
            :"r"(dummy)
            :"x30"
            );
            asm volatile(
	    	"addi %0, x30, 0\n\t"
	    	:"=r"(test)
	    	:
	    	:"x30"
	    	);
    	printf("Test = %d\n",test);
            
      
        } 
        else {
            // If moisture is above the threshold, set the motor control register to 0 (motor off)
            dummy=0xFFFFFFFD;
             motor = 0; 
          //  printf("no watre \n ");
            asm volatile( 
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "ori x30, x30,0"            //// output at 2nd bit , that switches off the motor
            :
            :"r"(dummy)
            :"x30"
        );
        asm volatile(
	    	"addi %0, x30, 0\n\t"
	    	:"=r"(test1)
	    	:
	    	:"x30"
	    	);
	 printf("Test = %d\n",test1);
        }

  printf("motor=%d \n", motor);   
}


return 0;
}





```

# Assembly Code

```

out:     file format elf32-littleriscv


Disassembly of section .text:

00010054 <main>:
   10054:	fe010113          	addi	sp,sp,-32
   10058:	00812e23          	sw	s0,28(sp)
   1005c:	02010413          	addi	s0,sp,32
   10060:	1f400793          	li	a5,500
   10064:	fef42623          	sw	a5,-20(s0)
   10068:	001f7793          	andi	a5,t5,1
   1006c:	fef42423          	sw	a5,-24(s0)
   10070:	fe842703          	lw	a4,-24(s0)
   10074:	00100793          	li	a5,1
   10078:	00f71e63          	bne	a4,a5,10094 <main+0x40>
   1007c:	ffd00793          	li	a5,-3
   10080:	fef42223          	sw	a5,-28(s0)
   10084:	fe442783          	lw	a5,-28(s0)
   10088:	00ff7f33          	and	t5,t5,a5
   1008c:	002f6f13          	ori	t5,t5,2
   10090:	0180006f          	j	100a8 <main+0x54>
   10094:	ffd00793          	li	a5,-3
   10098:	fef42223          	sw	a5,-28(s0)
   1009c:	fe442783          	lw	a5,-28(s0)
   100a0:	00ff7f33          	and	t5,t5,a5
   100a4:	000f6f13          	ori	t5,t5,0
   100a8:	00000793          	li	a5,0
   100ac:	00078513          	mv	a0,a5
   100b0:	01c12403          	lw	s0,28(sp)
   100b4:	02010113          	addi	sp,sp,32
   100b8:	00008067          	ret

```

Number of different instructions: 10
List of unique instructions:
```
ori
addi
j
li
ret
mv
andi
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


