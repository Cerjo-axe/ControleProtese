// constantes reles

const int relays[4] = {2,3,4,5};

//constantes botões
const int buttonOne = 10;
const int buttonTwo = 11;
const int buttonThree = 12;
const int buttonFour = 13;

void setup() {

  Serial.begin(9600);

  //declarando saidas
  for(int i=0; i<4;i++)
  {
    pinMode(relays[i],OUTPUT);
  }
  Serial.println("Reles declarados");

  //declarando entradas
  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
  pinMode(buttonThree, INPUT);
  pinMode(buttonFour, INPUT);
  Serial.println("Botoes declarados");

  ActivateAll();
}

void loop() {
  
  Serial.println("Selecione o movimento");
  ReadInput();

  delay(500);

}

void InflateActuator(int relay)
{
  for(int i=0; i<4; i++)
  {
    if(i!= relay)
    {
      digitalWrite(relays[i], LOW);
    }
  }
}

void ReadInput () {
  Serial.println("Selecione o movimento");
  if (digitalRead(buttonOne) == LOW){
    Serial.println("selecionado 1");
    MakeMovement(buttonOne , 0);
  } else if(digitalRead(buttonTwo)== LOW){
    Serial.println("selecionado 2");
    MakeMovement(buttonTwo , 1);
  }else if(digitalRead(buttonThree) == LOW){
    Serial.println("selecionado 3");
    MakeMovement(buttonThree , 2);
  }else if(digitalRead(buttonFour) == LOW){
    Serial.println("selecionado 4");
    MakeMovement(buttonFour , 3);
  }
}

void MakeMovement(int btn , int rel)
{
  while(digitalRead(btn) == LOW)
  {
    InflateActuator(rel);
  }
  ActivateAll();
}


void ActivateAll()
{
  for(int i=0; i<4; i++)
  {
    digitalWrite(relays[i], HIGH);
  }
}
