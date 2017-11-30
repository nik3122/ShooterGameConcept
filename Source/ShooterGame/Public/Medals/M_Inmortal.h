// Todos los derechos reservados por Catness Game Studios

#pragma once

#include "Medals/Medal.h"
#include "M_Inmortal.generated.h"

/**
 * 
 */


UCLASS()
class SHOOTERGAME_API UM_Inmortal : public UMedal
{
	GENERATED_BODY()


		UM_Inmortal();


	UMedal* GetAchievedMedal(AConceptStats* Stats) override;
};
