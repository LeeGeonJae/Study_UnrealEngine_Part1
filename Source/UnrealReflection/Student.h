// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
#include "Student.generated.h"				// generated 헤더 파일은 가장 아래에 인클루드 되어야 합니다.

/**
 * 
 */
UCLASS()
class UNREALREFLECTION_API UStudent : public UPerson
{
	GENERATED_BODY()
public:
	UStudent();

	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 Id;
		
};
