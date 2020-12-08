/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config C:/Users/Usuario/SCADE/SCADE TP_2/BE2/KCG/config.txt
** Generation date: 2020-12-08T12:13:03
*************************************************************$ */
#ifndef _AutoPilot_H_
#define _AutoPilot_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_float32 /* _L14/, _L17/, _L2/, _L6/, altitude/ */ altitude;
  kcg_bool /* _L20/,
     _L21/,
     autoPilotOnOff/,
     automacticPilot/ */ automacticPilot;
  kcg_float32 /* stickPoint/ */ stickPoint;
} inC_AutoPilot;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* stickSetPoint/ */ stickSetPoint;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  SSM_ST_SM1 /* SM1: */ SM1_state_nxt;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_AutoPilot;

/* ===========  node initialization and cycle functions  =========== */
/* AutoPilot/ */
extern void AutoPilot(inC_AutoPilot *inC, outC_AutoPilot *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void AutoPilot_reset(outC_AutoPilot *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void AutoPilot_init(outC_AutoPilot *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _AutoPilot_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** AutoPilot.h
** Generation date: 2020-12-08T12:13:03
*************************************************************$ */

