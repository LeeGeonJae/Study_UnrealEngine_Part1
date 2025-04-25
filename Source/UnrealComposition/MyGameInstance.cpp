// Fill out your copyright notice in the Description page of Project Settings.

#include "Person.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"
#include "Card.h"
#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("=================================================="));

	TArray<UPerson*> Persons = { NewObject<UStaff>(), NewObject<UStudent>(), NewObject<UTeacher>() };
	for (const auto& Person : Persons)
	{
		const UCard* OwnCard = Person->GetCard();
		ensureMsgf(OwnCard, TEXT("%s님은 현재 카드를 가지고 있지 않습니다."), *Person->GetName());

		ECardType CardType = OwnCard->GetCardType();
		//UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %d"), *Person->GetName(), (uint8)CardType);

		const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));
		if (CardEnumType)
		{
			FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
			UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %s"), *Person->GetName(), *CardMetaData);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("=================================================="));
}
