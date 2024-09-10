#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataformas.generated.h"

UCLASS()
class DONKEYKONG_API APlataformas : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlataformas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Componente de malla estática
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaDePlataforma;

	// Variables para el movimiento
	FVector posicionActual;
	FVector posicionInicial;
	FVector posicionFinal;
	float incrementoZ;
	float incrementoY;
	bool subir;
	bool moverDerecha;
	bool detener;

	// Nueva variable para controlar el movimiento
	bool bMoverPlataforma;

	// Función para mover aleatoriamente la plataforma
	void MoverAleatoriamente();
};
