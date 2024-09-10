#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barril.generated.h"

UCLASS()
class DONKEYKONG_API ABarril : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABarril();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Componente de malla estática para el cilindro
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CilindroMesh;
};
