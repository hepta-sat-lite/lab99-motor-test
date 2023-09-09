#include "mbed.h"
#include "HEPTA_EPS.h"
#include "HEPTA_COM.h"

RawSerial pc(USBTX,USBRX, 9600);
HEPTA_EPS eps(PA_0,PA_4);
HEPTA_COM com(PA_9,PA_10,9600);
PwmOut PWM[]={PB_0, PA_6, PB_1, PA_8};
//In4=PB_0
//In3=PA_6
//In1=PB_1
//In2=PA_8
//out3,4 left motor
//out1,2 right motor
void motorStop(){
    //rover.printf("Stop\r\n");
    PWM[0].pulsewidth_us(0);
    PWM[1].pulsewidth_us(0);
    PWM[2].pulsewidth_us(0);
    PWM[3].pulsewidth_us(0);
}

void motorFor(){
    motorStop();
    wait(1);
    //rover.printf("Forward\r\n");
    PWM[0].pulsewidth_us(20000);
    PWM[1].pulsewidth_us(20000);
    PWM[2].pulsewidth_us(20000);
    PWM[3].pulsewidth_us(20000);
    //wait(50);
}
/*
void motorRev(){
    motorStop();
    wait(1);
    //rover.printf("Rev\r\n");
    PWM[0].pulsewidth_us(0);
    PWM[1].pulsewidth_us(20000);
    PWM[2].pulsewidth_us(20000);
    PWM[3].pulsewidth_us(0);
}
*/
void motorRight(){
    motorStop();
    wait(1);
    //rover.printf("Right\r\n");
    PWM[0].pulsewidth_us(0);
    PWM[1].pulsewidth_us(0);
    PWM[2].pulsewidth_us(10000);
    PWM[3].pulsewidth_us(10000);
}

void motorLeft(){
    motorStop();
    wait(1);
    //rover.printf("Left\r\n");
    PWM[0].pulsewidth_us(10000);
    PWM[1].pulsewidth_us(10000);
    PWM[2].pulsewidth_us(0);
    PWM[3].pulsewidth_us(10000);
}


int main()
{
    eps.turn_on_regulator(); //turn on 3.3V conveter
    PWM[0].period_us(20000);
    PWM[1].period_us(20000);
    PWM[2].period_us(20000);
    PWM[3].period_us(20000);
    
    while (1) {
        motorStop();
        wait(1);
        pc.printf("forword\r\n");
        //com.printf("forword\r\n");
        motorFor();
        wait(5);
        pc.printf("right\r\n");
        //com.printf("right\r\n");
        motorRight();
        wait(5);
        pc.printf("left\r\n");
        //com.printf("left\r\n");
        motorLeft();
        wait(5);
        //motorRev();
        //wait(5);
    }
}