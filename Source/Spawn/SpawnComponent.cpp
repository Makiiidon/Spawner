// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnComponent.h"

// Sets default values for this component's properties
USpawnComponent::USpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	SpawnTimer = SPAWN_INTERVAL;
	DeleteTimer = DELETE_INTERVAL;
	// ...
}


// Called when the game starts
void USpawnComponent::BeginPlay()
{
	Super::BeginPlay();


	Coin->SetActorHiddenInGame(true);

	InputListener->InputComponent->BindAction("Spawn", IE_Pressed, this, &USpawnComponent::SpawnBatch);

	// ...
	
}


// Called every frame
void USpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//SpawnTimer -= DeltaTime;

	//if (SpawnTimer <= 0.0f && Coin != NULL) {
	//	SpawnTimer = SPAWN_INTERVAL;
	//	SpawnBatch();
	//}

	if (DeleteTimer <= 0.0f) {
		DestroyAll();
		DeleteTimer = DELETE_INTERVAL;
		//UE_LOG(LogTemp, Display, TEXT("Deleted All Coins."));
	}
	else {
		DeleteTimer -= DeltaTime;
	}

	// ...
}

void USpawnComponent::DestroyAll()
{

	for (int i = 0; i < SpawnedObjects.Num(); i++) {
		SpawnedObjects[i]->Destroy();
	}

	SpawnedObjects.Reset();

}

void USpawnComponent::SpawnBatch()
{

	for (int i = 0; i < 10; i++) {
		FActorSpawnParameters params;
		params.Template = Coin;
		params.Owner = GetOwner();

		AActor* myActor = GetWorld()->SpawnActor<AActor>(Coin->GetClass(), params);
		myActor->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
		myActor->SetActorLocationAndRotation(FVector(
			GetOwner()->GetActorLocation().X,
			FMath::RandRange((double)StartSpawnLocation.Y, (double)EndSpawnLocation.Y),
			FMath::RandRange((double)StartSpawnLocation.Z, (double)EndSpawnLocation.Z)),
			GetOwner()->GetActorRotation());

		myActor->SetActorHiddenInGame(false);

		SpawnedObjects.Add(myActor);
	}
	//UE_LOG(LogTemp, Display, TEXT("Spawned"));

}







