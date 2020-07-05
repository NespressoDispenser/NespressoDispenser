//***
//Elatec Reader Source code -> used in AppBlaster.exe to create firmware image
//***
#include "twn4.sys.h"
#include "apptools.h"

#define MAXIDBYTES  10
#define MAXIDBITS   (MAXIDBYTES*8)

byte ID[MAXIDBYTES];
int IDBitCnt;
int TagType;

byte LastID[MAXIDBYTES];
int LastIDBitCnt;
int LastTagType;
const int I2CAddress = 0x30;

// If necessary adjust default parameters
#ifndef __APP_CONFIG_H__
    #define LFTAGTYPES        		0
    #define HFTAGTYPES        		0
#endif

const unsigned char AppManifest[] = { EXECUTE_APP, 1, EXECUTE_APP_ALWAYS, TLV_END };

// Setup tag types as configured in AppBlaster
void ConfigSetTagTypes(void)
{
	if (LFTAGTYPES || HFTAGTYPES)
    	SetTagTypes(LFTAGTYPES,HFTAGTYPES);
}

int main(void)
{
	//define communication mode I2C
	SetHostChannel(CHANNEL_I2C);
	I2CInit(I2CMODE_MASTER);
	// Set tag types
	ConfigSetTagTypes();
    // Make some noise at startup at low volume
    SetVolume(30);
    BeepLow();
    BeepHigh();
    // Continue with higher volume
    SetVolume(80);
    // No transponder found up to now
    LastTagType = NOTAG;
	while (true)
    {
        // Search a transponder
        if (SearchTag(&TagType,&IDBitCnt,ID,sizeof(ID)))
        {
			// Is this transponder new to us?
			if (TagType != LastTagType || IDBitCnt != LastIDBitCnt || !CompBits(ID,0,LastID,0,MAXIDBITS))
			{
				// Save this as known ID, before modifying the ID for proper output format
				CopyBits(LastID,0,ID,0,MAXIDBITS);
				LastIDBitCnt = IDBitCnt;
				LastTagType = TagType;
				//Sound a beep
				BeepHigh();
				I2CMasterStart();
				I2CMasterBeginWrite(I2CAddress);
				// Send UID
				for(int i = 0; i<=4;i++){ //Mifare/Legic ID length is 4 bytes
				I2CMasterTransmitByte(ID[i]);
				}
				I2CMasterStop();
			}
			StartTimer(2000);
        }
        if (TestTimer())
        {
            LastTagType = NOTAG;
        }
    }
}
