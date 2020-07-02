#include "sensors_functions.h"

void init_pins(){
    // Inductive sensors pins as input
    pinMode(IND_SENS_1,INPUT);
    pinMode(IND_SENS_2,INPUT);
    pinMode(IND_SENS_3,INPUT);
    pinMode(IND_SENS_4,INPUT);

    // Phototransitors pins as input
	pinMode(PHOTOTR_SENS_1,INPUT);
	pinMode(PHOTOTR_SENS_2,INPUT);
	pinMode(PHOTOTR_SENS_3,INPUT);

    // Touch sensors pins as input
    pinMode(TOUCH_SENS_1,INPUT);
    pinMode(TOUCH_SENS_2,INPUT);
    pinMode(TOUCH_SENS_3,INPUT);
    pinMode(TOUCH_SENS_4,INPUT);

    // Laser modules pins as output
	pinMode(LASER_EM_1,OUTPUT);
	pinMode(LASER_EM_2,OUTPUT);
	pinMode(LASER_EM_3,OUTPUT);
}

int find_capsule_ind_sens(IND_SENS_INPUT Sensor){
    int present = 0;				// contains the information about the presence
    								// of the capsule
    bool state = false;				// contains the state of the sensor
	
	// Acquisition ot sensor state
    switch(Sensor){
        case IND_SENS_INPUT_1:
            state = digitalRead(IND_SENS_1);
        break;
        case IND_SENS_INPUT_2:
            state = digitalRead(IND_SENS_2);
        break;
        case IND_SENS_INPUT_3:
            state = digitalRead(IND_SENS_3);
        break;
        case IND_SENS_INPUT_4:
            state = digitalRead(IND_SENS_4);
        break;
        default:
            return -1;
        break;  
    }

    // Determination of capsule presence
    if(state == LOW){
    	present = 1;
    } else if(state == HIGH) {
    	present = 0;
    } else {
    	present = -1;
    }

    //0 when not present, 1 when present, -1 when erreur
    return present;
}

int find_capsule_laser_photor_sens(LASER_EM_INPUT Laser, PHOTOTR_SNES_INPUT Phototr){
	int present = 0;				// contains the information about the presence 
    								// of the capsule
	bool state = false;				// contains the state of the sensor

	// Laser light on
	switch(Laser){
		case LASER_EM_INPUT_1:
			digitalWrite(LASER_EM_1,HIGH);
		break;
		case LASER_EM_INPUT_2:
			digitalWrite(LASER_EM_2,HIGH);
		break;
		case LASER_EM_INPUT_3:
			digitalWrite(LASER_EM_3,HIGH);
		break;
		default:
			return -1;
		break;	
	}

	// Acquisition ot sensor state
	switch(Phototr){
		case PHOTOTR_SNES_INPUT_1:
			state = digitalRead(PHOTOTR_SENS_1);
		break;
		case PHOTOTR_SNES_INPUT_2:
			state = digitalRead(PHOTOTR_SENS_2);
		break;
		case PHOTOTR_SNES_INPUT_3:
			state = digitalRead(PHOTOTR_SENS_3);
		break;
		default:
			return -1;
		break;	
	}

    // Determination of capsule presence
    if(state == 0){
    	present = 1;
    } else if(state == 1) {
    	present = 0;
    } else {
    	present = -1;
    }
	
    //0 when not present, 1 when present, -1 when erreur
	return present;
}

int find_capsule_touch_sens(TOUCH_SENS_INPUT Sensor){
    int touched = 0;				  // contains the final information
    bool state = false;				// contains the state of the sensor
	
	// Acquisition etat
    switch(Sensor){
        case TOUCH_SENS_INPUT_1:
            state = digitalRead(TOUCH_SENS_1);
        break;
        case TOUCH_SENS_INPUT_2:
            state = digitalRead(TOUCH_SENS_2);
        break;
        case TOUCH_SENS_INPUT_3:
            state = digitalRead(TOUCH_SENS_3);
        break;
        case TOUCH_SENS_INPUT_4:
            state = digitalRead(TOUCH_SENS_4);
        break;
        default:
            return -1;
        break;  
    }

    // Determination of touched sensor
    if(state == HIGH){
    	touched = 1;
    } else if(state == LOW) {
    	touched = 0;
    } else {
    	touched = -1;
    }

    //0 when not present, 1 when present, -1 when erreur
    return touched;
}
