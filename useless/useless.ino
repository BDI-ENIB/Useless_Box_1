/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int entree = 7 ; //interrupteur n°1
int sortie = 5;//interrupteur n°2
int etat_bouton = LOW ;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(entree, OUTPUT) ;
  pinMode(sortie, INPUT) ;

}

void loop() {

// put your main code here, to run repeatedly:
  digitalWrite(entree, HIGH) ;
  etat_bouton = digitalRead(sortie) ;
  digitalRead(pos) ;
  
  while (etat_bouton == LOW) {//bouton à replacer
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);   // waits 15ms for the servo to reach the position
    pos+=30;
  }
  
  if (etat_bouton == HIGH and pos != 0) {//bouton bien
    pos=0;
    myservo.write(pos) ; //moteur retourne à sa pos initiale
  }
}

