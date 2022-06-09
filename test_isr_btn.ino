#define ledPin 13      // Пин для светодиода
#define setLedOnPin 3  // Пин кнопки включения светодиода
#define setLedOffPin 5 // Пин кнопки выключения светодиода

volatile uint8_t state_3 = 0;
volatile uint8_t state_5 = 0;
int state1=1;
int state2=1;
long i=0;
uint8_t oldPIND = 0xFF;

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // Разрешаем PCINT для указанного пина
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // Очищаем признак запроса прерывания для соответствующей группы пинов
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // Разрешаем PCINT для соответствующей группы пинов
}


ISR (PCINT2_vect) { // Обработчик запросов прерывания от пинов D0..D7

  state_3=!digitalRead(setLedOnPin);

//  if (state_3)
//  Serial.println("Press 3 "); 
//  if (!state_3)
//  Serial.println("Release 3 "); 

  state_5=!digitalRead(setLedOffPin);

//  if (state_5)
//  Serial.println("Press 5 "); 
//  if (!state_5)
//  Serial.println("Release 5 "); 

}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(setLedOnPin,  INPUT_PULLUP); // Подтянем пины-источники PCINT к питанию
  pinMode(setLedOffPin, INPUT_PULLUP);
  pciSetup(setLedOnPin); // И разрешим на них прерывания
  pciSetup(setLedOffPin);
  Serial.begin(9600);
}


void loop() {

if (state1!=state_3){
if(state_3)  {
Serial.println("btn 3 press ");
}
if(!state_3)  
Serial.println("btn 3 release ");
state1=state_3;
}

if (state2!=state_5){
  
if(state_5)  {
Serial.println("btn 5 press ");
 }



if(!state_5)  {
Serial.println("btn 5 release ");
i=0;}

state2=state_5;
}

if(state_5){
i++;

if (i == 400000)
{
  Serial.println("btn 5 press 100 ");
  i=0;
}
}



}
