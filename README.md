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
int soilMoistureValue = 0;
int percentage=0;
void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}
void loop() {
soilMoistureValue = analogRead(A0);
Serial.println(percentage);
percentage = map(soilMoistureValue, 490, 1023, 100, 0);
if(percentage < 10)  
{
  Serial.println(" pump on");
  digitalWrite(3,LOW);
}
if(percentage >80)
{
  Serial.println("pump off");
  digitalWrite(3,HIGH);
}
}

```

# Assembly Code

```
Disassembly of section .text:

00000000000100b0 <register_fini>:
   100b0:	ffff0797          	auipc	a5,0xffff0
   100b4:	f5078793          	addi	a5,a5,-176 # 0 <register_fini-0x100b0>
   100b8:	c791                	beqz	a5,100c4 <register_fini+0x14>
   100ba:	00000517          	auipc	a0,0x0
   100be:	0e250513          	addi	a0,a0,226 # 1019c <__libc_fini_array>
   100c2:	a845                	j	10172 <atexit>
   100c4:	8082                	ret

00000000000100c6 <_start>:
   100c6:	00002197          	auipc	gp,0x2
   100ca:	bb218193          	addi	gp,gp,-1102 # 11c78 <__global_pointer$>
   100ce:	f6018513          	addi	a0,gp,-160 # 11bd8 <_edata>
   100d2:	f9818613          	addi	a2,gp,-104 # 11c10 <__BSS_END__>
   100d6:	8e09                	sub	a2,a2,a0
   100d8:	4581                	li	a1,0
   100da:	164000ef          	jal	ra,1023e <memset>
   100de:	00000517          	auipc	a0,0x0
   100e2:	0be50513          	addi	a0,a0,190 # 1019c <__libc_fini_array>
   100e6:	08c000ef          	jal	ra,10172 <atexit>
   100ea:	0ea000ef          	jal	ra,101d4 <__libc_init_array>
   100ee:	4502                	lw	a0,0(sp)
   100f0:	002c                	addi	a1,sp,8
   100f2:	4601                	li	a2,0
   100f4:	070000ef          	jal	ra,10164 <main>
   100f8:	a051                	j	1017c <exit>

00000000000100fa <__do_global_dtors_aux>:
   100fa:	f601c783          	lbu	a5,-160(gp) # 11bd8 <_edata>
   100fe:	eb95                	bnez	a5,10132 <__do_global_dtors_aux+0x38>
   10100:	ffff0797          	auipc	a5,0xffff0
   10104:	f0078793          	addi	a5,a5,-256 # 0 <register_fini-0x100b0>
   10108:	c38d                	beqz	a5,1012a <__do_global_dtors_aux+0x30>
   1010a:	1141                	addi	sp,sp,-16
   1010c:	00001517          	auipc	a0,0x1
   10110:	34c50513          	addi	a0,a0,844 # 11458 <__FRAME_END__>
   10114:	e406                	sd	ra,8(sp)
   10116:	00000097          	auipc	ra,0x0
   1011a:	000000e7          	jalr	zero # 0 <register_fini-0x100b0>
   1011e:	60a2                	ld	ra,8(sp)
   10120:	4785                	li	a5,1
   10122:	f6f18023          	sb	a5,-160(gp) # 11bd8 <_edata>
   10126:	0141                	addi	sp,sp,16
   10128:	8082                	ret
   1012a:	4785                	li	a5,1
   1012c:	f6f18023          	sb	a5,-160(gp) # 11bd8 <_edata>
   10130:	8082                	ret
   10132:	8082                	ret

0000000000010134 <frame_dummy>:
   10134:	ffff0797          	auipc	a5,0xffff0
   10138:	ecc78793          	addi	a5,a5,-308 # 0 <register_fini-0x100b0>
   1013c:	cb99                	beqz	a5,10152 <frame_dummy+0x1e>
   1013e:	f6818593          	addi	a1,gp,-152 # 11be0 <object.5475>
   10142:	00001517          	auipc	a0,0x1
   10146:	31650513          	addi	a0,a0,790 # 11458 <__FRAME_END__>
   1014a:	00000317          	auipc	t1,0x0
   1014e:	00000067          	jr	zero # 0 <register_fini-0x100b0>
   10152:	8082                	ret

0000000000010154 <soilMoistureValue>:
   10154:	1101                	addi	sp,sp,-32
   10156:	ec22                	sd	s0,24(sp)
   10158:	1000                	addi	s0,sp,32
   1015a:	fe042623          	sw	zero,-20(s0)
   1015e:	fe042423          	sw	zero,-24(s0)
   10162:	a001                	j	10162 <soilMoistureValue+0xe>

0000000000010164 <main>:
   10164:	1141                	addi	sp,sp,-16
   10166:	e406                	sd	ra,8(sp)
   10168:	e022                	sd	s0,0(sp)
   1016a:	0800                	addi	s0,sp,16
   1016c:	fe9ff0ef          	jal	ra,10154 <soilMoistureValue>
   10170:	bff5                	j	1016c <main+0x8>

0000000000010172 <atexit>:
   10172:	85aa                	mv	a1,a0
   10174:	4681                	li	a3,0
   10176:	4601                	li	a2,0
   10178:	4501                	li	a0,0
   1017a:	a2bd                	j	102e8 <__register_exitproc>

000000000001017c <exit>:
   1017c:	1141                	addi	sp,sp,-16
   1017e:	4581                	li	a1,0
   10180:	e022                	sd	s0,0(sp)
   10182:	e406                	sd	ra,8(sp)
   10184:	842a                	mv	s0,a0
   10186:	1da000ef          	jal	ra,10360 <__call_exitprocs>
   1018a:	f4818793          	addi	a5,gp,-184 # 11bc0 <_global_impure_ptr>
   1018e:	6388                	ld	a0,0(a5)
   10190:	6d3c                	ld	a5,88(a0)
   10192:	c391                	beqz	a5,10196 <exit+0x1a>
   10194:	9782                	jalr	a5
   10196:	8522                	mv	a0,s0
   10198:	28a000ef          	jal	ra,10422 <_exit>

000000000001019c <__libc_fini_array>:
   1019c:	1101                	addi	sp,sp,-32
   1019e:	e822                	sd	s0,16(sp)
   101a0:	00001797          	auipc	a5,0x1
   101a4:	2d878793          	addi	a5,a5,728 # 11478 <__fini_array_end>
   101a8:	00001417          	auipc	s0,0x1
   101ac:	2c840413          	addi	s0,s0,712 # 11470 <__init_array_end>
   101b0:	8f81                	sub	a5,a5,s0
   101b2:	e426                	sd	s1,8(sp)
   101b4:	ec06                	sd	ra,24(sp)
   101b6:	4037d493          	srai	s1,a5,0x3
   101ba:	c881                	beqz	s1,101ca <__libc_fini_array+0x2e>
   101bc:	17e1                	addi	a5,a5,-8
   101be:	943e                	add	s0,s0,a5
   101c0:	601c                	ld	a5,0(s0)
   101c2:	14fd                	addi	s1,s1,-1
   101c4:	1461                	addi	s0,s0,-8
   101c6:	9782                	jalr	a5
   101c8:	fce5                	bnez	s1,101c0 <__libc_fini_array+0x24>
   101ca:	60e2                	ld	ra,24(sp)
   101cc:	6442                	ld	s0,16(sp)
   101ce:	64a2                	ld	s1,8(sp)
   101d0:	6105                	addi	sp,sp,32
   101d2:	8082                	ret

00000000000101d4 <__libc_init_array>:
   101d4:	1101                	addi	sp,sp,-32
   101d6:	e822                	sd	s0,16(sp)
   101d8:	e04a                	sd	s2,0(sp)
   101da:	00001417          	auipc	s0,0x1
   101de:	28240413          	addi	s0,s0,642 # 1145c <__preinit_array_end>
   101e2:	00001917          	auipc	s2,0x1
   101e6:	27a90913          	addi	s2,s2,634 # 1145c <__preinit_array_end>
   101ea:	40890933          	sub	s2,s2,s0
   101ee:	ec06                	sd	ra,24(sp)
   101f0:	e426                	sd	s1,8(sp)
   101f2:	40395913          	srai	s2,s2,0x3
   101f6:	00090963          	beqz	s2,10208 <__libc_init_array+0x34>
   101fa:	4481                	li	s1,0
   101fc:	601c                	ld	a5,0(s0)
   101fe:	0485                	addi	s1,s1,1
   10200:	0421                	addi	s0,s0,8
   10202:	9782                	jalr	a5
   10204:	fe991ce3          	bne	s2,s1,101fc <__libc_init_array+0x28>
   10208:	00001417          	auipc	s0,0x1
   1020c:	25840413          	addi	s0,s0,600 # 11460 <__init_array_start>
   10210:	00001917          	auipc	s2,0x1
   10214:	26090913          	addi	s2,s2,608 # 11470 <__init_array_end>
   10218:	40890933          	sub	s2,s2,s0
   1021c:	40395913          	srai	s2,s2,0x3
   10220:	00090963          	beqz	s2,10232 <__libc_init_array+0x5e>
   10224:	4481                	li	s1,0
   10226:	601c                	ld	a5,0(s0)
   10228:	0485                	addi	s1,s1,1
   1022a:	0421                	addi	s0,s0,8
   1022c:	9782                	jalr	a5
   1022e:	fe991ce3          	bne	s2,s1,10226 <__libc_init_array+0x52>
   10232:	60e2                	ld	ra,24(sp)
   10234:	6442                	ld	s0,16(sp)
   10236:	64a2                	ld	s1,8(sp)
   10238:	6902                	ld	s2,0(sp)
   1023a:	6105                	addi	sp,sp,32
   1023c:	8082                	ret

000000000001023e <memset>:
   1023e:	433d                	li	t1,15
   10240:	872a                	mv	a4,a0
   10242:	02c37163          	bgeu	t1,a2,10264 <memset+0x26>
   10246:	00f77793          	andi	a5,a4,15
   1024a:	e3c1                	bnez	a5,102ca <memset+0x8c>
   1024c:	e1bd                	bnez	a1,102b2 <memset+0x74>
   1024e:	ff067693          	andi	a3,a2,-16
   10252:	8a3d                	andi	a2,a2,15
   10254:	96ba                	add	a3,a3,a4
   10256:	e30c                	sd	a1,0(a4)
   10258:	e70c                	sd	a1,8(a4)
   1025a:	0741                	addi	a4,a4,16
   1025c:	fed76de3          	bltu	a4,a3,10256 <memset+0x18>
   10260:	e211                	bnez	a2,10264 <memset+0x26>
   10262:	8082                	ret
   10264:	40c306b3          	sub	a3,t1,a2
   10268:	068a                	slli	a3,a3,0x2
   1026a:	00000297          	auipc	t0,0x0
   1026e:	9696                	add	a3,a3,t0
   10270:	00a68067          	jr	10(a3)
   10274:	00b70723          	sb	a1,14(a4)
   10278:	00b706a3          	sb	a1,13(a4)
   1027c:	00b70623          	sb	a1,12(a4)
   10280:	00b705a3          	sb	a1,11(a4)
   10284:	00b70523          	sb	a1,10(a4)
   10288:	00b704a3          	sb	a1,9(a4)
   1028c:	00b70423          	sb	a1,8(a4)
   10290:	00b703a3          	sb	a1,7(a4)
   10294:	00b70323          	sb	a1,6(a4)
   10298:	00b702a3          	sb	a1,5(a4)
   1029c:	00b70223          	sb	a1,4(a4)
   102a0:	00b701a3          	sb	a1,3(a4)
   102a4:	00b70123          	sb	a1,2(a4)
   102a8:	00b700a3          	sb	a1,1(a4)
   102ac:	00b70023          	sb	a1,0(a4)
   102b0:	8082                	ret
   102b2:	0ff5f593          	andi	a1,a1,255
   102b6:	00859693          	slli	a3,a1,0x8
   102ba:	8dd5                	or	a1,a1,a3
   102bc:	01059693          	slli	a3,a1,0x10
   102c0:	8dd5                	or	a1,a1,a3
   102c2:	02059693          	slli	a3,a1,0x20
   102c6:	8dd5                	or	a1,a1,a3
   102c8:	b759                	j	1024e <memset+0x10>
   102ca:	00279693          	slli	a3,a5,0x2
   102ce:	00000297          	auipc	t0,0x0
   102d2:	9696                	add	a3,a3,t0
   102d4:	8286                	mv	t0,ra
   102d6:	fa2680e7          	jalr	-94(a3)
   102da:	8096                	mv	ra,t0
   102dc:	17c1                	addi	a5,a5,-16
   102de:	8f1d                	sub	a4,a4,a5
   102e0:	963e                	add	a2,a2,a5
   102e2:	f8c371e3          	bgeu	t1,a2,10264 <memset+0x26>
   102e6:	b79d                	j	1024c <memset+0xe>

00000000000102e8 <__register_exitproc>:
   102e8:	f4818793          	addi	a5,gp,-184 # 11bc0 <_global_impure_ptr>
   102ec:	6398                	ld	a4,0(a5)
   102ee:	1f873783          	ld	a5,504(a4)
   102f2:	c3b1                	beqz	a5,10336 <__register_exitproc+0x4e>
   102f4:	4798                	lw	a4,8(a5)
   102f6:	487d                	li	a6,31
   102f8:	06e84263          	blt	a6,a4,1035c <__register_exitproc+0x74>
   102fc:	c505                	beqz	a0,10324 <__register_exitproc+0x3c>
   102fe:	00371813          	slli	a6,a4,0x3
   10302:	983e                	add	a6,a6,a5
   10304:	10c83823          	sd	a2,272(a6)
   10308:	3107a883          	lw	a7,784(a5)
   1030c:	4605                	li	a2,1
   1030e:	00e6163b          	sllw	a2,a2,a4
   10312:	00c8e8b3          	or	a7,a7,a2
   10316:	3117a823          	sw	a7,784(a5)
   1031a:	20d83823          	sd	a3,528(a6)
   1031e:	4689                	li	a3,2
   10320:	02d50063          	beq	a0,a3,10340 <__register_exitproc+0x58>
   10324:	00270693          	addi	a3,a4,2
   10328:	068e                	slli	a3,a3,0x3
   1032a:	2705                	addiw	a4,a4,1
   1032c:	c798                	sw	a4,8(a5)
   1032e:	97b6                	add	a5,a5,a3
   10330:	e38c                	sd	a1,0(a5)
   10332:	4501                	li	a0,0
   10334:	8082                	ret
   10336:	20070793          	addi	a5,a4,512
   1033a:	1ef73c23          	sd	a5,504(a4)
   1033e:	bf5d                	j	102f4 <__register_exitproc+0xc>
   10340:	3147a683          	lw	a3,788(a5)
   10344:	4501                	li	a0,0
   10346:	8e55                	or	a2,a2,a3
   10348:	00270693          	addi	a3,a4,2
   1034c:	068e                	slli	a3,a3,0x3
   1034e:	2705                	addiw	a4,a4,1
   10350:	30c7aa23          	sw	a2,788(a5)
   10354:	c798                	sw	a4,8(a5)
   10356:	97b6                	add	a5,a5,a3
   10358:	e38c                	sd	a1,0(a5)
   1035a:	8082                	ret
   1035c:	557d                	li	a0,-1
   1035e:	8082                	ret

0000000000010360 <__call_exitprocs>:
   10360:	715d                	addi	sp,sp,-80
   10362:	f4818793          	addi	a5,gp,-184 # 11bc0 <_global_impure_ptr>
   10366:	e062                	sd	s8,0(sp)
   10368:	0007bc03          	ld	s8,0(a5)
   1036c:	f44e                	sd	s3,40(sp)
   1036e:	f052                	sd	s4,32(sp)
   10370:	ec56                	sd	s5,24(sp)
   10372:	e85a                	sd	s6,16(sp)
   10374:	e486                	sd	ra,72(sp)
   10376:	e0a2                	sd	s0,64(sp)
   10378:	fc26                	sd	s1,56(sp)
   1037a:	f84a                	sd	s2,48(sp)
   1037c:	e45e                	sd	s7,8(sp)
   1037e:	8aaa                	mv	s5,a0
   10380:	8b2e                	mv	s6,a1
   10382:	4a05                	li	s4,1
   10384:	59fd                	li	s3,-1
   10386:	1f8c3903          	ld	s2,504(s8)
   1038a:	02090463          	beqz	s2,103b2 <__call_exitprocs+0x52>
   1038e:	00892483          	lw	s1,8(s2)
   10392:	fff4841b          	addiw	s0,s1,-1
   10396:	00044e63          	bltz	s0,103b2 <__call_exitprocs+0x52>
   1039a:	048e                	slli	s1,s1,0x3
   1039c:	94ca                	add	s1,s1,s2
   1039e:	020b0663          	beqz	s6,103ca <__call_exitprocs+0x6a>
   103a2:	2084b783          	ld	a5,520(s1)
   103a6:	03678263          	beq	a5,s6,103ca <__call_exitprocs+0x6a>
   103aa:	347d                	addiw	s0,s0,-1
   103ac:	14e1                	addi	s1,s1,-8
   103ae:	ff3418e3          	bne	s0,s3,1039e <__call_exitprocs+0x3e>
   103b2:	60a6                	ld	ra,72(sp)
   103b4:	6406                	ld	s0,64(sp)
   103b6:	74e2                	ld	s1,56(sp)
   103b8:	7942                	ld	s2,48(sp)
   103ba:	79a2                	ld	s3,40(sp)
   103bc:	7a02                	ld	s4,32(sp)
   103be:	6ae2                	ld	s5,24(sp)
   103c0:	6b42                	ld	s6,16(sp)
   103c2:	6ba2                	ld	s7,8(sp)
   103c4:	6c02                	ld	s8,0(sp)
   103c6:	6161                	addi	sp,sp,80
   103c8:	8082                	ret
   103ca:	00892783          	lw	a5,8(s2)
   103ce:	6498                	ld	a4,8(s1)
   103d0:	37fd                	addiw	a5,a5,-1
   103d2:	04878263          	beq	a5,s0,10416 <__call_exitprocs+0xb6>
   103d6:	0004b423          	sd	zero,8(s1)
   103da:	db61                	beqz	a4,103aa <__call_exitprocs+0x4a>
   103dc:	31092783          	lw	a5,784(s2)
   103e0:	008a16bb          	sllw	a3,s4,s0
   103e4:	00892b83          	lw	s7,8(s2)
   103e8:	8ff5                	and	a5,a5,a3
   103ea:	2781                	sext.w	a5,a5
   103ec:	eb99                	bnez	a5,10402 <__call_exitprocs+0xa2>
   103ee:	9702                	jalr	a4
   103f0:	00892783          	lw	a5,8(s2)
   103f4:	f97799e3          	bne	a5,s7,10386 <__call_exitprocs+0x26>
   103f8:	1f8c3783          	ld	a5,504(s8)
   103fc:	fb2787e3          	beq	a5,s2,103aa <__call_exitprocs+0x4a>
   10400:	b759                	j	10386 <__call_exitprocs+0x26>
   10402:	31492783          	lw	a5,788(s2)
   10406:	1084b583          	ld	a1,264(s1)
   1040a:	8ff5                	and	a5,a5,a3
   1040c:	2781                	sext.w	a5,a5
   1040e:	e799                	bnez	a5,1041c <__call_exitprocs+0xbc>
   10410:	8556                	mv	a0,s5
   10412:	9702                	jalr	a4
   10414:	bff1                	j	103f0 <__call_exitprocs+0x90>
   10416:	00892423          	sw	s0,8(s2)
   1041a:	b7c1                	j	103da <__call_exitprocs+0x7a>
   1041c:	852e                	mv	a0,a1
   1041e:	9702                	jalr	a4
   10420:	bfc1                	j	103f0 <__call_exitprocs+0x90>

0000000000010422 <_exit>:
   10422:	4581                	li	a1,0
   10424:	4601                	li	a2,0
   10426:	4681                	li	a3,0
   10428:	4701                	li	a4,0
   1042a:	4781                	li	a5,0
   1042c:	05d00893          	li	a7,93
   10430:	00000073          	ecall
   10434:	00054363          	bltz	a0,1043a <_exit+0x18>
   10438:	a001                	j	10438 <_exit+0x16>
   1043a:	1141                	addi	sp,sp,-16
   1043c:	e022                	sd	s0,0(sp)
   1043e:	842a                	mv	s0,a0
   10440:	e406                	sd	ra,8(sp)
   10442:	4080043b          	negw	s0,s0
   10446:	008000ef          	jal	ra,1044e <__errno>
   1044a:	c100                	sw	s0,0(a0)
   1044c:	a001                	j	1044c <_exit+0x2a>

000000000001044e <__errno>:
   1044e:	f5818793          	addi	a5,gp,-168 # 11bd0 <_impure_ptr>
   10452:	6388                	ld	a0,0(a5)
   10454:	8082                	ret
```



