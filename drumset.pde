import processing.serial.*;
import processing.sound.*;
Serial myPort;
SoundFile file;
float r = 1;
String val;
int flag = 0;
String[] ins = new String[2]; //Input array to handle comma separated inputs like R,234 for adjusting the rate.
String[] music = new String[8];
{
music[0] = "K1";
music[1] = "S2";
music[2] = "K1";
music[3] = "R2";
}
int i=0,fre;
void setup()
{
  
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); 
}
void draw()
{
  if(flag==1)
  {
   for(i=0;i<music.length;i++)
   {
     if(music[i] != null)
     {
     String f = music[i] + ".wav";
     file = new SoundFile(this, f);
     //file.rate(r);
     file.play();
     delay(400*int(r));
   }
   }
  }
}

void serialEvent( Serial myPort) {
val = myPort.readStringUntil('\n');

if (val != null) {
  val = trim(val);
  println(val);
  ins = split(val,',');
  if(val.equals("S1"))
  {
    flag=1;
  if(val.equals("L1"))
  {
    myPort.clear();
    println(val);
    play("K1",1,0);
  }
  if(val.equals("L2"))
  {
    myPort.clear();
    println(val);
    play("K2",1,1);
  }
  if(val.equals("L3"))
  {
    myPort.clear();
    println(val);
    play("R1",1,2);
  }
  if(val.equals("L4"))
  {
    myPort.clear();
    println(val);
    play("R2",1,3);
  }
  if(val.equals("L5"))
  {
    myPort.clear();
    println(val);
    play("R3",1,4);
  }
  if(val.equals("L6"))
  {
    myPort.clear();
    println(val);
    play("R4",1,5);
  }
  if(val.equals("L7"))
  {
    myPort.clear();
    println(val);
    play("S1",1,6);
  }
  if(val.equals("L8"))
  {
    myPort.clear();
    println(val);
    play("S2",1,7);
  }
  }
  else
  {
  if(val.equals("L1"))
  {
    myPort.clear();
    println(val);
    play("K1",0,0);
  }
  if(val.equals("L2"))
  {
    myPort.clear();
    println(val);
   play("K2",0,0);
  }
  if(val.equals("L3"))
  {
    myPort.clear();
    println(val);
    play("R1",0,0);
  }
  if(val.equals("L4"))
  {
    myPort.clear();
    println(val);
    play("R2",0,0);
  }
  if(val.equals("L5"))
  {
    myPort.clear();
    println(val);
    play("R3",0,0);
  }
  if(val.equals("L6"))
  {
    myPort.clear();
    println(val);
    play("R4",0,0);
  }
  if(val.equals("L7"))
  {
    myPort.clear();
    println(val);
    play("S1",0,0);
  }
  if(val.equals("L8"))
  {
    myPort.clear();
    println(val);
    play("S2",0,0);
  }
  }
}
  switch(ins[0])
  {
    case "R": int t = int(ins[1]);
    println(t);
    r = map(t,0,1024,1,8);
    break;
  }
}

void play(String toplay, int what, int pos)  //what = 1 - sequencer and what = 0 - normal
{
  if(what == 0)
  {
    String f = toplay + ".wav";
     file = new SoundFile(this, f);
     //file.rate(r);
     file.play();
     delay(400*int(r));
     return;
  }
  else
  {
    music[pos] = toplay;
    return;
  }
}