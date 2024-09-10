#include "Barril.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABarril::ABarril()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear el componente de malla estática y adjuntarlo al actor
	CilindroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CilindroMesh"));
	//CilindroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plataforma_Mesh"));

	CilindroMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	CilindroMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 90.0f));
	RootComponent = CilindroMesh;

	// Configurar la malla para simular físicas
	CilindroMesh->SetSimulatePhysics(true);

	// Asignar una malla de cilindro (asegúrate de tener una malla de cilindro en tu proyecto)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CilindroMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (CilindroMeshAsset.Succeeded())
	{
		CilindroMesh->SetStaticMesh(CilindroMeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void ABarril::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABarril::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
