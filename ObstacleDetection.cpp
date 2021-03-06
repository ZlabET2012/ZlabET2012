#include "ObstacleDetection.h"

#define SONAR_ALERT_DISTANCE 30 /* ´¹gZTÉæéáQ¨m£[cm] */

ObstacleDetection::ObstacleDetection(){
	counter = 0;
}

// áQ¨mðs¤
BOOL ObstacleDetection::detect(S32 sonar){
	BOOL alert = FALSE;

	// ñ40msecüúÉáQ¨m
	if (counter == 9)
	{
		if ((sonar <= SONAR_ALERT_DISTANCE) && (sonar >= 0))
		{
			alert = TRUE; /* áQ¨ðm */
		}
		else
		{
			alert = FALSE; /* áQ¨³µ */
		}
		counter = 0;
	}
	else{
		counter++;
	}

	return alert;
}
