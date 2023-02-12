#include <Servo.h>;
#define Lpwm_pin 5 // pin of controlling speed---- ENA of motor driver board
#define Rpwm_pin 10 // pin of controlling speed--- ENB of motor driver board
#define trigPin A1
#define echoPin A0
int pinLB = 2; // IN1 of motor driver board
int pinLF = 4; // IN2 of motor driver board
int pinRB = 7; // IN3 of motor driver board
int pinRF = 8; // IN4 of motor driver board
unsigned char Lpwm_val; // left wheel speed max 250
unsigned char Rpwm_val; // right wheel speed max 250
#define Car_state = 0;

#define LineSensorLeft 6
#define LineSensorCenter 9
#define LineSensorRight 11

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //car pins
  pinMode(pinLB,OUTPUT); //pin 2
  pinMode(pinLF,OUTPUT); // pin 4
  pinMode(pinRB,OUTPUT); // pin 7
  pinMode(pinRF,OUTPUT); // pin 8
  pinMode(Lpwm_pin,OUTPUT); // pin 11 (PWM)
  pinMode(Rpwm_pin,OUTPUT); // pin 10 (PWM)
  
}
void moveStraight(){
  //car speed/starts/
  Lpwm_val = 150;
  Rpwm_val = 150;
  analogWrite(Lpwm_pin,Lpwm_val);
  analogWrite(Rpwm_pin,Rpwm_val);
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,HIGH);
}
void myStop(){
  digitalWrite(pinRB,LOW);
  digitalWrite(pinRF,LOW);
  digitalWrite(pinLB,LOW);
  digitalWrite(pinLF,LOW);
}
void turnRight(){
  //car speed/starts/
  Lpwm_val = 180;
  Rpwm_val = 90;
  analogWrite(Lpwm_pin,Lpwm_val);
  analogWrite(Rpwm_pin,Rpwm_val);
  digitalWrite(pinRB,LOW);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,LOW);
}
void strongTurnRight(){
  //car speed/starts/
  Lpwm_val = 250;
  Rpwm_val = 0; //60
  analogWrite(Lpwm_pin,Lpwm_val);
  analogWrite(Rpwm_pin,Rpwm_val);
  digitalWrite(pinRB,LOW);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,LOW);
}
void turnLeft(){
  //car speed/starts/
  Lpwm_val = 80;
  Rpwm_val = 180;
  analogWrite(Lpwm_pin,Lpwm_val);
  analogWrite(Rpwm_pin,Rpwm_val);
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,LOW);
  digitalWrite(pinLB,LOW);
  digitalWrite(pinLF,HIGH);
}
void strongTurnLeft(){
  //car speed/starts/
  Lpwm_val = 0; //60
  Rpwm_val = 220;
  analogWrite(Lpwm_pin,Lpwm_val);
  analogWrite(Rpwm_pin,Rpwm_val);
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,LOW);
  digitalWrite(pinLB,LOW);
  digitalWrite(pinLF,HIGH);
}
void goBack(){
    //car speed/starts/
    Lpwm_val = 150;
    Rpwm_val = 150;
    analogWrite(Lpwm_pin,Lpwm_val);
    analogWrite(Rpwm_pin,Rpwm_val);
     digitalWrite(pinRB,HIGH);  
     digitalWrite(pinRF,LOW);
     digitalWrite(pinLB,HIGH);  
     digitalWrite(pinLF,LOW);  
}

  bool valLeft ;
  bool valCenter ;
  bool valRight ;
void loop() {
   valLeft = digitalRead(LineSensorLeft);
   valCenter = digitalRead(LineSensorCenter);
   valRight = digitalRead(LineSensorRight);
  
  if(valLeft == HIGH && valCenter == HIGH && valRight == HIGH){
    moveStraight();
    }
    else if(valLeft == LOW && valCenter == HIGH && valRight == HIGH){
          while(valLeft != HIGH ){
               strongTurnRight();
               valLeft = digitalRead(LineSensorLeft);
          }
        }
      else if(valLeft == HIGH && valCenter == HIGH && valRight == LOW){
        while(valRight != HIGH ){
               strongTurnLeft();
               valRight = digitalRead(LineSensorLeft);
          }
           
      }
      else if(valLeft == LOW && valCenter == LOW && valRight == HIGH){
       turnRight();
      }
      else if(valLeft == HIGH && valCenter == LOW && valRight == LOW){
         turnLeft();
      }

}
