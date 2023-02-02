#include "Config.h"
#include "Alimentador.h"
#include "Thread.h"
#include "ThreadController.h"

Config config;
Alimentador alimentador;

void setup() {
  config.setup(9600);
}


void loop() {
 alimentador.shouldRunThenRun();
}




