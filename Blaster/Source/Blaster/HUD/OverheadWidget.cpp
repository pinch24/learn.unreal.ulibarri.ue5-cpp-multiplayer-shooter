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
			//Role = FString("Authority");
			Role = FString("A");
			break;
		case ROLE_AutonomousProxy:
			//Role = FString("Autonomous Proxy");
			Role = FString("AP");
			break;
		case ROLE_SimulatedProxy:
			//Role = FString("Simulated Proxy");
			Role = FString("SP");
			break;
		case ROLE_None:
			//Role = FString("None");
			Role = FString("N");
			break;
		case ROLE_MAX:
			//Role = FString("Max");
			Role = FString("M");
			break;
	}
	//const FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);
	const FString RemoteRoleString = FString::Printf(TEXT("%s"), *Role);
	SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
