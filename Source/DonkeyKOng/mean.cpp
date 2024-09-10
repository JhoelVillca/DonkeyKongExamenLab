#include "mean.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
Amean::Amean()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear el componente de malla estática y adjuntarlo al actor
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// Asignar una malla de esfera
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}

	// Inicializar los rangos de movimiento
	RangoMovimientoY = 100.0f;
	RangoMovimientoZ = 100.0f;
}

// Called when the game starts or when spawned
void Amean::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void Amean::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Mover el actor aleatoriamente
	MoverAleatoriamente();
}

void Amean::MoverAleatoriamente()
{
	FVector NuevaPosicion = GetActorLocation();
	NuevaPosicion.Y += FMath::RandRange(-RangoMovimientoY, RangoMovimientoY) * GetWorld()->GetDeltaSeconds();
	NuevaPosicion.Z += FMath::RandRange(-RangoMovimientoZ, RangoMovimientoZ) * GetWorld()->GetDeltaSeconds();
	SetActorLocation(NuevaPosicion);
}
