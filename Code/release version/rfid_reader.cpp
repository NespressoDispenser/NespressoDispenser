#include "rfid_reader.h"
USER::USER() {
  solde = -1;
  logged = false;
}

int USER::get_solde() {
  return solde;
}

byte USER::get_id(int index) {
  if (index <= ID_LENGTH)
    return id[index];
}
void USER::set_solde(int new_solde) {
  solde = new_solde;
}

void USER::set_id(const byte new_id, int index) {
  if (index <= ID_LENGTH)
    id[index] = new_id;
}

bool USER::is_logged() {
  return logged;
}

void USER::log_in() {
  logged = true;
}

void USER::logout() {
  logged = false;
  solde = (-1); // no money
}

bool USER::buy_capsule(unsigned int price) {
  if (price <= solde) {
    solde -= price;
    return true;
  }
  else {
    return false;
  }
}

bool init_reader() {
  Wire.begin(I2C_ADDRESS); // join i2c bus with address I2C_ADDRESS
}
