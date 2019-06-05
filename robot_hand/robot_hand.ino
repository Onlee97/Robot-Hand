#include <Servo.h>
#define MaxChars 20

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
  

int my_index = 0;
int angle = 0;
int newAngle = 0;
char strValue[MaxChars + 1];

void setup() {
  // initialize serial:
  Serial.begin(9600);
  servo0.attach(7);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(8);
  
  //servo.write(0);
}

void loop() {
  //myservo.write(90);
}

int get_angle(char *strValue, int my_index) {
  char val[2];
  val[0] = strValue[my_index];
  int angle0 = atoi(val);
  return angle0*20;
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
      char ch = Serial.read(); //Read every character
      Serial.write(ch);
      if(my_index < MaxChars && isDigit(ch)) { 
            strValue[my_index++] = ch; //Put character that is digit into array
      } 
      else { // if non-digit detected (newline) 
            strValue[my_index] = 0; 
            
            int angle0 = get_angle(strValue, 0);
            int angle1 = get_angle(strValue, 1);
            int angle2 = get_angle(strValue, 2);
            int angle3 = get_angle(strValue, 3);
            int angle4 = get_angle(strValue, 4);
            
            servo0.write(angle0);
            servo1.write(angle1);
            servo2.write(angle2);
            servo3.write(angle3);
            servo4.write(angle4);
            
            
            //newAngle = atoi(strValue);
            //servo0.write(newAngle); 
            //if(newAngle >= 0 && newAngle <= 180){
                   /*
                   if(newAngle < angle) 
                       for(; angle > newAngle; angle -= 1) {
                             myservo.write(angle*20);
                       }  
                    else 
                       for(; angle < newAngle; angle += 1){
                          myservo.write(angle*20);
                    } */
                    //myservo.write(newAngle);
            //}
            my_index = 0;
            angle = newAngle;
      }  
  }
}