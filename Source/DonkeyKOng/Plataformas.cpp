#include "Plataformas.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"
#include "DonkeyKOngGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlataformas::APlataformas()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Esta línea busca y carga una malla estática específica desde el contenido del proyecto.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> plataforma(TEXT("StaticMesh'/Game/Geometry/PlataformaMesh/untitled_Cubo.untitled_Cubo'"));

	// Crea un nuevo componente de malla estática y lo asigna a la variable del puntero declarado en Plataforma.h
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

	// Inicializa la variable de control de movimiento
	bMoverPlataforma = false;
}

// Called when the game starts or when spawned
void APlataformas::BeginPlay()
{
	Super::BeginPlay();
	posicionActual = GetActorLocation();
	posicionInicial = posicionActual;
	posicionFinal = posicionActual + FVector(0.0f, 200.0f, 200.0f);
	incrementoZ = 2.0f;
	incrementoY = 2.0f;
	subir = false;
	moverDerecha = false;
	detener = false;

	// Obtener el GameMode y la variable Movimiento
	ADonkeyKOngGameMode* GameMode = Cast<ADonkeyKOngGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		bMoverPlataforma = GameMode->Movimiento;
	}
}

// Called every frame
void APlataformas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Actualizar la variable de movimiento cada frame
	ADonkeyKOngGameMode* GameMode = Cast<ADonkeyKOngGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		bMoverPlataforma = GameMode->Movimiento;
	}

	if (bMoverPlataforma && !detener) {
		MoverAleatoriamente();
	}

	SetActorLocation(posicionActual);
}

void APlataformas::MoverAleatoriamente()
{
	// Movimiento cíclico en el eje Z
	if (!subir)
	{
		if (posicionActual.Z < posicionFinal.Z)
		{
			posicionActual.Z += incrementoZ;
		}
		else
		{
			subir = true;
		}
	}
	else
	{
		if (posicionActual.Z > posicionInicial.Z)
		{
			posicionActual.Z -= incrementoZ;
		}
		else {
			subir = false;
		}
	}

	// Movimiento cíclico en el eje Y
	if (!moverDerecha)
	{
		if (posicionActual.Y < posicionFinal.Y)
		{
			posicionActual.Y += incrementoY;
		}
		else
		{
			moverDerecha = true;
		}
	}
	else
	{
		if (posicionActual.Y > posicionInicial.Y)
		{
			posicionActual.Y -= incrementoY;
		}
		else {
			moverDerecha = false;
		}
	}
}
