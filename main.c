#include <kipr/wombat.h>

//light
int light;	//port for the light sensor
light=0;

//motors
int right;	//right wheel
right=0;
int left;	//left wheel
left=3;

//speed
int rspeedeight;
rspeedeight=800;
int lspeedeight;
lspeedeight=800;
int lbackeight;
lbackeight=-800;
int rbackeight;
rbackeight=-800;

//distances
int bpcr;		//starting box forward before a turn
bpcr=600;
int turnpcr;	//90 degree turn to the right
turnpcr=600;
int tpcr;		//moving forward after the turn to the pcr machine
tpcr=675;
int pcrb;		//moving backwards after getting the pcr machine to lift up the arm extenstion
pcrb=750;

//servos
int bar;		//the bar that is going to be used to open the pcr machine
bar=0;
int pcrdown;	//starting down at the start of the game before 
pcrdown=190;
int pcrup;		//bar of the pcr machine moving up in order to open the pcr machine
pcrup=1000;
int arm;		//arm that extends to get the bot guy and for the ring stand
arm=3;
int botdown;	//arm down before the game starts / before getting bot guy
botdown=1601;
int botup;		//arm up in order to get bot guy
botup=700;

int main()
{
	//opening the pcr machine
    set_servo_position(bar,pcrdown);	
    set_servo_position(arm,botdown);
    enable_servos();
    cmpc(0);
    while(gmpc(right)<bpcr)		//to make the bot go foward to the pcr machine
    {
        mav(right,rspeedeight);
        mav(left,lspeedeight);
    }
    cmpc(0);
    while(gmpc(right)<turnpcr)	//turn the bot to be facing the pcr machine
    {
        mav(right,rspeedeight);
        mav(left,lbackeight);
    }
    cmpc(0);
    while(gmpc(right)<tpcr)		//go more foward if needed
    {
        mav(right,rspeedeight);
        mav(left,lspeedeight);
    }
    ao();
    set_servo_position(bar,pcrup);	//lift the pcr machine ~ repeats more than once in order to ensure balls get out
    msleep(1000);
    set_servo_position(bar,pcrdown);
    msleep(250);
    set_servo_position(bar,pcrup);
    msleep(1000);
    set_servo_position(bar,pcrdown);
    msleep(250);
    set_servo_position(bar,pcrup);
    msleep(1000);
    set_servo_position(bar,pcrdown);
    msleep(250);
    set_servo_position(bar,pcrup);
    msleep(1000);
    set_servo_position(bar,pcrdown);
    msleep(250);
    set_servo_position(bar,pcrup);
    msleep(1000);
    set_servo_position(bar,pcrdown);
    msleep(10);
    
    return 0;
}
