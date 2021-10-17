//parameter initialization
int east_green = 22; //three led's for each road are declared as three seperate variables
int east_yellow = 23;
int east_red = 24;
int north_green = 25;
int north_yellow = 26;
int north_red = 27;
int west_green = 28;
int west_yellow = 29;
int west_red = 30;
int south_green = 31;
int south_yellow = 32;
int south_red = 33;

//Emergency buttons, push buttons in proteus
int east_em=39;
int west_em = 43;
int south_em = 45;
int north_em = 41;

//Empty buttons, push buttons in proteus
int east_empty = 46;
int north_empty = 47;
int south_empty = 49;
int west_empty = 48;

//delay for each light, 5 secs for green, 2 secs for yellow
int delay_green = 5000;
int delay_yellow = 2000;
int delay_time=100;

//needed to handle void loop
int next_state = 0; //initialized to zero

void setup() {
  // put your setup code here, to run once:
  pinMode(east_green, OUTPUT);
  pinMode(east_yellow, OUTPUT);
  pinMode(east_red, OUTPUT);
  pinMode(north_green, OUTPUT);
  pinMode(north_yellow, OUTPUT);
  pinMode(north_red, OUTPUT);
  pinMode(west_green, OUTPUT);
  pinMode(west_yellow, OUTPUT);
  pinMode(west_red, OUTPUT);
  pinMode(south_green, OUTPUT);
  pinMode(south_yellow, OUTPUT);
  pinMode(south_red, OUTPUT);
  
  pinMode(east_em, INPUT_PULLUP); //the switches are normally pulled up, that means when they are pressed they will be LOW
  pinMode(north_em, INPUT_PULLUP);
  pinMode(west_em, INPUT_PULLUP);
  pinMode(south_em, INPUT_PULLUP);

  pinMode(east_empty, INPUT_PULLUP);
  pinMode(north_empty, INPUT_PULLUP);
  pinMode(west_empty, INPUT_PULLUP);
  pinMode(south_empty, INPUT_PULLUP);
  
}

//Emergency Function
int emergency(int em)
{
  if(digitalRead(em)==LOW) return 1;
  else return 0;
}

//Empty Function
int empty(int emp)
{
  if(digitalRead(emp)==LOW) return 1;
  else return 0;
}

//Infinite Loop
void loop() {
  switch(next_state){
    case 0:
      next_state = eg();
      break;
    case 1:
      next_state = ey();
      break;
    case 2:
      next_state = ng();
      break;
    case 3:
      next_state = ny();
      break;
    case 4:
      next_state = wg();
      break;
    case 5:
      next_state = wy();
      break;
    case 6:
      next_state = sg();
      break;
    case 7:
      next_state = sy();
      break;
  }
}

int eg()
{
  digitalWrite(east_green, HIGH);
  digitalWrite(east_yellow,LOW);
  digitalWrite(east_red,LOW);
  
  digitalWrite(north_green,LOW);
  digitalWrite(north_yellow,LOW);
  digitalWrite(north_red, HIGH);

  digitalWrite(west_green,LOW);
  digitalWrite(west_yellow,LOW);
  digitalWrite(west_red, HIGH);

  digitalWrite(south_green,LOW);
  digitalWrite(south_yellow,LOW);
  digitalWrite(south_red, HIGH);

  //emergency check in west, south, north and empty check in east
  for(int i=0;i<delay_green;i=i+delay_time)
  {
    if(emergency(west_em)==1) return 4;
    else if(emergency(south_em)==1) return 6;
    else if(emergency(north_em)==1) return 2;
    else if(empty(east_empty)==1) return 1;
    delay(delay_time);
  }

  delay(delay_green);
  return 1; 
}

int ey()
{
  digitalWrite(east_green, LOW);
  digitalWrite(east_yellow,HIGH);
  digitalWrite(east_red,LOW);
  
  digitalWrite(north_green,LOW);
  digitalWrite(north_yellow,HIGH);
  digitalWrite(north_red, HIGH);

  digitalWrite(west_green,LOW);
  digitalWrite(west_yellow,LOW);
  digitalWrite(west_red, HIGH);

  digitalWrite(south_green,LOW);
  digitalWrite(south_yellow,LOW);
  digitalWrite(south_red, HIGH);

  //emergency check 
  for(int i=0;i<delay_yellow;i=i+delay_time)
  {
    if(emergency(west_em)==1) return 4;
    else if(emergency(south_em)==1) return 6;
    else if(emergency(north_em)==1) return 2;
    else if(emergency(east_em)==1) return 0;
    delay(delay_time);
  }

  delay(delay_yellow);
  return 2; 
}

int ng()
{
  digitalWrite(east_green, LOW);
  digitalWrite(east_yellow,LOW);
  digitalWrite(east_red,HIGH);
  
  digitalWrite(north_green,HIGH);
  digitalWrite(north_yellow,LOW);
  digitalWrite(north_red, LOW);

  digitalWrite(west_green,LOW);
  digitalWrite(west_yellow,LOW);
  digitalWrite(west_red, HIGH);

  digitalWrite(south_green,LOW);
  digitalWrite(south_yellow,LOW);
  digitalWrite(south_red, HIGH);

  //emergency check in west, south, east and empty check in north 
  for(int i=0;i<delay_green;i=i+delay_time)
  {
    if(emergency(west_em)==1) return 4;
    else if(emergency(south_em)==1) return 6;
    else if(emergency(east_em)==1) return 0;
    else if(empty(north_empty)==1) return 3;
    delay(delay_time);
  }

  delay(delay_green);
  return 3; 
}

int ny()
{
  digitalWrite(east_green, LOW);
  digitalWrite(east_yellow,LOW);
  digitalWrite(east_red,HIGH);
  
  digitalWrite(north_green,LOW);
  digitalWrite(north_yellow,HIGH);
  digitalWrite(north_red, LOW);

  digitalWrite(west_green,LOW);
  digitalWrite(west_yellow,HIGH);
  digitalWrite(west_red, HIGH);

  digitalWrite(south_green,LOW);
  digitalWrite(south_yellow,LOW);
  digitalWrite(south_red, HIGH);

  //emergency check 
  for(int i=0;i<delay_yellow;i=i+delay_time)
  {
    if(emergency(west_em)==1) return 4;
    else if(emergency(south_em)==1) return 6;
    else if(emergency(north_em)==1) return 2;
    else if(emergency(east_em)==1) return 0;
    delay(delay_time);
  }

  delay(delay_yellow);
  return 4;
}

int wg()
{
  digitalWrite(east_green, LOW);
  digitalWrite(east_yellow,LOW);
  digitalWrite(east_red,HIGH);
  
  digitalWrite(north_green,LOW);
  digitalWrite(north_yellow,LOW);
  digitalWrite(north_red, HIGH);

  digitalWrite(west_green,HIGH);
  digitalWrite(west_yellow,LOW);
  digitalWrite(west_red, LOW);

  digitalWrite(south_green,LOW);
  digitalWrite(south_yellow,LOW);
  digitalWrite(south_red, HIGH);

  //emergency check in east, north and south and empty check in west
  for(int i=0;i<delay_green;i=i+delay_time)
  {
    if(emergency(north_em)==1) return 2;
    else if(emergency(south_em)==1) return 6;
    else if(emergency(east_em)==1) return 0;
    else if(empty(west_empty)==1) return 5;
    delay(delay_time);
  }

  delay(delay_green);
  return 5; 
}

int wy()
{
  digitalWrite(east_green, LOW);
  digitalWrite(east_yellow,LOW);
  digitalWrite(east_red,HIGH);
  
  digitalWrite(north_green,LOW);
  digitalWrite(north_yellow,LOW);
  digitalWrite(north_red, HIGH);

  digitalWrite(west_green,LOW);
  digitalWrite(west_yellow,HIGH);
  digitalWrite(west_red, LOW);

  digitalWrite(south_green,LOW);
  digitalWrite(south_yellow,HIGH);
  digitalWrite(south_red, HIGH);

  //emergency check 
  for(int i=0;i<delay_yellow;i=i+delay_time)
  {
    if(emergency(west_em)==1) return 4;
    else if(emergency(south_em)==1) return 6;
    else if(emergency(north_em)==1) return 2;
    else if(emergency(east_em)==1) return 0;
    delay(delay_time);
  }

  delay(delay_yellow);
  return 6;
}

int sg()
{
  digitalWrite(east_green, LOW);
  digitalWrite(east_yellow,LOW);
  digitalWrite(east_red,HIGH);
  
  digitalWrite(north_green,LOW);
  digitalWrite(north_yellow,LOW);
  digitalWrite(north_red, HIGH);

  digitalWrite(west_green,LOW);
  digitalWrite(west_yellow,LOW);
  digitalWrite(west_red, HIGH);

  digitalWrite(south_green,HIGH);
  digitalWrite(south_yellow,LOW);
  digitalWrite(south_red, LOW);

  //emergency check in east, west, north and empty check in south
  for(int i=0;i<delay_green;i=i+delay_time)
  {
    if(emergency(north_em)==1) return 2;
    else if(emergency(west_em)==1) return 4;
    else if(emergency(east_em)==1) return 0;
    else if(empty(south_empty)==1) return 7;
    delay(delay_time);
  }

  delay(delay_green);
  return 7; 
}

int sy()
{
  digitalWrite(east_green, LOW);
  digitalWrite(east_yellow,HIGH);
  digitalWrite(east_red,HIGH);
  
  digitalWrite(north_green,LOW);
  digitalWrite(north_yellow,LOW);
  digitalWrite(north_red, HIGH);

  digitalWrite(west_green,LOW);
  digitalWrite(west_yellow,LOW);
  digitalWrite(west_red, HIGH);

  digitalWrite(south_green,LOW);
  digitalWrite(south_yellow,HIGH);
  digitalWrite(south_red, LOW);

  //emergency check 
  for(int i=0;i<delay_yellow;i=i+delay_time)
  {
    if(emergency(west_em)==1) return 4;
    else if(emergency(south_em)==1) return 6;
    else if(emergency(north_em)==1) return 2;
    else if(emergency(east_em)==1) return 0;
    delay(delay_time);
  }

  delay(delay_yellow);
  return 0;
}
