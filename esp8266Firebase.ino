#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Configure com suas credenciais
// Credencial está em configuração do projeto, contas e serviços.
#define FIREBASE_HOST "esp8266-9b07c-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "xd6x07LftrBEFN3bJ7R1As9LOiNkQOqhoVxgEEkC"
#define WIFI_SSID "LinkSysE900"
#define WIFI_PASSWORD "123654789"

int led;
void setup() {
  //Define GPIO2 como saída
  pinMode(2, OUTPUT);
  //Inicia o monitor serial
  Serial.begin(115200);

  //Rotina pra conectar ao wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("conectado: ");
  Serial.println(WiFi.localIP());

  //Iniciar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  led = Firebase.getBool("led");

  if(led == true){
    Firebase.setBool("led",false);
    digitalWrite(2, LOW);
  }else{
    Firebase.setBool("led",true);
    digitalWrite(2, HIGH);
  }
  delay(1000);
}
