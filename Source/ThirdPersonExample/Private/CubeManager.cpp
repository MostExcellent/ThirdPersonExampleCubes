#include "CubeManager.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "HitCube.h"
//#include "Kismet/KismetMathLibrary.h"

ACubeManager::ACubeManager()
{
	PrimaryActorTick.bCanEverTick = true;  // Set to true for future use

	// Create the root capsule
	RootCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootCapsule"));
	RootComponent = RootCapsule;
}

void ACubeManager::BeginPlay()
{
    Super::BeginPlay();

    // Spawn actors
    for (int i = 0; i < NumberOfActors; ++i)
    {
        float Angle = 2 * PI * i / NumberOfActors; // Calculate the angle for even spacing
        FVector SpawnPosition = GetActorLocation() + FVector(SpawnRadius * FMath::Cos(Angle), SpawnRadius * FMath::Sin(Angle), 0);
        FRotator SpawnRotation = FRotator::ZeroRotator;
        FActorSpawnParameters SpawnParams;

        AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnPosition, SpawnRotation, SpawnParams);
        if (SpawnedActor)
        {
            SpawnedActors.Add(SpawnedActor);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Spawned %d actors"), SpawnedActors.Num());

    // Jump will be handled in blueprint
    ActorsSpawnedEvent();
}

void ACubeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACubeManager::ActorsSpawnedEvent_Implementation()
{
	if (SpawnedActors.Num() != 0 && bJumpOnSpawn)
    {
        for (AActor* Actor : SpawnedActors)
        {
            AHitCube* Cube = Cast<AHitCube>(Actor);
            if (Cube)
            {
                Cube->Jump(JumpHeight);
            }
        }
    }
}
