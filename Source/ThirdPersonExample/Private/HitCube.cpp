#include "HitCube.h"
#include "GameFramework/Character.h"

AHitCube::AHitCube()
{
	PrimaryActorTick.bCanEverTick = true;

	// Make the mesh the root component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// Enable physics
	MeshComponent->SetSimulatePhysics(true);

	// Do collisions
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
}

void AHitCube::BeginPlay()
{
	Super::BeginPlay();
	// We'll call jump in blueprint in the manager class
}

void AHitCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHitCube::Jump(float Height)
{
	// Assuming gravity is set to -980
	float InitialVelocity = FMath::Sqrt(2 * 980 * Height);
	MeshComponent->SetPhysicsLinearVelocity(FVector(0, 0, InitialVelocity));

	UE_LOG(LogTemp, Warning, TEXT("Jumping with velocity %f"), InitialVelocity);
}

void AHitCube::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Check if the other actor is indeed a character
	if (OtherActor && OtherActor != this && OtherComp && OtherActor->IsA<ACharacter>())
	{
		OnHit();
	}
}

void AHitCube::OnHit_Implementation()
{
	// Destroy the actor when hit
	//Destroy();
	// I'm just gonna do this in blueprint
}
