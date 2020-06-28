# Description
Two softwares are available with the Elatec Reader:
- Director.exe
- AppBlaster.exe

# Director.exe
This programm is use to read any card via USB. In order to implement this, you have to load the right firmware USB

# AppBlaster.exe
This software allows you to custom the internal code of the Elatec reader. You have to create a source file (C programmed language) name it "App_HUS100_XXXXXXX_.c". You will then create a new firmware adding your source code file. Upload the firmware "TWN4_CCx322_HUS100_XXXXXXX.bix" in the device and you're ready to go. 

If something is unclear, please refer to the documentation "TWN4 API Reference DocRev24.pdf" and "TWN4 AppBlaster Config Cards User Guide DocRev10.pdf" and don't forget to check you wiring.
