#include "PlataformaPasto.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APlataformaPasto::APlataformaPasto()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Esta línea busca y carga una malla estática específica desde el contenido del proyecto.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> plataforma(TEXT("StaticMesh'/Game/Geometry/PlataformaMesh/untitled_weed14.untitled_weed14'"));

    // Crea un nuevo componente de malla estática y lo asigna a la variable del puntero declarado en PlataformaPasto.h
    MallaDePlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlataformaMesh"));

    // Establece la escala relativa del componente de malla.
    MallaDePlataforma->SetRelativeScale3D(FVector(1.0f, 7.5f, 1.0f));

    // Establece la rotación relativa del componente de malla.
    MallaDePlataforma->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));

    // Asigna la malla estática cargada al componente de malla.
    if (plataforma.Succeeded())
    {
        MallaDePlataforma->SetStaticMesh(plataforma.Object);
    }

    // Establece el componente de malla como el componente raíz del actor.
    SetRootComponent(MallaDePlataforma);
}

// Called when the game starts or when spawned
void APlataformaPasto::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APlataformaPasto::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
