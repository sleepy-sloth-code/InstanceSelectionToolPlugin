// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "InstanceSelectionToolBPLibrary.generated.h"

// References the Classes containing level instance functions
class ALevelInstance;

UCLASS()
class UInstanceSelectionToolBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	/*
	 * Test Function
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "InstanceSelectionTool sample test testing"), Category = "InstanceSelectionToolTesting")
	static float InstanceSelectionToolSampleFunction(float Param);
	*/
	
	// Create Level Instance, with an option for creating a Packed Level Actor also
	// Takes in arguments: World Context, array of actors, create packed level actor?
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DefaultToSelf))
	static ALevelInstance* CreateLevelInstanceFromArray(
		UObject* WorldContextObject,
		const TArray<AActor*>& Actors,
		const bool bPackedLevelActor = false
	);
};
