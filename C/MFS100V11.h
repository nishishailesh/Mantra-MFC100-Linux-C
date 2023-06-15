/*******************************************************
 *            File           : MFS100V11.h
 *	      Description    : Header File for MFS100 devices
 *
 *            Copyright @ Mantra Softech India Pvt Ltd
 *********************************************************/

    
#ifndef  MFS100V11_H
#define  MFS100V11_H
    
#if defined (__cplusplus)
extern "C" {
#endif

void *MFS100Init (unsigned char* serialno, int latentThreshold, int Xfer_Size, int pcbversion);
void *MFS100InitWithKey (unsigned char* serialno,int latentThreshold, int Xfer_Size, int pcbversion,unsigned char* UnlockKey);
int MFS100Uninit(void *device);
int MFS100GetWidth(void *device);
int MFS100GetHeight(void *device);
int MFS100StartXcan(void *device, int Frames, int Timeout);
int MFS100StopXcan(void *device);
int MFS100DeviceConnected();    //change here
int MFS100GetFinalFrame(void *device,unsigned char *Final_frame);
int MFS100RotateImage(void *device, int Direction);
int MFS100GetContrast(void *device);
int MFS100ExtractISOTemplate(void *device,unsigned char* RawImage, unsigned char* Iso_19794_2_Template, int *TemplateLength);
int MFS100ExtractANSITemplate(void *device,unsigned char* RawImage, unsigned char *Ansi_378_2004_Template, int *TemplateLength);
int MFS100ExtractISOImage(void *device,unsigned char* RawImage,unsigned char *ISOImage, int *ISOImageSize, unsigned char FingerPosition);
int MFS100MatchISO(void *device,unsigned char* probeTemplate,unsigned char* galleryTemplate, int Rotation, int *score);
int MFS100MatchANSI(void *device,unsigned char* probeTemplate,unsigned char* galleryTemplate, int Rotation, int *score);
int MFS100LastErrorCode();
int MFS100GetPreviewFrame(void *device,unsigned char *Frame);
int MFS100ConvertRawToBmp(void *device,unsigned char* frame, unsigned char* Imagedata, int ht, int wd);

int MFS100GetSDKVersion(); 
int MFS100GetInfo(char* Make, char* Model);
int MFS100AutoCapture(void *device, int Timeout, int MinimumQuality, unsigned char *AutoCaptureRawImage, unsigned char* BitmapImageData, unsigned char* Iso_19794_2_Template, int * ISO_TemplateLength, unsigned char* Ansi_378_2004_Template, int * ANSI_TemplateLength, int *Quality, int *NFIQ,void (*MFS100AutoCaptureCallBack)(unsigned char*));
int MFS100GetQuality(void *device);
int MFS100GetNFIQ(void *device);
int MFS100IsLive(void *device,unsigned char* FinalFrame500DPI,int threshold,int *score);
int MFS100ExtractWSQImage(void *device,unsigned char* FinalFrame,unsigned char **WSQImage,int *WSQImageSize,float compressionRatio);


#define MFS100_E_SUCCESS					0               //Success
#define MFS100_E_NO_DEVICE					-1307           //No Device Present
#define MFS100_E_INVALIDPARAM					-1101           //Invalid Parameters
#define MFS100_E_NULLPARAM					-1121           //Null Parameters
#define MFS100_E_MEMORY						-1120           //Memory allocation failed
#define MFS100_E_CORRUPT_SERIAL					-1314           //Serial no currupted
#define MFS100_E_UNKNOWN_SENSOR					-1142           //Unknown Sensor
#define MFS100_E_LOAD_FIRMWARE_FAILED				-1317           //Firmware failed to load
#define MFS100_E_NOT_INITIALIZED				-1309           //Device Not Initialized
#define MFS100_E_SYNC_PROBLEM					-1139           //Sync Problem
#define MFS100_E_OTHER						-1122           //Other Error
#define MFS100_E_TIMEOUT					-1140           //Timeout
#define MFS100_E_NOT_GOOD_IMAGE					-1115           //Input image is not good
#define MFS100_E_BLANKIMAGE					-1114		//Image is blank or contains non-recognizable fingerprint
#define MFS100_E_EXTRACTOR_INIT_FAILED				-1116		//Extractor Library cannot Initialize
#define MFS100_E_FILE_IO					-1117		//Error occured while opening/reading file
#define MFS100_E_BAD_LICENSE					-1129		//Provided license is not valid, or no license was found
#define MFS100_E_BAD_FORMAT					-1132		//Unsupported Format
#define MFS100_E_BAD_VALUE					-1133		//Invalid Value Provided
#define MFS100_E_BAD_TEMPLATE					-1135		//Invalide template or unsupported template format
#define MFS100_E_READ_ONLY					-1136		//Value cannot be modified
#define MFS100_E_NOT_DEFINED					-1137		//Value is not defined
#define MFS100_E_NULL_TEMPLATE					-1138		//Template is NULL (contains no finger)
#define MFS100_E_NOT_IMPLEMENTED                                -1134           //Function not implemented
#define MFS100_E_BAD_QUALITY                                    -1318           //Bad Quality Finger
#define MFS100_E_CAPTURING_STOPPED                              -1319           //Capturing stopped
#define MFS100_E_LATENT_FINGER                                  -1320           //latent finger on device
#define MFS100_E_INVALID_KEY                                    -1322			//Already start or already stopped

#define MFS100_E_USB_ERROR_IO                         -1            //USB IO port error
#define MFS100_E_USB_ERROR_INVALID_PARAM              -2            //Invalid parameter to usb function
#define MFS100_E_USB_ERROR_ACCESS                     -3            //Cannot Access USB port, rights problems
#define MFS100_E_USB_ERROR_NO_DEVICE                  -4            //No USB Device
#define MFS100_E_USB_ERROR_NOT_FOUND                  -5            //Unknown Error
#define MFS100_E_USB_ERROR_BUSY                       -6            //USB Busy, Disconnect sensor and connect again
#define MFS100_E_USB_ERROR_TIMEOUT                    -7            //USB Timeout
#define MFS100_E_USB_ERROR_OVERFLOW                   -8            //USB Data Overflow
#define MFS100_E_USB_ERROR_PIPE                       -9            //Cannot access USB Pipe
#define MFS100_E_USB_ERROR_INTERRUPTED                -10           //Hardware Inturrupt Error
#define MFS100_E_USB_ERROR_NO_MEM                     -11           //No internal memory
#define MFS100_E_USB_ERROR_NOT_SUPPORTED              -12           //Functionality not supported
#define MFS100_E_USB_OPEN_FAILED		      -13           //USB Port open failed
#define MFS100_E_USB_CLAIM_INTERFACE_FAILED           -14           //USB Claim interface failed
#define MFS100_E_USB_ERROR_OTHER                      -99           //Other USB related error

#if defined (__cplusplus)
}
#endif

#endif /* MFS100V11_H */


