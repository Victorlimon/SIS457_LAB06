// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArcanoidGameModeBase.h"
#include "Paddle.h"
#include "Brick.h"

void AArcanoidGameModeBase::BeginPlay()
{
	Super::BeginPlay();


	FVector SpawnPaddle0(50.0f, 0.0f, 200.0f);
	FVector SpawnPaddle1(-100.0f, 0.0f, 0.0f);

	// Crear 2 Paddle
	for (int i = 0; i <=1 ; i++)
	{
		APaddle* SpawnedPaddle = GetWorld()->SpawnActor<APaddle>(APaddle::StaticClass(), SpawnPaddle0, FRotator::ZeroRotator);

		if (SpawnedPaddle)
		{
			//Si el Spawn tiene éxito, establezca la Nave Enemigo Spawned en el local y registra la cadena de éxito
			Paddle = SpawnedPaddle;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Paddle creado bien"), *Paddle->GetName()));
		}
		SpawnPaddle0 = SpawnPaddle0 + SpawnPaddle1;
	}




	//const FVector Ubicacion(20.0f, 50.0f, 100.0f);
	//const FRotator Rotacion(0.0f, 0.0f, 0.0f);

	//UWorld* const World = GetWorld();

	//if (World != nullptr) {
	//	// Spawn o generacion o creacion de actores en tiempo de ejecucion
	//	ladrillo01 = World->SpawnActor<ABrick>(Ubicacion, Rotacion);
	//	ladrillo01->SetHidden(false);
	//	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan, TEXT("Actor ladrillo 01 creado"));

	//}

}

AArcanoidGameModeBase::AArcanoidGameModeBase()
{

}
