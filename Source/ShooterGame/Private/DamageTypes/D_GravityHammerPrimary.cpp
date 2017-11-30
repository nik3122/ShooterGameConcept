// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "D_GravityHammerPrimary.h"



UD_GravityHammerPrimary::UD_GravityHammerPrimary() {

	BaseDamageColor = FLinearColor::FLinearColor(255, 255, 0);
	LowDamageColor = FLinearColor::FLinearColor(255, 149, 0);
	MedDamageColor = FLinearColor::FLinearColor(255, 102, 0);
	HighDamageColor = FLinearColor::FLinearColor(255, 0, 0);
}


void UD_GravityHammerPrimary::DamagePlayer(float Damage, AController* KillerPlayer, AController* KilledPlayer, UConceptDamageBehavior* DamageBehavior) {
	AConceptPlayerController* KilledController = Cast<AConceptPlayerController>(KilledPlayer);
	if (KilledController) {
		AConceptCharacter*  KilledCharacter = Cast<AConceptCharacter>(KilledController->GetPawn());
		if (KilledCharacter) {
			KilledCharacter->ShakeManager(CameraShakeClass, false, Damage / 10);
		}
	}

	AConceptPlayerController* KillerController = Cast<AConceptPlayerController>(KillerPlayer);

	DamageBehavior->ApplyLifeDamage(Damage, this->GetClass());
	DamageBehavior->ApplyHitAnim(3, Damage);
	DamageBehavior->ApplyRadialImpulse(KillerController, KillerController->MyCharacter->GetActorLocation(), 2000, 2500000, 0.5f);
}
