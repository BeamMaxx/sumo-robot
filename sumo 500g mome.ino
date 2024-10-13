#include <Servo.h>
#define lA 5
#define lB 6
#define rA 10
#define rB 9
int distance = 100 ;
Servo s1;
void setup() {
  s1.attach(3);
  Serial.begin(9600);
  pinMode(lA, OUTPUT);
  pinMode(lB, OUTPUT);
  pinMode(rA, OUTPUT);
  pinMode(rB, OUTPUT);
}
void loop() {
  s1.write(0);
  delay(500);
  s1.write(180);
  delay(500);
  readsensor();
  //Run(400);
  // forward(100,100);
  // delay(1000);
  // backward(100,100);
  // delay(1000);
}
void readsensor() {
  Serial.print(analogRead(A6));//qtr
  Serial.print("  ");
  Serial.print(analogRead(A5));//qtr
  Serial.print("  ");
  Serial.print(analogRead(A0));//left
  Serial.print("  ");
  Serial.print(analogRead(A1));//fornt
  Serial.print("  ");
  Serial.print(analogRead(A7));//right
  Serial.print("  ");
  //Serial.print(analogRead(A7));
  //Serial.println("  ");
  delay(3000);
}
void Run(int distance) {
  delay(5000);
while (1) {
        if (analogRead(A6) < 100 || analogRead(A5) < 100) {
          b(200);
          delay(200);
          r(200);
          delay(150);
        } else if (analogRead(A2) > distance && analogRead(A3) < distance && analogRead(A4) > distance) {
          f(255);
        } else if (analogRead(A2) < distance && analogRead(A3) > distance && analogRead(A4) > distance) {
          l(120);delay(100);
        } else if (analogRead(A2) > distance && analogRead(A3) > distance && analogRead(A4) < distance) {
          r(120);delay(100);
        } else {
          f(100);
        }
      }
}
void f(int s) {
  analogWrite(lA, s);
  analogWrite(lB, 0);
  analogWrite(rA, s);
  analogWrite(rB, 0);
}

void r(int s) {
  analogWrite(lA, s);
  analogWrite(lB, 0);
  analogWrite(rA, 0);
  analogWrite(rB, s);
}
void l(int s) {
  analogWrite(lA, 0);
  analogWrite(lB, s);
  analogWrite(rA, s);
  analogWrite(rB, 0);
}
void b(int s) {
  analogWrite(lA, 0);
  analogWrite(lB, s);
  analogWrite(rA, 0);
  analogWrite(rB, s);
}

void s() {

  analogWrite(lA, 100);
  analogWrite(lB, 100);
  analogWrite(rA, 100);
  analogWrite(rB, 100);
}
void bl(int s) {

  analogWrite(lA, s);
  analogWrite(lB, s);

}
