# iiitb_riscv_drip_irrigation_system

# project Overview

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



