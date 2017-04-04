
// PART I set up definitions
#include <MouseController.h>
//for serial input from a second (slave to master) Arduino if using 2 optical mice to get movement in all angles.
#define SOP '<'
#define EOP '>'
// Initialize USB Controller
USBHost usb;

// Attach mouse controller to USB
MouseController mouse(usb);


//set channel you want movement to output TTL on in this case channel 36
const int movement = 36;
const int overflow = 6000; //set overflow for you mouse.
const int movementeventID = 99; //set ID of movement event (this is just for subsetting in data frame if you have other events in the same log file).
const int timeout = 5; //time out in milllisecond for serial on Arduino. Set this to what resolution you want.

//set rest of variables
int roll = 0;
int pitch = 0;
int jaw = 0;

int jawdelta;
int pitchdelta;
int rotation = 0;

int unsigned long timer = 0; // unsigned long means its a really long number to be stored 
int trial = 0;
int varState = 0;


// PART II mouse move events

void mouseMoved() {
  pitchdelta = mouse.getYChange();
  jawdelta = mouse.getXChange();
  pitch = pitchdelta + pitch;
  jaw = jawdelta + jaw;
  if(roll > overflow | roll < (-overflow) ){roll = 0;}
  if(pitch > overflow | pitch < (-overflow) ){
    pitch = 0;
    rotation++;
  }
  if(jaw > overflow | jaw < (-overflow) ){jaw = 0;}
    
    Serial.print(timer);
    Serial.print(',');
    Serial.print(trial);
    Serial.print(',');
    Serial.print(varState);
    Serial.print(',');  
    Serial.print(movementeventID);
    Serial.print(',');
    Serial.print(jawdelta);
    Serial.print(',');
    Serial.println(pitchdelta);

    digitalWrite(movement, HIGH);
    delay(timeout);
    digitalWrite(movement, LOW);
    delay(timeout);

}





// PART III setup the physical input outputs on the chip
void setup() {
  // initialize serial communication at 9600
  Serial.begin(9600);
  //mouse control
  Mouse.begin();
  // you have to trigger the experiment by opening the log window and trigger output. But you can basically set the trigger to anything you want.
 
  Serial.println("******************************************************");
  Serial.println("PLEASE INITIALIZE:");
  Serial.println("type anything into the console and press start"); 
  Serial.println("******************************************************");
   while(Serial.available()==0){
   };

}


// how output is going to be written to you log file. Here CSV.
void printInfo(int unsigned long  timer, int trial, int varState, int event, int value) {
  Serial.print(timer);
  Serial.print(',');
  Serial.print(trial);
  Serial.print(',');
  Serial.print(varState);
  Serial.print(',');  
  Serial.print(event);
  Serial.print(',');
  Serial.print(value);
  Serial.print(',');
  Serial.println(0);
}



// PART III the loop
// the loop routine runs over and over again forever:
void loop() {
  
 while(trial<=9999){

  usb.Task();
  // set the timer to current time
  timer = millis();
  
  //set everyhting you want to happen in the experiment here.
  
 }

 //set everything to low here to make sure othing triggers when experiment is done

 
 Serial.println("******************************************************");
 exit(0); 
}

