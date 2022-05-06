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
int rforward;
rforward=1000;
int lforward;
lforward=1000;
int lback;
lback=-1000;
int rback;
rback=-1000;

//servos
int bar;
bar=0;
int arm;
arm=3;

//servo distances
int bvertical;		//vertical for the bar
bvertical=1450;
int bdown;
bdown=340;
int bup;
bup=1150;
int bfloor;
bfloor=230;
int bring;
bring=735;
int bringdown;
bringdown=419;
int avertical;		//vertical for the arm
avertical=657;
int abotguy;
abotguy=802;

//digital ports
int lbump;
lbump=2;
int rbump;
rbump=0;
int lever;
lever=4;

void Forward(int distance);
void Turning_Right(int degrees);
void Turning_Left(int degrees);
void Back(int distance);
void Back_Till_Hit();
void Opening_PCR_Machine();
void Hit_The_Lever();

int main()
{
    set_servo_position(bar,bvertical);
    set_servo_position(arm,abotguy);
    enable_servos();
    Turning_Left(100);
    Forward(80);
    Turning_Right(102);
    Forward(193);
    Turning_Left(102);
    Back_Till_Hit();
    set_servo_position(arm,avertical);
    set_servo_position(bar,bfloor);
    Forward(120);
    Turning_Left(90);
    set_servo_position(bar,bdown);
    Turning_Right(115);
    Forward(30);
    Opening_PCR_Machine();
    Turning_Left(20);
    Back_Till_Hit();
    Forward(30);
    Turning_Left(102);
    Hit_The_Lever();
    Back(30);
    Turning_Right(102);
    set_servo_position(bar,bring);
    Back_Till_Hit();
    Forward(50);
    Turning_Right(160);
    Forward(15);
    Turning_Left(60);
    set_servo_position(bar,bringdown);
    Turning_Right(90);
    Turning_Left(130);
    return 0;
}

void Forward(int distance)
{
    mav(right,rforward);
    mav(left,lforward);
    msleep(40*distance);	//this makes it go an inch forward
    ao();
}

void Turning_Right(int degrees)
{
    mav(right,rback);
    mav(left,lforward);
    msleep(10*degrees);
    ao();
}

void Turning_Left(int degrees)
{
    mav(right,rforward);
    mav(left,lback);
    msleep(10*degrees);
    ao();
}

void Back(int distance)
{
    mav(right,rback);
    mav(left,lback);
    msleep(40*distance);	//this makes it go an inch forward
    ao();
}

void Back_Till_Hit()
{
    while(digital(lbump)==0||digital(rbump)==0)
    {
        mav(right,rback);
        mav(left,lback);
    }
}

void Opening_PCR_Machine()
{
    set_servo_position(bar,bup);
    msleep(1000);
    set_servo_position(bar,bdown);
    msleep(250);
    set_servo_position(bar,bup);
    msleep(1000);
    set_servo_position(bar,bdown);
    msleep(250);
    set_servo_position(bar,bup);
    msleep(1000);
    set_servo_position(bar,bdown);
    msleep(10);
}

void Hit_The_Lever()
{
    while(digital(lever)==0)
    {
        mav(right,rforward);
        mav(left,lforward);
    }
}