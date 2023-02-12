// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPAWN_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		FVector PushVector;

	UPROPERTY(EditAnywhere)
		FVector PullVector;

	UPROPERTY(EditAnywhere)
		float Lerp;

	UPROPERTY(EditAnywhere)
		float MovementTime = 5.0f;

	UPROPERTY(EditAnywhere)
		float MOVE_INTERVAL = 0.1f;

	float MoveTimer;
	float LerpTimer;

	void Pull();
	void Push();

	bool isPushing = true;
		
};
