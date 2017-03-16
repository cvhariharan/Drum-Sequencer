// Load AVR timer interrupt macros
#include <avr/interrupt.h>

// Wave parameters
#define PI2     6.283185 // 2 * PI
int AMP  =   1 ;    // Amplification factor for sine wave
#define OFFSET  128      // Shifting wave to positive values only

// Wave table
#define LENGTH  256  // The length of the waveform lookup table
byte wave[LENGTH];   // Storage for the waveform


//Random Variables for debugging
int x=0;
int y=0;
int i=0;

//Hardware list
int Speaker=9;

int Button1=2;
int ButtonValue1=0;
int Button2=3;
int ButtonValue2=0;
int Button3=4;
int ButtonValue3=0;
int Button4=5;
int ButtonValue4=0;
int Button5=6;
int ButtonValue5=0;
int Button6=7;
int ButtonValue6=0;
int Button7=8;
int ButtonValue7=0;

int Sensor1=A0;
int SensorValue1=0;
int Sensor2=A1;
int SensorValue2=0;
int Sensor3=13;
int SensorValue3=0;


//Prototypes
//void attack(); - For use later maybe
void decay();
void RemoveFluctuations();
  
void setup() {

 
  //Set timer1 for 8-bit fast PWM output
  pinMode(9, OUTPUT); // Make timer's PWM pin an output
  TCCR1B  = (1 << CS10);    // Set prescaler to full 16MHz
  TCCR1A |= (1 << COM1A1);  
  TCCR1A |= (1 << WGM10);   // CTC - Put timer into 8-bit fast PWM mode
  TCCR1B |= (1 << WGM12); 

  //Set up timer 2 to call ISR when interrupted
  TCCR2A = 0;               
  TCCR2B = (1 << CS21);     // Set prescaler to divide by 8, pushing to 2 MHz
  TIMSK2 = (1 << OCIE2A);   
  OCR2A = 1;               // sets the frequency of the generated wave
  sei();                    

//Input declaration
for(i=2;i<8;i++){
  pinMode(i,INPUT); //Notes
}
pinMode(Sensor3, INPUT); //For half-notes, it is just a button
pinMode(A0, INPUT); //For decay (Potentiometer)
pinMode(A1, INPUT); //For manipulating wave (Potentiometer)

  Serial.begin(9600);

}


void loop() {  
  //Read Real Time Values
  SensorValue1=analogRead(Sensor1);
  SensorValue2=analogRead(Sensor2);
  SensorValue3=digitalRead(Sensor3);
  //Take care of Fluctuations
  RemoveFluctuations();

/*Serial.println(SensorValue2);//Testing
delay(500);*/

  ButtonValue1=digitalRead(Button1);
  ButtonValue2=digitalRead(Button2);
  ButtonValue3=digitalRead(Button3);
  ButtonValue4=digitalRead(Button4);
  ButtonValue5=digitalRead(Button5);
  ButtonValue6=digitalRead(Button6);
  ButtonValue7=digitalRead(Button7);

//When Instrument is inactive, Default - Decay
        if(ButtonValue1==HIGH && ButtonValue2==HIGH && ButtonValue3==HIGH && ButtonValue4==HIGH&& ButtonValue5==HIGH && ButtonValue6==HIGH && ButtonValue7==HIGH && AMP==1000){
    decay();
    AMP=1;
   }

//Populate table with  wave
     for (int i=0; i<LENGTH; i++) {
      int v=(AMP*sin((SensorValue2/10*PI2/LENGTH)*i));// Calculate current entry
 //     v+=(AMP*sin((PI2/LENGTH)*i*(SensorValue2/100))); //Experimenting with partials, this may change, am trying to come up with something that sounds better*/
      wave[i] = int(v+OFFSET);// Store value as integer 
  }
  

  
//Note Press
    if(ButtonValue1==LOW && SensorValue3==HIGH){
     OCR2A=59.72;  
     AMP=1000;
    } 
 
    if(ButtonValue2==LOW && SensorValue3==HIGH){
     OCR2A=53.20;
     AMP=1000;
    } 
    
    if(ButtonValue3==LOW && SensorValue3==HIGH){
     OCR2A=47.40;     
     AMP=1000;   
    }
    
    if(ButtonValue4==LOW && SensorValue3==HIGH){
     OCR2A=44.74;
     AMP=1000;
    
    }    
    if(ButtonValue5==LOW && SensorValue3==HIGH){
     OCR2A=39.85;   
     AMP=1000;
    } 
    
    if(ButtonValue6==LOW && SensorValue3==HIGH){
     OCR2A=35.51;   
     AMP=1000;
    }
    
    if(ButtonValue7==LOW && SensorValue3==HIGH){
     OCR2A=31.63;   
     AMP=1000;
    }
   
  //Sharps activated by sensor3
  if(ButtonValue1==LOW && SensorValue3==LOW){
     OCR2A=56.37; 
     AMP=1000;
    } 
    
    if(ButtonValue2==LOW && SensorValue3==LOW){
     OCR2A=50.22; 
     AMP=1000;
    } 
    
    if(ButtonValue3==LOW && SensorValue3==LOW){
     OCR2A=44.74;
     AMP=1000;
    }
    
    if(ButtonValue4==LOW && SensorValue3==LOW){
     OCR2A=42.22; 
     AMP=1000;
    }    
    
    if(ButtonValue5==LOW && SensorValue3==LOW){
     OCR2A=37.62; 
     AMP=1000;
    } 
    
    if(ButtonValue6==LOW && SensorValue3==LOW){
     OCR2A=33.51; 
     AMP=1000;
    }
    
    if(ButtonValue7==LOW && SensorValue3==LOW){
     OCR2A=29.86; 
     AMP=1000;
    }

}

//Output Compare Match Interrupt, called every time TCNT2 = OCR2A
ISR(TIMER2_COMPA_vect) {
  static byte index=0;    // Points to successive entries in the wavetable
  OCR1AL = wave[index++]; // Update the PWM output
  asm("NOP;NOP");         // Added 2 no operation cycles for fine tuning
  TCNT2 = 6;              // This is timing to compensate for time spent in ISR
}

//Defines duration of release
void decay(){
  int i,j;
  for(j=0;j<128;j++){
    for(i=0;i<LENGTH;i++){
      if(wave[i]<126){wave[i]++;}
      if(wave[i]>128){wave[i]--;}
      ButtonValue1=digitalRead(Button1);
      ButtonValue2=digitalRead(Button2);
      ButtonValue3=digitalRead(Button3);
      ButtonValue4=digitalRead(Button4);
      ButtonValue5=digitalRead(Button5);
      ButtonValue6=digitalRead(Button6);
      ButtonValue7=digitalRead(Button7);
      SensorValue3=digitalRead(Sensor3);
     if(ButtonValue1==LOW || ButtonValue2==LOW || ButtonValue3==LOW || ButtonValue4==LOW || ButtonValue5==LOW || ButtonValue6==LOW || ButtonValue7==LOW || SensorValue3==LOW){
        break; //Interrupt if another key is pressed
        }  
     if(SensorValue1<900){
       delayMicroseconds(SensorValue1/10);
       }
     if(SensorValue1>900){
        delayMicroseconds(SensorValue1); //If potentiometer is turned very high, it will produce a continuous sound
       }
  }
 }
}

//Maybe use later
/*void attack(){
  int i,j;
  for(j=0;j<128;j++){
    for(i=0;i<LENGTH;i++){
      if(wave[i]<127){wave[i]--;}
      if(wave[i]>127){wave[i]++;}    
    }
      ButtonValue1=digitalRead(Button1);
      ButtonValue2=digitalRead(Button2);
      ButtonValue3=digitalRead(Button3);
      ButtonValue4=digitalRead(Button4);
      ButtonValue5=digitalRead(Button5);
      ButtonValue6=digitalRead(Button6);
      ButtonValue7=digitalRead(Button7);
      SensorValue3=digitalRead(Sensor3);
     if((ButtonValue1==HIGH && ButtonValue2==HIGH && ButtonValue3==HIGH && ButtonValue4==HIGH && ButtonValue5==HIGH && ButtonValue6==HIGH && ButtonValue7==HIGH)){
     break; //Interrupt fade in if key is released or Sharps are toggled
     }
    delay(SensorValue1/10);
   }
*/   

void RemoveFluctuations(){
  if(SensorValue2>=0 && SensorValue2<50){
    SensorValue2=25;
  }
  if(SensorValue2>50 && SensorValue2<100){
    SensorValue2=75;
  }
  if(SensorValue2>100 && SensorValue2<150){
    SensorValue2=125;
  }
  if(SensorValue2>150 && SensorValue2<200){
    SensorValue2=175;
  }
  if(SensorValue2>200 && SensorValue2<250){
    SensorValue2=225;
  }
  if(SensorValue2>250 && SensorValue2<300){
    SensorValue2=275;
  }
  if(SensorValue2>300 && SensorValue2<350){
    SensorValue2=325;
  }
  if(SensorValue2>350 && SensorValue2<400){
    SensorValue2=375;
  }
  if(SensorValue2>400 && SensorValue2<450){
    SensorValue2=425;
  }
  if(SensorValue2>450 && SensorValue2<500){
    SensorValue2=475;
  }
  if(SensorValue2>500 && SensorValue2<550){
    SensorValue2=525;
  }
  if(SensorValue2>550 && SensorValue2<600){
    SensorValue2=575;
  }
  if(SensorValue2>600 && SensorValue2<650){
    SensorValue2=625;
  }
  if(SensorValue2>650 && SensorValue2<700){
    SensorValue2=675;
  }
  if(SensorValue2>700 && SensorValue2<750){
    SensorValue2=725;
  }
  if(SensorValue2>750 && SensorValue2<800){
    SensorValue2=775;
  }
  if(SensorValue2>800 && SensorValue2<850){
    SensorValue2=825;
  }
  if(SensorValue2>850 && SensorValue2<900){
    SensorValue2=875;
  }
  if(SensorValue2>900 && SensorValue2<950){
    SensorValue2=925;
  }
  if(SensorValue2>950 && SensorValue2<=1023){
    SensorValue2=1000;
  }
  
}
/*void SharpsToggleDetection(){
  SensorValue3=digitalRead(Sensor3);
  if (SensorValue3==HIGH)
}
*/
