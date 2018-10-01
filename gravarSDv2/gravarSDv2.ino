#include <SdFat.h>
 
SdFat sdCard;
SdFile meuArquivo;

const int pinoPWM = 3;
const int chipSelect = 4;
const int sensorCorrente = A0;
const int sensorTensao = A1;
const int botaoGravar = 2;
const int ledGravar = 7;

void setup()
{
Serial.begin(9600);
pinMode(pinoPWM, INPUT);
pinMode(sensorTensao, INPUT);
pinMode(sensorCorrente, INPUT);
pinMode(botaoGravar, INPUT);
pinMode(ledGravar, OUTPUT);

if(!sdCard.begin(chipSelect,SPI_HALF_SPEED))sdCard.initErrorHalt();

}

void loop()
{
digitalWrite(ledGravar,LOW);
int tensao = analogRead(sensorTensao);
int corrente = analogRead(sensorCorrente);
int pwm = pulseIn(pinoPWM,HIGH);

//tensao corrente pwm
String str1 = tensao + " ";
String str2 = str1 + corrente;
String str3 = str2 + " ";
String valor = str3 + pwm;

int gravar = digitalRead(botaoGravar);
if(gravar==HIGH)
{
  //Serial.println("Gravando");
  digitalWrite(ledGravar,HIGH);
    if (!meuArquivo.open("servo_data.txt", O_RDWR | O_CREAT | O_AT_END))
    {
      sdCard.errorHalt("Erro na abertura do arquivo SERVO_DATA.TXT!");
    }
    Serial.println(valor);
    meuArquivo.println(valor);
    meuArquivo.close();
}
delay(100);
}
