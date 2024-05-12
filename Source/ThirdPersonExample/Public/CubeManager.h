#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeManager.generated.h"

class UCapsuleComponent;

UCLASS()
class THIRDPERSONEXAMPLE_API ACubeManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACubeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame, maybe use it to check if cubes are on the ground?
	virtual void Tick(float DeltaTime) override;

	// Invisible capsule to set as the root component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Root")
	UCapsuleComponent* RootCapsule;

	// Array to hold references to spawned cubes (or other actors)
	TArray<AActor*> SpawnedActors;

	// We will check if they're cubes and make them jump in blueprint

	// Number of cubes to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Config")
	int NumberOfActors = 5;

	// The cubes will be spawned in a circle around the manager
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Config")
	float SpawnRadius = 1000.0f;  // in Unreal units (centimeters)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Config")
	TSubclassOf<AActor> ActorToSpawn;

	// Bool that determines whether the actors "jump" if they are cubes when spawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Config")
	bool bJumpOnSpawn = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Config")
	float JumpHeight = 100.0f;  // in Unreal units (centimeters)

	// Now we have some overengineering for fun

	// We will have this by default call the delegate on all spawned actors
	UFUNCTION(BlueprintNativeEvent, Category = "Spawn Events")
	void ActorsSpawnedEvent();
	virtual void ActorsSpawnedEvent_Implementation();
};
