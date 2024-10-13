#define DL1  17
#define DL2  16
#define PWML 5

#define DR1  8
#define DR2  9
#define PWMR 6

#define leftsensor 7
#define frontsensor A6
#define rightsensor 4

#define leftqtr A4
#define rightqtr A5

int qtr = 700;  //ค่ากลาง

#define led_buzzer 3
#define button 2
#define ir 2

#define DS1 10
#define DS2 11
#define DS3 12

int irr=0;
int Speed = 20;
int MaxSpeed = 102; // Idle Speed while no sensor giving data.
int LastValue = 5; // Last Value Variable for remembering last Opponent sensor sense.
void setup() {
  pinMode(leftsensor, INPUT_PULLUP);
  pinMode(frontsensor, INPUT);
  pinMode(rightsensor, INPUT_PULLUP);
  
  pinMode(leftqtr, INPUT_PULLUP);
  pinMode(rightqtr, INPUT_PULLUP);
  
  Serial.begin(9600);
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);

  pinMode(led_buzzer, OUTPUT);
  pinMode(button, INPUT);
  pinMode(ir, INPUT);

  pinMode(DS1, INPUT_PULLUP);
  pinMode(DS2, INPUT_PULLUP);
  pinMode(DS3, INPUT_PULLUP);
  
  digitalWrite(led_buzzer, HIGH);

    tone(led_buzzer, 3800, 1000);
  delay(100);
  noTone(led_buzzer);
  


  
  delay(5000);                     //หน่วงเวลา
}

void loop() {

if (analogRead(leftqtr)>800 && analogRead(rightqtr)>800 ){
if (analogRead(frontsensor)<400) {
   Set_Motor(255, 255, 1);
   Serial.println("forward");
   
  } else if (digitalRead(leftsensor) == LOW) {
    Set_Motor(-120,120, 100);
    Serial.println("left");
    
  } else if (digitalRead(rightsensor) == LOW) {
 
    Set_Motor(120, -120, 100);
    Serial.println("right");
    
  } 
    
}else

if (analogRead(leftqtr)<qtr && analogRead(rightqtr)>800 ){
  Set_Motor(-80, -80, 250);
  Set_Motor(80, -80, 400);
  Serial.println("Out of area");
  //LastValue=3;
}else

if (analogRead(leftqtr)>qtr && analogRead(rightqtr)<1020 ){
  Set_Motor(-80, -80, 250);
  Set_Motor(-80, 80, 400);
 // LastValue=7; 
  Serial.println("Out of area");
}

  
  /*Set_Motor(100, 100, 1000);
  Set_Motor(100, -100, 1000);
  Set_Motor(-100, 100, 1000);*/
   
   
    if (digitalRead(DS1) == 1 && digitalRead(DS2) == 1 && digitalRead(DS3) == 0) {
      Set_Motor(80, 80, 500);
      Set_Motor(-80, 80, 200);
        Serial.println("go to left");
      }else if (digitalRead(DS1) == 0 && digitalRead(DS2) == 0 && digitalRead(DS3) == 0) {
        Set_Motor(0, 0, 0);
        Serial.println("wait");
      }else if (digitalRead(DS1) == 0 && digitalRead(DS2) == 1 && digitalRead(DS3) == 1) {
        Set_Motor(80, 80, 500);
      Set_Motor(80, -80, 200);
        Serial.println("go to right");
      }else if (digitalRead(DS1) == 1 && digitalRead(DS2) == 0 && digitalRead(DS3) == 1) {
        Set_Motor(120,120, 1);
        Serial.println("limit break");
      }else if (digitalRead(DS1) == 1 && digitalRead(DS2) == 1 && digitalRead(DS3) == 1) {
        Set_Motor(35,30,1 );
        Serial.println("slow life");
      }
       /* if (analogRead(frontsensor) < 400) {
          
 
   Set_Motor(40,40, 1);
   
  } else if (digitalRead(leftsensor) == LOW) {
    
    Set_Motor(-80, 80, 160);
    
    
  } else if (digitalRead(rightsensor) == LOW) {
    
    Set_Motor(80, -80, 160);
    
    
  }else{
    Set_Motor(45, 45, 1);
  }
      }*/
      
    

  
}
//ปรับปรุงและแก้ไข โดย https://web.facebook.com/oat.KT.robot

//////////////////////////////////////////Code Setting Motor *[ห้ามลบ]*////////////////////////////////////////////////

void Set_Motor(int spl, int spr, int timeV)
{
  if (spl > 0)
  {
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, HIGH);
    analogWrite(PWML, spl);
  }
  else if (spl < 0)
  {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, -spl);
  }
  else
  {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, HIGH);
    analogWrite(PWML, -255);
  }
  //////////////////////////////////////
  if (spr > 0)
  {
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, HIGH);
    analogWrite(PWMR, spr);
  }
  else if (spr < 0)
  {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, -spr);
  }
  else
  {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, HIGH);
    analogWrite(PWMR, -255);
  }
  delay(timeV);
}
