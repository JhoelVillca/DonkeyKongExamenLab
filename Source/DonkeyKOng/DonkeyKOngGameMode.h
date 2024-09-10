#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKOngGameMode.generated.h"

UCLASS(minimalapi)
class ADonkeyKOngGameMode : public AGameModeBase
{


    GENERATED_BODY()

public:
    ADonkeyKOngGameMode();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Nueva función para mover aleatoriamente la plataforma
    void MoverPlataformaAleatoriamente(AActor* Actor, bool bMover);

    // Variable para controlar el movimiento de las plataformas
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Control")
    bool Movimiento;

private:
    TMap<int32, AActor*> ContPlataformas;
    FVector Posicion;
    FRotator Rotacion;
    float z;
    int32 Clave;
};
