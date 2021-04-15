#include "Particle.h"

// LEDs to be blinked

// in-built LED
const pin_t INTERNAL_LED = D7;
const pin_t EXTERNAL_LED = D6;

// option function but allows your code to run before the cloud is connected.
SYSTEM_THREAD(ENABLED);

// This function is called when the Particle.function is called
int ledToggle(String command) {
	if (command.equals("on")) {
        digitalWrite(INTERNAL_LED, HIGH);
        digitalWrite(EXTERNAL_LED, HIGH);
        return 1;
    }
    else if (command.equals("off")) {
        digitalWrite(INTERNAL_LED, LOW);
        digitalWrite(EXTERNAL_LED, LOW);
        return 0;
    }
    else {
		// Unknown option
        return -1;
    }
}

// Called when the device boots
void setup() {
	pinMode(INTERNAL_LED, OUTPUT);
	pinMode(EXTERNAL_LED, OUTPUT);
	Particle.function("led", ledToggle);
}

void loop() {
}
