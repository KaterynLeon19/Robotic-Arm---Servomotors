//bibliotecas

#include <Servo.h>

// Macrodefiniciones (donde estan conectado los pins)

#define Ser1 5
#define Ser2 6
#define Ser3 9
#define Ser4 10
#define IR 11   


// Setup Infrarrojo
int detection = HIGH;    // no obstacle

//Declaracion de objetos servo

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

 
//////////////////////////////////////////////////////////funcion de servos ida y vuelta (para servos grua)/////////////////////////////////////////////////////////////////////////

void movimientoIyV (Servo S, int angulo1 , int angulo2 , int tiempo){ //funcion de moviento de servos tiempo en milisegundos, andulo en grados

          
      if(angulo1 < angulo2){               
        for (int pos = angulo1 ; pos <= angulo2 ; pos += 1) { //ida
          S.write(pos);           
          delay(tiempo);                                 //el tiempo en el cual se cierra          
        }
      }
      if(angulo2 < angulo1){
        for(int pos = angulo1 ; pos >= angulo2 ; pos--){
          S.write(pos);           
          delay(tiempo);            
        }
      }
}
 
//declaracion de pins de coneccion

void setup() {

  // Setup IR
  Serial.begin(9600);   
  pinMode(IR, INPUT); 

  //Ser1 , Ser2 , Ser3 , Ser 4 son los pines  donde estan conectados se define arriba en macrodefiniciones
  Servo1.attach(Ser1); 
  Servo2.attach(Ser2);
  Servo3.attach(Ser3);
  Servo4.attach(Ser4);

}

////////////////////////////////////////////////////////////////////////loop///////////////////////////////////////////////////////////////////////////////////////////////////////

//ciclo para caragar la pelotita

void loop() {

  // en movimientoIyV quiere decir que va y vuelve a su misma posicion 
  // movimientoIyV (Servo , angulo 1 , angulo 2 , veocidad a la que se mueve (en ms))

  // T1 inicializacion de servos
  Servo1.write(50);
  Servo2.write(175);
  Servo3.write(1);
  Servo4.write(160);

  // Condicion de que la pelota este detectada por el infrarrojo para iniciar el movimiento
  detection = digitalRead(IR);
  if(detection == LOW){

     //T4
    //MOVIMIENTO MUÑECA - SE ACOMODA
    movimientoIyV (Servo1, 0, 50, 60);
    delay(3000);
    
    //T3
    // MOVIMIENTO CODO - BAJA
    movimientoIyV (Servo2 , 175, 76 , 60);
    delay(3000);
   
    //T4
    //MOVIMIENTO MUÑECA - SE ACOMODA
    movimientoIyV (Servo3, 1, 15, 60);
    delay(3000);

    // MOVIMIENTO CODO - BAJA
    movimientoIyV (Servo2 ,76, 73 , 60);
    delay(3000);
    
    
    //T5
    // MOVIMIENTO MANO - CIERRA LA PELOTA
    movimientoIyV(Servo4 , 160 , 130 , 60);
    delay(3000);

      // MOVIMIENTO CODO - BAJA
    movimientoIyV (Servo2 ,73, 80, 60);
    delay(3000);

     //T2
    //MOVIMIENTO BASE
    movimientoIyV (Servo1 , 50, 25 , 60);
    delay(3000);
    
  
    //T6
    //SUBE CODO
    movimientoIyV(Servo2 , 80 , 155 , 60);
    delay(3000);

    //T2
    //MOVIMIENTO BASE
    movimientoIyV (Servo1 , 25, 80 , 60);
    delay(3000);


    //T6
    //SUBE CODO
    movimientoIyV(Servo2 , 155 , 115 , 60);
    delay(3000);

  //T5
    // MOVIMIENTO MANO - CIERRA LA PELOTA
    movimientoIyV(Servo4 , 130 , 160 , 60);
    delay(3000);

  /*  //T2
    //MOVIMIENTO BASE
    movimientoIyV (Servo1 , 50, 75 , 60);
    delay(3000);
    
    
    //T7
    movimientoIyV(Servo3 , 15 , 50 , 60);
    delay(3000);
 
    
    //T8
    // GIRA LA BASE
    movimientoIyV(Servo1 , 0 , 65 , 60);
    delay(3000);
    
    //T9
    // BAJA EL CODO A DEJAR LA PELOTA
    movimientoIyV(Servo2 , 155 , 125 , 60);
    delay(3000);
    //T10
    //ABRE LA MANO PARA SOLTAR LA PELOTA
    movimientoIyV(Servo4 , 120 , 160 , 60);
    delay(3000);
    
    //REGRESA POSIIOCN INICIAL
    
    //T11
    
    movimientoIyV(Servo1 , 62 , 50 , 60);
    delay(3000);

    //T12
    
    movimientoIyV(Servo2 , 125 , 175 , 60);
    delay(3000);

    //T13
    
    movimientoIyV(Servo3 , 15 , 1 , 60);
    delay(3000);
   */
    }
   
  delay(500);
}
