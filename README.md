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
    int* MOTOR_CTRL;
    int dummy;
    
    
        while(1) {
        // Read sensor data into x30
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
            "or %1, x30,2"                 // output at 2nd bit , that switches on the motor
            :"=r"(dummy)
            :"r"(*MOTOR_CTRL)
        );
        } 
        else {
            // If moisture is above the threshold, set the motor control register to 0 (motor off)
            dummy=0xFFFFFFFD;
            asm(
            "and x30,x30, %0\n\t"     // Load immediate 1 into x30
            "or %1, x30,0"            //// output at 2nd bit , that switches off the motor
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


drip_irrigation.o:     file format elf32-littleriscv


drip_irrigation.o:     file format elf32-littleriscv


Disassembly of section .text:

00010094 <exit>:
   10094:	ff010113          	add	sp,sp,-16
   10098:	00000593          	li	a1,0
   1009c:	00812423          	sw	s0,8(sp)
   100a0:	00112623          	sw	ra,12(sp)
   100a4:	00050413          	mv	s0,a0
   100a8:	2d4000ef          	jal	1037c <__call_exitprocs>
   100ac:	c281a503          	lw	a0,-984(gp) # 11a18 <_global_impure_ptr>
   100b0:	03c52783          	lw	a5,60(a0)
   100b4:	00078463          	beqz	a5,100bc <exit+0x28>
   100b8:	000780e7          	jalr	a5
   100bc:	00040513          	mv	a0,s0
   100c0:	4e4000ef          	jal	105a4 <_exit>

000100c4 <register_fini>:
   100c4:	00000793          	li	a5,0
   100c8:	00078863          	beqz	a5,100d8 <register_fini+0x14>
   100cc:	00010537          	lui	a0,0x10
   100d0:	49c50513          	add	a0,a0,1180 # 1049c <__libc_fini_array>
   100d4:	4240006f          	j	104f8 <atexit>
   100d8:	00008067          	ret

000100dc <_start>:
   100dc:	00002197          	auipc	gp,0x2
   100e0:	d1418193          	add	gp,gp,-748 # 11df0 <__global_pointer$>
   100e4:	c3418513          	add	a0,gp,-972 # 11a24 <completed.1>
   100e8:	c5018613          	add	a2,gp,-944 # 11a40 <__BSS_END__>
   100ec:	40a60633          	sub	a2,a2,a0
   100f0:	00000593          	li	a1,0
   100f4:	1ac000ef          	jal	102a0 <memset>
   100f8:	00000517          	auipc	a0,0x0
   100fc:	40050513          	add	a0,a0,1024 # 104f8 <atexit>
   10100:	00050863          	beqz	a0,10110 <_start+0x34>
   10104:	00000517          	auipc	a0,0x0
   10108:	39850513          	add	a0,a0,920 # 1049c <__libc_fini_array>
   1010c:	3ec000ef          	jal	104f8 <atexit>
   10110:	0f4000ef          	jal	10204 <__libc_init_array>
   10114:	00012503          	lw	a0,0(sp)
   10118:	00410593          	add	a1,sp,4
   1011c:	00000613          	li	a2,0
   10120:	06c000ef          	jal	1018c <main>
   10124:	f71ff06f          	j	10094 <exit>

00010128 <__do_global_dtors_aux>:
   10128:	ff010113          	add	sp,sp,-16
   1012c:	00812423          	sw	s0,8(sp)
   10130:	c341c783          	lbu	a5,-972(gp) # 11a24 <completed.1>
   10134:	00112623          	sw	ra,12(sp)
   10138:	02079263          	bnez	a5,1015c <__do_global_dtors_aux+0x34>
   1013c:	00000793          	li	a5,0
   10140:	00078a63          	beqz	a5,10154 <__do_global_dtors_aux+0x2c>
   10144:	00011537          	lui	a0,0x11
   10148:	5dc50513          	add	a0,a0,1500 # 115dc <__EH_FRAME_BEGIN__>
   1014c:	00000097          	auipc	ra,0x0
   10150:	000000e7          	jalr	zero # 0 <exit-0x10094>
   10154:	00100793          	li	a5,1
   10158:	c2f18a23          	sb	a5,-972(gp) # 11a24 <completed.1>
   1015c:	00c12083          	lw	ra,12(sp)
   10160:	00812403          	lw	s0,8(sp)
   10164:	01010113          	add	sp,sp,16
   10168:	00008067          	ret

0001016c <frame_dummy>:
   1016c:	00000793          	li	a5,0
   10170:	00078c63          	beqz	a5,10188 <frame_dummy+0x1c>
   10174:	00011537          	lui	a0,0x11
   10178:	c3818593          	add	a1,gp,-968 # 11a28 <object.0>
   1017c:	5dc50513          	add	a0,a0,1500 # 115dc <__EH_FRAME_BEGIN__>
   10180:	00000317          	auipc	t1,0x0
   10184:	00000067          	jr	zero # 0 <exit-0x10094>
   10188:	00008067          	ret

0001018c <main>:
   1018c:	fe010113          	add	sp,sp,-32
   10190:	00812e23          	sw	s0,28(sp)
   10194:	02010413          	add	s0,sp,32
   10198:	1f400793          	li	a5,500
   1019c:	fef42623          	sw	a5,-20(s0)
   101a0:	001f7793          	and	a5,t5,1
   101a4:	fef42423          	sw	a5,-24(s0)
   101a8:	fe842703          	lw	a4,-24(s0)
   101ac:	00100793          	li	a5,1
   101b0:	02f71263          	bne	a4,a5,101d4 <main+0x48>
   101b4:	ffd00793          	li	a5,-3
   101b8:	fef42223          	sw	a5,-28(s0)
   101bc:	fe042783          	lw	a5,-32(s0)
   101c0:	0007a783          	lw	a5,0(a5)
   101c4:	00ff7f33          	and	t5,t5,a5
   101c8:	002f6793          	or	a5,t5,2
   101cc:	fef42223          	sw	a5,-28(s0)
   101d0:	0200006f          	j	101f0 <main+0x64>
   101d4:	ffd00793          	li	a5,-3
   101d8:	fef42223          	sw	a5,-28(s0)
   101dc:	fe042783          	lw	a5,-32(s0)
   101e0:	0007a783          	lw	a5,0(a5)
   101e4:	00ff7f33          	and	t5,t5,a5
   101e8:	000f6793          	or	a5,t5,0
   101ec:	fef42223          	sw	a5,-28(s0)
   101f0:	00000793          	li	a5,0
   101f4:	00078513          	mv	a0,a5
   101f8:	01c12403          	lw	s0,28(sp)
   101fc:	02010113          	add	sp,sp,32
   10200:	00008067          	ret

00010204 <__libc_init_array>:
   10204:	ff010113          	add	sp,sp,-16
   10208:	00812423          	sw	s0,8(sp)
   1020c:	000117b7          	lui	a5,0x11
   10210:	00011437          	lui	s0,0x11
   10214:	01212023          	sw	s2,0(sp)
   10218:	5e078793          	add	a5,a5,1504 # 115e0 <__init_array_start>
   1021c:	5e040713          	add	a4,s0,1504 # 115e0 <__init_array_start>
   10220:	00112623          	sw	ra,12(sp)
   10224:	00912223          	sw	s1,4(sp)
   10228:	40e78933          	sub	s2,a5,a4
   1022c:	02e78263          	beq	a5,a4,10250 <__libc_init_array+0x4c>
   10230:	40295913          	sra	s2,s2,0x2
   10234:	5e040413          	add	s0,s0,1504
   10238:	00000493          	li	s1,0
   1023c:	00042783          	lw	a5,0(s0)
   10240:	00148493          	add	s1,s1,1
   10244:	00440413          	add	s0,s0,4
   10248:	000780e7          	jalr	a5
   1024c:	ff24e8e3          	bltu	s1,s2,1023c <__libc_init_array+0x38>
   10250:	00011437          	lui	s0,0x11
   10254:	000117b7          	lui	a5,0x11
   10258:	5e878793          	add	a5,a5,1512 # 115e8 <__do_global_dtors_aux_fini_array_entry>
   1025c:	5e040713          	add	a4,s0,1504 # 115e0 <__init_array_start>
   10260:	40e78933          	sub	s2,a5,a4
   10264:	40295913          	sra	s2,s2,0x2
   10268:	02e78063          	beq	a5,a4,10288 <__libc_init_array+0x84>
   1026c:	5e040413          	add	s0,s0,1504
   10270:	00000493          	li	s1,0
   10274:	00042783          	lw	a5,0(s0)
   10278:	00148493          	add	s1,s1,1
   1027c:	00440413          	add	s0,s0,4
   10280:	000780e7          	jalr	a5
   10284:	ff24e8e3          	bltu	s1,s2,10274 <__libc_init_array+0x70>
   10288:	00c12083          	lw	ra,12(sp)
   1028c:	00812403          	lw	s0,8(sp)
   10290:	00412483          	lw	s1,4(sp)
   10294:	00012903          	lw	s2,0(sp)
   10298:	01010113          	add	sp,sp,16
   1029c:	00008067          	ret

000102a0 <memset>:
   102a0:	00f00313          	li	t1,15
   102a4:	00050713          	mv	a4,a0
   102a8:	02c37e63          	bgeu	t1,a2,102e4 <memset+0x44>
   102ac:	00f77793          	and	a5,a4,15
   102b0:	0a079063          	bnez	a5,10350 <memset+0xb0>
   102b4:	08059263          	bnez	a1,10338 <memset+0x98>
   102b8:	ff067693          	and	a3,a2,-16
   102bc:	00f67613          	and	a2,a2,15
   102c0:	00e686b3          	add	a3,a3,a4
   102c4:	00b72023          	sw	a1,0(a4)
   102c8:	00b72223          	sw	a1,4(a4)
   102cc:	00b72423          	sw	a1,8(a4)
   102d0:	00b72623          	sw	a1,12(a4)
   102d4:	01070713          	add	a4,a4,16
   102d8:	fed766e3          	bltu	a4,a3,102c4 <memset+0x24>
   102dc:	00061463          	bnez	a2,102e4 <memset+0x44>
   102e0:	00008067          	ret
   102e4:	40c306b3          	sub	a3,t1,a2
   102e8:	00269693          	sll	a3,a3,0x2
   102ec:	00000297          	auipc	t0,0x0
   102f0:	005686b3          	add	a3,a3,t0
   102f4:	00c68067          	jr	12(a3)
   102f8:	00b70723          	sb	a1,14(a4)
   102fc:	00b706a3          	sb	a1,13(a4)
   10300:	00b70623          	sb	a1,12(a4)
   10304:	00b705a3          	sb	a1,11(a4)
   10308:	00b70523          	sb	a1,10(a4)
   1030c:	00b704a3          	sb	a1,9(a4)
   10310:	00b70423          	sb	a1,8(a4)
   10314:	00b703a3          	sb	a1,7(a4)
   10318:	00b70323          	sb	a1,6(a4)
   1031c:	00b702a3          	sb	a1,5(a4)
   10320:	00b70223          	sb	a1,4(a4)
   10324:	00b701a3          	sb	a1,3(a4)
   10328:	00b70123          	sb	a1,2(a4)
   1032c:	00b700a3          	sb	a1,1(a4)
   10330:	00b70023          	sb	a1,0(a4)
   10334:	00008067          	ret
   10338:	0ff5f593          	zext.b	a1,a1
   1033c:	00859693          	sll	a3,a1,0x8
   10340:	00d5e5b3          	or	a1,a1,a3
   10344:	01059693          	sll	a3,a1,0x10
   10348:	00d5e5b3          	or	a1,a1,a3
   1034c:	f6dff06f          	j	102b8 <memset+0x18>
   10350:	00279693          	sll	a3,a5,0x2
   10354:	00000297          	auipc	t0,0x0
   10358:	005686b3          	add	a3,a3,t0
   1035c:	00008293          	mv	t0,ra
   10360:	fa0680e7          	jalr	-96(a3)
   10364:	00028093          	mv	ra,t0
   10368:	ff078793          	add	a5,a5,-16
   1036c:	40f70733          	sub	a4,a4,a5
   10370:	00f60633          	add	a2,a2,a5
   10374:	f6c378e3          	bgeu	t1,a2,102e4 <memset+0x44>
   10378:	f3dff06f          	j	102b4 <memset+0x14>

0001037c <__call_exitprocs>:
   1037c:	fd010113          	add	sp,sp,-48
   10380:	01412c23          	sw	s4,24(sp)
   10384:	c281aa03          	lw	s4,-984(gp) # 11a18 <_global_impure_ptr>
   10388:	03212023          	sw	s2,32(sp)
   1038c:	02112623          	sw	ra,44(sp)
   10390:	148a2903          	lw	s2,328(s4)
   10394:	02812423          	sw	s0,40(sp)
   10398:	02912223          	sw	s1,36(sp)
   1039c:	01312e23          	sw	s3,28(sp)
   103a0:	01512a23          	sw	s5,20(sp)
   103a4:	01612823          	sw	s6,16(sp)
   103a8:	01712623          	sw	s7,12(sp)
   103ac:	01812423          	sw	s8,8(sp)
   103b0:	04090063          	beqz	s2,103f0 <__call_exitprocs+0x74>
   103b4:	00050b13          	mv	s6,a0
   103b8:	00058b93          	mv	s7,a1
   103bc:	00100a93          	li	s5,1
   103c0:	fff00993          	li	s3,-1
   103c4:	00492483          	lw	s1,4(s2)
   103c8:	fff48413          	add	s0,s1,-1
   103cc:	02044263          	bltz	s0,103f0 <__call_exitprocs+0x74>
   103d0:	00249493          	sll	s1,s1,0x2
   103d4:	009904b3          	add	s1,s2,s1
   103d8:	040b8463          	beqz	s7,10420 <__call_exitprocs+0xa4>
   103dc:	1044a783          	lw	a5,260(s1)
   103e0:	05778063          	beq	a5,s7,10420 <__call_exitprocs+0xa4>
   103e4:	fff40413          	add	s0,s0,-1
   103e8:	ffc48493          	add	s1,s1,-4
   103ec:	ff3416e3          	bne	s0,s3,103d8 <__call_exitprocs+0x5c>
   103f0:	02c12083          	lw	ra,44(sp)
   103f4:	02812403          	lw	s0,40(sp)
   103f8:	02412483          	lw	s1,36(sp)
   103fc:	02012903          	lw	s2,32(sp)
   10400:	01c12983          	lw	s3,28(sp)
   10404:	01812a03          	lw	s4,24(sp)
   10408:	01412a83          	lw	s5,20(sp)
   1040c:	01012b03          	lw	s6,16(sp)
   10410:	00c12b83          	lw	s7,12(sp)
   10414:	00812c03          	lw	s8,8(sp)
   10418:	03010113          	add	sp,sp,48
   1041c:	00008067          	ret
   10420:	00492783          	lw	a5,4(s2)
   10424:	0044a683          	lw	a3,4(s1)
   10428:	fff78793          	add	a5,a5,-1
   1042c:	04878e63          	beq	a5,s0,10488 <__call_exitprocs+0x10c>
   10430:	0004a223          	sw	zero,4(s1)
   10434:	fa0688e3          	beqz	a3,103e4 <__call_exitprocs+0x68>
   10438:	18892783          	lw	a5,392(s2)
   1043c:	008a9733          	sll	a4,s5,s0
   10440:	00492c03          	lw	s8,4(s2)
   10444:	00f777b3          	and	a5,a4,a5
   10448:	02079263          	bnez	a5,1046c <__call_exitprocs+0xf0>
   1044c:	000680e7          	jalr	a3
   10450:	00492703          	lw	a4,4(s2)
   10454:	148a2783          	lw	a5,328(s4)
   10458:	01871463          	bne	a4,s8,10460 <__call_exitprocs+0xe4>
   1045c:	f92784e3          	beq	a5,s2,103e4 <__call_exitprocs+0x68>
   10460:	f80788e3          	beqz	a5,103f0 <__call_exitprocs+0x74>
   10464:	00078913          	mv	s2,a5
   10468:	f5dff06f          	j	103c4 <__call_exitprocs+0x48>
   1046c:	18c92783          	lw	a5,396(s2)
   10470:	0844a583          	lw	a1,132(s1)
   10474:	00f77733          	and	a4,a4,a5
   10478:	00071c63          	bnez	a4,10490 <__call_exitprocs+0x114>
   1047c:	000b0513          	mv	a0,s6
   10480:	000680e7          	jalr	a3
   10484:	fcdff06f          	j	10450 <__call_exitprocs+0xd4>
   10488:	00892223          	sw	s0,4(s2)
   1048c:	fa9ff06f          	j	10434 <__call_exitprocs+0xb8>
   10490:	00058513          	mv	a0,a1
   10494:	000680e7          	jalr	a3
   10498:	fb9ff06f          	j	10450 <__call_exitprocs+0xd4>

0001049c <__libc_fini_array>:
   1049c:	ff010113          	add	sp,sp,-16
   104a0:	00812423          	sw	s0,8(sp)
   104a4:	000117b7          	lui	a5,0x11
   104a8:	00011437          	lui	s0,0x11
   104ac:	5e878793          	add	a5,a5,1512 # 115e8 <__do_global_dtors_aux_fini_array_entry>
   104b0:	5ec40413          	add	s0,s0,1516 # 115ec <__fini_array_end>
   104b4:	40f40433          	sub	s0,s0,a5
   104b8:	00912223          	sw	s1,4(sp)
   104bc:	00112623          	sw	ra,12(sp)
   104c0:	40245493          	sra	s1,s0,0x2
   104c4:	02048063          	beqz	s1,104e4 <__libc_fini_array+0x48>
   104c8:	ffc40413          	add	s0,s0,-4
   104cc:	00f40433          	add	s0,s0,a5
   104d0:	00042783          	lw	a5,0(s0)
   104d4:	fff48493          	add	s1,s1,-1
   104d8:	ffc40413          	add	s0,s0,-4
   104dc:	000780e7          	jalr	a5
   104e0:	fe0498e3          	bnez	s1,104d0 <__libc_fini_array+0x34>
   104e4:	00c12083          	lw	ra,12(sp)
   104e8:	00812403          	lw	s0,8(sp)
   104ec:	00412483          	lw	s1,4(sp)
   104f0:	01010113          	add	sp,sp,16
   104f4:	00008067          	ret

000104f8 <atexit>:
   104f8:	00050593          	mv	a1,a0
   104fc:	00000693          	li	a3,0
   10500:	00000613          	li	a2,0
   10504:	00000513          	li	a0,0
   10508:	0040006f          	j	1050c <__register_exitproc>

0001050c <__register_exitproc>:
   1050c:	c281a703          	lw	a4,-984(gp) # 11a18 <_global_impure_ptr>
   10510:	14872783          	lw	a5,328(a4)
   10514:	04078c63          	beqz	a5,1056c <__register_exitproc+0x60>
   10518:	0047a703          	lw	a4,4(a5)
   1051c:	01f00813          	li	a6,31
   10520:	06e84e63          	blt	a6,a4,1059c <__register_exitproc+0x90>
   10524:	00271813          	sll	a6,a4,0x2
   10528:	02050663          	beqz	a0,10554 <__register_exitproc+0x48>
   1052c:	01078333          	add	t1,a5,a6
   10530:	08c32423          	sw	a2,136(t1) # 10208 <__libc_init_array+0x4>
   10534:	1887a883          	lw	a7,392(a5)
   10538:	00100613          	li	a2,1
   1053c:	00e61633          	sll	a2,a2,a4
   10540:	00c8e8b3          	or	a7,a7,a2
   10544:	1917a423          	sw	a7,392(a5)
   10548:	10d32423          	sw	a3,264(t1)
   1054c:	00200693          	li	a3,2
   10550:	02d50463          	beq	a0,a3,10578 <__register_exitproc+0x6c>
   10554:	00170713          	add	a4,a4,1
   10558:	00e7a223          	sw	a4,4(a5)
   1055c:	010787b3          	add	a5,a5,a6
   10560:	00b7a423          	sw	a1,8(a5)
   10564:	00000513          	li	a0,0
   10568:	00008067          	ret
   1056c:	14c70793          	add	a5,a4,332
   10570:	14f72423          	sw	a5,328(a4)
   10574:	fa5ff06f          	j	10518 <__register_exitproc+0xc>
   10578:	18c7a683          	lw	a3,396(a5)
   1057c:	00170713          	add	a4,a4,1
   10580:	00e7a223          	sw	a4,4(a5)
   10584:	00c6e6b3          	or	a3,a3,a2
   10588:	18d7a623          	sw	a3,396(a5)
   1058c:	010787b3          	add	a5,a5,a6
   10590:	00b7a423          	sw	a1,8(a5)
   10594:	00000513          	li	a0,0
   10598:	00008067          	ret
   1059c:	fff00513          	li	a0,-1
   105a0:	00008067          	ret

000105a4 <_exit>:
   105a4:	05d00893          	li	a7,93
   105a8:	00000073          	ecall
   105ac:	00054463          	bltz	a0,105b4 <_exit+0x10>
   105b0:	0000006f          	j	105b0 <_exit+0xc>
   105b4:	ff010113          	add	sp,sp,-16
   105b8:	00812423          	sw	s0,8(sp)
   105bc:	00050413          	mv	s0,a0
   105c0:	00112623          	sw	ra,12(sp)
   105c4:	40800433          	neg	s0,s0
   105c8:	00c000ef          	jal	105d4 <__errno>
   105cc:	00852023          	sw	s0,0(a0)
   105d0:	0000006f          	j	105d0 <_exit+0x2c>

000105d4 <__errno>:
   105d4:	c301a503          	lw	a0,-976(gp) # 11a20 <_impure_ptr>
   105d8:	00008067          	ret

```

Number of different instructions: 11
List of unique instructions:
```
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
```

# Word of Thanks

I sciencerly thank Mr. Kunal Gosh(Founder/VSD) for helping me out to complete this flow smoothly.

## Reference

* https://github.com/The-OpenROAD-Project/OpenSTA.git
* https://github.com/kunalg123
* https://www.vsdiat.com
* https://github.com/SakethGajawada/RISCV-GNU


