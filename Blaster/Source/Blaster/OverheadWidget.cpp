// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText) {
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	const ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole) {
		case ROLE_Authority:
			Role = FString("Authority");
			break;
		case ROLE_AutonomousProxy:
			Role = FString("Autonomous Proxy");
			break;
		case ROLE_SimulatedProxy:
			Role = FString("Simulated Proxy");
			break;
		case ROLE_None:
			Role = FString("None");
			break;
		case ROLE_MAX:
			Role = FString("Max");
			break;
	}
	const FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);
	SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
