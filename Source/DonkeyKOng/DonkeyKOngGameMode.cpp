#include "DonkeyKOngGameMode.h"
#include "DonkeyKOngCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Plataformas.h"
#include "PlataformaPasto.h"
#include "Barril.h"
#include "Math/UnrealMathUtility.h"
#include "mean.h"

ADonkeyKOngGameMode::ADonkeyKOngGameMode()
{
    // Inicializar la variable Movimiento
    Movimiento = false;

    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
    Posicion = FVector(1180.0f, 0.0f, 6.0f);
    Rotacion = FRotator(0.0f, 0.0f, 0.0f);
    z = 0.0f; // Inicializar z
    Clave = 0; // Inicializar Clave
}

void ADonkeyKOngGameMode::BeginPlay()
{
    Super::BeginPlay();
    //la plataforma
    for (int i = 0; i < 7; i++)
    {
        APlataformas* PT = GetWorld()->SpawnActor<APlataformas>(APlataformas::StaticClass(), Posicion, Rotacion);
        if (Movimiento != true) {
            APlataformaPasto* PT2 = GetWorld()->SpawnActor<APlataformaPasto>(APlataformaPasto::StaticClass(), Posicion, Rotacion);
        }
        ContPlataformas.Add(Clave, PT);
        Clave++; // Incrementar Clave para cada plataforma
        z += 600.0f;
        Posicion = FVector(1270.0f, (FMath::RandRange(200.0f, 300.0f) * ((i % 2 != 0) ? 1 : -1)), z);
        Rotacion = FRotator(0.0f, 0.0f, 4.0f * ((i % 2 != 0) ? 0.0f : 1.0f));
    }

    //el barril
    FVector BarrilPosicion = FVector(1200.f, -516.0f, 3200.0f); // Posición inicial del barril
    FRotator BarrilRotacion = FRotator::ZeroRotator; // Rotación inicial del barril
    GetWorld()->SpawnActor<ABarril>(ABarril::StaticClass(), BarrilPosicion, BarrilRotacion);

    //el objeto mean
    FVector MeanPosicion = FVector(1200.f, -516.0f, 3200.0f); // Posición inicial del objeto mean
    FRotator MeanRotacion = FRotator::ZeroRotator; // Rotación inicial del objeto mean
    GetWorld()->SpawnActor<Amean>(Amean::StaticClass(), MeanPosicion, MeanRotacion);

    // Mover aleatoriamente una plataforma
    APlataformas* Plataforma = Cast<APlataformas>(ContPlataformas[0]); // Supongamos que queremos mover la primera plataforma
    if (Plataforma)
    {
        MoverPlataformaAleatoriamente(Plataforma, true);
    }
}

void ADonkeyKOngGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Implementación de la función para mover aleatoriamente la plataforma
void ADonkeyKOngGameMode::MoverPlataformaAleatoriamente(AActor* Actor, bool bMover)
{
    if (bMover && Actor)
    {
        FVector NuevaPosicion = FVector(FMath::RandRange(-1000.0f, 1000.0f), FMath::RandRange(-1000.0f, 1000.0f), FMath::RandRange(0.0f, 1000.0f));
        Actor->SetActorLocation(NuevaPosicion);
    }
}