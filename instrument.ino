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

void setup() {
  // put your setup code here, to run once:
  pinMode(swi1, INPUT);
  pinMode(swi2, INPUT);
  pinMode(swi3, INPUT);
  pinMode(swi4, INPUT);
  pinMode(swi5, INPUT);
  pinMode(swi6, INPUT);
  pinMode(swi7, INPUT);
  pinMode(swi8, INPUT);
  Serial.begin(9600);
}

void loop() {
if(digitalRead(sel)==HIGH)
{
 Serial.println("S1");
 delay(180);
}
else
{
  Serial.println("S0");
  delay(180);
}
red = analogRead(A0); //Rate adjustment
if(red > 0)
{
Serial.print("R,");
Serial.println(red);
}
if(digitalRead(swi1) == HIGH)
{
  Serial.println("L1");
  delay(180);
}

if(digitalRead(swi2) == HIGH)
{
  Serial.println("L2");
  delay(180);
}

if(digitalRead(swi3) == HIGH)
{
  Serial.println("L3");
  delay(180);
}

if(digitalRead(swi4) == HIGH)
{
  Serial.println("L4");
  delay(180);
}
if(digitalRead(swi5) == HIGH)
{
  Serial.println("L5");
  delay(180);
}
if(digitalRead(swi6) == HIGH)
{
  Serial.println("L6");
  delay(180);
}
if(digitalRead(swi7) == HIGH)
{
  Serial.println("L7");
  delay(180);
}
if(digitalRead(swi8) == HIGH)
{
  Serial.println("L8");
  delay(180);
}
}
