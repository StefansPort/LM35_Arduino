


float LM35Sensor=A5;            // LM35 an A5 angeschlossen
float sensormesswert;           // Variable für den Messwert des Sensors
int temperatur;                 // Variable für die spätere Umrechnung zur Temperatur
unsigned int Abfrage;           // Variable für die spätere Prüfung "Ist der Zeitpunkt zur nächsten Messung erreicht?", unsigned = nur Positivzahlen
const int Zeitvorgabe = 1000;   // Zeitvorgabe bis zur erneuten Herausgabe von Daten in Millisekunden, const = Read-only

void setup() 
{
Serial.begin(9600);             // Start serielle Kommunikation

Serial.println("************************"); // *******************************
Serial.println("****Arduino is ready****"); // Ausgabe auf dem seriellen Monitor vor dem Loop, um zu überprüfen, ob die serielle Kommunikation funktioniert
Serial.print("**Check every ");             // 
Serial.print(Zeitvorgabe);                  // Wiedergabe der definierten Zeitvorgabe auf dem seriellen Monitor
Serial.println(" ms**");                    // 
Serial.println("************************"); // ******************************* 
}

void loop()                     // Start des Loop
{

sensormesswert=analogRead(LM35Sensor);    // Auslesen des analogen Messwertes an A5
                                
temperatur=((sensormesswert*500)/1024);   // Umrechnung des Messergebnis in Grad Celsius
                                          // Anmerkung: Der Sensor wird mit 5V betrieben, misst in 10mV-Schritten.
                                          // 5000mV/10mV=500
                                          // Auflösung Arduino Uno 5V/1024 Teile, deshalb Teiler durch 1024 (Der Uno misst von 0-1023=1024 Teile)

unsigned long Ergebnis = millis();        // Variable "Ergebnis" zur Prüfung ob eine nächste Ausgabe erfolgen soll

  if (Ergebnis - Abfrage >= Zeitvorgabe) {
    Abfrage = Ergebnis;

// Rechnerisch: Wenn das Ergebnis in Millis abzüglich der Abfrage größer oder gleich der Zeitvorgabe, dann ist die Abfrage = Ergebnis
// Gedanklich: Ansonsten lasse hier so lange im Kreis laufen BIS die Zeitvorgabe erreicht ist, ... danach:


Serial.print(temperatur);                 // Im seriellen Monitor wird die Temperatur eingeblendet. Ohne Zeilenumbruch.
Serial.println("°C");                     // Im seriellen Monitor wird hinter der Temperatur die Einheit eingeblendet. Mit Zeilenumbruch

// Sprung an den Anfang des Loop

}}
