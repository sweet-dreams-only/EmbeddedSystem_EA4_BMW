/* temporary for CM475A contract folder until ES999A_Impl is baselined */
#ifndef ELECGLBPRM_H
#define ELECGLBPRM_H

#define ELECGLBPRM_PWMTMRPERDIVS_CNTPERNANOSEC_U13P19 (41943UL)  /* (1 count / 12.5 nanosec) = 0.08 = 41943 counts */
#define ELECGLBPRM_PWMPERDMIN_NANOSEC_U32  (45455UL)  /* max freq = 22kHz so min period = 1/22000 = 45455 nanosec */

/* Motor Control ISR Interrupt source as DMA */
#define ELECGLBPRM_MOTCTRLINTRPTTRIGCFGA_CNT_U08  			0U

/* Motor Control ISR Interrupt source as TSG31 Peak */
#define ELECGLBPRM_MOTCTRLINTRPTTRIGCFGB_CNT_U08  			1U

/* Stub for unit Testing- The below constant is a config parameter*/
/* Motor Control ISR Source Select */
extern  uint8 ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08;

#endif
