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
    int sensor_ip;
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
		"andi %0, x30, 0x01\n\t"
		: "=r" (sesensor_value)
		:
		: 
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
   10054:	fd010113          	addi	sp,sp,-48
   10058:	02812623          	sw	s0,44(sp)
   1005c:	03010413          	addi	s0,sp,48
   10060:	001f7793          	andi	a5,t5,1
   10064:	fef42623          	sw	a5,-20(s0)
   10068:	fec42703          	lw	a4,-20(s0)
   1006c:	00100793          	li	a5,1
   10070:	02f71663          	bne	a4,a5,1009c <main+0x48>
   10074:	ffd00793          	li	a5,-3
   10078:	fef42423          	sw	a5,-24(s0)
   1007c:	00100793          	li	a5,1
   10080:	fef42223          	sw	a5,-28(s0)
   10084:	fe842783          	lw	a5,-24(s0)
   10088:	00ff7f33          	and	t5,t5,a5
   1008c:	002f6f13          	ori	t5,t5,2
   10090:	000f0793          	mv	a5,t5
   10094:	fef42023          	sw	a5,-32(s0)
   10098:	fc9ff06f          	j	10060 <main+0xc>
   1009c:	ffd00793          	li	a5,-3
   100a0:	fef42423          	sw	a5,-24(s0)
   100a4:	fe042223          	sw	zero,-28(s0)
   100a8:	fe842783          	lw	a5,-24(s0)
   100ac:	00ff7f33          	and	t5,t5,a5
   100b0:	000f6f13          	ori	t5,t5,0
   100b4:	000f0793          	mv	a5,t5
   100b8:	fcf42e23          	sw	a5,-36(s0)
   100bc:	fa5ff06f          	j	10060 <main+0xc>
```

Number of different instructions: 10
List of unique instructions:
```
sw
bne
and
li
addi
andi
j
lw
ori
mv

```


![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/b417dbf5-d76a-48cd-9f71-dc9fc682def3)



### Spike Simulation

The motor should be turned on when the moisture sensor input is equal to 1. The motor should be turned off when the moisture sensor input is equal to 0. Based on the results from spike simulation, this behavior is as expected

commands
```
 riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -o out d.c
 spike pk out

```


![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/88341712-f69e-4ac9-acaa-14d096b5722d)


### Functional simulation

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/8a2e63b9-6c9c-40dd-9eb3-6eddb7fd824d)


![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/9fd7547c-2719-4423-80e0-bc7812d90242)

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/fbbdc587-29c0-4c8c-8e7f-c66fa1f1268a)


### output

In the below figure when ID_instruction is being fef42423 the output is read.The instruction sw a5, -24(s0) stores the value in register a5 to a specific memory location. 

      10078:	fef42423          	sw	a5,-24(s0)


![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/acdadb8b-6161-44fa-b5ce-f58c90736ee7)


 output value is read at the instruction "fe842783." This instruction loads the value from memory at the address located at -24(sp) and stores it in register a5. 

 10084: fe842783      lw a5, -24(sp)


![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/08ec655a-09d6-4846-a8e3-7127f011a1cc)




### Gate Level Simulation :

```

read_liberty -lib sky130_fd_sc_hd__tt_025C_1v80_256.lib 
read_verilog processor.v 
synth -top wrapper
dfflibmap -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib 
abc -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib
write_verilog synth_processor_test.v
```

command to run gls simulation

```

iverilog -o test synth_processor_test.v testbench.v sky130_sram_1kbyte_1rw1r_32x256_8.v sky130_fd_sc_hd.v primitives.v
```

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/ecccb444-7d79-4d52-a9fd-1176117a5463)


### wrapper module after netlist created

```
show wrapper
```

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/1be94917-691d-4aae-8603-e26ee64a6d6c)





# Word of Thanks

I sciencerly thank Mr. Kunal Gosh(Founder/VSD) for helping me out to complete this flow smoothly.

## Reference

* https://github.com/The-OpenROAD-Project/OpenSTA.git
* https://github.com/kunalg123
* https://www.vsdiat.com
* https://github.com/SakethGajawada/RISCV-GNU


