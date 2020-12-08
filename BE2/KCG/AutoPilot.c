/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Usuario/SCADE/SCADE TP_2/BE2/KCG/config.txt
** Generation date: 2020-12-08T12:13:03
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "AutoPilot.h"

/* AutoPilot/ */
void AutoPilot(inC_AutoPilot *inC, outC_AutoPilot *outC)
{
  /* Descending/, _L5/ */
  kcg_bool Descending;
  /* Cruising/, _L15/ */
  kcg_bool Cruising;
  /* Climbing/, _L1/ */
  kcg_bool Climbing;
  /* SM1: */
  SSM_ST_SM1 SM1_state_act;

  Cruising = (inC->altitude >= crusingLowerThreshold) & (inC->altitude <=
      cruisingUpperThreshold);
  Descending = inC->altitude > descentLowerThreshold;
  Climbing = inC->altitude < climbUpperThreshold;
  /* SM1: */
  switch (outC->SM1_state_nxt) {
    case SSM_st_AutoPilotOff_SM1 :
      if (inC->automacticPilot & Climbing) {
        SM1_state_act = SSM_st_Climb_SM1;
      }
      else if (inC->automacticPilot & Cruising) {
        SM1_state_act = SSM_st_Cruising_SM1;
      }
      else if (inC->automacticPilot & Descending) {
        SM1_state_act = SSM_st_Descent_SM1;
      }
      else {
        SM1_state_act = SSM_st_AutoPilotOff_SM1;
      }
      break;
    case SSM_st_Descent_SM1 :
      if (inC->automacticPilot) {
        if (Cruising) {
          SM1_state_act = SSM_st_Cruising_SM1;
        }
        else {
          SM1_state_act = SSM_st_Descent_SM1;
        }
      }
      else {
        SM1_state_act = SSM_st_AutoPilotOff_SM1;
      }
      break;
    case SSM_st_Cruising_SM1 :
      if (inC->automacticPilot) {
        if (Descending) {
          SM1_state_act = SSM_st_Descent_SM1;
        }
        else if (Climbing) {
          SM1_state_act = SSM_st_Climb_SM1;
        }
        else {
          SM1_state_act = SSM_st_Cruising_SM1;
        }
      }
      else {
        SM1_state_act = SSM_st_AutoPilotOff_SM1;
      }
      break;
    case SSM_st_Climb_SM1 :
      if (inC->automacticPilot) {
        if (Cruising) {
          SM1_state_act = SSM_st_Cruising_SM1;
        }
        else {
          SM1_state_act = SSM_st_Climb_SM1;
        }
      }
      else {
        SM1_state_act = SSM_st_AutoPilotOff_SM1;
      }
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM1: */
  switch (SM1_state_act) {
    case SSM_st_AutoPilotOff_SM1 :
      outC->stickSetPoint = inC->stickPoint;
      outC->SM1_state_nxt = SSM_st_AutoPilotOff_SM1;
      break;
    case SSM_st_Descent_SM1 :
      outC->stickSetPoint = stickPointDescent;
      outC->SM1_state_nxt = SSM_st_Descent_SM1;
      break;
    case SSM_st_Cruising_SM1 :
      outC->stickSetPoint = stickPoinCruising;
      outC->SM1_state_nxt = SSM_st_Cruising_SM1;
      break;
    case SSM_st_Climb_SM1 :
      outC->stickSetPoint = stickPointClimb;
      outC->SM1_state_nxt = SSM_st_Climb_SM1;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void AutoPilot_init(outC_AutoPilot *outC)
{
  outC->stickSetPoint = kcg_lit_float32(0.0);
  outC->SM1_state_nxt = SSM_st_AutoPilotOff_SM1;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void AutoPilot_reset(outC_AutoPilot *outC)
{
  outC->SM1_state_nxt = SSM_st_AutoPilotOff_SM1;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** AutoPilot.c
** Generation date: 2020-12-08T12:13:03
*************************************************************$ */

