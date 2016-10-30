// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "MLiewCSProjectile.generated.h"

UCLASS(config = Game)
class AMLiewCSProjectile : public AActor
{
	GENERATED_BODY()

	/** explosion FX */
	UPROPERTY(EditDefaultsOnly, Category = Effect)
	UParticleSystem* ExplosionFX;

	/** explosion sound */
	UPROPERTY(EditDefaultsOnly, Category = Effect)
	USoundCue* ExplosionSound;

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;

public:
	AMLiewCSProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

