#pragma once
#ifndef __RFID_READER_H__
#define __RFID_READER_H__
#include <Wire.h>
#include <SPI.h>
//constants
#define ID_LENGTH 4
#define I2C_ADDRESS 0X30
//two known IDs
const byte DATABASE[][4] = {{0x66, 0x1E, 0x82, 0x1F}, {0x77, 0x09, 0x1D, 0x8E}};
class USER {
  private:
    int solde;
    byte id[ID_LENGTH];
    bool logged;
  public:
    USER();
    int get_solde();
    byte get_id(int index);
    void set_solde(int new_solde);
    void set_id(const byte new_id, int index);
    bool is_logged();
    void log_in();
    void logout();
    bool buy_capsule(unsigned int price);
};
//begin I2C bus
bool init_reader();
#endif
