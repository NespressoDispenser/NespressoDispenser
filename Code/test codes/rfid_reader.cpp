#include "rfid_reader.h"

bool init_reader(){
	Wire.begin();
	pinMode(GPIO_LED_GREEN, INPUT);
	pinMode(GPIO_LED_RED, INPUT);
	
}

void read_card(int reader_adress, int data_lentgh, USER* actif_user){
	//Wire.requestFrom(0x30, 4);    // request X bytes from slave device adress Y
	Wire.requestFrom(reader_adress, data_lentgh);
	int i = 0;
	char temp_id[ID_LENTGH] = {"EMPTY"};
    while (Wire.available()){   // slave may send less than requested
      char c = Wire.read(); // receive a byte as character
      if(IS_HEX(c)){
		    temp_id[i] = c;
		    i++;
        //Serial.print(c);
	      }
    }
    if(!strcmp(actif_user->get_id(),temp_id))
      actif_user->set_id(temp_id);
      
}

bool is_logged(USER* actif_user){
  if(strcmp(actif_user->get_id(), "NO_USER")){
    return false;
  }
  else{
    return true;
  }
}
void buy_capsule(unsigned int price,USER* actif_user){
  int solde = actif_user->get_solde();
    solde -= price;
    actif_user->set_solde(solde);
}
bool enough_money(unsigned int price,USER* actif_user){
  int solde = actif_user->get_solde();
  if(price <= solde){
    return true;
  }
  else{
    return false;
  }
}

void logout(USER* actif_user){
  actif_user->set_id("NO_USER");
  actif_user->set_solde(-1); // no money
}

USER::USER(){
  solde = -1;
  strcpy(id, "NO_USER");
  }
void USER::set_solde(int new_solde){
  solde = new_solde;
}
void USER::set_id(char* new_id){
	strcpy(id, new_id);
}
int USER::get_solde(){
	return solde;
}
char* USER::get_id(){
  return id;
}
void USER::set_database_length(unsigned int number_user){
	database_length = number_user;
}
unsigned int USER::get_database_length(){
	return database_length;
}
