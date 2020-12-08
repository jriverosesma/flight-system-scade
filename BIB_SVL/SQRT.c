#include <math.h>
#include "kcg_types.h"

/*$ ************************************************************************* */
/*                                                                            */
/*$ IDENTIFICATION DE LA FONCTION  SQRT                                       */
/*                                                                            */
/*$ ************************************************************************* */
/*$ ROLE DE LA FONCTION                                                       */
/*$                                                                           */
/*$     Ce symbole fournit la racine carree de l'entree                       */
/*$                                                                           */
/*$ FIN ROLE DE LA FONCTION                                                   */
/*$ ************************************************************************* */
/*$ ARGUMENTS                                                                 */
/*$       ENTREE                                                              */
/*$         E1  : valeur reelle dont on veut la racine carree                 */
/*$       SORTIE                                                              */
/*$         S1  : racine carree de l'entree                                   */
/*$       ENTREE SORTIE                                                       */
/*$         Aucune                                                            */
/*$       CODE RETOUR                                                         */
/*$         Aucun                                                             */
/*$ FIN ARGUMENTS                                                             */
/*$ ************************************************************************* */
kcg_float32 SQRT(kcg_float32 E /* SQRT::E */)
{
   /*
	. S1 = racine carree de E1
	*/
	
	
	return(sqrt(E));
}
