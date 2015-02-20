/*
 * SPARK SERVO GONG
 * =========================================================
 * Copy this into a new application at:
 * https://www.spark.io/build and go nuts!
 * ---------------------------------------------------------
 *  Based on: https://github.com/technobly/SparkCore-FacebookLikesAlert
 * =========================================================
 *
 *
 * WIRING is so simple
 * -----------------------------
 * SERVO             SPARK CORE
 * Brown or Black  - GND
 * Red             - VIN (5V)
 * Orange or White - A7
 * -----------------------------
 */

/* ============================= INCLUDES ================================== */
#include "application.h"

/* === CHANGE THESE NUMBERS TO FIND WHAT SERVO DEGREE MAPS TO WHICH DIGIT == */
#define SERVO_DEG_0 0 // servo degree value to point to digit 0
#define SERVO_DEG_9 180 // servo degree value to point to digit 9

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

// Define the pins we're going to call pinMode on
int led = D0;  // You'll need to wire an LED to this one to see it blink.
int led2 = D7; // This one is the built-in tiny one to the right of the USB jack

float resting = 28;
float angServo = resting;
float angGoal = angServo;
bool reset = false;

/* This function is called once at start up ---------------------------------*/
void setup(){
    Spark.function("pushed", pushed);
    myservo.attach(A7);  // attaches servo to A7 pin to the servo object
    myservo.write(angGoal);
    gong();
}

void gong(){
    angGoal = 160;
    reset = true;
}

void pushed(String foo){
    // Not using the 'foo' string param currently, but could
    // be used to change behavior based on branch, author etc.
    gong();
    digitalWrite(led, HIGH);   // Turn ON the LED pins
    digitalWrite(led2, HIGH);
    delay(5000);               // Wait for 5000mS = 5 seconds
    digitalWrite(led, LOW);    // Turn OFF the LED pins
    digitalWrite(led2, LOW);
}


/* This function loops forever ----------------------------------------------*/
void loop(){
    if(angServo != angGoal){
        if(angGoal > angServo){
            if(angServo > 90){
                angServo += .125; // gently engage bell clapper lever
            }else{
                angServo += .25;
            }
        }else{
            if(angServo > 70){
                angServo -= 1;
            }else{
                angServo -= .125; // return to resting position gently
            }
        }
        myservo.write(angServo);
        if(angServo == angGoal && reset){
            delay(5000);
            reset = false;
            angGoal = resting;
        }
    }
}
