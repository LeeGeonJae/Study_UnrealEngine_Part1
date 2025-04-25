// Fill out your copyright notice in the Description page of Project Settings.

#include "Card.h"
#include "Student.h"

UStudent::UStudent()
{
	Name = TEXT("이학생");
	Card->SetCardType(ECardType::Student);
}

void UStudent::DoLesson()
{
	ILessonInterface::DoLesson();
	UE_LOG(LogTemp, Log, TEXT("%s 님은 공부합니다."), *Name);
}

void UStudent::GetNotification(const FString& School, const FString& NewCourseInfo)
{
	UE_LOG(LogTemp, Log, TEXT("[Student] %s님이 %s로부터 받은 메시지 : %s"), *Name, *School, *NewCourseInfo);
}
