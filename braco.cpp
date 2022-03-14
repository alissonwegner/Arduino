#include <Servo.h>
// INTPUT_PULLUP usado para não precisar usar resistores
#define potGarra 0        // porta A0 Joystick esquerda POT X
#define potBase 1         // porta A1 Joystick esquerda POT Y
#define potAltura 2       // porta A2 Joystick direita  POT X
#define potProfundidade 3 // porta A3 Joystick direita  POT Y
#define botao 6
#define botao2 7

int valorGarra;
int valorBase;
int valorAltura;
int valorProfundidade;

int valorGarraFinal;
int valorBaseFinal;
int valorAlturaFinal;
int valorProfundidadeFinal;
int i = 0; // 1. Inicialização
int arraygarra[] = {90, 180, 90, 180, 100, 180};
int arraybase[] = {0, 180, 90, 180, 100, 180};
int arrayaltura[] = {0, 60, 40, 180, 100, 180};
int arrayprofundidade[] = {40, 100, 50, 180, 100, 180};

Servo myservoBase;         // Objeto servo para controlar a base
Servo myservoGarra;        // Objeto servo para controlar a garra
Servo myservoAltura;       // Objeto servo para controlar a altura do braço
Servo myservoProfundidade; // Objeto servo para profundidade a altura do braço

void setup()
{
    myservoBase.attach(9); // Associa cada objeto a um pino pwm
    myservoGarra.attach(10);
    myservoAltura.attach(11);
    myservoProfundidade.attach(12);
    // pinMode(botao, INPUT_PULLUP);
    // pinMode(botao2, INPUT_PULLUP);
    Serial.begin(9600);   // console serial 9600 Bps
    valorBaseFinal = 180; // valores usados para o controle dos servomotores
    valorAlturaFinal = 180;
    valorProfundidadeFinal = 180;

    Serial.print("Iniciado");
    Serial.print("i:");
    Serial.println(i);
}

void leituraJoysticks()
{
    valorGarra = map(analogRead(potGarra), 0, 1023, 10, 90); // leitura do Joystick POT Garra
    // Serial.print(" Valor Garra ="); Serial.println(valorGarra);                      // print Valor Garra

    valorBase = map(analogRead(potBase), 0, 1023, 0, 180); // leitura do Joystick POT Base
    // Serial.print(" Valor Base ="); Serial.println(valorBase);                   // print Valor Base

    valorAltura = map(analogRead(potAltura), 0, 1023, 0, 180); // leitura do Joystick POT Altura
                                                               //  Serial.print(" Valor Altura ="); Serial.println(valorAltura);               // print Valor Altura

    valorProfundidade = map(analogRead(potProfundidade), 0, 1023, 0, 180); // leitura do Joystick POT Profundidade
    //  Serial.print(" Valor Profundidade ="); Serial.println(valorProfundidade);   // print Valor Profundidade

    //  Serial.println(); Serial.println();
    // salta duas linhas
}

void loop()
{
    leituraJoysticks();
    myservoGarra.write(valorGarra);
    myservoBase.write(valorBase);
    myservoAltura.write(valorAltura);
    myservoProfundidade.write(valorProfundidade); // comando PWM para o servomotor Garra
    if (digitalRead(botao) == HIGH)
    {
        exec();
        digitalWrite(botao, LOW);
        myservoGarra.write(90);
        myservoBase.write(90);
        myservoAltura.write(90);
        myservoProfundidade.write(90);
    }
    if (digitalRead(botao2) == HIGH)
    {
        exec2();
        digitalWrite(botao2, LOW);
            myservoGarra.write(90);
         myservoBase.write(90);
          myservoAltura.write(90);
          myservoProfundidade.write(90);
    }

}

void exec()
{
    for (i = 0; i < 3; i++)
    {
        myservoGarra.write(arraygarra[i]);
        myservoBase.write(arraybase[i]);
        myservoAltura.write(arrayaltura[i]);
        myservoProfundidade.write(arrayprofundidade[i]);
        delay(500);
        Serial.print(" Valor Garra =");
        Serial.println(i);
    }
}
void exec2()
{

    for (i = 1; i <= 3; i++)
    {

        myservoGarra.write(arraygarra[i + 3]);
        myservoBase.write(arraybase[i + 3]);
        myservoAltura.write(arrayaltura[i + 3]);
        myservoProfundidade.write(arrayprofundidade[i + 3]);
        delay(500);

        Serial.print(" Valor Garra =");
        Serial.println(i);

        }
    }

