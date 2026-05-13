// ============================================
//   STATION MÉTÉO - DHT11 + LCD I2C
//   Arduino UNO
// ============================================

// Bibliothèque pour la communication I2C (LCD)
#include <Wire.h>

// Bibliothèque pour contrôler l'écran LCD I2C
#include <LiquidCrystal_I2C.h>

// Bibliothèque pour le capteur DHT (température + humidité)
#include <DHT.h>

// Définition de la broche où est connecté le capteur DHT11
#define DHTPIN 2

// Définition du type de capteur utilisé (DHT11)
#define DHTTYPE DHT11

// Création de l'objet capteur DHT avec la broche et le type
DHT dht(DHTPIN, DHTTYPE);

// Création de l'objet écran LCD
// 0x27 = adresse I2C de l'écran
// 16 colonnes et 2 lignes
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ============================================
// SETUP : exécuté une seule fois au démarrage
// ============================================
void setup() {

  // Démarrage de la communication série (PC)
  Serial.begin(9600);

  // Initialisation du capteur DHT11
  dht.begin();

  // Initialisation de l'écran LCD
  lcd.begin();          // initialise le LCD
  lcd.backlight();      // allume le rétroéclairage

  // Position du curseur (colonne 0, ligne 0)
  lcd.setCursor(0,0);

  // Affichage du texte
  lcd.print("Station Meteo");

  // Position du curseur (colonne 0, ligne 1)
  lcd.setCursor(0,1);

  // Affichage du texte
  lcd.print("Demarrage...");

  // Pause de 2 secondes pour affichage
  delay(2000);

  // Efface l'écran LCD
  lcd.clear();
}

// ============================================
// LOOP : boucle infinie
// ============================================
void loop() {

  // Lecture de la température (°C)
  float temperature = dht.readTemperature();

  // Lecture de l'humidité (%)
  float humidite = dht.readHumidity();

  // Vérifie si les données sont valides
  if (isnan(temperature) || isnan(humidite)) {

    // Efface l'écran
    lcd.clear();

    // Affiche erreur ligne 1
    lcd.setCursor(0,0);
    lcd.print("Erreur DHT11");

    // Message dans le moniteur série
    Serial.println("Erreur lecture DHT11");

    // Pause
    delay(2000);

    // Sort de la boucle et recommence
    return;
  } 
  else{
 // Efface l'écran avant nouvel affichage
  lcd.clear();

  // =========================
  // AFFICHAGE TEMPÉRATURE
  // =========================

  // Position ligne 1
  lcd.setCursor(0,0);

  // Texte
  lcd.print("Temp:");

  // Valeur température
  lcd.print(temperature);

  // Symbole degré (ASCII 223)
  lcd.print((char)223);

  // Unité
  lcd.print("C");

  // =========================
  // AFFICHAGE HUMIDITÉ
  // =========================

  // Position ligne 2
  lcd.setCursor(0,1);

  // Texte
  lcd.print("Hum:");

  // Valeur humidité
  lcd.print(humidite);

  // Symbole %
  lcd.print("%");

  // =========================
  // MONITEUR SÉRIE (PC)
  // =========================

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidite: ");
  Serial.println(humidite);

  Serial.println("----------------");

  // Pause de 2 secondes avant nouvelle lecture
  delay(2000);

  }

 
}