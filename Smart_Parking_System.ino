#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

int PIR1 = 11;
int PIR2 = 10;

Servo servo_13;
Servo servo_12;
int position1 = 90;
int position2 = 90;

//int i = 0;
//int j = 0;
//int k = 0;

int available = 7;
int total = 7;

void setup()
{
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT);
  
  servo_13.attach(13, 500, 2500);
  servo_12.attach(12, 500, 2500);
  
  servo_13.write(90);
  servo_12.write(90);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  
  int gate1 = digitalRead(PIR1);
  int gate2 = digitalRead(PIR2);
  
  Serial.print("Gate 1: ");
  Serial.println(gate1);
  Serial.print("Gate 2: ");
  Serial.println(gate2);

  if (available == 1){
    //lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Space left for");
  lcd.setCursor(0,1);
    lcd.print("     ");
  lcd.print(available);
  lcd.print(" car      ");
  }
  else if (available >= 1){
  //lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Space left for");
    lcd.setCursor(0,1);
    lcd.print("     ");
  lcd.print(available);
  lcd.print(" cars      ");
  }
  else{
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("     Sorry!      ");
    lcd.setCursor(1,1);
    lcd.print("No place left!");  
  }
    
  if (gate1 == 1) {
    if(available != 0){
      available--;
      servo1open();
      servo1close();
    }
  }
    
  else if (gate2 == 1) {
    if(available != total){
      available++;
      servo2open();
      servo2close();
    }
  }
   


}

//SERVO 1
void servo1open(){
  
  for (position1 = 90; position1 <= 180; position1 += 1) {
    servo_13.write(position1);
    delay(5); 
  }
  delay(3000);
}

void servo1close(){
  for (position1 = 180; position1 >= 90; position1 -= 1) {
    servo_13.write(position1);
    delay(5);
  }
  //delay(2000);
}

//SERVO 2
void servo2open(){
  
  for (position2 = 90; position2 <= 180; position2 += 1) {
    servo_12.write(position2);
    delay(5); 
  }
  delay(3000);
}

void servo2close(){
  for (position2 = 180; position2 >= 90; position2 -= 1) {
    servo_12.write(position2);
    delay(5);
  }
  //delay(2000);
}
