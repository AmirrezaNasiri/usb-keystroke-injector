
#define DEBUG_DIP false
#define MAX_PAYLOAD_LEN 300
#define MAX_SDCARD_LEN 1400

/*
 * Bluetooth Pins
 */
#define BLUETOOTH_STATE 8
//#define BLUETOOTH_TXD 8
//#define BLUETOOTH_RXD 9

/*
 * SD Card Pins
 */
#define SD_CS 10

/*
 * DIP Pins
 * [1] Emulate      
 * [2] Debug  
 * [3] Mode         
 * [4] Forth Opt.   
 * [5] Fifth Opt.   
 * [6] Sixth Opt.        
 */
#define DIP_EMULATE 2
#define DIP_DEBUG 3
#define DIP_MODE 4
#define DIP_4 5
#define DIP_5 6
#define DIP_6 7

/*
 * LDR
 */
#define LDR_PIN 20
#define LDR_TOLERATE 0.1
#define LDR_WAIT 1000

#define LED 21
#define MORSE_UNIT_LENGTH 250


/*
 * ==================================================================================================
 * ==================================================================================================
*/

// DIP
boolean emulate = false;
boolean debug = true;
char mode;
boolean dip4;
boolean dip5;
boolean dip6;

// Bluetooth
boolean bluetoothConnected = false;
// SoftwareSerial bluetoothSerial(BLUETOOTH_RXD, BLUETOOTH_TXD);

// SD Card
File myFile;

// USB
boolean reportUsbIsReady = true;

// Payload Buffers
char strPayload[MAX_PAYLOAD_LEN];
byte strLen   = 0;
char strSdCard[MAX_SDCARD_LEN];
char* line = NULL;
boolean isContextReady = false;


// LDR
int ldrIndicator = 0;
int ldrReadyTries = 0;
int ldrValue = -1;

// Other
int delayRatio = 1;



// Errors
#define WARN_EMULATION_OFF 3
#define WARN_WAITING_FOR_SERIAL 2
#define WARN_WAITING_FOR_BLUETOOTH 0
#define WARN_SD_BEGIN_FAILED 4
#define WARN_SD_OPEN_FAILED 5
