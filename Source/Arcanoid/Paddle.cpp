// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PaddleMessAsset(TEXT("/Game/Meshes/SM_Paddle.SM_Paddle"));

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));
	SM_Paddle->SetStaticMesh(PaddleMessAsset.Object);


	RootComponent = SM_Paddle;

	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhisicActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));



	////Buscar Instancias existentes de esta clase creando en un array
	//TArray<AActor*> Instances;

	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), APaddle::StaticClass(), Instances);

	//if (Instances.Num() > 1)
	//{
	//	//Si existe al menos uno de ellos, establezca la instancia con el primero encontrado
	//	Instance = Cast<APaddle>(Instances[0]);

	//	//Agregar mensaje de depuración en pantalla                                         ya existe
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s ya exixte"), *Instance->GetName()));
	//	//Entonces destruye a este actor

	//	Destroy();
	//}
}

void APaddle::MoveHorizontal(float _AxisValue)
{
	AddMovementInput(FVector(_AxisValue, 0.0f, 0.0f), 1.0f, false);
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

