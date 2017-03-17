#define portOfPin(P)\
  (((P)>=0&&(P)<8)?&PORTD:(((P)>7&&(P)<14)?&PORTB:&PORTC))
#define ddrOfPin(P)\
  (((P)>=0&&(P)<8)?&DDRD:(((P)>7&&(P)<14)?&DDRB:&DDRC))
#define pinOfPin(P)\
  (((P)>=0&&(P)<8)?&PIND:(((P)>7&&(P)<14)?&PINB:&PINC))
#define pinIndex(P)((uint8_t)(P>13?P-14:P&7))
#define pinMask(P)((uint8_t)(1<<pinIndex(P)))

#define pinAsInput(P) *(ddrOfPin(P))&=~pinMask(P)
#define pinAsInputPullUp(P) *(ddrOfPin(P))&=~pinMask(P);digitalHigh(P)
#define pinAsOutput(P) *(ddrOfPin(P))|=pinMask(P)
#define digitalLow(P) *(portOfPin(P))&=~pinMask(P)
#define digitalHigh(P) *(portOfPin(P))|=pinMask(P)
#define isHigh(P)((*(pinOfPin(P))& pinMask(P))>0)
#define isLow(P)((*(pinOfPin(P))& pinMask(P))==0)
#define digitalState(P)((uint8_t)isHigh(P))
const int swi1 = 11;
const int swi2 = 10;
const int swi3 = 9;
const int swi4 = 8;
const int swi5 = 7;
const int swi6 = 6;
const int swi7 = 5;
const int swi8 = 4;
const int sel = 3; //To select mode: ON-sequencer or OFF-normal instrument
int red;
int change;
int s1,s2,s3,s4,s5,s6,s7,s8;

void setup() {
  // put your setup code here, to run once:
  pinAsInput(swi1);
  pinAsInput(swi2);
  pinAsInput(swi3);
   pinAsInput(swi4);
    pinAsInput(swi5);
     pinAsInput(swi6);
      pinAsInput(swi7);
       pinAsInput(swi8);
       s1=s2=s3=s4=s5=s6=s7=s8=0;
    Serial.begin(9600);
  /*if(digitalState(sel)==HIGH)
{
 Serial.println("S1");
}
else
{
  Serial.println("S0");
}

red = analogRead(A0); //Rate adjustment*/
}
void loop() {
/*change = analogRead(A0); //Rate adjustment
if(abs(red-change)>80)
{
  red=change;
Serial.print("R,");
Serial.println(red);
Serial.println(change);
}*/
if(digitalState(swi1) == HIGH)
{
 while(digitalState(swi1) == HIGH);
 Serial.println("L1");
 Serial.flush();
}

if(digitalState(swi2) == HIGH)
{
  while(digitalState(swi2) == HIGH);
 Serial.println("L3");
 Serial.flush();
}

if(digitalState(swi3) == HIGH)
{
 while(digitalState(swi3) == HIGH);
 Serial.println("L3");
 Serial.flush();
}

if(digitalState(swi4) == HIGH)
{
  while(digitalState(swi4) == HIGH);
 Serial.println("L4");
 Serial.flush();
}
if(digitalState(swi5) == HIGH)
{
  while(digitalState(swi5) == HIGH);
 Serial.println("L5");
 Serial.flush();
}
if(digitalState(swi6) == HIGH)
{
  while(digitalState(swi6) == HIGH);
 Serial.println("L6");
 Serial.flush();
}
if(digitalState(swi7) == HIGH)
{
  while(digitalState(swi7) == HIGH);
 Serial.println("L7");
 Serial.flush();
}
if(digitalState(swi8) == HIGH)
{
 while(digitalState(swi8) == HIGH);
 Serial.println("L8");
 Serial.flush();
}
delay(30);
}
