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
int bpcr;			//starting box forward before a turn
bpcr=4000;
int ninety;			//90 degree turn
ninety=1100;
int tpcr;			//moving forward after the turn after leaving the starting box
tpcr=8000;
int pcrf;			//moving forward to get to the pcr machine
pcrf=675;
int backbot;		//moving backwards to lift and extend servos
backbot=700;
int turnbf;			//turn before moving forward to get botguy
turnbf=550;
int forwardbot;		//going forward get botguy
forwardbot=1000;
int turnbot;		//turn to get botguy
turnbot=3000;

//servos
int bar;		//the bar that is going to be used to open the pcr machine
bar=0;
int pcrdown;	//starting down at the start of the game before 
pcrdown=300;
int pcrup;		//bar of the pcr machine moving up in order to open the pcr machine
pcrup=1000;
int up;			// up for when its not in use
up=1359;
int arm;		//arm that extends to get the bot guy and for the ring stand
arm=3;
int botdown;	//arm down before the game starts / before getting bot guy
botdown=750;
int botup;		//arm up in order to get bot guy
botup=880;

int main()
{
	//opening the pcr machine
    set_servo_position(bar,pcrdown);	
    set_servo_position(arm,botdown);
    enable_servos();
    cmpc(0);
    while(gmpc(right)<bpcr)		//to make the bot go foward out of the starting box
    {
        mav(right,rspeedeight);
        mav(left,lspeedeight);
    }
    cmpc(3);
    while(gmpc(left)<ninety)	//turn the bot 90 degrees to the right
    {
        mav(right,rbackeight);
        mav(left,lspeedeight);
    }
    cmpc(0);
    while(gmpc(right)<tpcr)		//go foward to align with the pcr machine
    {
        mav(right,rspeedeight);
        mav(left,lspeedeight);
    }
    cmpc(0);
    while(gmpc(right)<ninety)	//turn the bot 90 degrees to the left
    {
        mav(right,rspeedeight);
        mav(left,lbackeight);
    }
    cmpc(0);
    while(gmpc(right)<pcrf)		//go more foward to make sure the bar goes into the pcr machine
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
    msleep(10);
    
    //getting botguy
    cmpc(0);
    while(abs(gmpc(right))<backbot)		//make the bot go backwards in order to lift the bar and extend the arm
    {
        mav(right,rbackeight);
        mav(left,lbackeight);
    }
    ao();
    set_servo_position(bar,up);
    msleep(10);
    set_servo_position(arm,botup);
    msleep(10);
    cmpc(3);
    while(gmpc(left)<turnbf)	//turn the bot to then go forward to get bot guy
    {
        mav(right,rbackeight);
        mav(left,lspeedeight);
    }
    cmpc(0);
    while(gmpc(right)<forwardbot)	//go forward to get botguy
    {
        mav(right,rspeedeight);
        mav(left,lspeedeight);
    }
    cmpc(0);
    while(gmpc(right)<turnbot)	//turn to get behind botguy
    {
        mav(right,rspeedeight);
        mav(left,lbackeight);
    }
    return 0;
}
