#include "kcg_types.h"
#include <math.h>
#define M_PI 3.1415

/*$ ************************************************************************* */
/*                                                                            */
/*$ IDENTIFICATION DE LA FONCTION  ASIN                                       */
/*                                                                            */
/*$ ************************************************************************* */
/*$ ROLE DE LA FONCTION                                                       */
/*$                                                                           */
/*$     Ce symbole fournit l'arc-sinus de l'entree                            */
/*$                                                                           */
/*$ FIN ROLE DE LA FONCTION                                                   */
/*$ ************************************************************************* */
/*$ ARGUMENTS                                                                 */
/*$       ENTREE                                                              */
/*$         E1  : valeur reelle dont on veut l'arc-sinus                      */
/*$       SORTIE                                                              */
/*$         S1  : arc-sinus de l'entree                                       */
/*$       ENTREE SORTIE                                                       */
/*$         Aucune                                                            */
/*$       CODE RETOUR                                                         */
/*$         Aucun                                                             */
/*$ FIN ARGUMENTS                                                             */
/*$ ************************************************************************* */
kcg_float32 ASIN(kcg_float32 E1 /* ASIN::E1 */)
{
   /* S1 = arc-sinus de E1 */
	
   return(asin((double)E1)*180/M_PI);
}
