// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinCounter.h"
//#include "Spawn/Coin.h"


// Sets default values
ACoinCounter::ACoinCounter()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ACoinCounter::OverlapBegin);
}

// Called when the game starts or when spawned
void ACoinCounter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoinCounter::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (Cast<ACoin>(OtherActor) != nullptr) {
		counter++;

	}*/
}

void ACoinCounter::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Number of coins that hit the plane is %d"), &counter);

}




