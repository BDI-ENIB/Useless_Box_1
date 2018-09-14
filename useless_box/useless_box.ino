/*
  programme useless box
  quand on active le switch, le moteur s'active et fait tourner le bras
  le bras pousse la porte et appuie sur le switch
  quand le switch est désactivé par le bras, le moteur tourne dans l'autre sens jusqu'à sa position de départ
*/

#include <Servo.h>

Servo moteur ; //on déclare le moteur

const int entree = 7 ; //interrupteur n°1
const int sortie = 5;//interrupteur n°2
int etat_bouton = LOW ;
int pos_moteur = 0 ;

void setup() {
  // put your setup code here, to run once:
  moteur.attach(9) ; //moteur sur pin 9
  pinMode(entree, OUTPUT) ;
  pinMode(sortie, INPUT) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(entree, HIGH) ;
  etat_bouton = digitalRead(sortie) ;
   pos_moteur = digitalRead(moteur) ;
  if (etat_bouton == LOW) {//bouton à replacer
    moteur.write(100) ; //le moteur avance de 100 degrés (angle au pif pour l'instant)
   
  }
  else if (etat_bouton == HIGH and pos_moteur != 0) {
    moteur.write(0) ; //moteur retourne à sa pos initiale
  }

}
