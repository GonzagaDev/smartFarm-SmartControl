class Reles {
  //22 a 37 Sendo 22 relé 1 e 37 relé 16
  int reles[16] = { 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37 };
  #define qtdReles (sizeof(reles) / sizeof(char *))  //array size
  public:
    Reles() {}

    void setup() {
      for(int i = 0; i < qtdReles; i = i + 1){
        pinMode(reles[i], OUTPUT);
      }
    };

    void on(int numeroRele){
       digitalWrite(reles[numeroRele], HIGH);
    };

    void off(int numeroRele){
       digitalWrite(reles[numeroRele], LOW);
    };
};