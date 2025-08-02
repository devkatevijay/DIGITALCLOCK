/*******************************************************************************
* File Name: Buzzer_Write.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Buzzer_Write_H) /* Pins Buzzer_Write_H */
#define CY_PINS_Buzzer_Write_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Buzzer_Write_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Buzzer_Write__PORT == 15 && ((Buzzer_Write__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Buzzer_Write_Write(uint8 value);
void    Buzzer_Write_SetDriveMode(uint8 mode);
uint8   Buzzer_Write_ReadDataReg(void);
uint8   Buzzer_Write_Read(void);
void    Buzzer_Write_SetInterruptMode(uint16 position, uint16 mode);
uint8   Buzzer_Write_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Buzzer_Write_SetDriveMode() function.
     *  @{
     */
        #define Buzzer_Write_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Buzzer_Write_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Buzzer_Write_DM_RES_UP          PIN_DM_RES_UP
        #define Buzzer_Write_DM_RES_DWN         PIN_DM_RES_DWN
        #define Buzzer_Write_DM_OD_LO           PIN_DM_OD_LO
        #define Buzzer_Write_DM_OD_HI           PIN_DM_OD_HI
        #define Buzzer_Write_DM_STRONG          PIN_DM_STRONG
        #define Buzzer_Write_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Buzzer_Write_MASK               Buzzer_Write__MASK
#define Buzzer_Write_SHIFT              Buzzer_Write__SHIFT
#define Buzzer_Write_WIDTH              1u

/* Interrupt constants */
#if defined(Buzzer_Write__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Buzzer_Write_SetInterruptMode() function.
     *  @{
     */
        #define Buzzer_Write_INTR_NONE      (uint16)(0x0000u)
        #define Buzzer_Write_INTR_RISING    (uint16)(0x0001u)
        #define Buzzer_Write_INTR_FALLING   (uint16)(0x0002u)
        #define Buzzer_Write_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Buzzer_Write_INTR_MASK      (0x01u) 
#endif /* (Buzzer_Write__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Buzzer_Write_PS                     (* (reg8 *) Buzzer_Write__PS)
/* Data Register */
#define Buzzer_Write_DR                     (* (reg8 *) Buzzer_Write__DR)
/* Port Number */
#define Buzzer_Write_PRT_NUM                (* (reg8 *) Buzzer_Write__PRT) 
/* Connect to Analog Globals */                                                  
#define Buzzer_Write_AG                     (* (reg8 *) Buzzer_Write__AG)                       
/* Analog MUX bux enable */
#define Buzzer_Write_AMUX                   (* (reg8 *) Buzzer_Write__AMUX) 
/* Bidirectional Enable */                                                        
#define Buzzer_Write_BIE                    (* (reg8 *) Buzzer_Write__BIE)
/* Bit-mask for Aliased Register Access */
#define Buzzer_Write_BIT_MASK               (* (reg8 *) Buzzer_Write__BIT_MASK)
/* Bypass Enable */
#define Buzzer_Write_BYP                    (* (reg8 *) Buzzer_Write__BYP)
/* Port wide control signals */                                                   
#define Buzzer_Write_CTL                    (* (reg8 *) Buzzer_Write__CTL)
/* Drive Modes */
#define Buzzer_Write_DM0                    (* (reg8 *) Buzzer_Write__DM0) 
#define Buzzer_Write_DM1                    (* (reg8 *) Buzzer_Write__DM1)
#define Buzzer_Write_DM2                    (* (reg8 *) Buzzer_Write__DM2) 
/* Input Buffer Disable Override */
#define Buzzer_Write_INP_DIS                (* (reg8 *) Buzzer_Write__INP_DIS)
/* LCD Common or Segment Drive */
#define Buzzer_Write_LCD_COM_SEG            (* (reg8 *) Buzzer_Write__LCD_COM_SEG)
/* Enable Segment LCD */
#define Buzzer_Write_LCD_EN                 (* (reg8 *) Buzzer_Write__LCD_EN)
/* Slew Rate Control */
#define Buzzer_Write_SLW                    (* (reg8 *) Buzzer_Write__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Buzzer_Write_PRTDSI__CAPS_SEL       (* (reg8 *) Buzzer_Write__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Buzzer_Write_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Buzzer_Write__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Buzzer_Write_PRTDSI__OE_SEL0        (* (reg8 *) Buzzer_Write__PRTDSI__OE_SEL0) 
#define Buzzer_Write_PRTDSI__OE_SEL1        (* (reg8 *) Buzzer_Write__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Buzzer_Write_PRTDSI__OUT_SEL0       (* (reg8 *) Buzzer_Write__PRTDSI__OUT_SEL0) 
#define Buzzer_Write_PRTDSI__OUT_SEL1       (* (reg8 *) Buzzer_Write__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Buzzer_Write_PRTDSI__SYNC_OUT       (* (reg8 *) Buzzer_Write__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Buzzer_Write__SIO_CFG)
    #define Buzzer_Write_SIO_HYST_EN        (* (reg8 *) Buzzer_Write__SIO_HYST_EN)
    #define Buzzer_Write_SIO_REG_HIFREQ     (* (reg8 *) Buzzer_Write__SIO_REG_HIFREQ)
    #define Buzzer_Write_SIO_CFG            (* (reg8 *) Buzzer_Write__SIO_CFG)
    #define Buzzer_Write_SIO_DIFF           (* (reg8 *) Buzzer_Write__SIO_DIFF)
#endif /* (Buzzer_Write__SIO_CFG) */

/* Interrupt Registers */
#if defined(Buzzer_Write__INTSTAT)
    #define Buzzer_Write_INTSTAT            (* (reg8 *) Buzzer_Write__INTSTAT)
    #define Buzzer_Write_SNAP               (* (reg8 *) Buzzer_Write__SNAP)
    
	#define Buzzer_Write_0_INTTYPE_REG 		(* (reg8 *) Buzzer_Write__0__INTTYPE)
#endif /* (Buzzer_Write__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Buzzer_Write_H */


/* [] END OF FILE */
