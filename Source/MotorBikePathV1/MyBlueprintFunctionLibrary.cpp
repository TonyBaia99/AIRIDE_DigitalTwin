// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

static TArray<FVector> motorBikePath;

static TArray<FVector4> trafficConeInitialPosition;

void UMyBlueprintFunctionLibrary::cleanMotorBikePath()
{
    motorBikePath.Empty();
}

/**
 * Metodo che inizializza il vettore nella quale si trovano le coordinate del path della moto.
*/
void UMyBlueprintFunctionLibrary::cleanTrafficConeInitialPosition()
{
    trafficConeInitialPosition.Empty();
}

/**
 * Metodo che ritorna il Path che la moto dovrà percorrere.
*/
TArray<FVector> UMyBlueprintFunctionLibrary::returnMotorBikePath()
{
	return motorBikePath; 
}

/**
 * Metodo che ritorna il vettore delle info iniziali sui coni
*/
TArray<FVector4> UMyBlueprintFunctionLibrary::returnTrafficConeInitialPosition()
{
	return trafficConeInitialPosition; 
}

/**
 * Metodo che mi recupera le coordinate dai txt nella cartella specificata e mi genera un vettore di stringhe in cui
 * ci sono tutte le coordinate. Nello stesso tempo rimepie un array di coordinate 3D che rappresenterà effettivamente il path.
*/
TArray<FString> UMyBlueprintFunctionLibrary::generateMotorBikePath(FString pathFolder)
{
	TArray<FString> output;

	FString filePath = FPaths::ProjectDir()+"/digitalTwinMotorBikePath/"+pathFolder+"/unrealEnginePathL2.txt";
	FFileHelper::LoadFileToStringArray(output, *filePath);

	for(int i=0; i<output.Num(); i++){
		TArray<FString> temp;
		temp.Reset(3);
		
		output[i].ParseIntoArray(temp,TEXT(" "), true);

		float x,y,z;
		FDefaultValueHelper converter;
		converter.ParseFloat(temp[0],x);
		converter.ParseFloat(temp[1],y);
		converter.ParseFloat(temp[2],z);
		motorBikePath.Add(FVector(x,y,z));
	}

	return output;
}

TArray<FString> UMyBlueprintFunctionLibrary::generateTrafficConeInitialPosition(FString pathFolder)
{
    TArray<FString> output;

	trafficConeInitialPosition.Init(FVector4(1,0,-1,-1),77);

	FString filePath = FPaths::ProjectDir() + "/digitalTwinMotorBikePath/"+pathFolder+"/trafficConeLogFusion.txt";
	FFileHelper::LoadFileToStringArray(output, *filePath);

	for(int i=0; i<output.Num(); i++){
		TArray<FString> temp;
		temp.Reset(5);
		
		output[i].ParseIntoArray(temp,TEXT(","), true);

		int frame, ID, stato;
		float posX, posY;
		FDefaultValueHelper converter;
		converter.ParseInt(temp[0], frame);
		converter.ParseInt(temp[1], ID);
		converter.ParseInt(temp[2], stato);
		converter.ParseFloat(temp[5], posX);
		converter.ParseFloat(temp[6], posY);
		
		trafficConeInitialPosition[ID]= FVector4(frame,stato,posX,posY);
	}

    return output;
}

