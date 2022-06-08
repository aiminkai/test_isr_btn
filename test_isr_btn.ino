/*
При публичном размещении кода ссылка на первоисточник обязательна.
*/


#define btn1_pin 3
boolean flag = false;
boolean temp_flag = false;
long btn_press_time = 0;
long btn_release_time = 0;
int dbc = 80;
int dbc2 = 2000;

//********************************
void setup() 
{
  pinMode(btn1_pin,INPUT_PULLUP); // BUTTON


  PCICR =  0b00000100; // Включить прерывание PCINT2
  PCMSK2 = 0b00001000; // Разрешить прерывание для  D3
  
  Serial.begin(9600);
}

//****************************************
void loop() 
{
if (temp_flag!=flag){
  if (flag==0) Serial.println("release");
  if (flag==1) Serial.println("press");
  temp_flag=flag;
}
}

//****************************************
ISR (PCINT2_vect) //Обработчик прерывания для пина D3
{
  
   boolean btnState = bitRead(PIND, 3); //считываем состояние кнопки
     
   if (btnState == 0  && millis()-btn_press_time>dbc) {
    btn_press_time=millis();
    flag = true;
   
   }
   if (btnState == 1 && millis()-btn_release_time>dbc) {
    btn_release_time=millis();
    flag = false;
    }
   
 }
