#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  while(1) {
    printf("Waiting for reset\n");
    
	while(digitalRead(0) == 1){
	digitalWrite (1, HIGH) ;    
    digitalWrite (2,  LOW) ;
	printf("Waiting for event\n");	
	}
    
    while(digitalRead(0) == 0){		
		digitalWrite (2, HIGH) ;    
        digitalWrite (1,  LOW) ;
		ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "my1", "my 2", "my 33333");
		printf("Alarm\n");		
	}   
  }
  /*NOTREACHED*/
  return 0 ;
}
