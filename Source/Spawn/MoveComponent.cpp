// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	MoveTimer = MovementTime;
	LerpTimer = MOVE_INTERVAL;
	// ...
	
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (MoveTimer <= 0.0f) {
		MoveTimer = MovementTime;
		isPushing = !isPushing;
	}
	else {
		MoveTimer -= DeltaTime;
	}


	if (LerpTimer <= 0.0f) {
		if (isPushing) {
			Push();

		}
		else if (!isPushing) {
			Pull();

		}
		LerpTimer = MOVE_INTERVAL;
	}
	else {
		LerpTimer -= DeltaTime;
	}
	

	// ...
}

void UMoveComponent::Pull()
{
	double xVal = GetOwner()->GetActorLocation().X + (PullVector.X - GetOwner()->GetActorLocation().X) * Lerp ;
	GetOwner()->SetActorLocation(FVector(xVal, GetOwner()->GetActorLocation().Y, GetOwner()->GetActorLocation().Z));
	//UE_LOG(LogTemp, Display, TEXT("PULL"));

}

void UMoveComponent::Push()
{
	double xVal = GetOwner()->GetActorLocation().X + (PushVector.X - GetOwner()->GetActorLocation().X) * Lerp ;
	GetOwner()->SetActorLocation(FVector(xVal, GetOwner()->GetActorLocation().Y, GetOwner()->GetActorLocation().Z));
	//UE_LOG(LogTemp, Display, TEXT("PUSH."));

}

