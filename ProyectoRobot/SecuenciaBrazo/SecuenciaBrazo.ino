#include <Servo.h> // Incluimos la biblioteca Servo
//Determina los pines que controlaran al brazo robotico
//estos pines son los PWM e inicia con el pin
// que controla al servomotor del eje de las pinzas
// del gripper Pin 11, finalizando con el pin 3
// que controla a la base del brazo robotico.
#define PinSerGripper 11
#define PinSerMuneca 10
#define PinSerCodo2 9
#define PinSerCodo1 6
#define PinSerHombro 5
#define PinSerEje 3
//Cargo los valores iniciales
#define init_serv_gripper 30
#define init_serv_muneca 80
#define init_serv_codo2 35
#define init_serv_codo1 55
#define init_serv_hMAX 165
#define init_serv_EJE 90
Servo Srv_Gripper,Srv_muneca,Srv_Codo2, Srv_Codo1, Srv_Hombro, Srv_Eje; 
//Definimos los servos que vamos a utilizar
byte Vlr_Hombro = 0;
byte BufferIn[4];
boolean StringCompleta = false;
boolean ValPWMLeido = false;
byte Cont_char =0;
void setup()
{
Serial.begin(9600);
Serial.println("INICIANDO");
Srv_Gripper.attach(PinSerGripper);
Srv_Gripper.write(init_serv_gripper);
Srv_muneca.attach(PinSerMuneca);
Srv_muneca.write(init_serv_muneca);
Srv_Codo2.attach(PinSerCodo2);
Srv_Codo2.write(init_serv_codo2);
Srv_Codo1.attach(PinSerCodo1);
Srv_Codo1.write(init_serv_codo1);//INCREMENTO Y SE LEVANTA
Srv_Hombro.attach(PinSerHombro);
Srv_Hombro.write(init_serv_hMAX);//DECREMENTO SE LEVANTA
Vlr_Hombro = init_serv_hMAX;
Srv_Eje.attach(PinSerEje);
Srv_Eje.write(init_serv_EJE);
Cont_char=0;
ValPWMLeido = false;
BufferIn[0]= 0;
BufferIn[1]= 200;
}
void loop()
{
if ((StringCompleta == true)&&(Cont_char ==2))
{
ValPWMLeido = false;
if (BufferIn[0]== 191){Srv_Gripper.write(BufferIn[1]);}
if (BufferIn[0]== 192){Srv_muneca.write(BufferIn[1]);}
if (BufferIn[0]== 193){Srv_Codo2.write(BufferIn[1]);}
if (BufferIn[0]== 194){Srv_Codo1.write(BufferIn[1]);}
if (BufferIn[0]== 195){Srv_Hombro.write(BufferIn[1]);}
if (BufferIn[0]== 196){Srv_Eje.write(BufferIn[1]);}
//Serial.println(BufferIn[0]);
//Serial.println(BufferIn[1]);
StringCompleta = false;
Cont_char=0;
ValPWMLeido = true;
BufferIn[0]= 0;
BufferIn[1]= 200;
}
}
void serialEvent()
{
if(ValPWMLeido = true)
{
while (Serial.available())
{
BufferIn[Cont_char] = (byte)Serial.read();
if(BufferIn[1]!= 200){StringCompleta=true;}
Cont_char++;
}
}
}
