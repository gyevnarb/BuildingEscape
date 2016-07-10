// Copyright © Bálint Gyevnár 2016

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();
	void CloseDoor();
private:
	AActor* Owner = GetOwner();

	float DoorLastOpenTime = 0.f;
	
	UPROPERTY(EditAnywhere)
	float TriggerMass = 60.f;

	UPROPERTY(EditAnywhere)
	float OpenDegree = 90.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 2.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	float GetTotalMassOnPlate() const;
};
