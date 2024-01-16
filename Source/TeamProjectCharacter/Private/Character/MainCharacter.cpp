// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 3인칭 메시 초기화
	ThirdPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ThirdPersonMesh"));
	ThirdPersonMesh->SetupAttachment(RootComponent);

	// 3인칭 메시 설정
	ThirdPersonMesh->SetOwnerNoSee(true); // 소유자는 메시를 볼 수 없음
	ThirdPersonMesh->bCastDynamicShadow = true;
	ThirdPersonMesh->CastShadow = true;
	// 일인칭 카메라 초기화
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(RootComponent);

	// 손 스켈레탈 메시 초기화
	HandMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandMesh"));
	HandMeshComponent->SetupAttachment(FirstPersonCameraComponent);
	HandMeshComponent->bCastDynamicShadow = false;
	HandMeshComponent->CastShadow = false;


	HandMeshComponent->SetOnlyOwnerSee(true); // 오직 소유자만 메시를 볼 수 있음
	HandMeshComponent->bCastDynamicShadow = false;
	HandMeshComponent->CastShadow = false;
	
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

