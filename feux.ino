
// On définit les variables pour chaque broche 
//FEU 1 
const int R1 = 2;      //La broche 4 devient le feu rouge 1 
const int J1 = 3;      //La broche 3 devient le feu jaune 1 
const int V1 = 4;      //La broche 2 devient le feu vert 1 
//FEU2 
const int R2 = 5;      //La broche 8 devient le feu rouge 2 
const int J2 = 6;      //La broche 9 devient le feu jaune 2 
const int V2 = 7;     //La broche 10 devient le feu vert 2 
//TEMPS 
int time1 = 2000;     //Le temps est fixé à 2 secondes 
int time2 = 8000;     //Le temps est fixé à 8 secondes 
 
void setup() { 
 
//On initialise les sorties 
pinMode(R1, OUTPUT); 
pinMode(J1, OUTPUT); 
pinMode(V1, OUTPUT); 
 
pinMode(R2, OUTPUT); 
pinMode(J2, OUTPUT); 
pinMode(V2, OUTPUT); 
} 
 
void loop() { 
 
//Phase 1: R1 et V2 sont allumés, R2, J1 et J2 sont éteints 
digitalWrite(R2, LOW);     //R2 éteint 
digitalWrite(J1, LOW);     //J1 éteint 
digitalWrite(J2, LOW);     //J2 éteint 
digitalWrite(R1, HIGH);    //R1 allumé 
digitalWrite(V2, HIGH);    //V2 allumé 
delay(time2);              //durée: 6'000 millisecondes, soit 6 secondes 
 
//Phase 2: R1, J1, J2 allumés et V2 éteint 
digitalWrite(V2, LOW);     //V2 éteint 
digitalWrite(J1, HIGH);    //J1 allumé 
digitalWrite(J2, HIGH);    //J2 allumé 
delay(time1);               //durée: 2'000 millisecondes, soit 2 secondes 
 
//Phase 3: R1, J1, J2 éteints et V1 et R2 allumés 
digitalWrite(R1, LOW);     //R1 éteint 
digitalWrite(J1, LOW);     //J1 éteint 
digitalWrite(J2, LOW);     //J2 éteint 
digitalWrite(V1, HIGH);    //V1 allumé 
digitalWrite(R2, HIGH);    //R2 allumé 
delay(time2); 
 
//Phase 4: V1 éteint et J1, J2 et R2 allumés 
digitalWrite(V1, LOW);     //V1 éteint 
digitalWrite(J1, HIGH);    //J1 allumé 
digitalWrite(J2, HIGH);    //J2 allumé 
digitalWrite(R2, HIGH);    //R2 allumé 
delay(time2); 
}
