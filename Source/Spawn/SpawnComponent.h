// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPAWN_API USpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		AActor* Coin = NULL;

	UPROPERTY(EditAnywhere)
		APawn* InputListener;

	UPROPERTY(EditAnywhere)
		float SPAWN_INTERVAL = 1.0f;

	UPROPERTY(EditAnywhere)
		float DELETE_INTERVAL = 1.0f;

	UPROPERTY(EditAnywhere)
		FVector StartSpawnLocation;

	UPROPERTY(EditAnywhere)
		FVector EndSpawnLocation;

	float SpawnTimer = 0.0f;
	float DeleteTimer = 0.0f;


	TArray<AActor*> SpawnedObjects;

	void DestroyAll();

	void SpawnBatch();
};
