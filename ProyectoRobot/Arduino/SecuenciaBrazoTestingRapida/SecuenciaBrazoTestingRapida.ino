#include<Servo.h>
Servo gripper;
Servo giromuneca;
Servo verticalmuneca;
Servo codo;
Servo girohombro;
int pos = 90;
int a = 90;
void setup()
{
  gripper.attach(11);
  gripper.write(90);
  giromuneca.attach(10);
  giromuneca.write(180);
  verticalmuneca.attach(9);
  verticalmuneca.write(90);
  codo.attach(6);
  codo.write(90);
  girohombro.attach(5);
  girohombro.write(90);
  
}
void loop(){
        gripper.write(180);
        for(pos = 90; pos >=0; pos--){
           gripper.write(pos);
           delay(5);
        }
        for(pos = 0; pos <= 90; pos++){
           gripper.write(pos);
           delay(5);
        }
        for(pos = 90; pos >=0; pos--){
           gripper.write(pos);
           delay(5);
        }
        for(pos = 0; pos <= 90; pos++){
           gripper.write(pos);
           delay(5);
        }
        for(pos = 90; pos >= 0; pos--){
           gripper.write(pos);
           delay(5);
        }
        for(pos = 0; pos <= 90; pos++){
           gripper.write(pos);
           delay(5);
        }
//**************************************************************endGripper
        delay(500);
        //ahora corregimos el siguiente movimiento
        for(pos = 90; pos <= 180; pos++){
           giromuneca.write(pos);
           delay(5);
        }
        for(pos= 180; pos >=0; pos--){
           giromuneca.write(pos);
           delay(5);
        }
        for(pos= 0; pos <=90; pos++){
           giromuneca.write(pos);
           delay(5);
        }
        
        giromuneca.write(180);

//**************************************************************endMuñeca
//giro para recoger objeto A
        for(pos= 90; pos >=0 ; pos--){
           girohombro.write(pos);
           delay(10);
        }
        
        //delay(1000);
   //     girohombro.write(180);
//**************************************************************endHombro
        for(pos=90; pos >=0; pos--){
           codo.write(pos);
           verticalmuneca.write(pos);
           delay(10);
        }
        for(pos= 0; pos<= 50; pos++){
           verticalmuneca.write(pos);
           delay(10);
        }
        for(pos= 90; pos>=0; pos--){
           gripper.write(pos);
           delay(20);
        }
        //alza el objeto inclinandolo 150 grados
        //********Con inclinacion de 10 mueve el servo 
         for(pos= 0; pos <=10; pos++){
           codo.write(pos);
           verticalmuneca.write(50+(2*pos)/3);
           delay(30);
        }
        //lleva al punto b
        for(pos= 0; pos<=180; pos++){
           girohombro.write(pos);
           //giromuneca.write(90+pos/2);
           delay(10);
        }
        for(pos=90; pos>=0; pos--){
         // para que no se vaya hacia atras
         codo.write(pos); 
         verticalmuneca.write(50+(2*pos/3));
         //giromuneca.write(90+3*pos/5); que mantenga el objeto normal
         delay(10);
         }
        for(pos= 0; pos<=90; pos++){
         gripper.write(pos);
         delay(10);
        }
        for(pos= 0; pos<=90; pos++){
         codo.write(pos);
         verticalmuneca.write(50+4*pos/9);
         girohombro.write(180-pos);
         delay(10);
        }
        
        delay(6000);

}
