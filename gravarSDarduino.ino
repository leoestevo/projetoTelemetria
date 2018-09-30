#include <SdFat.h>
 
SdFat sdCard;
SdFile meuArquivo;

const int chipSelect = 4;
const int potenciometro = A0;
const int botaoGravar = 2;
const int ledGravar = 7;

void setup()
{
Serial.begin(9600);
pinMode(potenciometro, INPUT);
pinMode(botaoGravar, INPUT);
pinMode(ledGravar, OUTPUT);

if(!sdCard.begin(chipSelect,SPI_HALF_SPEED))sdCard.initErrorHalt();

}

void loop()
{
digitalWrite(ledGravar,LOW);
//Serial.println("Veio até aqui");
int valor = analogRead(potenciometro);
int gravar = digitalRead(botaoGravar);
if(gravar==HIGH)
{
  //Serial.println("Gravando");
  digitalWrite(ledGravar,HIGH);
    if (!meuArquivo.open("ler_pot.txt", O_RDWR | O_CREAT | O_AT_END))
    {
      sdCard.errorHalt("Erro na abertura do arquivo LER_POT.TXT!");
    }
    Serial.println(valor);
    meuArquivo.println(valor);
    meuArquivo.close();
}
delay(100);
}
