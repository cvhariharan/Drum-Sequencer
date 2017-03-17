import processing.serial.*;
import processing.sound.*;
Serial myPort;
String val;
SinOsc sine;
int[] music = {200,140,342,444};
int i=0,fre;
void setup()
{
  
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName,115200);
  myPort.bufferUntil('\n'); 
  sine = new SinOsc(this);
    //Start the Sine Oscillator. 
    sine.play();
}
void draw()
{
  //println(frameRate);
   for(i=0;i<music.length;i++)
   {
     fre = music[i];
     sine.freq(fre);
     delay(400);
     sine.freq(0);
     delay(100);
   }
  /*if ( myPort.available() > 0) 
  {  // If data is available,
  val = myPort.readStringUntil('\n');   
  if(val.equals("1\n"))
  {
    sine.freq(200);
    println("1");
  }
  if(val.equals("2\n"))
  {
    sine.freq(240);
    println("2");
  }
  if(val.equals("3\n"))
  {
    sine.freq(280);
    println("3");
  }
  if(val.equals("4\n"))
  {
    sine.freq(320);
    println("4");
  }
  
  } */
//println(val); //print it out in the console
}

void serialEvent( Serial myPort) {
//put the incoming data into a String - 
//the '\n' is our end delimiter indicating the end of a complete packet
val = myPort.readStringUntil('\n');
//make sure our data isn't empty before continuing
if (val != null) {
  
  val = trim(val);
  println(val);
  if(val.equals("L1"))
  {
    myPort.clear();
    println(val);
    music[0] = 200;
    //sine.freq(200);
     //delay(400);
    // sine.freq(0);
     //delay(100);
  }
  if(val.equals("L2"))
  {
    myPort.clear();
    println(val);
    music[1] = 300;
    //sine.freq(300);
    // delay(400);
    // sine.freq(0);
     //delay(100);
  }
  if(val.equals("L3"))
  {
    myPort.clear();
    println(val);
    music[2] = 400;
    //sine.freq(400);
    // delay(400);
     //sine.freq(0);
    // delay(100);
  }
  if(val.equals("L4"))
  {
    myPort.clear();
    println(val);
    music[3] =  500;
   // sine.freq(500);
    // delay(400);
     //sine.freq(0);
     //delay(100);
  }
  if(val.equals("L5"))
  {
    myPort.clear();
    println(val);
    sine.freq(600);
    music[4] = 600;
    // delay(400);
     //sine.freq(0);
     //delay(100);
  }
  if(val.equals("L6"))
  {
    myPort.clear();
    println(val);
    //sine.freq(600);
    music[5] = 700;
    // delay(400);
     //sine.freq(0);
     //delay(100);
  }
  if(val.equals("L7"))
  {
    myPort.clear();
    println(val);
    //sine.freq(700);
    music[6] = 800;
    // delay(400);
     //sine.freq(0);
     //delay(100);
  }
  if(val.equals("L8"))
  {
    myPort.clear();
    println(val);
    //sine.freq(800);
    music[7] = 900;
    // delay(400);
     //sine.freq(0);
     //delay(100);
  }
}
}