#include "Config.h"
#include "Alimentador.h"
#include "Thread.h"
#include "ThreadController.h"

#define botaoReset 2
int valorBotao =0;
Config config;
Alimentador alimentador;

void setup() {
  pinMode(botaoReset,INPUT);
  config.setup(9600);
}


void loop() {
 alimentador.shouldRunThenRun();
 valorBotao = digitalRead(botaoReset);

 if(valorBotao){
  // simular ciclo alimentador
  DateTime now = rtc.now();
  alimentador.exec(now.minute());
 }
}




