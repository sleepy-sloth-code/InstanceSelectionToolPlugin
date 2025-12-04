// References the Classes containing level instance functions
#include "LevelInstance/LevelInstanceActor.h"
#include "LevelInstance/LevelInstanceSubsystem.h"

// References to Plugin
#include "InstanceSelectionToolBPLibrary.h"
#include "InstanceSelectionTool.h"

UInstanceSelectionToolBPLibrary::UInstanceSelectionToolBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}
/*
 * Test Function
float UInstanceSelectionToolBPLibrary::InstanceSelectionToolSampleFunction(float Param)
{
	return -1;
}
*/

// Create Level Instance, with an option for creating a Packed Level Actor also
ALevelInstance* UInstanceSelectionToolBPLibrary::CreateLevelInstanceFromArray(
	UObject* WorldContextObject,
	const TArray<AActor*>& Actors,
	const bool bPackedLevelActor //Default to false
	)
{	
	//Resolve World argument, if no World Context is found return null
	UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World == nullptr)
	{
		return nullptr;
	}
	
	// Resolve Level Instance Subsystem, if the subsystem can't be accessed then returns null and logs the error
	ULevelInstanceSubsystem* const LevelInstanceSubsystem = World->GetSubsystem<ULevelInstanceSubsystem>();
	if (LevelInstanceSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%hs: Could not call the Level Instance Subsystem"), __FUNCTION__);
		return nullptr;
	}
	
	// Create Level Instance using Actors array and Params we resolved
	// Depending on Packed Level Actor option will either create with or without
	FNewLevelInstanceParams Params;
	Params.Type = bPackedLevelActor ? ELevelInstanceCreationType::PackedLevelActor : ELevelInstanceCreationType::LevelInstance;
	ILevelInstanceInterface* const LevelInstanceInterface = LevelInstanceSubsystem->CreateLevelInstanceFrom(Actors, Params);
	
	// Cast the result to a Level Instance Actor and return
	ALevelInstance* const LevelInstanceActor = Cast<ALevelInstance>(LevelInstanceInterface);
	return LevelInstanceActor;
}

