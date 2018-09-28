#include <SdFat.h>
 
SdFat sdCard;
SdFile meuArquivo;

const int chipSelect = 4;
const int sensorCorrente = A0;
const int botaoGravar = 0;
const int ledGravar = LOW;

void setup()
{
pinMode(sensorCorrente, INPUT);
pinMode(botaoGravar, INPUT);
pinMode(ledGravar, OUTPUT);
}

void loop()
{
digitalWrite(ledGravar,LOW);
int valor = analogRead(sensorCorrente);
if(botaoGravar)
{
  digitalWrite(ledGravar,HIGH);
    if(!sdCard.begin(chipSelect,SPI_HALF_SPEED))sdCard.initErrorHalt();
    if (!meuArquivo.open("ler_pot.txt", O_RDWR | O_CREAT | O_AT_END))
    {
      sdCard.errorHalt("Erro na abertura do arquivo LER_POT.TXT!");
    }
    meuArquivo.println(valor);
    meuArquivo.close();
}
delay(100);
}