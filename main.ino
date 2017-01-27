/**************************************************************************
 *  Structure																															*
 **************************************************************************/
struct Led
{
  int port ;
  int lvl  ;
};

/**************************************************************************
 *  Variables                                                             *
 **************************************************************************/
Led blue   = {12, 0} ;
Led yellow = {11, 0} ;
Led red    = {10, 0} ;
Led white  = {9,  0} ;


/**************************************************************************
 *  Base fonction       	                                                *
 **************************************************************************/
/* Analogic */
void 
a_inc(struct Led *led)
{
  analogWrite(led->port, led->lvl=led->lvl+5) ;
}

void 
a_dec(struct Led *led)
{
  analogWrite(led->port, led->lvl=led->lvl-5) ;
}


/* Digital */
void
d_led(struct Led *led, int time)
{
  digitalWrite(led->port, HIGH) ;
  delay(time) ;
  digitalWrite(led->port, LOW) ;
  delay(time) ;
}

/**************************************************************************
 *  dinamic light fonction                                                *
 **************************************************************************/

/* Digital */
void
d_slow_color(struct Led *l1, struct Led *l2, struct Led *l3)
{
  if (l1 != NULL)
    d_led(l1, 1000) ;
  if (l2 != NULL)
    d_led(l2, 1000) ;
  if (l3 != NULL)
    d_led(l3, 1000) ;
}

void
d_fast_color(struct Led *l1, struct Led *l2, struct Led *l3)
{  
  if (l1 != NULL)
    d_led(l1, 100) ;
  if (l2 != NULL)
    d_led(l2, 100) ;
  if (l3 != NULL)
    d_led(l3, 100) ;
  }

void
d_veryfast_color(struct Led *l1, struct Led *l2, struct Led *l3)
{
  if (l1 != NULL)
    d_led(l1, 50) ;
  if (l2 != NULL)
    d_led(l2, 50) ;
  if (l3 != NULL)
    d_led(l3, 50) ;
}

void
d_insane_color(struct Led *l1, struct Led *l2, struct Led *l3)
{
  if (l1 != NULL)
    d_led(l1, 15) ;
  if (l2 != NULL)
    d_led(l2, 15) ;
  if (l3 != NULL)
    d_led(l3, 15) ;
}



/* Analogic */
void
a_color(struct Led *l1, int time)
{
  while(l1->lvl < 255)
  {
    a_inc(l1) ;
    delay(time) ;
  }
  
  while(l1->lvl > 0)
  {
    a_dec(l1) ;
    delay(time) ;
  }
}
/* meta fonction */
void
a_slow_color(struct Led *l1)
{
  a_color(l1, 100) ;
}

void
a_normal_color(struct Led *l1)
{
  a_color(l1, 50) ;
}

void
a_fast_color(struct Led *l1)
{
  a_color(l1, 10) ;
}

void
a_veryfast_color(struct Led *l1)
{
  a_color(l1, 5) ;
}




void
a_2color(struct Led *l1, struct Led *l2, int time)
{
  while(l1->lvl < 255)
  {
    a_inc(l1) ;
    delay(time) ;
  }
  
  while(l1->lvl > 0 || l2->lvl < 255)
  { 
    a_inc(l2) ;
    a_dec(l1) ;
    delay(time) ;
  }
  
  while(l2->lvl > 0)
  {
    a_dec(l2) ;
    delay(time) ;
  }
}
/* meta fonction */
void
a_slow_2color(struct Led *l1, struct Led *l2)
{
  a_2color(l1, l2, 100) ;
}

void
a_normal_2color(struct Led *l1, struct Led *l2)
{
  a_2color(l1, l2, 50) ;
}

void
a_fast_2color(struct Led *l1, struct Led *l2)
{
  a_2color(l1, l2, 10) ;
}

void
a_veryfast_2color(struct Led *l1, struct Led *l2)
{
  a_2color(l1, l2, 5) ;
}



void
a_3color(struct Led *l1, struct Led *l2, struct Led *l3, int time)
{
  while(l1->lvl < 255)
  {
    a_inc(l1) ;
    delay(time) ;
  }
  
  while(l1->lvl > 0 || l2->lvl < 255)
  { 
    a_inc(l2) ;
    a_dec(l1) ;
    delay(time) ;
  }
  
  while(l2->lvl > 0 || l3->lvl < 255)
  {
    a_inc(l3) ;
    a_dec(l2) ;
    delay(time) ;
  }
  
  while(l3->lvl > 0)
  {
    a_dec(l3) ;
    delay(time) ;
  }
}

/* meta fonction */
void
a_slow_3color(struct Led *l1, struct Led *l2, struct Led *l3)
{
  a_3color(l1, l2, l3, 100) ;
}

void
a_normal_3color(struct Led *l1, struct Led *l2, struct Led *l3)
{
  a_3color(l1, l2, l3, 50) ;
}

void
a_fast_3color(struct Led *l1, struct Led *l2, struct Led *l3)
{
  a_3color(l1, l2, l3, 10) ;
}

void
a_veryfast_3color(struct Led *l1, struct Led *l2, struct Led *l3)
{
  a_3color(l1, l2, l3, 5) ;
}

void
metaltime(struct Led *l1, struct Led *l2, struct Led *l3, struct Led *l4)
{
  int rand ;
  
  for (int i = 0 ; i < 15 ; i++)
  {
    rand = random(1,5) ;
    switch (rand)
    {
      case 1 :
        d_insane_color(l1, l1, (Led *)0) ;
        break ;
      case 2 :
        d_insane_color(l2, l2, (Led *)0) ;
        break ;
      case 3 :
        d_insane_color(l3, l3, (Led *)0) ;
        break ;
      case 4 :
        d_insane_color(l4, l4, (Led *)0) ;
        break ;
      default :
        break ;
    }
  }
}


/**************************************************************************
 *  main fonction                                                         *
 **************************************************************************/

void 
setup() 
{
  pinMode(red.port,    OUTPUT);
  pinMode(blue.port,   OUTPUT);
  pinMode(white.port,  OUTPUT);
  pinMode(yellow.port, OUTPUT);
  
  
  d_led(&blue,    50) ;
  d_led(&yellow,  50) ;
  d_led(&red,     50) ;
  d_led(&white,   50) ;
  
  randomSeed(analogRead(0));
}

void 
loop()
{ 
  a_fast_3color(&white, &blue, &red) ;

/* fast time */
  for(int i = 0 ; i < 8 ; i++)
    d_insane_color(&white,&blue,(Led *)0) ;
 
  for(int i = 0 ; i < 3 ; i++)
    d_insane_color(&red,&white,(Led *)0) ;
   
  for(int i = 0 ; i < 5 ; i++)
    d_insane_color(&yellow,&white,(Led *)0) ;
 
  for(int i = 0 ; i < 1 ; i++)
    d_insane_color(&red,&blue,(Led *)0) ;
 
  for(int i = 0 ; i < 7 ; i++)
    d_insane_color(&red,&white,(Led *)0) ;
 
  for(int i = 0 ; i < 10 ; i++)
    d_veryfast_color(&blue,&white,&blue) ;
 
  for(int i = 0 ; i < 10 ; i++)
    d_insane_color(&blue,&white,(Led *)0) ;

 for(int i = 0 ; i < 10 ; i++)
    d_insane_color(&red,&white,(Led *)0) ;

 for(int i = 0 ; i < 10 ; i++)
    d_insane_color(&red,&blue,(Led *)0) ;

 for(int i = 0 ; i < 15 ; i++)
    d_insane_color(&yellow,&white,(Led *)0) ;
/* slow time */ 
  for(int i = 0 ; i < 1 ; i++)
     a_fast_3color(&red, &blue, &white) ;
     
  for(int i = 0 ; i < 2 ; i++)
     a_veryfast_2color(&red, &yellow) ;

  metaltime(&white, &blue, &red, &yellow) ;
}

