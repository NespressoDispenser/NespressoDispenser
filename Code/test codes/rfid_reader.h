#pragma once
#ifndef RFID_READER_H
#define RFID_READER_H
#include <Wire.h>
#include <SPI.h>

#define GPIO_LED_GREEN 2
#define GPIO_LED_RED 3
//**macros**
#define READ_LED_G digitalRead(GPIO_LED_GREEN) //macro lire GPIO led
#define READ_LED_R digitalRead(GPIO_LED_RED) 

#define IS_HEX(c) (((isdigit(c)) or (c >= 'A' and c <= 'F')) ? true: false)
//**constantes**
#define FILENAME "database.txt"
#define NBR_PERS 40
#define SOLDE_LENGTH 6
#define ID_LENTGH 8

class USER{
private:
	int solde;// = {"EMPTY"};
	char id[ID_LENTGH];// = {"NO_USER"};
	unsigned int database_length = 0;
public:
	USER();
	int get_solde();
	char* get_id();
	void set_solde(int new_solde);
	void set_id(char* new_id);
	void set_database_length(unsigned int user_number);
	unsigned int get_database_length();
};

bool init_reader();

void read_card(int reader_adress, int data_lentgh, USER* actif_user); //retourner ID ?

bool is_logged(USER* actif_user);

void buy_capsule(unsigned int price,USER* actif_user);

bool enough_money(unsigned int price,USER* actif_user);

void logout(USER* actif_user);
#endif
