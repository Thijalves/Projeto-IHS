#include <Arduino.h>

#include "defines.h"
#include "movements.h"

void move_y_axis(Servo &tilt_servo, int &tilt_angle, char movement){
    Serial.println("Move along y axis");
    switch (movement){
        case 's':
            Serial.println("Move down");
            if(tilt_angle + 5 > 60)
                Serial.println("Maximum down");
            else {
                tilt_angle += 5;
                tilt_servo.write(tilt_angle);
            }
            break;
        
        case 'w':
            Serial.println("Move up");
            if(tilt_angle - 5 < 10)
                Serial.println("Maximum up");
            else {
                tilt_angle -= 5;
                tilt_servo.write(tilt_angle);
            }
            break;
        default:
            Serial.println("Unrecognized command");
    }
}

void move_x_axis(char movement){
    Serial.println("Move along x axis");

    switch(movement){
        case 'a':
            Serial.println("Rotate clockwise");
            digitalWrite(ROTATION_D1, HIGH);
            digitalWrite(ROTATION_D2, LOW);
            delay(10);
            digitalWrite(ROTATION_D1, LOW);
            digitalWrite(ROTATION_D2, LOW);
            break;
        case 'd':
            Serial.println("Rotate counter-clockwise");
            digitalWrite(ROTATION_D1, LOW);
            digitalWrite(ROTATION_D2, HIGH);
            delay(10);
            digitalWrite(ROTATION_D1, LOW);
            digitalWrite(ROTATION_D2, LOW);
            break;
    }
}

void shoot(Servo &shoot_servo){
    Serial.println("Shoot!");
    shoot_servo.write(90);
    delay(200);
    shoot_servo.write(0);
}

void toggle_impulse(bool &impulse_on){
    if(impulse_on){
        Serial.println("Impulse off");
        digitalWrite(IMPULSE_D1, LOW);
        digitalWrite(IMPULSE_D2, LOW);
        impulse_on = false;
    } else {
        Serial.println("Impulse on");
        digitalWrite(IMPULSE_D1, LOW);
        digitalWrite(IMPULSE_D2, HIGH);
        impulse_on = true;
    }
}