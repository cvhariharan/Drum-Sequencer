#include <ADCTouch.h>


const int swi1 = A0;
const int swi2 = A1;
const int swi3 = A2;
const int swi4 = A3;
const int swi5 = A4;
const int swi6 = A5;
const int swi7 = 5;
const int swi8 = 4;
const int sel = 3; //To select mode: ON-sequencer or OFF-normal instrument
int red;
int change;
int threshold = 40;
int s[8];
void setup() {
    Serial.begin(115200);
  if(digitalRead(sel)==1)
{
 Serial.println("S1");
}
else
{
  Serial.println("S0");
}

red = analogRead(A0); //Rate adjustment
s[0] = ADCTouch.read(swi1,500);
s[1] = ADCTouch.read(swi2,500);
s[2] = ADCTouch.read(swi3,500);
s[3] = ADCTouch.read(swi4,500);
s[4] = ADCTouch.read(swi5,500);
s[5] = ADCTouch.read(swi6,500);
s[6] = ADCTouch.read(swi7,500);
s[7] = ADCTouch.read(swi8,500);
}
void loop() {
/*change = analogRead(A0); //Rate adjustment
if(abs(red-change)>80)
{
  red=change;
Serial.print("R,");
Serial.println(red);
//Serial.println(change);
}*/
if(capRead(swi1,1) == 1)
{
 while(capRead(swi1,1) == 1);
 Serial.println("L1");
 Serial.flush();
}

if(capRead(swi2,2) == 1)
{
  while(capRead(swi2,2) == 1);
 Serial.println("L2");
 Serial.flush();
}

if(capRead(swi3,3) == 1)
{
 while(capRead(swi3,3) == 1);
 Serial.println("L3");
 Serial.flush();
}

if(capRead(swi4,4) == 1)
{
  while(capRead(swi4,4) == 1);
 Serial.println("L4");
 Serial.flush();
}
if(capRead(swi5,5) == 1)
{
  while(capRead(swi5,5) == 1);
 Serial.println("L5");
 Serial.flush();
}
if(capRead(swi6,6) == 1)
{
  while(capRead(swi6,6) == 1);
 Serial.println("L6");
 Serial.flush();
}
if(capRead(swi7,7) == 1)
{
  while(capRead(swi7,7) == 1);
 Serial.println("L7");
 Serial.flush();
}
if(capRead(swi8,8) == 1)
{
 while(capRead(swi8,8) == 1);
 Serial.println("L8");
 Serial.flush();
}
delay(30);
}

int capRead(int swi,int p)
{
  int c = ADCTouch.read(swi);
  c -=s[p-1];
  return (c > threshold);
}


