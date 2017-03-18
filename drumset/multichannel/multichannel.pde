import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;
import processing.serial.*;
import processing.sound.*;
Serial myPort;
SoundFile[] file = new SoundFile[10];
SoundFile file1;
Minim       minim;
AudioOutput out;
Sampler S1;
Sampler S2;
Sampler R1;
Sampler R2;
Sampler R3;
Sampler R4;
Sampler K1;
Sampler K2;
AudioSample[] drums = new AudioSample[8];
int r = 500;
String val;
int flag = 0,j;
int[][] seq = {{1,0,0,1,0,1,0,1},{1,0,1,1,0,0,0,1},{1,0,0,1,0,0,0,0},{1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0},{1,0,0,0,1,0,0,1},{1,0,0,0,1,0,0,0},{1,0,0,1,0,0,0,1}};
int i=0,fre,m=0;
void setup()
{
  frameRate(300);
  /*String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
  myPort.bufferUntil('\n');*/ 
  minim = new Minim(this);
  drums[0] = minim.loadSample("S1.mp3",512);
  drums[1] = minim.loadSample("S2.mp3",512);
  drums[2]  = minim.loadSample("R1.mp3",512);
  drums[3] = minim.loadSample("R2.mp3",512);
  drums[4]  = minim.loadSample("R3.mp3",512);
  drums[5]  = minim.loadSample("R4.mp3",512);
  drums[6] = minim.loadSample("K1.mp3",512);
  drums[7] = minim.loadSample("K2.mp3",512);
}
void draw()
{
 //println(frameRate);
 //myPort.bufferUntil('\n'); 
for(i=0;i<8;i++)
{
  for(j=0;j<8;j++)
  {
    if(seq[j][i]==1)
    {
      drums[j].trigger();
    }
  }
  delay(r);
}
}

/*void serialEvent( Serial myPort) {
val = myPort.readStringUntil('\n');

if (val != null) {
  val = trim(val);
  if(val.equals("S1"))
  {
    flag=1;
  }
  
  ins = split(val,',');
  if(flag==1)
  {
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
    String f = toplay + ".mp3";
    if(m==10)
    m=0;
     file[m] = new SoundFile(this, f);
     //file.rate(1.2);
     file[m].play();
     m++;
     //delay(50);
     return;
  }
  else
  {
    music[pos] = toplay;
    return;
  }
}*/