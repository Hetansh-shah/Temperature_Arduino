#include <muTimer.h> //using inbuilt library function we can write the code by avoiding usage of delay,millis,micros function 
#define Led_pin 13  //  the specific pin number configures the onboard led to work                                  
#define lm35 A1 // configures the analog pin A1 for GPIO

bool LED_State; // bool defines boolean variables and perform logical operations
muTimer myTimer1=muTimer(); //Create an instance of muTimer for generating delay
void setup() {
  // put your setup code here, to run once:
  pinMode(lm35,INPUT); //configures A1 pin (lm35) as input
  pinMode(Led_pin, OUTPUT); // configures the D13 (onboard led) as output
  Serial.begin(9600);//initialize serial communication to 9600Hz baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_value=analogRead(lm35); //reads the analog values of lm35 sensor
  float temperature=(sensor_value*0.488); //converts the analog value to degree celcius
  Serial.print("Temperature = "); //prints "Temperature = " on the serial monitor
  Serial.print(temperature); //prints the value of temperature on the serial monitor
  Serial.println(" degree Celcius");//prints "degree Celcius = " on the serial monitor
  if (temperature>30){
    LED_State=myTimer1.delayOnOff(!LED_State, 500, 500);//uses delayOnOff(variable,OnTime,OffTime) from muTimer library and sets ON time and OFF time in microsecons as 500,500 respectively
    digitalWrite(Led_pin, LED_State);//Writes the new value of LED_State to pin Led_pin
  }
  else{
    LED_State=myTimer1.delayOnOff(!LED_State, 250, 250);//uses delayOnOff(variable,OnTime,OffTime) from muTimer library and sets ON time and OFF time in microseconds as 250,250 respectively
    digitalWrite(Led_pin, LED_State);//Writes the new value of LED_State to pin Led_pin
  }  
}


