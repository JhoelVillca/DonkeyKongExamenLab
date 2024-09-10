#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "mean.generated.h"
UCLASS()
class DONKEYKONG_API Amean : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Amean();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Componente de malla estática
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;

	// Función para mover el actor
	void MoverAleatoriamente();

	// Rango de movimiento
	UPROPERTY(EditAnywhere)
	float RangoMovimientoY;

	UPROPERTY(EditAnywhere)
	float RangoMovimientoZ;
};
