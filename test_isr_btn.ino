/*
При публичном размещении кода ссылка на первоисточник обязательна.
*/

#define btn_long_push 1000   // Длительность долинного нажатия кнопки
uint8_t btn_state;
#define btn1_pin 5
boolean flag;

//********************************
void setup() 
{
  pinMode(btn1_pin,INPUT_PULLUP); // BUTTON


  PCICR =  0b00000100; // PCICR |= (1<<PCIE1); Включить прерывание PCINT2
  PCMSK2 = 0b00001000; // Разрешить прерывание для  D3
  
  Serial.begin(9600);
}

//****************************************
void loop() 
{
 // boolean btn_state = !digitalRead(btn1_pin);
//  if (!flag && btn_state){
//    flag=true;
//    Serial.println("нажатие");
//  }
//if (flag && !btn_state){
//    flag=false;
//    Serial.println("отжатие");
//  }


  
//  switch (btn_state)
//    {
//  case 0:   {
//            Serial.print("нажатие ");
//            Serial.println(btn_state);
//            }
//   break;
//   
//  case 1:  {
//            Serial.print("Отжатие ");
//            Serial.println(btn_state);  
//           }
//    break;
//    
//
//    }
 // btn_state=0; //обнуляем статус энкодера
}

//****************************************
ISR (PCINT2_vect) //Обработчик прерывания от пинов D3
{
   btn_state = bitRead(PIND, 4); //считываем состояние кнопки
  if (btn_state==0){
     Serial.println("нажатие");
  }

 }
