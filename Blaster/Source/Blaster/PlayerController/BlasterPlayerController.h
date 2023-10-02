#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BlasterPlayerController.generated.h"

UCLASS()
class BLASTER_API ABlasterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	class ABlasterHUD* BlasterHUD;
	
protected:
	virtual void BeginPlay() override;

public:
	void SetHUDHealth(float Health, float MaxHealth);
};
