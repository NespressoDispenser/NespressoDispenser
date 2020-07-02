#ifndef _HEADERFILE__SENSOR_FUNCTIONS_H
#define _HEADERFILE__SENSOR_FUNCTIONS_H

#include "Arduino.h"


//!!!! ATTENTION !!!! VALUES TO CHANGE!

// Definition pins inductives sensors
#define IND_SENS_1		30
#define IND_SENS_2		32
#define IND_SENS_3		36
#define IND_SENS_4		34

// Definition pins phototransistors
#define PHOTOTR_SENS_1	6
#define PHOTOTR_SENS_2	7
#define PHOTOTR_SENS_3	8

// Definition pins inductives sensors
#define TOUCH_SENS_1	9
#define TOUCH_SENS_2	10
#define TOUCH_SENS_3	11
#define TOUCH_SENS_4	12

// Definition pins laser
#define LASER_EM_1		13
#define LASER_EM_2		14
#define LASER_EM_3		15

enum PHOTOTR_SNES_INPUT{
	PHOTOTR_SNES_INPUT_1 = 0,
	PHOTOTR_SNES_INPUT_2,
	PHOTOTR_SNES_INPUT_3
};

enum IND_SENS_INPUT{
	IND_SENS_INPUT_1 = 0,
	IND_SENS_INPUT_2,
	IND_SENS_INPUT_3,
	IND_SENS_INPUT_4
};

enum TOUCH_SENS_INPUT{
	TOUCH_SENS_INPUT_1 = 0,
	TOUCH_SENS_INPUT_2,
	TOUCH_SENS_INPUT_3,
	TOUCH_SENS_INPUT_4
};

enum LASER_EM_INPUT{
	LASER_EM_INPUT_1 = 0,
	LASER_EM_INPUT_2,
	LASER_EM_INPUT_3
};

// Initialization pins
void init_pins();

/* Input parametres:
 *	Sensor		pin of inductive sensor
 *
 *	Returns:
 *	0	-> when capsule not present
 *	1	-> when detected capsule
 *	-1	-> when error
 */
int find_capsule_ind_sens(IND_SENS_INPUT Sensor);

/* Input parametres:
 *	Laser		pin of laser module
 *  Phototr		pin of phototransistor
 *
 *	Returns:
 *	0	-> when capsule not present
 *	1	-> when detected capsule
 *	-1	-> when error
 */
int find_capsule_laser_photor_sens(LASER_EM_INPUT Laser, PHOTOTR_SNES_INPUT Phototr);

/* Input parametres:
 *	Sensor		pin of touch sensor
 *
 *	Returns:
 *	0	-> when capsule not present
 *	1	-> when detected capsule
 *	-1	-> when error
 */
int find_capsule_touch_sens(TOUCH_SENS_INPUT Sensor);

#endif //_HEADERFILE__SENSOR_FUNCTIONS_H
