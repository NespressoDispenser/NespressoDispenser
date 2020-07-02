#pragma once
#include "database.h"

void init_database(int chip_select){
	pinMode(chip_select, OUTPUT); // chip select pin must be set to OUTPUT mode
  if (!SD.begin(chip_select)) { // Initialize SD card
    Serial.println("Error SD Card"); // if return value is false, something went wrong.
  }
  
  if (SD.exists(FILENAME)) { // if "file.txt" exists, fill will be deleted
    Serial.println("Database existing");
  }
}

void read_database(USER* personne){
  
	//file = SD.open(FILENAME, FILE_READ); // open "file.txt" to read data
  File file = SD.open("data.csv");
	file.seek(0);
	unsigned int cnt_ligne = 0;
	unsigned int cnt_lettre = 0;
	bool lire_id = false;
	bool lire_solde = false;
	char temp_id[ID_LENTGH];
	char temp_solde[SOLDE_LENGTH];
	while (file.available()) {
      //on commence par lire l'ID dans le fichier
      if(!lire_id and !lire_solde){
        lire_id = true;
      }
      char c = file.read();
      //ràz du compteur de lettre lors d'un ';'
     if(c == ';'){
      if(lire_id){
        //personne[cnt_ligne].id[++cnt_lettre] = '\0';
		temp_id[++cnt_lettre] = '\0';
        lire_id = false;
        lire_solde = true;
      }
      else{
        //personne[cnt_ligne].solde[++cnt_lettre] = '\0';
		temp_solde[++cnt_lettre] = '\0';
        lire_id = true;
        lire_solde = false;
      }
      cnt_lettre = 0; 
     }
     if(c != '\r' and c != '\n' and c != ';'){
        //on détermine si on est en train de récupérer l'ID ou le solde
        if(lire_id){
			temp_id[cnt_lettre] = c;
			//personne[cnt_ligne].id[cnt_lettre] = c;
        }
        else{
			//personne[cnt_ligne].solde[cnt_lettre] = c;
			temp_solde[cnt_lettre]=c;
        }
        cnt_lettre++;
     }
     else{
       if(c == '\n'){

int solde = 0;
int factor = cnt_lettre-1;
        for(int i = 0; i<cnt_lettre ; i++){
          solde += pow(10,factor)* temp_solde[i];
        }
		personne[cnt_ligne].set_id(temp_id);
		personne[cnt_ligne].set_solde(solde);
        //Serial.println(personne[cnt_ligne].id);
        //Serial.println(personne[cnt_ligne].solde);
        //Serial.println("en ligne:");
        //Serial.println(cnt_ligne);
        cnt_ligne++;
       }
     }    
	 personne->set_database_length(cnt_ligne);
   }
}
bool find_id(USER* personne, USER* actif_user){
	for(int i = 0; i< personne->get_database_length();i++){
		//if(actif_user->get_id().equals(personne[i].get_id())){
    if(actif_user->get_id() == personne[i].get_id()){
		Serial.println("ID found");
		/*Serial.println(i);  
		Serial.println("Son solde est de ");
		Serial.println(personne[i].id);	*/
		return true;
		}
	}
	return false;
}
