#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitCube.generated.h"

UCLASS()
class THIRDPERSONEXAMPLE_API AHitCube : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHitCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Jump function to create a jumping effect based on the maximum height
	UFUNCTION(BlueprintCallable)
	void Jump(float Height);

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// Event to call when the cube is hit by a character
	// Overkill but allows for easy extension
	UFUNCTION(BlueprintNativeEvent)
	void OnHit();
	virtual void OnHit_Implementation();

private:

	UPROPERTY(EditAnywhere, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;
};