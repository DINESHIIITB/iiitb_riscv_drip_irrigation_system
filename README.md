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

### OpenLane

OpenLane is an open-source framework designed to automate the entire digital integrated circuit (IC) design process, from Register-Transfer Level (RTL) to Graphics Data System II (GDSII). It leverages various open-source tools and custom scripts to facilitate the implementation of Application-Specific Integrated Circuits (ASICs). Here's a brief overview of the key components:

OpenROAD: OpenROAD is a project that focuses on optimizing the RTL-to-GDSII design flow. It includes tools for floorplanning, placement, and detailed routing.

Yosys: Yosys is a synthesis tool that translates RTL code into a logical netlist. It is widely used for RTL synthesis and formal verification.

Magic: Magic is a VLSI layout tool used for physical design, including placement and routing. It allows designers to view and manipulate the layout of transistors and interconnections.


OpenLane integrates these tools and scripts into a cohesive automated flow, making it easier for designers to go from RTL description of the digital circuit to the final layout suitable for manufacturing. The framework is designed to be extensible and customizable, allowing users to adapt it to their specific design needs. It is particularly popular in the open-source hardware community, where it enables collaborative ASIC development.

### steps to run design:

The commands to prepare the design and overwite in a existing run folder the reports and results along with the command to include the lef files is given below:

sed -i's/max_transition   :0.04/max_transition   :0.75'*/*.lib

make mount
%./flow.tcl -interactive
% package require openlane 0.9
% prep -design project -verbose 99

### Synthesis

GTECH Mapping (Generic Technology Mapping):

Input: The starting point for logic synthesis is the Register Transfer Level (RTL) netlist, which is a high-level abstraction of the digital design described in a Hardware Description Language (HDL) like Verilog or VHDL.
Process: GTECH Mapping involves mapping the RTL netlist to a set of generic gates. These generic gates are not specific to any particular technology or manufacturing process. Instead, they represent a more abstract view of the logic functions described in the RTL.
Objective: The goal of GTECH Mapping is to create a generic representation of the design that can be further optimized and refined. Abstract Intermediate Graphs for Electronic Realization (AIGERs) and other topologies may be used during logical optimization to enhance the efficiency of the design.

Technology Mapping:

Input: The output of the GTECH Mapping phase, which is a more abstract and optimized netlist, serves as the input for the Technology Mapping step.
Process: Technology Mapping involves mapping the post-optimized GTECH netlist to standard cells that are part of a specific Process Design Kit (PDK). Standard cells are predefined, characterized, and optimized logic cells that are available in the technology library associated with a particular semiconductor manufacturing process.
Objective: The aim of Technology Mapping is to translate the generic, optimized netlist into a form that is compatible with the available technology and can be implemented using the standard cells provided by the process technology. This step is crucial for ensuring that the final design meets the physical constraints and performance requirements of the target technology.

```
run_synthesis
```

PHYSICAL DESIGN

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/deb7db69-adcc-4924-be90-448d7058d77d)

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/85069b58-0916-480c-bcc7-8127a2406f94)

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/739303b1-0c71-40fd-8480-e8f700879979)

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/addf2ac4-a503-4e45-a78b-5665a7ca4ff2)


### FLOOR PLAN

FP_CORE_UTIL: Specifies the floorplan core utilization, indicating how much of the chip's core area is utilized by the design.

FP_ASPECT_RATIO: Defines the aspect ratio of the floorplan, which is the ratio of the width to the height.

FP_CORE_MARGIN: Represents the margin area between the core (where components are placed) and the die boundary.

FP_IO_MODE: This switch defines the pin configurations. If set to 1, it indicates equidistant pin configurations; if set to 0, it indicates non-equidistant pin configurations.

FP_CORE_VMETAL and FP_CORE_HMETAL: These specify the vertical and horizontal metal layers, respectively, used in the floorplan. The note suggests that the values specified in the file are usually one less than those used in the command.

```
% run_floorplan
```
### Placement

Global Placement:

This stage aims to find an optimal position for all cells, even if the placement is not yet legal, and cells may overlap. The optimization focuses on reducing the half parameter wire length, improving overall wirelength and signal delay.

Detailed Placement:

Following global placement, the detailed placement stage adjusts the positions of cells to legalize them, ensuring that the placement adheres to the design rules and constraints. This step refines the initial placement obtained during the global placement stage.\

```
run_placement
```

### CTS



Clock tree synteshsis is used to create the clock distribution network that is used to deliver the clock to all sequential elements. The main goal is to create a network with minimal skew across the chip. H-trees are a common network topology that is used to achieve this goal.

The purpose of building a clock tree is enable the clock input to reach every element and to ensure a zero clock skew. H-tree is a common methodology followed in CTS.

Run the following command to perform CTS
```
run_cts
```
### Timing  reports

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/a1d5ebe9-c5d8-46c2-a9ac-f883a4a68dce)

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/becd6ee5-af2d-4734-9031-ec3cd4b0600c)

### Area

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/4ffe3f9f-bbba-439a-a32b-23d31a3efaea)

### Skew report
![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/4e9d0ad6-0b4b-4b0f-aa0b-3281363d1839)

### Power report

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/d19fa19a-8b9c-4505-92cd-73ec4be18fa2)

### Routing

Global Routing:

The routing region is partitioned into rectangular grids, which are represented as coarse 3D routes using the Fastroute tool.This stage provides an initial, high-level connection between standard cells, establishing a broad layout for the routing.

Detailed Routing:

Finer grids and routing guides are used in this stage to implement the physical wiring with greater precision. TritonRoute is the primary tool for detailed routing.Features of TritonRoute include honoring pre-processed route guides, assuming that each net satisfies inter-guide connectivity.TritonRoute utilizes a Mixed-Integer Linear Programming (MILP) based panel routing scheme, allowing for efficient optimization in determining the best paths.The routing process employs an intra-layer parallel and inter-layer sequential framework, optimizing the connections within individual metal layers and coordinating sequential connections across different layers.

```
% run_routing
```

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/f8d998e9-4675-4600-9136-38a93c5416b7)
 

After running the floorplan, a .def file is generated within the results/floorplan directory. The DEF (Design Exchange Format) file typically contains information about the placement of components, power rings, and other floorplan-related details.

The command provided is rewrite. However, the typical command to start Magic and load a layout file is magic. If you are already in the results/floorplan directory, you might use:
```
magic -T /home/dinesh/.volare/volare/sky130/versions/1341f54f5ce0c4955326297f235e4ace1eb6d419/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &
```

f

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/fd03abdd-2162-4740-bcf1-6de8969ffec1)

### Die Area

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/34226fd7-ff7e-47ff-8db9-9f801e27ab13)

### Core Area

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/8d573123-9068-4aa1-9c9a-3677a1008613)


### Placement

Post placement: the design can be viewed on magic within results/placement directory. Run the follwing command in that directory:
```
magic -T /home/dinesh/.volare/volare/sky130/versions/1341f54f5ce0c4955326297f235e4ace1eb6d419/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &
```

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/461bd9d8-8d0a-4013-89e7-0ed9919d35c8)


### Routing

In routing stage

Routing options can be configured in the config.tcl file, allowing for optimizations and the selection of different TritonRoute engine versions. It's important to note that there is a tradeoff between achieving an optimized route and the runtime required for routing.

Ensure that the CURRENT_DEF is set to pdn.def for the routing stage. Two routing engines are employed for the different stages:

Global Routing:
Handled by the Fast Route engine, which generates initial routing guides to establish a coarse layout.

Detailed Routing:
Utilizes the Triton Route engine, building upon the global route to implement fine-grained wiring with strategies and optimizations for finding the best paths to connect the pins.

```
magic -T /home/dinesh/.volare/volare/sky130/versions/1341f54f5ce0c4955326297f235e4ace1eb6d419/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &
```

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/798ef051-1b12-4e26-abe6-5a5b07b02dc9)

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/57928805-f803-4d05-b29e-579185ca5e6e)

here drc violations are zero

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/bdc8bd56-2f13-480e-8441-9db8268c0cd8)


### post routing timing reports

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/895ed6a7-1772-4ef2-a674-f832db9f18a9)


### post routing Area reports

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/6e9ae2e6-aa69-47e1-9fc8-29036e8be715)

### post routing power reports

![image](https://github.com/DINESHIIITB/iiitb_riscv_drip_irrigation_system/assets/140998565/aa444d72-178a-4642-b12b-039cbb8262f5)

# Word of Thanks

I sciencerly thank Mr. Kunal Gosh(Founder/VSD) for helping me out to complete this flow smoothly.

## Reference

* https://github.com/The-OpenROAD-Project/OpenSTA.git
* https://github.com/kunalg123
* https://www.vsdiat.com
* https://github.com/SakethGajawada/RISCV-GNU


