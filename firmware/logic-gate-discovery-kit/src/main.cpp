#include <Arduino.h>

#define RED_LED_PIN 24
#define GREEN_LED_PIN 23
#define BLUE_LED_PIN 22

#define WIRE_PIN 1
#define NOT_PIN 2
#define OR_PIN 3
#define AND_PIN 4
#define XOR_PIN 5

#define BUTTON_PIN_1 0
#define BUTTON_PIN_2 14

// states
#define LATCH_STATE     0b11111
#define WIRE_STATE      0b11110
#define NOT_STATE       0b11101
#define OR_STATE        0b11011
#define AND_STATE       0b10111
#define XOR_STATE       0b01111

bool wire_logic(bool button_state) {
    return button_state;
}

bool or_logic(bool button_1_state, bool button_2_state) {
    return button_1_state || button_2_state;
}

bool and_logic(bool button_1_state, bool button_2_state) {
    return button_1_state && button_2_state;
}

void turn_red() {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}

void turn_green() {
    digitalWrite(RED_LED_PIN, LOW);
    analogWrite(GREEN_LED_PIN, 40);
    digitalWrite(BLUE_LED_PIN, LOW);
}

void turn_blue() {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, HIGH);
}

void turn_purple() {
    analogWrite(RED_LED_PIN, 40);
    digitalWrite(GREEN_LED_PIN, LOW);
    analogWrite(BLUE_LED_PIN, 100);
}

void turn_yellow() {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(BLUE_LED_PIN, LOW);
}

void turn_white() {
    analogWrite(RED_LED_PIN, 20);
    analogWrite(GREEN_LED_PIN, 15);
    analogWrite(BLUE_LED_PIN, 30);
}

void turn_off() {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}

void setup() {
    pinMode(WIRE_PIN, INPUT);
    pinMode(NOT_PIN, INPUT);
    pinMode(OR_PIN, INPUT);
    pinMode(AND_PIN, INPUT);
    pinMode(XOR_PIN, INPUT);

    pinMode(BUTTON_PIN_1, INPUT);
    pinMode(BUTTON_PIN_2, INPUT);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    bool wire_state = false;
    bool not_state = false;
    bool or_state = false;
    bool and_state = false;
    bool xor_state = false;

    bool button_1_state = false;
    bool button_2_state = false;

    wire_state = digitalRead(WIRE_PIN);
    not_state = digitalRead(NOT_PIN);
    or_state = digitalRead(OR_PIN);
    and_state = digitalRead(AND_PIN);
    xor_state = digitalRead(XOR_PIN);

    button_1_state = !digitalRead(BUTTON_PIN_1);
    button_2_state = !digitalRead(BUTTON_PIN_2);

    int bit_state = (xor_state << 4) | (and_state << 3) | (or_state << 2) | (not_state << 1) | wire_state;

    Serial.println(bit_state, BIN);

    switch(bit_state) {
        case LATCH_STATE:
            turn_green();
            break;
        case WIRE_STATE:
            if (wire_logic(button_2_state)) {
                turn_white();
            }
            else {
                turn_off();
            }
            break;
        case NOT_STATE:
            turn_green();
            break;
        case OR_STATE:
            if (or_logic(button_1_state, button_2_state)) {
                turn_purple();
            }
            else {
                turn_off();
            }
            break;
        case AND_STATE:
            if (and_logic(button_1_state, button_2_state)) {
                turn_blue();
            }
            else {
                turn_off();
            }
            break;
        case XOR_STATE:
            turn_green();
            break;
        default:
            turn_green();
            break;
    }
    delay(50);
}
