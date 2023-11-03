// Function to monitor water level and control the buzzer
#include<stdio.h>
int main()  {

    int sensor_value;
    int motor;
    int dummy;
    int i;
    int rain_sensor_ip;
    int test,test1;
    
    
        for (int j=0; j<15;j++) {
       // while(1){
        
	
       if(j<10)
			sensor_value=1;
	else
			sensor_value=0;
			

		asm volatile(
		
		"andi %0, x30, 0x01\n\t"
		: "=r" (sensor_value)
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



