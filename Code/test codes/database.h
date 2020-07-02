#pragma once
#include <SPI.h>
#include <Arduino.h>
#include <SD.h> 
#include "rfid_reader.h"
//#ifndef DATABASE_H
#define DATABASE_H


#define FILENAME "database.csv"
#define NBR_PERS 40
//String NCREDIT_ID = "BB";

void init_database(int chip_select);

void read_database(USER* personne);

bool find_id(USER* personne, USER* actif_user);

//#endif
