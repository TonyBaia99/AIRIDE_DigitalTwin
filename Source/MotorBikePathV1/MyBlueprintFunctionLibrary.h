// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/UnrealString.h"
#include "Misc/DefaultValueHelper.h"
#include "Containers/Array.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MOTORBIKEPATHV1_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "MySpline")
	static TArray<FVector> returnMotorBikePath();

	UFUNCTION(BlueprintCallable, Category = "MySpline")
	static TArray<FVector4> returnTrafficConeInitialPosition();	

	UFUNCTION(BlueprintCallable, Category = "MySpline")
	static void cleanMotorBikePath();

	UFUNCTION(BlueprintCallable, Category = "MySpline")
	static void cleanTrafficConeInitialPosition();

	UFUNCTION(BlueprintCallable, Category = "MySpline")
	static TArray<FString> generateMotorBikePath(FString pathFolder);

	UFUNCTION(BlueprintCallable, Category = "MySpline")
	static TArray<FString> generateTrafficConeInitialPosition(FString pathFolder);
};