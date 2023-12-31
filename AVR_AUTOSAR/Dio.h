/*
 * Dio.h
 *
 *  Created on: Jul 15, 2023
 *      Author: O. A.
 * 
 * Description: Header file for Dio Module.
 * 
 */
#ifndef DIO_H_
#define DIO_H_


/* Id for the company in the AUTOSAR EX. Vector = 31, Valeo = 7*/
#define DIO_VENDOR_ID    (7U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (0U)
#define DIO_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/************************************************************************************
 *                      API Service Id Macros for Dio module
 *     Service ID (unique ID for each function used for example for reporting errors)
 ************************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           ((uint8)0x00)

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          ((uint8)0x01)

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              ((uint8)0x02)

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             ((uint8)0x03)

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     ((uint8)0x04)

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    ((uint8)0x05)

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       ((uint8)0x12)

/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   ((uint8)0x10)

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           ((uint8)0x11)


/*******************************************************************************
 *                      DET Error Codes for Dio module                                       *
 *******************************************************************************/

/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID ((uint8)0x0A)

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             ((uint8)0x10)

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    ((uint8)0x14)

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      ((uint8)0x1F)

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             ((uint8)0x20)

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document).
 */
#define DIO_E_UNINIT                   ((uint8)0xF0)

/*******************************************************************************
 *                              Dio Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;


#define DIO_CHANNEL0  0
#define DIO_CHANNEL1  1
#define DIO_CHANNEL2  2
#define DIO_CHANNEL3  3
#define DIO_CHANNEL4  4
#define DIO_CHANNEL5  5
#define DIO_CHANNEL6  6
#define DIO_CHANNEL7  7

#define DIO_PORTA     0
#define DIO_PORTB     1
#define DIO_PORTC     2
#define DIO_PORTD     3


/* Structure for Dio_ChannelGroup */
typedef struct
{
  uint8         mask;           /* Mask which defines the positions of the channel group */
  uint8        offset;    /* Position of the group from LSB */
  Dio_PortType PortIndex; /* This shall be the port ID which the Channel group is defined. */

} Dio_ChannelGroupType;

typedef struct
{
  Dio_PortType    PortIndex;       /* Member contains the ID of the Port that this channel belongs to */
  Dio_ChannelType ChannelIndex; /* Member contains the ID of the Channel*/

}Dio_ConfigChannel;

/* Data Structure required for initializing the Dio Driver */
typedef struct
{
  Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;



/*******************************************************************************
 *                      Function Prototypes for Dio module                                    *
 *******************************************************************************/
/* Function for DIO read Channel API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType const ChannelId);

/* Function for DIO write Channel API */
void Dio_WriteChannel(Dio_ChannelType const ChannelId, Dio_LevelType const Level);

#if 0
/* Function for DIO read Port API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType const PortId);

/* Function for DIO write Port API */
void Dio_WritePort(Dio_PortType const PortId, Dio_PortLevelType const Level);
#endif

/* Function for DIO Initialization API */
void Dio_Init(const Dio_ConfigType * ConfigPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType const ChannelId);
#endif

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Post-Build PB structures to be used by Dio and other modules */
extern const Dio_ConfigType Dio_Configuration;


#endif /* DIO_H_ */
